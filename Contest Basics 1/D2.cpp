#include<bits/stdc++.h>
using namespace std;

double xt1,yt1,xt2,yt2,r1,r2;

int main(){
	cin >> xt1 >> yt1 >> r1 >> xt2 >> yt2 >> r2;
	if (xt1 == xt2 && yt1 == yt2 && r1 == 0 && r2 == 0) {
		cout << 1;
	}
	double diff =  (xt1-xt2)*(xt1-xt2) + (yt1-yt2)*(yt1-yt2) - (r1 + r2)*(r1 + r2);
	double diff2 =  (xt1-xt2)*(xt1-xt2) + (yt1-yt2)*(yt1-yt2) - (r1 - r2)*(r1 - r2);
	if (fabs(diff) <= 1e-6) diff = 0;
	if (fabs(diff2) <= 1e-6) diff2 = 0;
	if ((xt1-xt2)*(xt1-xt2) + (yt1-yt2)*(yt1-yt2) <= 1e-6 && fabs(r1 - r2) <= 1e-6 )
		cout << "infinity";
	else if (diff == 0 || diff2 == 0)
		cout << 1;
	else if ((diff < 0 && diff2 > 0) || (diff > 0 && diff2 < 0))
		cout << 2;
	else
		cout << 0;
	return 0;
}
