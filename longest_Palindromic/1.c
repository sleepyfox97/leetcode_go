#include <stdlib.h>

int isPalindrome(char *s, int start, int end){
    int tmp;
    int i;
    
    tmp = end - start;
    i = 0;
    while (i <= tmp / 2){
        if (s[start + i] != s[end - i])
            return (0);
        i++;
        }
    return (end);
}

char * longestPalindrome(char * s){
    int i;
    int j;
    int start;
    int end;
    char *re;
    
    i = 0;
    start = 0;
    end = 0;
    while(s[i]){
        j = i + end;
        while(j < strlen(s)){
            if (isPalindrome(s, i, j) > 0)
            {
                if (end < j - i + 1){
                    start = i;
                    end = j - i + 1;
                }
            }
            j++;
        }
        i++;
    }
    if (end == 0)
        end = 1;
    re = (char *)malloc(sizeof(char) * (end + 1));
    if (re == NULL)
        return (0);
    i = 0;
    while (i < end)
    {
        re[i] = s[start + i];
        i++;
    }
    re[i] = '\0';
    return (re);
}