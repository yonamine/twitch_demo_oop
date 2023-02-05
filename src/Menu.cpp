#include <limits>
#include <iostream>
#include <string>

#include "Menu.hpp"

static const std::string kFilename{"Dados.txt"};

Menu::Menu(std::shared_ptr<ClassRoom> room) : room_{room} {
}

void Menu::AddStudentMenuItem() {
    std::string name;
    std::cout << "Adding new student, please type name: ";
    std::cin >> name;
    room_->AddStudent(Student{name});
}

void Menu::RemoveStudentMenuItem() {
    std::string name;
    std::cout << "Remove student, please type name: ";
    std::cin >> name;
    if (room_->RemoveStudent(name)) {
        std::cout << name << " removed from class room" << std::endl;
    } else {
        std::cout << name << " isnot in the classroom" << std::endl;
    }
}

void Menu::SearchStudentMenuItem() {
    std::string name;
    std::cout << "Search student, please type name: ";
    std::cin >> name;
    bool result = room_->Search(name);
    std::cout << "Student " << name << (result ? " " : " not ") << "found" << std::endl;
}

void Menu::PrintStudentMenuItem() {
    std::cout << std::endl;
    room_->Print();
}

void Menu::LoadFromFileMenuItem() {
    room_->LoadFromFile(kFilename);
}

void Menu::SaveToFileMenuItem() {
    room_->SaveToFile(kFilename);
}

void Menu::QuitMenuItem() {
    quit_ = true;
}

int Menu::DrawMenu() {
    bool valid_input{false};
    int option{0};

    do {
        std::cout << std::endl << std::endl << std::endl;
        std::cout << "Classroom Menu" << std::endl;
        std::cout << "==============" << std::endl;

        std::cout << "1. Add Student" << std::endl;
        std::cout << "2. Remove Student" << std::endl;
        std::cout << "3. Search Student" << std::endl;
        std::cout << "4. Load from File" << std::endl;
        std::cout << "5. Save to File" << std::endl;

        std::cout << "8. Print Classroom" << std::endl;
        std::cout << "9. Exit" << std::endl;

        std::cout << "Your option: ";
        std::cin >> option;

        valid_input = std::cin.good();
        if (!valid_input) {
            std::cout << "That input is invalid!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!valid_input);

    return option;
}

void Menu::Show() {
    while(!quit_) {
        int option{DrawMenu()};
        switch(option) {
            case 1:
                AddStudentMenuItem();
                break;
            case 2:
                RemoveStudentMenuItem();
                break;
            case 3:
                SearchStudentMenuItem();
                break;
            case 4:
                LoadFromFileMenuItem();
                break;
            case 5:
                SaveToFileMenuItem();
                break;
            case 8:
                PrintStudentMenuItem();
                break;
            case 9:
                quit_ = true;
                break;
            default:
                std::cout << "Invalid option! Please try again." << std::endl;
        }
    }

    std::cout << "Thank You for using this application"
              << std::endl << std::endl;
}
