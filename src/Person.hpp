#pragma once

#include <iostream>
#include <string>

/**
 * @brief Base Class
 * 
 */
class Person {
    public:
        Person() = default;

        explicit Person(const std::string &name);

        /**
         * The methods 'SetName' and 'GetName' are common for
         * 'Student' class and 'Teacher' class. As 'SetName' 
         * and 'GetName' are under 'public:', 'Student' and 'Teacher'
         * class have access to those methods.
         */
        void SetName(const std::string &name);
        const std::string GetName() const;

    private:
        std::string name_;

};

std::ostream &operator<<(std::ostream &os, const Person &other);
