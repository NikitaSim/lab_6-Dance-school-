#pragma once

#include "person.h"
#include <vector>
#include <string>

class Student : public Person {
private:
	std::string dance_style;
public:
	Student(const std::string&, int, const std::string&);
	void change_style(const std::string&);
	void print_info() const override;
	std::string get_style() const;



};