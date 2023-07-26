#ifndef GETINPUT_HPP
#define GETINPUT_HPP

#include "define.hpp"
#include <iostream>
#include <string>

class GetInput {
private:
    static void ExitEOF();
    static void ClearBuffer();
    static bool CinError(const std::string message);
    static std::string EraseFrontSpace(const std::string& str);
    static std::string IgnoreEscapeSequences(const std::string& str);

public:    
    // get commands from user, if space is in front of command, it will be ignored
    static bool GetCommand(std::string& command);

    // get index from user, if ctrl+D is pressed, flush buffer and get index again
    static bool GetIndex(int& index);

    // get commands from user and if it is not valid, ask again
    static std::string GetValidCommand(std::string message, std::string color);
};

#endif
