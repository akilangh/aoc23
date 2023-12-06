#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cout, std::cin, std::endl;

int process(std::string line);
int process2(std::string line);
int get_left_number(std::string line);
int get_right_number(std::string line);
int check_for_number(std::string line, int index);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    std::string line;

    long sum = 0;

    if (file.is_open()) {
        while (file >> line) {
            sum += process2(line);
        }
        file.close();
    } else {
        cout << "Unable to open file." << endl;
        return 1;
    }

    cout << "sum = " << sum << endl;

    return 0;
}

int process(std::string line) {
    int num = 0;
    for (auto c : line) {
        if (std::isdigit(c)) {
            num = num * 10 + (c - '0');
            break;
        }
    }

    for (auto riter = line.rbegin(); riter != line.rend(); ++riter) {
        if (std::isdigit(*riter)) {
            num = num * 10 + (*riter - '0');
            break;
        }
    }

    return num;
}

int process2(std::string line) {
    int left_num = get_left_number(line);
    int right_num = get_right_number(line);

    cout << left_num << right_num << endl;

    return left_num * 10  + right_num;
}

int get_left_number(std::string line) {
    int num = 0;

    for (size_t i = 0; i < line.length(); i++) {
        if (std::isdigit(line[i])) {
            return line[i] - '0';
        } else {
            num = check_for_number(line, i);
            if (num != 0) {
                return num;
            }
        }
    }

    return num;
}

int get_right_number(std::string line) {
    int num = 0;

    for (size_t i = line.length() - 1; i >= 0; i--) {
        if (std::isdigit(line[i])) {
            return line[i] - '0';
        } else {
            num = check_for_number(line, i);
            if (num != 0) {
                return num;
            }
        }
    }

    return num;
}

int check_for_number(std::string line, int index) {
    std::vector<std::string> numbers = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for (size_t i = 0; i < numbers.size(); i++) {
        if (line.substr(index, numbers[i].length()) == numbers[i]) {
            return i + 1;
        }
    }

    return 0;
}