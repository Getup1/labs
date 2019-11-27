//ВВОД: <площа (га)> <середня врожайність (ц/га)> (x10)

#include <iostream>

int main() {
	const int REGIONS = 10;
	
	double yield = 0;
	double productivity = 0;

	for(int i = 0; i < REGIONS; i++) {
		double y, p;
		std::cin >> y >> p;
		productivity += p;
		yield += y * p;
	}

	std::cout << "Total yield: " << yield << " qq\n";
	std::cout << "Average prod: " << (float) productivity / REGIONS << " qq/ha" << std::endl;

	return 0;
}
