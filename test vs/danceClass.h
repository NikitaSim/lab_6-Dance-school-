#pragma once

#include "student.h"
#include "Instructor.h"
#include <string>
#include <vector>

class DanceClass {
private:
	std::string time;
	std::string location;
	std::string style;
	Instructor* instructor;
	std::vector<Student*> participants;
	int max_participants;
public:
	DanceClass(const std::string&, const std::string&, const std::string&, Instructor*, int);
	bool enroll(Student*);
	bool is_suitable_for(const Student*) const; // проверка подходит ли класс по стилю для ученика
	void get_info() const; //сделать войд чтобы сразу выводило
	~DanceClass();
};