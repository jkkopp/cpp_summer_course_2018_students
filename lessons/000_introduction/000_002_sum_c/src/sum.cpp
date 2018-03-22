	#include "sum.h"

float calculateSumOf( const float* const v, int num_v )
{
	return (num_v) ? *v+calculateSumOf(v+1, num_v-1) : 0;
}
