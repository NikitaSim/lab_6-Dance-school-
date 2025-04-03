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
			cin.ignore(); // ������� �����
			return value;
		}
		cout << "������! ������� �����.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

void showMainMenu() {
	cout << "\n=== ����� ������ ===\n";
	cout << "1. �������� �������\n";
	cout << "2. �������� �����������\n";
	cout << "3. ������� �������\n";
	cout << "4. �������� ������� �� �������\n";
	cout << "5. �������� ����������\n";
	cout << "0. �����\n";
	cout << "�������� ��������: ";
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
			case 1: { // �������� �������
				string name, style;
				int age;
				
				cout << "\n-- ���������� ������� --\n";
				cout << "���: ";
				getline(cin, name);
				age = inputNumber("�������: ");
				cout << "����� �����: ";
				getline(cin, style);

				school.add_member(new Student(name, age, style));
				cout << "������ ��������!\n";
				break;
			}

			case 2: { // �������� �����������
				string name, style;
				int age, styleCount;

				cout << "\n-- ���������� ����������� --\n";
				cout << "���: ";
				getline(cin, name);
				age = inputNumber("�������: ");
				Instructor* instr = new Instructor(name, age);

				styleCount = inputNumber("������� ������ ���������?: ");
				for (int i = 0; i < styleCount; i++) {
					cout << "����� #" << i + 1 << ": ";
					getline(cin, style);
					instr->add_teaching_style(style);
				}

				school.add_instructor(instr);
				cout << "���������� ��������!\n";
				break;
			}

			case 3: { // ������� �������

				if (school.instructorCount() == 0) {
					cout << "������� �������� ������������!\n";
					break;
				}

				string time, location, style;
				int instructorIdx, maxStudents;

				cout << "\n-- �������� ������� --\n";
				cout << "�����: ";
				getline(cin, time);
				cout << "�����: ";
				getline(cin, location);
				cout << "����� �����: ";
				getline(cin, style);

				maxStudents = inputNumber("����. ����������: ");
				cout << "\n��������� �����������:\n";
				school.printInstructors();
				instructorIdx = inputNumber("�������� ����������� (�����): ");
				instructorIdx--;
				
				if (!school.getInstructor(instructorIdx) || !school.getInstructor(instructorIdx)->can_teach(style)) {
					cout << "������: �������� ���������� ��� �����\n";
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
					cout << "������� �������!\n";

				}
				
				break;
			}

			case 4: { // �������� �������
				if (school.studentCount() == 0 || school.classCount() == 0) {
					cout << "����� ������� � �������!\n";
					break;
				}

				int memberIdx, classIdx;

				cout << "\n-- ������ �� ������� --\n";
				cout << "��������� �������:\n";
				school.printStudents();
				memberIdx = inputNumber("�������� ������� (�����): ");
				memberIdx--;

				cout << "\n��������� �������:\n";
				school.get_schedule();
				classIdx = inputNumber("�������� ������� (�����): ");
				classIdx--;

				if (school.enrollStudent(memberIdx, classIdx)) { 
					cout << "������ �������!\n";
				}
				else {
					cout << "������ ������ (��� ���� ��� �������������� �����)!\n";
				}
				break;
			}

			case 5: // �������� ����������
				cout << "\n-- ������� ���������� --\n";
				school.get_schedule();
				break;

			case 0: // �����
				cout << "�����...\n";
				break;

			default:
				cout << "�������� �����!\n";
			}
		} while (choice != 0);

	}

	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
