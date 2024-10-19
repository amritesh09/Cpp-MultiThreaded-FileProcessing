
#include "Logger.h"

Logger::Logger(const string& filename) {
    m_output.open(filename, ios::out | ios::app);
}

Logger::~Logger() {
    if (m_output.is_open()) {
        m_output.close();
    }
}

void Logger::log(const string& message) {
    lock_guard<mutex> lock(m_mutex);
    m_output << message << endl;
}
