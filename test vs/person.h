#pragma once

#include <string>

class Person {
protected:
	std::string name;
	int age;
public:
	Person(const std::string&, int);
	virtual void print_info() const;
	~Person() = default;
};