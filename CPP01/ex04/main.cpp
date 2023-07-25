#include "main.hpp"

int main(int argc, char** argv) {
    if (argc != 4) {
        Print::PrintError(INVALID_ARGUMENTS);
        return 1;
    }

    File file;

    file.OpenInfile(argv[1]);
    file.OpenOutfile(std::string(argv[1]) + APPENDIX);
    file.ConvertEveryWords(argv[2], argv[3]);
    return 0;
}
