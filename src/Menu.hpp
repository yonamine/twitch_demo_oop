#pragma once

#include <memory>
#include <map>

#include "ClassRoom.hpp"

class Menu {
    public:
        Menu(std::shared_ptr<ClassRoom> room);

        void Show();

    private:
        int DrawMenu();
        void AddStudentMenuItem();
        void RemoveStudentMenuItem();
        void SearchStudentMenuItem();
        void LoadFromFileMenuItem();
        void SaveToFileMenuItem();
        void PrintStudentMenuItem();
        void QuitMenuItem();

        bool quit_{false};
        std::shared_ptr<ClassRoom> room_;
};