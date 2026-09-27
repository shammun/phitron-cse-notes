#include <stdio.h>
#include <string.h>

int main(){
    char str1[105], str2[105], str3[105];

    scanf("%s", str1);
    scanf("%s", str2);
    scanf("%s", str3);

    int len = strlen(str1);
    int total_changes = 0;

    for(int i=0; i<len; i++){
        if(str1[i] != str2[i] && str1[i] != str3[i] && str2[i] != str3[i]){
            total_changes += 2;
        }

        else if(str1[i] == str2[i] && str2[i] != str3[i]){
            total_changes += 1;
        } else if(str1[i] == str3[i] && str1[i] != str2[i]){
            total_changes += 1;
        } else if(str2[i] == str3[i] && str2[i] != str1[i]){
            total_changes += 1;
        } else {
            total_changes += 0;
        }
    }

    printf("%d\n", total_changes);
    return 0;
}