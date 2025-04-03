#include "pch.h"
#include "CppUnitTest.h"
#include"../test vs/danceClass.h"
#include"../test vs/Instructor.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDanceSchool
{
    TEST_CLASS(UnitTestDanceSchool)
    {
    public:

        /*TEST_METHOD(TestClassCreation)
        {
            Instructor* instr = new Instructor("John", 40);
            DanceClass dc("18:00", "Studio 1", "Salsa", instr, 10);
            Assert::AreEqual(std::string("Salsa"), dc.get_style());
        }*/

        TEST_METHOD(TestSuccessfulEnrollment)
        {
            Instructor* instr = new Instructor("Elena", 35);
            Student* student = new Student("Kate", 22, "Salsa");
            DanceClass dc("19:00", "Studio 2", "Salsa", instr, 5);

            Assert::IsTrue(dc.enroll(student));
        }

        TEST_METHOD(TestClassOverflow)
        {
            Instructor* instr = new Instructor("Carlos", 40);
            DanceClass dc("20:00", "Main Hall", "Tango", instr, 1);
            Student* s1 = new Student("Mike", 25, "Tango");
            Student* s2 = new Student("Lena", 28, "Tango");

            dc.enroll(s1);
            Assert::IsFalse(dc.enroll(s2));
        }

        TEST_METHOD(TestStyleMismatch)
        {
            Instructor* instr = new Instructor("Paul", 50);
            Student* student = new Student("Lisa", 20, "Contemporary");
            DanceClass dc("21:00", "Studio 3", "Ballet", instr, 15);

            Assert::IsFalse(dc.enroll(student));
        }
    };
}
