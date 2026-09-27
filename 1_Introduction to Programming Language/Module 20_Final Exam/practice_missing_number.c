#include <stdio.h>

int main(){
    int T;
    scanf("%d", &T);

    long long results[100005];

    for(int i=0; i<T; i++){
        long long M, A,B,C;
        scanf("%lld %lld %lld %lld", &M, &A, &B, &C);

        long long remainder = M % (A * B * C);

        if(remainder == 0){
            results[i] = M / (A * B * C);
        }else{
            results[i] = -1;
        }
    }

    for(int i=0; i<T; i++){
        printf("%lld\n", results[i]);
    }
}