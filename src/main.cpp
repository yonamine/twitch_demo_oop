#include <iostream>
#include <memory>
#include <string>

#include "Menu.hpp"
#include "ClassRoom.hpp"
#include "Person.hpp"
#include "Teacher.hpp"
#include "Student.hpp"


int main(int argc, char **argv) {
    auto room = std::make_shared<ClassRoom>();
    Menu menu{room};
    menu.Show();

    /*
     * Below, The next lines are a simple test for Polymorphic.
     * Note that Polymorphic is not used in previous sample.
     */
    // std::unique_ptr<Person> person;
    /*
     * In the next line, 'Person' is a base class that can hold
     * a pointer to 'Teacher'. The reason is 'Teacher' class inherits
     * the 'Person' class and it works with the 'Student' class as well.
     */
    // person = std::make_unique<Teacher>("Joana");
    // if (person == nullptr) {
    //     std::cout << "Smart Pointer not initialized" << std::endl;
    // } else {
    //     std::cout << person->GetName() << std::endl;
    // }

    return EXIT_SUCCESS;
}