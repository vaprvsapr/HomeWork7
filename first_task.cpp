#include <iostream>
#include <fstream>

using namespace std;

int main() {
    cout << "Enter the absolute path to the input file: ";
    string content;
    string input_file_name = "C:\\projects\\MIPT\\CommentDeleter\\input_file.txt";
    cin >> input_file_name;
    ifstream input(input_file_name);

    string line;
    if(input.is_open()) {
        while(getline(input, line)) {
            content += line + "\n";
        }
    }
    input.close();

    cout << endl << "Enter the absolute path to the output file: ";
    string output_file_name = "C:\\projects\\MIPT\\CommentDeleter\\output_file.txt";
    cin >> output_file_name;
    ofstream output(output_file_name);


    bool is_multi_comment = false;
    bool is_single_comment = false;
    bool is_string = false;
    string new_liner;

    for(int i = 0; i < content.size() - 1; i++) {
        char symbol = content[i];
        char next_symbol = content[i + 1];

        if(!is_multi_comment and !is_single_comment) {
            if(symbol == '"') {
                is_string = !is_string;
            }
        }

        if(!is_string) {
            if(symbol == '/') {
                if(next_symbol == '/') {
                    is_single_comment = true;

                }

                if(next_symbol == '*') {
                    is_multi_comment = true;

                }
            }

            if(is_single_comment) {
                if(symbol == '\n') {
                    is_single_comment = false;

                }
            }
            if(is_multi_comment) {
                if(symbol == '*' and next_symbol == '/') {
                    is_multi_comment = false;
                    i++;
                    continue;
                }
            }

        }
        if(!is_multi_comment and !is_single_comment) {

            // Уберём лишние пустые строки.
            if(symbol == '\n')
                new_liner += '\n';
            else
                new_liner = "";
            if(new_liner == "\n\n") {
                new_liner = "";
                continue;
            }

            output << symbol;
        }

    }
}
