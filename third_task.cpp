/*
cmake_minimum_required(VERSION 3.1) # 3.1, ибо только в 3.1 была добавлена поддежка CXX_STANDARD
project(Directories)
add_executable(Directories main.cpp)
set_property(TARGET Directories PROPERTY CXX_STANDARD 17)
install(TARGETS Directories RUNTIME DESTINATION bin)
target_link_libraries(Directories stdc++fs)
 */

// Пример CMakeList
// Directories - название проекта

#include <iostream>
#include <experimental/filesystem> // Работа выполнена в CLion.
#include <string>

#define mac std::experimental::filesystem // Использовался для отладки и настройки

int main()
{
    std::string directory_absolute_path = "C:\\projects\\MIPT\\Directories";
    std::cout << "Please, enter the directory absolute path: ";
    std::cin >> directory_absolute_path;

    for(auto& p: mac::recursive_directory_iterator(directory_absolute_path))
        std::cout << p.path() << '\n';
}

