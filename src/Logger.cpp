#include <SFML/System.hpp>

#include "Logger.hpp"

namespace Decrogame {
    Logger::Logger(const std::string filename) {
        this->logfile = std::ofstream(filename);

        sf::err().rdbuf(this->logfile.rdbuf());
    }
    
    std::ofstream& Logger::GetLogFileStream() {
        return this->logfile;
    }
}
