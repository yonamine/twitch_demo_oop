#include "Person.hpp"

std::ostream &operator<<(std::ostream &os, const Person &other) {
    os << "Person:\n";
    os << "\tName: " << other.GetName() << std::endl;
    return os;
}

Person::Person(const std::string &name) : name_{name} {
    // Empty
}

void Person::SetName(const std::string &name) {
    name_ = name;
}

const std::string Person::GetName() const {
    return name_;
}

