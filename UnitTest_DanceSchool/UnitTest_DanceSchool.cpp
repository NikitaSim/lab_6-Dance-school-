#include "pch.h"
#include "CppUnitTest.h"
#include"../test vs/DanceSchool.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDanceSchool
{
	TEST_CLASS(UnitTestDanceSchool)
	{
	public:
		
        TEST_METHOD(TestAddStudent)
        {
            DanceSchool school;
            school.add_member(new Student("Tom", 30, "Ballet"));
            Assert::AreEqual(size_t(1), school.studentCount());
        }

        TEST_METHOD(TestGetInstructor)
        {
            DanceSchool school;
            Instructor* instr = new Instructor("Olga", 45);
            instr->add_teaching_style("tango");
            school.add_instructor(instr);

            Assert::IsNotNull(school.getInstructor(0));
            Assert::IsNull(school.getInstructor(1));
            Assert::IsNull(school.getInstructor(-1));
        }

        TEST_METHOD(TestSchoolEnrollment)
        {
            DanceSchool school;
            school.add_member(new Student("Anna", 25, "Salsa"));
            school.add_instructor(new Instructor("Maria", 35));

            DanceClass* cls = new DanceClass("18:00", "Studio", "Salsa", school.getInstructor(0), 10);
            school.schedule_class(cls);

            Assert::IsTrue(school.enrollStudent(0, 0));
        }
	};
}
