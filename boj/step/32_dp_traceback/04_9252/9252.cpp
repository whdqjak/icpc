#include <stdio.h>
#include <string.h>

int dp[1001][1001];

char s1[1001], s2[1001];
int lena, lenb;


int maxf(int a, int b){
    return a>b?a:b;
}

//lcs길이 반환  //a~, b~
int lcs() {
    for (int i = 0; i <= lena; ++i) {
        for (int j = 0; j <= lenb; ++j) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= lena; ++i) {
        for (int j = 1; j <= lenb; ++j) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = maxf(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[lena][lenb];
}


void printLcs() {
    int a = lena, b = lenb;
    char lcsStr[1001];
    int idx=0;
    
    while (a > 0 && b > 0) {
        if (s1[a - 1] == s2[b - 1]) {
            lcsStr[idx++] = s1[a - 1];
            a--;
            b--;
        }
        else if (dp[a - 1][b] >= dp[a][b - 1]) a--;
        else b--;
    }
    
    for (int i = idx - 1; i >= 0; --i) {
        printf("%c", lcsStr[i]);
    }
}

int main() {
    
    scanf("%s %s", s1, s2);
    lena=strlen(s1);
    lenb=strlen(s2);
    
    printf("%d\n", lcs());
    printLcs(0,0);
    
    return 0;
}