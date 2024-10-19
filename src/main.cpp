
#include "TaskQueue.h"
#include "FileProcessor.h"
#include "Logger.h"
#include <thread>
#include <vector>
#include <filesystem>
#include <iostream>

using namespace std;
namespace fs = filesystem;

int main() {
    const int NUM_THREADS = 4;
    TaskQueue queue;
    Logger logger("results.log");

    // Spawn worker threads.
    vector<thread> workers;
    for (int i = 0; i < NUM_THREADS; ++i) {
        workers.emplace_back(FileProcessor(queue, logger));
    }

    // Enqueue files to be processed.
    string directory = "./textfiles"; // directory where files are stored
    for (const auto& entry : fs::directory_iterator(directory)) {
        if (entry.is_regular_file()) {
            queue.push(entry.path().string());
        }
    }

    // Indicate to threads that all tasks are done.
    queue.set_done();

    // Join all threads.
    for (auto& worker : workers) {
        if (worker.joinable()) {
            worker.join();
        }
    }

    cout << "All files processed." << endl;
    return 0;
}
