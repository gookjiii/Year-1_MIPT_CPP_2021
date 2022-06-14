#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int res = 0, a[n];
		for (int i = 1; i <= n; i++)
			cin >> a[n],
			res = max(res, k - a[n]);
		cout << res << "\n";
	}
}
