
#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <mutex>
#include <string>

using namespace std;

class Logger {
public:
    Logger(const string& filename);
    ~Logger();

    void log(const string& message);

private:
    ofstream m_output;
    mutex m_mutex;
};

#endif // LOGGER_H
