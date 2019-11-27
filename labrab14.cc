#include <iostream>
#include <limits>

int main() {
	int size;
	std::cin >> size;

	double sum = 0, sumi = 0;;
	for(int i = 0; i < size; i++) {
		double max = std::numeric_limits<int>::min(), maxIndex = -1;
		for(int j = 0; j < size; j++) {
			double n;
			std::cin >> n;
			if(n > max) {
				max = n;
				maxIndex = j;
			}
		}
		sum += max;
		sumi += maxIndex + i + 2;
	}
	std::cout << sum << "; " << sumi << std::endl;
}
