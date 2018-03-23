#include "catch.hpp"

#include "Person.h"

TEST_CASE( "test person", "[Person]" ) {
    Person person( "Tom", "Hanks" );
    REQUIRE( person.get_first_name() == "Tom" );
    REQUIRE( person.get_last_name() == "Hanks" );
}
