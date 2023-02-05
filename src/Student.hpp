#pragma once

#include <string>

#include "Person.hpp"

/**
 * @brief Inheritance of Person Class
 * 
 */
class Student : public Person {
    public:
        Student() = default;
        explicit Student(const std::string &name);

        /**
         * 'SetGrade' and 'GetGrade' are only implemented
         * in 'Student' class. For 'Teacher' class, the value
         * for 'grade_' is useless.
         */
        void SetGrade(int grade);
        const int GetGrade() const;

    private:
        int grade_{0};
};

std::ostream &operator<<(std::ostream &os, const Student &other);
