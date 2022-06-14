#include <iostream>
using namespace std;

const int dx[] = {-1,-2,-2,-1,1,2,2,1};
const int dy[] = {-2,-1,1,2,2,1,-1,-2};

int n,i,j;

bool check(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < n)
		return true;
	return false;
}

int main(){
	std::cin >> n >> i >> j;
	int res = 0;
	for (int k = 0; k < 8; k++)
		if (check(i + dx[k], j + dy[k]))
			res++;
	std::cout << res << endl;
	return 0;
}
