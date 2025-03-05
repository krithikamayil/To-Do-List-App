#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
 struct task{
string description;
bool completed;
};

void addTask(vector<Task> &tasks);
void viewTasks(const vector<Task> &tasks);
void deleteTasks(vector<Task> &tasks);
void markTaskcompleted(vector<Task> &tasks);
void saveTasks(vector<Task> &tasks);
void loadTasks(vector<Task> &tasks);

int main() {
  vector<Task> tasks;
  loadTasks(tasks);

  int choice;
     vector<Task> tasks;
     loadTasks(tasks);

     int choice;

     do {
          cout << "\n📌 To-Do List App 📌" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Mark Task as Completed" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: deleteTask(tasks); break;
            case 4: markTaskCompleted(tasks); break;
            case 5: saveTasks(tasks); cout << "Tasks saved. Exiting..." << endl; break;
            default: cout << "Invalid choice. Try again!" << endl;
        }
    } while (choice != 5);

    return 0;
}

void addTask(vector<Task> &tasks) {
    Task newTask;
    cout << "Enter the task description: ";
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "✅ Task added successfully!" << endl;
}

void viewTasks(const vector<Task> &tasks) {
 if (tasks.empty()) {
        cout << "No tasks available!" << endl;
        return;
    }
    cout << "📋 Your Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << (tasks[i].completed ? "[✔] " : "[ ] ") << tasks[i].description << endl;
    }
}

void deleteTask(vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks to delete!" << endl;
        return;
    }
    int index;
    viewTasks(tasks);
    cout << "Enter task number to delete: ";
    cin >> index;
    cin.ignore();

    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "🗑 Task deleted successfully!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

void markTaskCompleted(vector<Task> &tasks) {
  if (tasks.empty()) {
        cout << "No tasks available to mark as completed!" << endl;
        return;
    }
    int index;
    viewTasks(tasks);
    cout << "Enter task number to mark as completed: ";
    cin >> index;
    cin.ignore();

    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "✅ Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

void saveTasks(const vector<Task> &tasks) {
    ofstream file("tasks.txt");
    for (const auto &task : tasks) {
        file << task.completed << " " << task.description << endl;
    }
    file.close();
}

void loadTasks(vector<Task> &tasks) {
    ifstream file("tasks.txt");
    if (!file) return;

    Task task;
    tasks.clear();
    while (file >> task.completed) {
        file.ignore();
        getline(file, task.description);
        tasks.push_back(task);
    }
    file.close();
}
