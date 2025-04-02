#include <iostream>
#include "person.h"
#include "student.h"
#include "Instructor.h"
#include "danceClass.h"
#include "DanceSchool.h"

DanceSchool::~DanceSchool() {
	// ����������� ��� ������
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

Instructor* DanceSchool::getInstructor(int id_instructor) {
	if (id_instructor < instructors.size()) {
		return instructors[id_instructor]; // -1 ���� ������� � 1
	}
	std::cout << "Instructor not found!!!" << std::endl;
	return nullptr;
}

void DanceSchool::printInstructors() const {
	for (Instructor* inst : instructors) {
		inst->print_info();
	}
}

void DanceSchool::printStudents() const {
	for (Student* stud : members) {
		stud->print_info();
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
	std::cout << "\n===== School Schedule =====\n";
	for (const auto* cls : classes) {
		cls->get_info();
	}
	std::cout << "==========================\n";
}