#pragma once

#include <string>

#include "Person.hpp"

class Student : public Person {
    public:
        Student() = default;
        explicit Student(const std::string &name);

        void SetGrade(int grade);
        const int GetGrade() const;

    private:
        int grade_{0};
};

std::ostream &operator<<(std::ostream &os, const Student &other);
