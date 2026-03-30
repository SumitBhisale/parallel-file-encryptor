#include "ProcessManagement.hpp"
#include "../encryptDecrypt/Cryption.hpp"
#include <unistd.h>

ProcessManagement::ProcessManagement()
{

}

bool ProcessManagement::SubmitToQueue(std::unique_ptr<Task> task)
{
    taskQueue.push(std::move(task));
    int pid = fork();
    if(pid > 0)
    {
        std::cout<<"Parent Process"<<std::endl;
    }
    else if (pid == 0)
    {
        std::cout<<"Child Process"<<std::endl;
        ProcessManagement::executeTasks();
        _exit(0);
    }
    else
    {
        std::cout<<"Failed to create child process"<<std::endl;
    }
    
    return true;
}

void ProcessManagement::executeTasks()
{
    while(!taskQueue.empty())
    {
        std::unique_ptr<Task> taskToExecute = std::move(taskQueue.front());
        taskQueue.pop();
        std::cout<<"Executing task: "<<taskToExecute->toString()<<std::endl;
        executeCryption(taskToExecute->toString());
    }
}