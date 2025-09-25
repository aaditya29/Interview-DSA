// Leetcode 3408. Design Task Manager
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class TaskManager
{
public:
    unordered_map<int, int> taskToUser;
    unordered_map<int, int> taskToPriority;

    set<pair<int, int>, greater<pair<int, int>>> taskSet;

    TaskManager(vector<vector<int>> &tasks)
    {
        for (auto &task : tasks)
        {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];

            taskToUser[taskId] = userId;
            taskToPriority[taskId] = priority;
            taskSet.insert({priority, taskId});
        }
    }

    void add(int userId, int taskId, int priority)
    {
        taskToUser[taskId] = userId;
        taskToPriority[taskId] = priority;
        taskSet.insert({priority, taskId});
    }

    void edit(int taskId, int newPriority)
    {

        int oldPriority = taskToPriority[taskId];
        taskSet.erase({oldPriority, taskId});

        taskToPriority[taskId] = newPriority;
        taskSet.insert({newPriority, taskId});
    }

    void rmv(int taskId)
    {
        int priority = taskToPriority[taskId];
        taskSet.erase({priority, taskId});

        taskToUser.erase(taskId);
        taskToPriority.erase(taskId);
    }

    int execTop()
    {
        if (taskSet.empty())
        {
            return -1;
        }

        auto [priority, taskId] = *taskSet.begin();
        int userId = taskToUser[taskId];

        taskSet.erase(taskSet.begin());
        taskToUser.erase(taskId);
        taskToPriority.erase(taskId);

        return userId;
    }
};

int main()
{
    vector<vector<int>> tasks = {{1, 1, 5}, {2, 2, 3}, {3, 3, 4}};
    TaskManager taskManager(tasks);

    taskManager.add(4, 4, 6);
    cout << taskManager.execTop() << endl; // Output: 4

    taskManager.edit(2, 7);
    cout << taskManager.execTop() << endl; // Output: 2

    taskManager.rmv(3);
    cout << taskManager.execTop() << endl; // Output: 1

    return 0;
}