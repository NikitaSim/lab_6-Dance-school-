#include <iostream>
#include "person.h"
#include "student.h"
#include "Instructor.h"
#include "danceClass.h"

DanceClass::DanceClass(const std::string& time, const std::string& location, const std::string& style, Instructor* instructor, int max_num): time(time), location(location), style(style), instructor(instructor), max_participants(max_num) {}

bool DanceClass::is_suitable_for(const Student* member) const {
	return (member->get_style() == style);
}
bool DanceClass::enroll(Student* member) {
	if (participants.size() >= max_participants) {
		std::cout << "There are no empty seats in the dance class" << std::endl;
		return false;
	}
	if (is_suitable_for(member)) {
		std::cout << "Member's style doesn't match class style\n";
		return false;
	}

	participants.push_back(member);
	return true;
}

void DanceClass::get_info() const {
	std::cout << style << " class at " << time << " in " << location << "Instructor: " << instructor->get_name() << std::endl;
}

DanceClass::~DanceClass() {
	
	std::cout << "Dance class " << style << " at " << time << " destroyed\n";
}