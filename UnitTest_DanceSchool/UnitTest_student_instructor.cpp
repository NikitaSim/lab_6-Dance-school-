#include "pch.h"
#include "CppUnitTest.h"
#include "../test vs/Instructor.h"
#include "../test vs/student.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDanceSchool
{
    TEST_CLASS(UnitTestDanceSchool)
    {
    public:

        TEST_METHOD(TestStudentCreation)
        {
            Student s("Anna", 25, "Salsa");
            Assert::AreEqual(std::string("Anna"), s.get_name());
            Assert::AreEqual(25, s.get_age());
            Assert::AreEqual(std::string("Salsa"), s.get_style());
        }

        TEST_METHOD(TestChangeStyle)
        {
            Student s("Bob", 30, "Tango");
            s.change_style("Salsa");
            Assert::AreEqual(std::string("Salsa"), s.get_style());
        }

        TEST_METHOD(TestAddTeachingStyle)
        {
            Instructor i("Maria", 35);
            i.add_teaching_style("Hip-Hop");
            Assert::IsTrue(i.can_teach("Hip-Hop"));
        }
    };
}
