#include <iostream>
using namespace std;
bool equal(double x, double y){
      return labs(x-y)<= 1e-6;}

int main ()
{
    double x1,y1,x2,y2,r1,r2;
    cin >> x1;
    cin >> y1;
    cin >> r1;
    cin >> x2;
    cin >> y2;
    cin >> r2;
    if (equal(x1,x2) && equal(y1,y2) && equal(r1,r2) ) {cout << "in?nity"<<endl;}
    else{
    double distSq = (x1 - x2) * (x1 - x2) +(y1 - y2) * (y1 - y2);
    double radSumSq = (r1 + r2) * (r1 + r2);

    if (equal(distSq, radSumSq)){cout << 1<< endl;}
    else if (distSq > radSumSq){cout << 0<< endl;}
    else if (distSq < radSumSq){cout << 2<<endl;}
    }
    return 0;
}
