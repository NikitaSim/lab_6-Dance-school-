#include <iostream>
#include "person.h"
#include "student.h"
#include "Instructor.h"
#include "danceClass.h"
#include "DanceSchool.h"

// печатать кто на занятии

DanceSchool::~DanceSchool() {
	// Освобождаем всю память
	for (DanceClass* cls : classes) {
		delete cls;
	}
	for (Instructor* instr : instructors) {
		delete instr;
	}
	for (Student* member : members) {
		delete member;
	}
	std::cout << "Dance school closed\n";
}

void DanceSchool::add_member(Student* member) {
	if (!member) throw std::invalid_argument("Member cannot be null");
	members.push_back(member);
}

void DanceSchool::add_instructor(Instructor* instructor) {
	instructors.push_back(instructor);
}

void DanceSchool::schedule_class(DanceClass* danceClass) {
	classes.push_back(danceClass);
}

size_t DanceSchool::instructorCount() const {
	return instructors.size();
}

size_t DanceSchool::studentCount() const {
	return members.size();
}

size_t DanceSchool::classCount() const {
	return classes.size();
}

Instructor* DanceSchool::getInstructor(int id_instructor) const {
	if (id_instructor >= 0 && id_instructor < instructors.size()) {
		return instructors[id_instructor]; // -1 если считать с 1
	}
	std::cout << "Instructor not found!!!" << std::endl;
	throw std::out_of_range("Invalid instructor index");
}

void DanceSchool::printInstructors() const {
	int i{ 1 };
	for (Instructor* inst : instructors) {
		std::cout << i << ": ";
		inst->print_info();
		i++;
	}
}

void DanceSchool::printStudents() const {
	int i{ 1 };
	for (Student* stud : members) {
		std::cout << i<<": ";
		stud->print_info();
		i++;
	}
}

bool DanceSchool::enrollStudent(int stud_id, int class_id) const {

	if (stud_id < 0 || stud_id >= members.size() ||
		class_id < 0 || class_id >= classes.size()) {
		return false;
	}
	return classes[class_id]->enroll(members[stud_id]);
}

void DanceSchool::get_schedule() const {
	int i{ 1 };
	std::cout << "\n===== School Schedule =====\n";
	for (DanceClass* cls : classes) {
		std::cout << i << ": ";
		cls->get_info();
		i++;
	}
	std::cout << "==========================\n";
}