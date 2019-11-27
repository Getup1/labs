#include <stdio.h>
#include <limits>

int main() {
	int length, min = std::numeric_limits<int>::max();
	scanf("%d", &length);
	int arr[length];

	for(int i = 0; i < length; i++) {
		printf("arr[%d] = ", i);
		scanf("%d", &arr[i]);
		if(!(i & 1))
			if(arr[i] < min)
				min = arr[i];
	}
	
	printf("arr = {");
	for(int i = 0; i < length; i++) {
		printf("%d%s", arr[i], i == length - 1 ? "" : ", ");
	}
	printf("}\nmin = %d\n", min);

	return 0;
}
