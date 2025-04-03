#pragma once

#include "Student.h"
#include "Instructor.h"
#include "DanceClass.h"
#include <vector>

class DanceSchool {
private:
	std::vector<Student*> members;
	std::vector<Instructor*> instructors;
	std::vector<DanceClass*> classes;
public:
	void add_member(Student*);
	void add_instructor(Instructor*);
	void schedule_class(DanceClass*);

	size_t instructorCount() const;
	size_t studentCount() const;
	size_t classCount() const;

	Instructor* getInstructor(int) const;
	void printInstructors() const;
	void printStudents() const;
	
	bool enrollStudent(int, int) const;

	//std::vector<DanceClass> find_classes(const std::string&) const; // найти занятия по стилю
	void get_schedule() const; //сделать войд чтобы сразу выводило
	~DanceSchool();
};