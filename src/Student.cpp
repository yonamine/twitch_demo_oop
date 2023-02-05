#include "Student.hpp"

std::ostream &operator<<(std::ostream &os, const Student &other) {
    os << "Student:\n";
    os << "\tName : " << other.GetName() << std::endl;
    os << "\tGrade: " << other.GetGrade() << std::endl;
    return os;
}

Student::Student(const std::string &name) : Person{name}
                                          , grade_{0} {
    // EMPTY
}

void Student::SetGrade(int grade) {
    grade_ = grade;
}

const int Student::GetGrade() const {
    return grade_;
}
