# include "custom.hpp"

void GetInput::ExitEOF() {
    if (std::cin.eof()) {
        PhoneBook::ClosePhoneBook();
    }
}

bool GetInput::CinError(const std::string message) {
    if (!std::cin.good()){
        GetInput::ClearBuffer();
        Print::PrintMessage(message, DEFAULT);
        return true;
    }
    return false;
}

std::string GetInput::EraseFrontSpace(const std::string& str) {
    std::size_t i = 0;
    while (i < str.size() && str[i] == ' ') {
        i++;
    }
    return str.substr(i);
}

std::string GetInput::IgnoreEscapeSequences(const std::string& str) {
    std::string newStr;
    std::size_t i = 0;
    while (i < str.size()) {
        if (str[i] == '\033') {
            i++;
            if (i < str.size() && str[i] == '[') {
                i++;
                while (i < str.size() && (std::isdigit(str[i]) || str[i] == ';')) {
                    i++;
                }
            }
        }
        else if (std::isprint(str[i])) {
            newStr += str[i];
        }
        i++;
    }
    return newStr;
}


void GetInput::ClearBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool GetInput::GetCommand(std::string& command) {
    std::getline(std::cin, command);
    ExitEOF();
    if (CinError(INVALID_INPUT)) {
        return false;
    }
    command = GetInput::EraseFrontSpace(command);
    command = GetInput::IgnoreEscapeSequences(command);
    if (command.empty()) {
        Print::PrintMessage(EMPTY_INPUT, RED);
        return false;
    }
    return true;
}

bool GetInput::GetIndex(int& index) {
    std::string str;

    std::getline(std::cin, str);
    ExitEOF();
    if (GetInput::CinError(INVALID_INDEX)) {
        return false;
    }
    try {
        str = GetInput::IgnoreEscapeSequences(str);
        index = std::stoi(str);
    } catch (const std::invalid_argument& ia) {
        Print::PrintMessage(INVALID_INDEX, DEFAULT);
        return false;
    } catch (const std::out_of_range& oor) {
        Print::PrintMessage(INVALID_INDEX, DEFAULT);
        return false;
    }
    if (index < 0 || index > 7) {
        Print::PrintMessage(INVALID_INDEX, DEFAULT);
        return false;
    }
    return true;
}

std::string GetInput::GetValidCommand(std::string message, std::string color) {
    std::string command;

    while (true) {
        Print::PrintWithoutNewline(message, color);
        if (GetInput::GetCommand(command)) {
            break;
        }
    }
    return command;
}
