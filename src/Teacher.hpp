#pragma once

#include <string>

#include "Person.hpp"

class Teacher : public Person {
    public:
        Teacher() = default;

        explicit Teacher(const std::string &name);

};

std::ostream &operator<<(std::ostream &os, const Teacher &other);

