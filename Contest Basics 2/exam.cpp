#include<iostream>

void add_array(int n, int* arr) {
	for(int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
}

int* sum_array(int n, int* a, int *b) {
	int* sum = new int[n];
	for(int i = 0; i < n; i++) {
		sum[i] = a[i] + b[i];
	}
	return sum;
}

int main() {
	int n;
	std::cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	add_array(n,a);
	add_array(n,b);
	int* res = sum_array(n,a,b);
	for (int i = 0; i < n; i++)
		std::cout << res[i] << " ";
	return 0;
}
