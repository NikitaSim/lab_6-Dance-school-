#include <iostream>
#include "person.h"
#include "student.h"
#include "Instructor.h"
#include "danceClass.h"
#include "DanceSchool.h"

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
    members.push_back(member);
}

void DanceSchool::add_instructor(Instructor* instructor) {
    instructors.push_back(instructor);
}

void DanceSchool::schedule_class(DanceClass* danceClass) {
    classes.push_back(danceClass);
}



void DanceSchool::get_schedule() const {
    std::cout << "\n===== School Schedule =====\n";
    for (const auto* cls : classes) {
        cls->get_info();
    }
    std::cout << "==========================\n";
}