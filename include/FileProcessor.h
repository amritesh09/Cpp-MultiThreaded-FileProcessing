
#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include "TaskQueue.h"
#include "Logger.h"
#include <string>
#include <unordered_map>

using namespace std;

class FileProcessor {
public:
    FileProcessor(TaskQueue& queue, Logger& logger);
    void operator()();

private:
    TaskQueue& m_queue;
    Logger& m_logger;

    void process_file(const string& filepath);
    void log_results(const string& filepath, const unordered_map<string, int>& word_count);
};

#endif // FILEPROCESSOR_H
