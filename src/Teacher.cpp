#include "Teacher.hpp"

std::ostream &operator<<(std::ostream &os, const Teacher &other) {
    os << "Teacher:\n";
    os << "\tName: " << other.GetName() << std::endl;
    return os;
}

Teacher::Teacher(const std::string &name) : Person{name} {
    // EMPTY
}