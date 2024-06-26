#include <bits/stdc++.h>
using namespace std;

int main() { // Tags: Prefix sums
	freopen("bcount.in", "r", stdin);
  	freopen("bcount.out", "w", stdout);
	int n, q; cin >> n >> q;
	
	vector<int> num_1(n + 1), num_2(n + 1), num_3(n + 1); // Prefix sums array of all 3 breeds

	for (int i = 1; i <= n; i++){ // Go through all indices
		int breed; cin >> breed;
		num_1[i] = num_1[i - 1];
		num_2[i] = num_2[i - 1];
		num_3[i] = num_3[i - 1];
		
		if (breed == 1) num_1[i]++;
		else if (breed == 2) num_2[i]++;
		else num_3[i]++;

		//cout << num_1[i] << " " << num_2[i] << " " << num_3[i] << endl;
	}

	for (int i = 0; i < q; i++){ // Each query
		int l, r; cin >> l >> r;

		int a, b, c;
		a = num_1[r] - num_1[l - 1]; // Breed 1
		b = num_2[r] - num_2[l - 1]; // Breed 2
		c = num_3[r] - num_3[l - 1]; // Breed 3

		cout << a << " " << b << " " << c << endl;
	}
}
