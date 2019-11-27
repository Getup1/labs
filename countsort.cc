#include <iostream>
#include <limits>
#include <cstdlib>

int main() {
        int n, min = std::numeric_limits<int>::max(), max = std::numeric_limits<int>::min();
        std::cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) {
                std::cin >> a[i];
                if(a[i] > max)
                        max = a[i];
                if(a[i] < min)
                        min = a[i];
        }
        int* count = (int*)malloc(sizeof(int) * (max - min));
        for(int i = 0; i < n; i++) {
                count[a[i] - min] += 1;
        }
        int writePtr = 0;
        for(int i = 0; i <= max - min; i++) {
                for(int j = 1; j <= count[i]; j++) {
                        a[writePtr++] = i + min;
                }
        }
        for(int i = 0; i < n; i++) {
                std::cout << a[i] << " ";
        }
        std::cout << std::endl;
        return 0;
}
