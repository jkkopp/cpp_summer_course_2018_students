#include "sum.h"

float calculate_sum_of( const std::vector<float>& summands )
{
    float sum = 0.0f;
    for( auto cur_summand : summands )
    {
        sum += cur_summand;
    }
    return sum;
}
