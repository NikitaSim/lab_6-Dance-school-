#include <iostream>
#include "person.h"
#include "Instructor.h"

void Instructor::add_teaching_style(const std::string& style) {
	teaching_style.push_back(style);
}

bool Instructor::can_teach(const std::string& style) {
	return std::find(teaching_style.begin(), teaching_style.end(), style) != teaching_style.end();
}

void Instructor::print_info() const {
	Person::print_info();
	std::cout << ", Teaches: ";
	for (std::string styles : teaching_style) {
		std::cout << styles << " " << std::endl;
	}
	
}

std::string Instructor::get_name() const {
	return name;
}