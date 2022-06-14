#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	for( ; t > 0 ; t--) {
		int n,q;
		cin >> n;
		int a[n + 1];
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		cin >> q;
		for(int k = 1; k <= q; k++) {
			int x;
			cin >> x;
			int index = -1;
			for(int i = 1; i <= n; i++)
				if(a[i] == x)
					index = i;
			cout << index << endl;
		}
	}
}
