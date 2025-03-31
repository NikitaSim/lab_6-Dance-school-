#include <iostream>
#include "person.h"

Person::Person(const std::string& name, int age) : name(name), age(age) {}

void Person::print_info() const {
	std::cout << name << "," << age << "years old" << std::endl;
}