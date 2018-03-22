#include "sum.h"
#include <stdio.h>

int main() {
    const int N = 4;
    const float values[N] = {1.0f, 2.0f, 3.0f, 4.0f};
    float sum = calculateSumOf( values, N );
    printf( "sum = %f\n", sum );
}
