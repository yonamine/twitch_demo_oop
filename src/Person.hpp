#pragma once

#include <iostream>
#include <string>

class Person {
    public:
        Person() = default;

        explicit Person(const std::string &name);

        void SetName(const std::string &name);
        const std::string GetName() const;

    private:
        std::string name_;

};

std::ostream &operator<<(std::ostream &os, const Person &other);
