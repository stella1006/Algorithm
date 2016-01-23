// Problem#: 17270
// Submission#: 4402758
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
	   double a, b, c, d, e, f;
	   double x, y;
	   double result;
	   cin >> a >> b >> c >> d >> e >> f;

	   double a1 = a * a + c*c;
	   double b1 = a*b+c*d;
	   double c1 = a*e+c*f;
	   double a2 = a*b+c*d;
	   double b2 = b*b + d*d;
	   double c2 = b*e + d*f;
	   
	   if (abs(a1 * b2 - a2 * b1) > 0.00000001) {
		   x =( 1.0 * ((c1)*(b2)-(a2)*(c2))) / ((a1)*(b2) - (b1)*(b1));
		   y =( 1.0 * ((c2) - (a2)*x)) / (b2);
	   } else if (a1 != 0) {
		   x = 1.0 * c1 / a1;
		   y = 0;
	   } else if (a2 != 0) {
		    x = 1.0 * c2 / a2;
		    y = 0;
	   } else if (b1 != 0) {
		   y = 1.0 * c1 / b1;
		   x = 0;
	   } else if (b2 != 0) {
		   y = 1.0 * c2 / b2;
		   x = 0;
	   }




	   result = (a*x+b*y-e)*(a*x+b*y-e) +  (c*x+d*y-f)*(c*x+d*y-f);
	   
	   //printf("Case #%d: ", t);
	   //printf("%8lf\n", result);

	   cout << "Case #" << t << ": " << setprecision(7) << std::fixed << result << endl;

		
	}

	//system("pause");
	return 0;
}                                 
