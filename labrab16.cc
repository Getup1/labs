#include <cstdio>
#include <cmath>

double poly2(double x, double a, double b, double c) {
	return a * pow(x, 2) + b * x + c;
}

int main() {
	double x, y;
	scanf("%lf", &x);

	y = (exp(poly2(x, 7.4, 0, 3)) - exp(2 * poly2(x, 8, -0.56, -1.5)))/poly2(x, 2.5, 3.8, -16.5);

	printf("%.3lf\n", y);
	return 0;
}
