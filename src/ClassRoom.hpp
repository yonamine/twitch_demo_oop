#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "Student.hpp"
#include "Teacher.hpp"

class ClassRoom {
    public:
        void SetTeacherName(const std::string &teacher_name);

        void AddStudent(Student student);

        bool RemoveStudent(const std::string &student_name);

        bool Search(const std::string &student_name);

        void SaveToFile(const std::string &filename);

        void LoadFromFile(const std::string &filename);

        void Print();

    private:
        std::vector<Student>::const_iterator FindStudent(const std::string &student_name);

    private:
        Teacher teacher_;
        std::vector<Student> students_;

};
