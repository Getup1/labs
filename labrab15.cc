#include <iostream>
#include <math.h>

double y(double x) {
	return sin(x);
}

int main() {
	double a, b, c, x, t;
	std::cin >> a >> b >> c >> x;
	if(c == 0 ||
	   sin(a + b / c) == 0 ||
	   tan(c - b) == -pow(a, 2) ||
	   tan(c - b) == INFINITY) {
		std::cout << "error" << std::endl;
		return 0;
	}	
	t = a + b / c;
	std::cout << x * (3 * y(t)) / (tan(c - b) + pow(a, 2)) + b * y(t) << std::endl;
	return 0;
}
