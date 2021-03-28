#include <iostream>
#include <fstream>
#include <random>

using namespace std;

string CreateDirectory() {
    string file = __FILE__;
    string output_file = {file.begin(), prev(file.end(), 8)};
    return output_file;
}

int main() {
    const size_t line_size = 30;
    const size_t number_of_lines = 25;

    string file_name = "file.txt";
    file_name = CreateDirectory() + file_name;
    ofstream output(file_name);

    for(int i = 0; i < number_of_lines; i++) {
        for(int j = 0; j < number_of_lines; j++) {
            char symbol = rand() % 26 + 65;
            output << symbol;
        }
        output << '\n';
    }
    output.close();

    size_t line_number;
    cin >> line_number;

     ifstream input(file_name);

     input.seekg(line_number * (line_size) - 3 * line_number); // Unknown magic. No hypotheses.
     string line;
     getline(input, line);
     cout << line;
}
