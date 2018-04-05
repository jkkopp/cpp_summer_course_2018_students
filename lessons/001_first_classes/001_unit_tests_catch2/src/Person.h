#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
  public:
    Person( const std::string& first_name, const std::string& last_name );

    const std::string& get_first_name() const;
    const std::string& get_last_name() const;

  private:
    std::string first_name_;
        std::string last_name_;
};

#endif // PERSON_H
