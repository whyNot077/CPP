#ifndef FILE_HPP
#define FILE_HPP

#include "define.hpp"
#include <fstream>
#include "Print.hpp"

class File {
private:
    std::ifstream m_infile;
    std::ofstream m_outfile;
    std::string m_line;


    std::string ConvertLine(const std::string& line, const std::string& find_str, const std::string& replace_str);
    void WriteLine(const std::string& line);
    std::ifstream& GetInputFileStream();

public:
    // Read file and return ifstream
    void OpenInfile(const std::string& filename);

    // Create a new file and return ofstream
    void OpenOutfile(const std::string& filename);
    // Close file
    ~File();

    void ConvertEveryWords(const std::string& find_str, const std::string& replace_str);
};

#endif
