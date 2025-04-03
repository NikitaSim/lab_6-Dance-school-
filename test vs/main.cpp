#include <iostream>
#include "person.h"
#include "student.h"
#include "Instructor.h"
#include "danceClass.h"
#include "DanceSchool.h"

using namespace std;

int inputNumber(const string& prompt) {
	int value;
	while (true) {
		cout << prompt;
		if (cin >> value) {
			cin.ignore(); // Очищаем буфер
			return value;
		}
		cout << "Ошибка! Введите число.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

void showMainMenu() {
	cout << "\n=== Школа танцев ===\n";
	cout << "1. Добавить ученика\n";
	cout << "2. Добавить инструктора\n";
	cout << "3. Создать занятие\n";
	cout << "4. Записать ученика на занятие\n";
	cout << "5. Показать расписание\n";
	cout << "0. Выход\n";
	cout << "Выберите действие: ";
}

int main() {
	try {
		setlocale(LC_ALL, "Russian");
		DanceSchool school;
		int choice;

		do {
			showMainMenu();
			choice = inputNumber("");

			switch (choice) {
			case 1: { // Добавить ученика
				string name, style;
				int age;
				
				cout << "\n-- Добавление ученика --\n";
				cout << "Имя: ";
				getline(cin, name);
				age = inputNumber("Возраст: ");
				cout << "Стиль танца: ";
				getline(cin, style);

				school.add_member(new Student(name, age, style));
				cout << "Ученик добавлен!\n";
				break;
			}

			case 2: { // Добавить инструктора
				string name, style;
				int age, styleCount;

				cout << "\n-- Добавление инструктора --\n";
				cout << "Имя: ";
				getline(cin, name);
				age = inputNumber("Возраст: ");
				Instructor* instr = new Instructor(name, age);

				styleCount = inputNumber("Сколько стилей преподает?: ");
				for (int i = 0; i < styleCount; i++) {
					cout << "Стиль #" << i + 1 << ": ";
					getline(cin, style);
					instr->add_teaching_style(style);
				}

				school.add_instructor(instr);
				cout << "Инструктор добавлен!\n";
				break;
			}

			case 3: { // Создать занятие

				if (school.instructorCount() == 0) {
					cout << "Сначала добавьте инструкторов!\n";
					break;
				}

				string time, location, style;
				int instructorIdx, maxStudents;

				cout << "\n-- Создание занятия --\n";
				cout << "Время: ";
				getline(cin, time);
				cout << "Место: ";
				getline(cin, location);
				cout << "Стиль танца: ";
				getline(cin, style);

				maxStudents = inputNumber("Макс. участников: ");
				cout << "\nДоступные инструкторы:\n";
				school.printInstructors();
				instructorIdx = inputNumber("Выберите инструктора (номер): ");
				instructorIdx--;
				
				if (!school.getInstructor(instructorIdx) || !school.getInstructor(instructorIdx)->can_teach(style)) {
					cout << "Ошибка: неверный инструктор или стиль\n";
					break;
				}

				else
				{
					DanceClass* cls = new DanceClass(
						time, location, style,
						school.getInstructor(instructorIdx),
						maxStudents
					);

					school.schedule_class(cls);
					cout << "Занятие создано!\n";

				}
				
				break;
			}

			case 4: { // Записать ученика
				if (school.studentCount() == 0 || school.classCount() == 0) {
					cout << "Нужны ученики и занятия!\n";
					break;
				}

				int memberIdx, classIdx;

				cout << "\n-- Запись на занятие --\n";
				cout << "Доступные ученики:\n";
				school.printStudents();
				memberIdx = inputNumber("Выберите ученика (номер): ");
				memberIdx--;

				cout << "\nДоступные занятия:\n";
				school.get_schedule();
				classIdx = inputNumber("Выберите занятие (номер): ");
				classIdx--;

				if (school.enrollStudent(memberIdx, classIdx)) { 
					cout << "Запись успешна!\n";
				}
				else {
					cout << "Ошибка записи (нет мест или несоответствие стиля)!\n";
				}
				break;
			}

			case 5: // Показать расписание
				cout << "\n-- Текущее расписание --\n";
				school.get_schedule();
				break;

			case 0: // Выход
				cout << "Выход...\n";
				break;

			default:
				cout << "Неверный выбор!\n";
			}
		} while (choice != 0);

	}

	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
