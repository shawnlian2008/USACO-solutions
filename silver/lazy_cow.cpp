#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("lazy.in", "r", stdin);
	freopen("lazy.out", "w", stdout);
	int n, k; cin >> n >> k;
	vector<vector<long long>> map(2 * n - 1, vector<long long>(2 * n - 1, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { 
			cin >> map[i + j][n - i + j - 1]; 
		}
	}

	vector<vector<long long>> prefix_sums(2 * n, vector<long long>(2 * n, 0));

	for (int i = 1; i <= 2 * n - 1; i++){
		for (int j = 1; j <= 2 * n - 1; j++){
			prefix_sums[i][j] = prefix_sums[i - 1][j] + prefix_sums[i][j - 1] - 
				prefix_sums[i - 1][j - 1] + map[i - 1][j - 1];
		}
	}
	
	long long ans = 0;
	for (int i = 1; i <= 2 * n - 1; i++){
		for (int j = 1; j <= 2 * n - 1; j++){
			long long sums = prefix_sums[min(i + k, 2 * n - 1)][min(j + k, 2 * n - 1)] - 
				prefix_sums[max(i - k - 1, 1)][min(j + k, 2 * n - 1)] - 
				prefix_sums[min(i + k, 2 * n - 1)][max(j - k - 1, 1)] + 
				prefix_sums[max(i - k - 1, 1)][max(j - k - 1, 1)];
			ans = max(ans, sums);
		}
	}

	cout << ans << endl;
}
