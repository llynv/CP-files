#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

const int N = 1e3 + 7;

int main()
{
    char s[N];
    gets(s);
    
    int len = strlen(s);
    char c[N][len + 1];
    int cnt = 0, j = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] != ' ') c[cnt][j++] = s[i];
        if (s[i] == ' ' || i == len - 1) {
            cnt++;
            j = 0;
        }
    }
    for (int i = cnt; i >= 0; --i) printf("%s ", c[i]);
}