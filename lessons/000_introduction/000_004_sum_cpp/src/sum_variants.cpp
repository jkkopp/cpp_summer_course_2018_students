#include "sum_variants.h"
#include <algorithm>
#include <numeric>


element_type sum_oldstyle( const container_type& summands ) {
    element_type result = ELEMENT_TYPE_ZERO;
    for( container_type::size_type index = 0; index < summands.size(); ++index ) {
        result += summands.at( index );
    }
    return result;
}

element_type sum_cpp11( const container_type& summands ) {
    element_type result = ELEMENT_TYPE_ZERO;
    for( auto& cur_summand : summands ) {
        result += cur_summand;
    }
    return result;
}

element_type sum_iterators( const container_type& summands ) {
    element_type result = ELEMENT_TYPE_ZERO;
    for( auto it = summands.begin(); it != summands.end(); ++it ) {
        result += *it;
    }
    return result;
}

element_type sum_algorithm( const container_type& summands ) {
    return std::accumulate( summands.begin(), summands.end(), ELEMENT_TYPE_ZERO );
}


element_type sum_function_obj( const container_type& summands ) {
    struct Sumator {
        Sumator( const element_type& init_value )
            : sum_ ( init_value ) {}

        void operator()( const element_type& cur_summand ) {
            sum_ += cur_summand;
        }

        element_type sum() const {
            return sum_;
        }
    private:
        element_type sum_;
    };

    Sumator sumator( ELEMENT_TYPE_ZERO );
    sumator = std::for_each( summands.begin(), summands.end(), sumator );
    return sumator.sum();
}

element_type sum_lambda( const container_type& summands ) {
    element_type result = ELEMENT_TYPE_ZERO;
    std::for_each( summands.begin(), summands.end(), [&result]( element_type cur_summand ) { result += cur_summand; } );
    return result;
}

auto sum_cpp11_func_style( const container_type& summands ) -> element_type {
    return std::accumulate( summands.begin(), summands.end(), ELEMENT_TYPE_ZERO );
}
