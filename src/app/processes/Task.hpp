#ifndef TASK_HPP
#define TASK_HPP

#include "../filehandling/IO.hpp"
#include <sstream>

enum class Action
{
    ENCRYPT,
    DECRYPT
};

struct Task
{
    std::fstream f_stream;
    Action action;
    std::string file_path;

    Task(std::fstream &&stream, Action act, std::string filepath):f_stream(std::move(stream)), action(act), file_path(filepath){}

    // Serialization
    std::string toString()
    {
        std::ostringstream oss;
        oss<<file_path<<","<<(action==Action::ENCRYPT? "ENCRYPT" : "DECRYPT");
        return oss.str(); // eg. "test.txt,ENCRYPT"
    }

    // De-serialization
    static Task fromString(const std::string &taskData)
    {
        std::istringstream iss(taskData);
        std::string file_path;
        std::string actionStr;

        if(std::getline(iss, file_path, ',') && std::getline(iss, actionStr))
        {
            Action action = (actionStr == "ENCRYPT" ? Action::ENCRYPT : Action::DECRYPT);
            IO io(file_path);
            std::fstream f_stream = io.getFileStream();
            if(f_stream.is_open())
            {
                return Task(std::move(f_stream), action, file_path);
            }
            else
            {
                throw std::runtime_error("Failed to open file: "+ file_path);
            }
        }
        else
        {
            throw std::runtime_error("Invalid task data format");
        }
    }


};



#endif