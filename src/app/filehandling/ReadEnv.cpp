#include "IO.hpp"
#include <sstream>

class ReadEnv{
    public:
        std::string getEnv()
        {
            std::string env_path = ".env";
            IO io(env_path);
            std::fstream f_stream = io.getFileStream();
            std::stringstream buffer; // Used to store file content temporarily in memory.
            buffer << f_stream.rdbuf(); // copies entire file content into buffer.
            std::string content = buffer.str(); // Converts stringstream content into a normal string.
            
            return content; // content now contains full .env file data.
        }

};