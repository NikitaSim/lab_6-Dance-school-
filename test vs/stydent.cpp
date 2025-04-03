#include <iostream>
#include "person.h"
#include "student.h"

Student::Student(const std::string& name, int age, const std::string& style): Person(name,age), dance_style(style){}

void Student::change_style(const std::string& style) {
	this->dance_style = style;
}

std::string Student::get_style() const {
	return dance_style;
}

void Student::print_info() const {
	Person::print_info();
	std::cout << "Style: " << dance_style<< std::endl;
}