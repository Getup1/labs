#include <stdio.h>
#include <utility>

int main() {
	const int SIZE = 10;

	int arr[SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int count = 0;

	for(int j = 1; j < SIZE; j++) {	
		bool sorted = false;
		for(int i = 0; i < SIZE - j; i++)
			if(arr[i] > arr[i + 1])
				std::swap(arr[i], arr[i + 1]);
			else
				sorted = true;
		printf("arr = {");
		for(int i = 0; i < SIZE; i++) {
			printf("%d%s", arr[i], i == SIZE - 1 ? "" : ", ");
		}
		printf("}\n");
		count++;
		if(sorted) break;
	}

	printf("%d\n", count);
	return 0;
}
