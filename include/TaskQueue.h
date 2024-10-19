
#ifndef TASKQUEUE_H
#define TASKQUEUE_H

#include <string>
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

class TaskQueue {
public:
    void push(const string& task);
    bool pop(string& task);
    void set_done();

private:
    queue<string> m_tasks;
    mutex m_mutex;
    condition_variable m_cond;
    bool done = false;
};

#endif // TASKQUEUE_H
