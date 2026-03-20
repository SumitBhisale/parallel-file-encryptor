#ifndef PROCESS_MANAGEMENT_HPP
#define PROCESS_MANAGEMENT_HPP

#include "Task.hpp"
#include <queue>
#include <memory>


// This class acts like a task scheduler: You give it tasks (one by one) It stores them safely (no memory leaks) Later, it executes them in order
class ProcessManagement{
    public:
        ProcessManagement();
        bool SubmitToQueue(std::unique_ptr<Task> task);  // 1. Accepts a Task wrapped in unique_ptr 2. Takes ownership of that task 3. Adds it to the queue
        void executeTasks();
    private:
        std::queue<std::unique_ptr<Task>> taskQueue; // 1. A FIFO queue of tasks 2. Each task is: stored as unique_ptr, owned by the queue 3. No copying allowed → only movement
}; 

#endif