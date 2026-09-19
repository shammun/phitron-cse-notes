(function () {
  var root = document.documentElement;
  function store(k, v) { try { if (v === null) localStorage.removeItem(k); else localStorage.setItem(k, v); } catch (e) {} }
  function toast(msg) {
    var t = document.createElement('div'); t.className = 'toast'; t.textContent = msg;
    document.body.appendChild(t); setTimeout(function () { t.remove(); }, 1400);
  }

  // ---- theme
  var themeBtn = document.getElementById('themeBtn');
  themeBtn && themeBtn.addEventListener('click', function () {
    var dark = root.dataset.theme ? root.dataset.theme === 'dark' : matchMedia('(prefers-color-scheme: dark)').matches;
    root.dataset.theme = dark ? 'light' : 'dark';
    store('theme', root.dataset.theme);
  });

  // ---- recall mode: hide code so you can write it from memory
  var recallBtn = document.getElementById('recallBtn');
  function syncRecall() { recallBtn && recallBtn.setAttribute('aria-pressed', root.classList.contains('recall')); }
  syncRecall();
  recallBtn && recallBtn.addEventListener('click', function () {
    var on = root.classList.toggle('recall');
    document.querySelectorAll('.codebox-wrap.revealed').forEach(function (w) { w.classList.remove('revealed'); });
    store('recall', on ? '1' : null); syncRecall();
    toast(on ? 'Recall mode on — code hidden' : 'Recall mode off');
  });

  document.addEventListener('click', function (ev) {
    var b = ev.target.closest('button'); if (!b) return;
    var wrap = b.closest('.codebox-wrap');
    if (b.classList.contains('reveal') && wrap) { wrap.classList.add('revealed'); }
    else if (b.classList.contains('expand') && wrap) {
      var open = wrap.classList.toggle('open');
      b.textContent = open ? 'Collapse ▴' : b.dataset.label || 'Show all ▾';
      if (!open) wrap.scrollIntoView({ block: 'nearest' });
    } else if (b.classList.contains('copy') && wrap) {
      var code = wrap.querySelector('td.code pre, .hl pre:last-child');
      var text = code ? code.innerText : '';
      var done = function () { toast('Code copied'); };
      if (navigator.clipboard && window.isSecureContext) navigator.clipboard.writeText(text).then(done, function () { fallback(text); });
      else fallback(text);
      function fallback(t) {
        var ta = document.createElement('textarea'); ta.value = t; document.body.appendChild(ta); ta.select();
        try { document.execCommand('copy'); done(); } catch (e) {} ta.remove();
      }
    }
  });
  document.querySelectorAll('.expand').forEach(function (b) { b.dataset.label = b.textContent; });

  // ---- search
  var box = document.getElementById('search'), q = document.getElementById('q'), list = document.getElementById('results');
  var base = window.SITE_ROOT || '';
  var sel = 0, hits = [];
  function openSearch() { box.hidden = false; q.value = ''; render(); q.focus(); }
  function closeSearch() { box.hidden = true; }
  function norm(s) { return (s || '').toLowerCase(); }
  function render() {
    var idx = window.SEARCH_INDEX || [];
    var terms = norm(q.value).split(/\s+/).filter(Boolean);
    hits = [];
    if (terms.length) {
      for (var i = 0; i < idx.length && hits.length < 60; i++) {
        var it = idx[i], hay = norm(it.t + ' ' + it.s + ' ' + it.x), title = norm(it.t);
        if (terms.every(function (t) { return hay.indexOf(t) >= 0; })) {
          var score = terms.reduce(function (a, t) { return a + (title.indexOf(t) >= 0 ? 2 : 0); }, 0) + (it.k === 'm' ? 1 : 0);
          hits.push({ it: it, score: score });
        }
      }
      hits.sort(function (a, b) { return b.score - a.score; });
    }
    sel = 0;
    list.innerHTML = '';
    if (terms.length && !hits.length) { list.innerHTML = '<li><a>No matches</a></li>'; return; }
    hits.slice(0, 40).forEach(function (h, i) {
      var li = document.createElement('li'), a = document.createElement('a');
      a.href = base + h.it.u; if (i === 0) a.className = 'sel';
      var k = document.createElement('span'); k.className = 'kind'; k.textContent = h.it.k === 'm' ? 'module' : 'program';
      var s = document.createElement('small'); s.textContent = h.it.s;
      a.appendChild(k); a.appendChild(document.createTextNode(h.it.t)); a.appendChild(s);
      a.addEventListener('click', closeSearch);
      li.appendChild(a); list.appendChild(li);
    });
  }
  if (box) {
    q.addEventListener('input', render);
    q.addEventListener('keydown', function (e) {
      var links = list.querySelectorAll('a[href]');
      if (e.key === 'ArrowDown' || e.key === 'ArrowUp') {
        e.preventDefault(); if (!links.length) return;
        links[sel] && links[sel].classList.remove('sel');
        sel = (sel + (e.key === 'ArrowDown' ? 1 : links.length - 1)) % links.length;
        links[sel].classList.add('sel'); links[sel].scrollIntoView({ block: 'nearest' });
      } else if (e.key === 'Enter' && links[sel]) { location.href = links[sel].href; closeSearch(); }
    });
    box.addEventListener('click', function (e) { if (e.target === box) closeSearch(); });
    document.getElementById('searchClose').addEventListener('click', closeSearch);
    ['searchBtn', 'heroSearch'].forEach(function (id) { var el = document.getElementById(id); el && el.addEventListener('click', openSearch); });
    document.addEventListener('keydown', function (e) {
      if (e.key === 'Escape' && !box.hidden) closeSearch();
      else if (e.key === '/' && box.hidden && !/input|textarea/i.test(document.activeElement.tagName)) { e.preventDefault(); openSearch(); }
    });
  }
  // ---- step players: click through a traced example one frame at a time
  document.querySelectorAll('.stepper').forEach(function (st) {
    var frames = st.querySelectorAll('.frame');
    var n = frames.length, i = 0, timer = null;
    var prev = st.querySelector('.sprev'), next = st.querySelector('.snext');
    var play = st.querySelector('.splay'), count = st.querySelector('.scount');
    function show(k) {
      i = Math.max(0, Math.min(n - 1, k));
      frames.forEach(function (f, j) { f.classList.toggle('on', j === i); });
      count.textContent = 'Step ' + (i + 1) + ' of ' + n;
      prev.disabled = i === 0; next.disabled = i === n - 1;
    }
    function stop() { clearInterval(timer); timer = null; play.textContent = 'Play ▶'; }
    prev.addEventListener('click', function () { stop(); show(i - 1); });
    next.addEventListener('click', function () { stop(); show(i + 1); });
    play.addEventListener('click', function () {
      if (timer) { stop(); return; }
      if (i === n - 1) show(0);
      play.textContent = 'Pause ⏸';
      timer = setInterval(function () { if (i === n - 1) stop(); else show(i + 1); }, 1400);
    });
    show(0);
  });
})();