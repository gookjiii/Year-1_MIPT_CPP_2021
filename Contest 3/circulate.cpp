// C++ program to find the
// incenter of a triangle
#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
	// coordinate of the vertices
	double x1 = 3.779852, x2 = 1.805325, x3 = -2.319490;
	double y1 = -5.253176, y2 = -2.679216, y3 = -5.161077;
	//double a = 3.24408, b = 4.81391, c = 6.10004;
	double a = 4.81391, b = 6.10004, c = 3.24408;
	// Formula to calculate in-center
	float x = (a * x1 + b *
				x2 + c * x3) / (a + b + c);
	float y = (a * y1 + b *
				y2 + c * y3) / (a + b + c);

	// System.out.print(setprecision(3));
	cout << "Incenter = "
		<< "(" << x << ", " << y << ")";
	return 0;
}

// This code is contributed by 29AjayKumar

