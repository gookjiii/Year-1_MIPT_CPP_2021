#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("vd2.inp.c","r",stdin);
	freopen("vd2.out.c","r",stdin);
	float r1,r2,r3;
	float res = 0;
	while(!feof(stdin)) {
		cin >> r1 >> r2 >> r3;
		cout << (r1*r2*r3)/(r1*r2+r1*r3+r2*r3) << " ";
		cout << (r1*r2)/(r1+r2) + r3 << " ";
		cout << (r1*r3)/(r1+r3) << " ";
		cout << (r2*r3)/(r2+r3) << " ";
		cout << (r1+r2+r3) << endl;
	}
	return 0;
}
