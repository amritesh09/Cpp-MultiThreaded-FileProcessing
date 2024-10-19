
#include "TaskQueue.h"

void TaskQueue::push(const string& task) {
    lock_guard<mutex> lock(m_mutex);
    m_tasks.push(task);
    m_cond.notify_one();
}

bool TaskQueue::pop(string& task) {
    unique_lock<mutex> lock(m_mutex);
    m_cond.wait(lock, [this] { return !m_tasks.empty() || done; });

    if (m_tasks.empty()) return false;

    task = m_tasks.front();
    m_tasks.pop();
    return true;
}

void TaskQueue::set_done() {
    lock_guard<mutex> lock(m_mutex);
    done = true;
    m_cond.notify_all();
}
