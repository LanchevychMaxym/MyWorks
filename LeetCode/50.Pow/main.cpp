#include<math.h>
class Solution {
public:
	double myPow(double x, int n) {
		if (x==1)
			return 1;
		if (n == 0)
			return 1;
		double res;
		res = myPow(x, n / 2);
	}
};
class Solution {
public:
	double myPow(double x, int n) {
		double temp;
		if (n == 0)
			return 1;
		temp = myPow(x, n / 2);
		if (n % 2 == 0)
			return temp * temp;
		else
		{
			if (n > 0)
				return x * temp * temp;
			else
				return (temp * temp) / x;
		}
	}
};