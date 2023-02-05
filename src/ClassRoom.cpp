#include <algorithm>
#include <sstream>

#include "ClassRoom.hpp"

void ClassRoom::SetTeacherName(const std::string &teacher_name) {
    teacher_.SetName(teacher_name);
}

void ClassRoom::AddStudent(Student student) {
    students_.emplace_back(student);
}

bool ClassRoom::RemoveStudent(const std::string &student_name) {
    auto it = FindStudent(student_name);

    if (it == students_.end()) {
        return false;
    }

    students_.erase(it);
    return true;
}


bool ClassRoom::Search(const std::string &student_name) {
    return (FindStudent(student_name) != students_.end());
}

void ClassRoom::SaveToFile(const std::string &filename) {
    constexpr char kTokenDelimiter{'|'};
    std::ofstream out;
    out.open(filename);

    out << "Teacher";
    out << kTokenDelimiter;
    out << teacher_.GetName();
    out << std::endl;
    for(const auto student : students_) {
        out << "Student";
        out << kTokenDelimiter;
        out << student.GetName();
        out << std::endl;
    }
    out.close();
}

void ClassRoom::LoadFromFile(const std::string &filename) {
    std::ifstream in;
    in.open(filename);

    std::string line;
    while(std::getline(in, line)) {
        constexpr char kTokenDelimiter{'|'};
        std::stringstream ss{line};
        std::string word;

        if(std::getline(ss, word, kTokenDelimiter)) {
            if (word == "Teacher") {
                std::getline(ss, word, kTokenDelimiter);
                SetTeacherName(word);
            } else if (word == "Student") {
                std::getline(ss, word, kTokenDelimiter);
                AddStudent(Student{ word });
            }
        }

    }

}

std::vector<Student>::const_iterator ClassRoom::FindStudent(const std::string &student_name) {
    auto it = std::find_if(std::begin(students_)
                         , std::end(students_)
                         , [student_name](const auto &student) {
        return (student.GetName() == student_name);
    });
    return it;
}


void ClassRoom::Print() {
    std::cout << "Class Room" << std::endl;
    std::cout << "==========" << std::endl;
    std::cout << teacher_ << std::endl;
    for(const auto student : students_) {
        std::cout << student << std::endl;
    }
    std::cout << std::endl;
}
