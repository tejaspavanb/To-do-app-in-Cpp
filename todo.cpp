#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    string due_date;
    string priority;
    bool is_complete;

    // Display task info (const function since it doesn't modify the object)
    void display(int index) const {
        cout << index << ". " << (is_complete ? "[Complete] " : "[Incomplete] ")
             << description << " (Due: " << due_date << ", Priority: " << priority << ")" << endl;
    }
};

// Load tasks from a file
vector<Task> load_tasks() {
    vector<Task> tasks;
    ifstream file("todo_list.txt");
    if (file.is_open()) {
        Task task;
        while (file >> task.is_complete >> ws && getline(file, task.description) &&
               getline(file, task.due_date) && getline(file, task.priority)) {
            tasks.push_back(task);
        }
        file.close();
    }
    return tasks;
}

// Save tasks to a file
void save_tasks(const vector<Task>& tasks) {
    ofstream file("todo_list.txt");
    for (const auto& task : tasks) {
        file << task.is_complete << "\n" << task.description << "\n" << task.due_date
             << "\n" << task.priority << "\n";
    }
    file.close();
}

// Add a new task
void add_task(vector<Task>& tasks) {
    Task task;
    cout << "Enter task description: ";
    getline(cin, task.description);
    cout << "Enter due date (YYYY-MM-DD): ";
    getline(cin, task.due_date);
    cout << "Enter priority (low, medium, high): ";
    getline(cin, task.priority);
    task.is_complete = false;
    tasks.push_back(task);
    save_tasks(tasks);
    cout << "Task added!\n";
}

// List all tasks
void list_tasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks found.\n";
        return;
    }
    cout << "To-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        tasks[i].display(i + 1);  // `display()` is now `const`, so it can be called here
    }
}

// Mark a task as complete
void complete_task(vector<Task>& tasks) {
    int task_number;
    cout << "Enter task number to mark as complete: ";
    cin >> task_number;
    cin.ignore(); // Clear input buffer
    if (task_number > 0 && task_number <= tasks.size()) {
        tasks[task_number - 1].is_complete = true;
        save_tasks(tasks);
        cout << "Task marked as complete!\n";
    } else {
        cout << "Invalid task number\n";
    }
}

// Delete a task
void delete_task(vector<Task>& tasks) {
    int task_number;
    cout << "Enter task number to delete: ";
    cin >> task_number;
    cin.ignore(); // Clear input buffer
    if (task_number > 0 && task_number <= tasks.size()) {
        tasks.erase(tasks.begin() + task_number - 1);
        save_tasks(tasks);
        cout << "Task deleted!\n";
    } else {
        cout << "Invalid task number\n";
    }
}

int main() {
    vector<Task> tasks = load_tasks();
    int choice;

    do {
        cout << "\nSimple To-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Complete\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1:
                add_task(tasks);
                break;
            case 2:
                list_tasks(tasks);
                break;
            case 3:
                complete_task(tasks);
                break;
            case 4:
                delete_task(tasks);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
