#ifndef SUM_VARIANTS_H_INCLUDED
#define SUM_VARIANTS_H_INCLUDED

#include <vector>

using element_type = float;
constexpr element_type ELEMENT_TYPE_ZERO = 0.0f;

using container_type = std::vector<element_type>;
using container_type_iterator = container_type::const_iterator;

element_type sum_oldstyle( const container_type& summands );

element_type sum_cpp11( const container_type& summands );

element_type sum_iterators( const container_type& summands );

element_type sum_algorithm( const container_type& summands );

element_type sum_function_obj( const container_type& summands );

element_type sum_lambda( const container_type& summands );

auto sum_cpp11_func_style( const container_type& summands ) -> element_type;


template <typename ELEMENT_T,
          template <typename ELMENT_T,
                    typename = std::allocator< ELEMENT_T> >
          class CONTAINER_T>
ELEMENT_T sum_template( const CONTAINER_T <ELEMENT_T>& summands ) {
    ELEMENT_T result = 0;
    auto it = summands.begin();
    while( it != summands.end() ) {
        result += *it;
        ++it;
    }
    return result;
}


#endif // SUM_VARIANTS_H_INCLUDED
