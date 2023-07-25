#include "File.hpp"

void File::OpenInfile(const std::string& filename) {
    m_infile.open(filename);
    if (!m_infile.is_open()) {
        Print::PrintError(ERROR_OPEN_FILE);
        exit(1);
    }
}

void File::OpenOutfile(const std::string& filename) {
    m_outfile.open(filename);
    if (!m_outfile.is_open()) {
        Print::PrintError(ERROR_CREATE_NEW_FILE);
        exit(1);
    }
}

std::string File::ConvertLine(const std::string& line, const std::string& find_str, const std::string& replace_str) {
    std::string new_line;
    std::size_t pos = 0;
    std::size_t start = 0;
    
    while ((pos = line.find(find_str, start)) != std::string::npos) {
        new_line += line.substr(start, pos - start) + replace_str;
        start = pos + find_str.length();
    }
    new_line += line.substr(start);
    return new_line;
}


void File::WriteLine(const std::string& message) {
    if (m_outfile.is_open()) {
        m_outfile << message;
    } else {
        Print::PrintError(ERROR_FILE_NOT_OPEN);
        exit(1);
    }
}

File::~File() {
    if (m_infile.is_open()) {
        m_infile.close();
    }
    if (m_outfile.is_open()) {
        m_outfile.close();
    }
}

std::ifstream& File::GetInputFileStream() {
    return m_infile;
}

void File::ConvertEveryWords(const std::string& find_str, const std::string& replace_str) {
    std::string line;
    bool is_first_line = true;

    while (std::getline(m_infile, line)) {
        if (!is_first_line) {
            WriteLine("\n");
        } else {
            is_first_line = false;
        }

        line = ConvertLine(line, find_str, replace_str);
        WriteLine(line);
    }
}
