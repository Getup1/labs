#include <iostream>
#include <fstream>
#include <string>

bool readInt(std::ifstream &stream, int &result) {
	char *buffer = new char[sizeof(int)];
	stream.read(buffer, sizeof(int));
	result = 0;
	// code for little endian, replace sizeof(int) - i - 1 to i for big endian
	for(size_t i = 0; i < sizeof(int); i++)
		result |= static_cast<int>(buffer[sizeof(int) - i - 1]) << (i * 8);
	delete[] buffer;
	return stream.good();
}

int main() {
	std::ifstream numberFile("numbers.dat", std::ifstream::binary);
	int negatives = 0;
	int positives = 0;
	int counter = 0;
	int n;
	std::string outputFileName;
	std::cin >> outputFileName;
	std::ofstream outputFile(outputFileName);
	while(readInt(numberFile, n)) {
		if(outputFile.is_open())
			outputFile << n << " ";
		std::cout << n << " ";
		if(n < 0)
			negatives++;
		else if(n > 0) {
			counter++;
			positives += n;
		}
	}
	double average = static_cast<double>(positives)/counter;
	if(outputFile.is_open()) {
		outputFile.precision(2);
		outputFile << std::fixed;
		outputFile << "\n" << negatives << " " << average << std::endl;
	}
	std::cout.precision(2);
	std::cout << std::fixed;
	std::cout << "\n" << negatives << " " << average << std::endl;
	return 0;
}
