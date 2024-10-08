# Command-Line To-Do List Manager

A simple C++ application that allows users to manage a to-do list via the command line. Users can add, view, mark tasks as complete, and delete tasks. Tasks are saved and loaded from a text file to persist between program runs.

## Features

- **Add a Task**: Create a new task with a description, due date, and priority.
- **View All Tasks**: Display all tasks with their current status (complete or incomplete), due date, and priority.
- **Mark Task as Complete**: Change the status of a task to complete.
- **Delete a Task**: Remove a task from the to-do list.
- **Save/Load from File**: Tasks are saved to a file (`todo_list.txt`) and reloaded when the program starts.

## How to Use

### Prerequisites
- A C++ compiler (e.g., `g++`)

### Compilation

To compile the program, run:

```bash
g++ todo.cpp -o todo
```

### Running the Program

Once compiled, you can run the program using:

```bash
./todo
```

### Menu Options

Upon running, the following menu options will be presented:

1. **Add Task**: Add a new task by providing a description, due date, and priority.
2. **View Tasks**: Display all tasks, showing their status, description, due date, and priority.
3. **Mark Task as Complete**: Mark a specific task as complete by providing the task number.
4. **Delete Task**: Delete a task from the to-do list by providing the task number.
5. **Exit**: Close the program.

### Example

```bash
Simple To-Do List Manager
1. Add Task
2. View Tasks
3. Mark Task as Complete
4. Delete Task
5. Exit
Enter your choice: 1
Enter task description: Add Repo to Github
Enter due date (YYYY-MM-DD): 2024-10-15
Enter priority (low, medium, high): high
Task added!
```

## File Storage

- **todo_list.txt**: The file where all tasks are stored. When tasks are added, marked as complete, or deleted, the file is updated automatically.

## Future Improvements

- Task sorting based on due date or priority.
- More detailed task attributes, such as categories or tags.
- Notifications for upcoming deadlines.
  
