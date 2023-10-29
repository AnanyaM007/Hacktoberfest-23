// write a c program to implement longest common subsequence(LCS)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void printAll(int i, int j, int index, char s1[], char s2[], int dp[][101], char *lcs)
{
    if (i == 0 || j == 0)
    {
        printf("%s\n", lcs);
        return;
    }

    if (s1[i - 1] == s2[j - 1])
    {
        lcs[index - 1] = s1[i - 1];
        printAll(i - 1, j - 1, index - 1, s1, s2, dp, lcs);
    }
    else if (dp[i - 1][j] > dp[i][j - 1])
    {
        printAll(i - 1, j, index, s1, s2, dp, lcs);
    }
    else if (dp[i][j - 1] > dp[i - 1][j])
    {
        printAll(i, j - 1, index, s1, s2, dp, lcs);
    }
    else
    {
        printAll(i - 1, j, index, s1, s2, dp, lcs);
        printAll(i, j - 1, index, s1, s2, dp, lcs);
    }
}

void printAllLCS(char s1[], char s2[], int m, int n)
{
    int dp[101][101];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    char *lcs = (char *)malloc((dp[m][n] + 1) * sizeof(char));
    memset(lcs, 0, (dp[m][n] + 1) * sizeof(char));

    printf("Longest common subsequences:\n");
    printAll(m, n, dp[m][n], s1, s2, dp, lcs);

    free(lcs);
}

int main()
{
    char s1[100], s2[100];
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);
    int m = strlen(s1);
    int n = strlen(s2);

    printAllLCS(s1, s2, m, n);

    return 0;
} 
