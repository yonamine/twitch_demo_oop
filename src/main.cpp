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
    return EXIT_SUCCESS;
}