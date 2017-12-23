#include<iostream>
using namespace std;


int dp[100][100];

void display(int a[][100], int m, int n) {

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

//m rows, n columns
int number_of_paths (int dp[][100], int m, int n) {

    if (dp[0][0] == -1) {
        //no paths to any block
        return 0;
    }

    dp[0][0] = 0;

    for (int i = 1; i < m; i++) {
        if(dp[i][0] != -1) {
            dp[i][0] = 1;
        } else {
            break;
        }
    }

    for (int j = 1; j < n; j++) {
        if(dp[0][j] != -1) {
            dp[0][j] = 1;
        } else {
            break;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {

            if (dp[i][j] == -1) {
                continue;
            }

            if (dp[i-1][j] == -1) {
                dp[i][j] = dp[i][j-1];
            } else if(dp[i][j-1] == -1) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    cout<<"Final Array: \n";
    display(dp,m,n);

    return dp[m-1][n-1];
}


int main () {

    int m,n,k,i,j;
    cout << "Enter rows and columns: ";
    cin >> m >> n;


    cout << "\nEnter number of obstacles: ";
    cin >> k;

    cout << "\nEnter position of obstacles:\n";

    while (k--) {
        cin >> i >> j;
        dp[i-1][j-1] = -1;
    }

    cout<<"Initial Array: \n";
    display(dp,m,n);

    cout << "Possible number of paths: " << number_of_paths(dp,m,n);
    return 0;
}
