#include <fstream>
#include <string>

namespace Decrogame {
    class Logger {
    private:
        std::ofstream logfile;

    public:
        Logger(const std::string filename);

        std::ofstream& GetLogFileStream();
    };
}
