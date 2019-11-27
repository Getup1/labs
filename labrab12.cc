#include <stdio.h>
#include <ctime>
#include <cstdlib>

float randomReal(float a, float b) {
	return a + (float)(rand()) / (float)(RAND_MAX / (b - a));
}

int main() {
	const int LENGTH = 10;
	
	srand(time(nullptr));

	float a, b, positives, negatives;
	float arr[LENGTH];
	scanf("%f%f", &a, &b);
	
	for(int i = 0; i < LENGTH; i++) {
		arr[i] = randomReal(a, b);
		if(arr[i] > 0)
			positives += arr[i];
		else
			negatives += arr[i];
	}

	printf("arr = {");
	for(int i = 0; i < LENGTH; i++) {
		printf("%f%s", arr[i], i == LENGTH- 1 ? "" : ", ");
	}
	printf("}\nquotient = %f\n", -positives/negatives);

	return 0;
}



