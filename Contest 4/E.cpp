#include<iostream>
#include<vector>
#include<unordered_set>

int main() {
	int n;
	std::vector<int> a, b;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int val;
		std::cin >> val;
		a.push_back(val);
	}
	int m;
	std::cin >> m;
	for (int i = 0; i < m; i++) {
		int val;
		std::cin >> val;
		b.push_back(val);
	}
	int c;
	std::cin >> c;
	std::unordered_set<int> count_set;
	for (int i = 0; i < n; i++)
		count_set.insert(c - a[i]);
	int res = 0;
	for (int i = 0; i < m; i++)
			res += count_set.count(b[i]);
	std::cout << res;
	return 0;
}
