#ifndef IO_HPP
#define IO_HPP

/*
The type std::string is declared and defined in
the <string> header, and it is accessed using the
std namespace as std::string.
*/

#include <string>
#include <fstream>

class IO{
    public:
        IO(const std::string &file_path);
        ~IO();
        std::fstream getFileStream();

    private:
        std::fstream file_stream;
};


#endif