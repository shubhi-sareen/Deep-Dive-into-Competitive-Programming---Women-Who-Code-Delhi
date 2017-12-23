#include <iostream>
#include <cstring>
using namespace std;

int maxnum(int a, int b);
void lcs(int dp[][100],int m, int n, char *a, char *b);

int len_lcs_rec( char *X, char *Y, int m, int n )
{
   if (m == 0 || n == 0)
     return 0;

   if (X[m-1] == Y[n-1])
     return 1 + len_lcs_rec(X, Y, m-1, n-1);

   else
     return maxnum(len_lcs_rec(X, Y, m, n-1), len_lcs_rec(X, Y, m-1, n));
}

int maxnum(int a, int b)
{
    return (a > b)? a : b;
}

int dp[100][100];

void display(int a[][100], int m, int n) {

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << a[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

int len_lcs (char *a, char *b, int m, int n) {

    for (int i = 0; i<= m; i++) {
        dp[0][i] = 0;
    }

    for (int i = 0; i<= n; i++) {
        dp[i][0] = 0;
    }

    cout<<"Initial Arrary Display:\n";

    display(dp, m, n);

    for (int i = 1; i<=m; i++) {
        for (int j = 1; j<=n; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = maxnum(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    cout<<"Displaying array after processing:\n";

    display(dp,m,n);
    cout<<"Longest common subsequence: ";
    lcs (dp,m,n,a,b);
    return dp[m][n];
}

void lcs(int dp[][100],int m, int n, char *a, char *b) {
    char retval[100];
    retval[dp[m][n]] = '\0';
    int i = m, j = n;
    while (dp[i][j] != 0) {
        if (dp[i-1][j] == dp[i][j]) {
            i = i-1;
        }
        else if (dp[i][j-1] == dp[i][j]) {
            j = j-1;
        }
        else {
            retval[dp[i][j] - 1] = a[i-1];
            i = i-1;
            j = j-1;
        }
    }
    cout << retval << "\n";
}

int main () {

    char *b = "aababcb", *a = "abc";
    cout << "len by recursion: " << len_lcs_rec(a,b,strlen(a),strlen(b))<<"\n\n";
    cout << "\nlen by DP: " << len_lcs(a,b,strlen(a),strlen(b));
    return 0;
}
