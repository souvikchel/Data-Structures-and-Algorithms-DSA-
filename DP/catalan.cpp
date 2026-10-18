#include <iostream>
#include <vector>
using namespace std;

// 1. Recursion
int catalanRec(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans += catalanRec(i) * catalanRec(n - i - 1);
    }

    return ans;
}

// 2. Memoization (Top-Down DP)
int catalanMemo(int n, vector<int>& dp) {
    if (n == 0 || n == 1) {
        return 1;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans += catalanMemo(i, dp) *
               catalanMemo(n - i - 1, dp);
    }

    return dp[n] = ans;
}

// 3. Tabulation (Bottom-Up DP)
int catalanTab(int n) {
    vector<int> dp(n + 1, 0);

    dp[0] = 1;

    if (n >= 1) {
        dp[1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    return dp[n];
}

int main() {
    int n = 6;

    cout << "Recursion: ";
    for (int i = 0; i <= n; i++) {
        cout << catalanRec(i) << " ";
    }

    cout << "\nMemoization: ";
    vector<int> dp(n + 1, -1);

    for (int i = 0; i <= n; i++) {
        cout << catalanMemo(i, dp) << " ";
    }

    cout << "\nTabulation: ";
    for (int i = 0; i <= n; i++) {
        cout << catalanTab(i) << " ";
    }

    cout << endl;

    return 0;
}