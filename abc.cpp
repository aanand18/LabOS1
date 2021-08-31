#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int solve(vector<vector<int>> matrix, int i, int j) {
	int n = matrix.size();
	int m = matrix[0].size();
	if (i < 0 || j < 0 || i >= n || j >= m) return 0;
	if (i == 0 && j == 0) return 1;
	if (dp[i][j] != -1) return dp[i][j];

	int a, b;
	if (i - 1 >= 0 && matrix[i - 1][j] != 1) a = solve(matrix, i - 1, j);
	else a = 0;
	if (j - 1 >= 0 && matrix[i][j - 1] != 1) b = solve(matrix, i, j - 1);
	else b = 0;
	dp[i][j] = a + b;
	return dp[i][j];
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrix;
	vector<int> a(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; j++) {
			cin >> a[j];
		}
		matrix.push_back(a);
	}
	memset(dp, -1, sizeof(dp));

	cout << solve(matrix, n - 1, m - 1) << endl;
}

