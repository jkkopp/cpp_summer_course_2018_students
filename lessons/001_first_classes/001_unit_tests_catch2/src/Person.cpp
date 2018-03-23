#include "Person.h"


Person::Person( const std::string& first_name, const std::string& last_name )
    : first_name_ ( first_name )
    , last_name_ ( last_name ) {
}

const std::string& Person::get_first_name() const {
    return first_name_;
}

const std::string& Person::get_last_name() const {
    return last_name_;
}
