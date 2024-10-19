
#include "FileProcessor.h"
#include <fstream>

FileProcessor::FileProcessor(TaskQueue& queue, Logger& logger) : m_queue(queue), m_logger(logger) {}

void FileProcessor::operator()() {
    string filepath;
    while (m_queue.pop(filepath)) {
        process_file(filepath);
    }
}

void FileProcessor::process_file(const string& filepath) {
    unordered_map<string, int> word_count;
    ifstream file(filepath);
    string word;

    if (!file.is_open()) {
        m_logger.log("Error opening file: " + filepath);
        return;
    }

    // Count words in the file.
    while (file >> word) {
        word_count[word]++;
    }

    file.close();
    log_results(filepath, word_count);
}

void FileProcessor::log_results(const string& filepath, const unordered_map<string, int>& word_count) {
    m_logger.log("Results for file: " + filepath);
    for (const auto& entry : word_count) {
        m_logger.log(entry.first + ": " + to_string(entry.second));
    }
    m_logger.log("----------------------------");
}
