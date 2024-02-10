#include <iostream>
#include <vector>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void add(const string& desc) {
        tasks.push_back(Task(desc));
        cout << "Task added successfully!!\n";
    }

    void show() const {
        if (tasks.empty()) {
            cout << "There are no tasks available.\n";
        } else {
            cout << "Tasks:\n";
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i].description << " - " 
                     << (tasks[i].completed ? "Completed" : "Pending") << "\n";
            }
        }
    }

    void remove(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task deleted successfully!!\n";
        } else {
            cout << "Invalid task number!!.\n";
        }
    }

    void markDone(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Task marked as done!\n";
        } else {
            cout << "Invalid task number!!.\n";
        }
    }
};

int main() {
    ToDoList toDoList;
    int choice;

    while (true) {
        cout << "\n-------------------------------------- To-Do List Menu --------------------------------------\n";
        cout << " 1. Add a Task\n 2. View the Tasks\n 3. Remove a Task\n 4. Mark a Task as Completed\n 5. Exit\n";
 
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore(); 
                string task;
                cout << "Enter the new task to be added: ";
                getline(cin, task);
                toDoList.add(task);
                break;
            }

            case 2:
                toDoList.show();
                break;

            case 3: {
                size_t taskNumber;
                cout << "Enter task number to remove: ";
                cin >> taskNumber;
                toDoList.remove(taskNumber);
                break;
            }

            case 4: {
                size_t taskNumber;
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                toDoList.markDone(taskNumber);
                break;
            }

            case 5:
                cout << "Exiting the Program.. Thank You, have a nice day!\n";
                return 0;

            default:
                cout << "Invalid choice. Please enter a correct option.\n";
        }
    }

    return 0;
}

