#pragma once

#include "person.h"
#include <vector>
#include <string>

class Instructor : public Person {
private:
	std::vector<std::string> teaching_style;
public:
	using Person::Person;
	void add_teaching_style(const std::string&);
	bool can_teach(const std::string&);
	void print_info() const override;
	std::string get_name() const;
};
