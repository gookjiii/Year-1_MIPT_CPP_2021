#include <iostream>
#define N 204

int a[N];
int n;

int main(){
	std::cin >> n;
	for (int i = 1; i < 2*n; i++)
		a[i] = (i > n ? n - (i % n) : i);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			std::cout << a[n - i + j] << " ";
		std::cout << "\n";
	}
	return 0;
}
