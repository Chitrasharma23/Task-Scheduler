#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Task {
public:
    string description;
    string date;
    string time;

    Task(const string& desc, const string& d, const string& t) 
        : description(desc), date(d), time(t) {}
};

class TaskScheduler {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description, const string& date, const string& time) {
        tasks.push_back(Task(description, date, time));
        cout << "Task added successfully!" << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks scheduled." << endl;
            return;
        }
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description 
                 << " on " << tasks[i].date << " at " << tasks[i].time << endl;
        }
    }

    void deleteTask(size_t index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted successfully!" << endl;
    }

    void editTask(size_t index, const string& newDescription, const string& newDate, const string& newTime) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        tasks[index - 1].description = newDescription;
        tasks[index - 1].date = newDate;
        tasks[index - 1].time = newTime;
        cout << "Task edited successfully!" << endl;
    }

    void checkReminders() {
        time_t now = time(0);
        tm* localtm = localtime(&now);
        char currentDate[11];
        char currentTime[6];
        strftime(currentDate, 11, "%Y-%m-%d", localtm);
        strftime(currentTime, 6, "%H:%M", localtm);

        for (const auto& task : tasks) {
            if (task.date == currentDate && task.time == currentTime) {
                cout << "Reminder: " << task.description << " is due now!" << endl;
            }
        }
    }
};

int main() {
    TaskScheduler scheduler;
    int choice;
    string description, date, time;
    size_t index;

    while (true) {
        cout << "\nTask Scheduler\n";
        cout << "1. Add task\n";
        cout << "2. View tasks\n";
        cout << "3. Delete task\n";
        cout << "4. Edit task\n";
        cout << "5. Check reminders\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // to ignore the newline character left in the buffer

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, description);
                cout << "Enter task date (YYYY-MM-DD): ";
                getline(cin, date);
                cout << "Enter task time (HH:MM): ";
                getline(cin, time);
                scheduler.addTask(description, date, time);
                break;
            case 2:
                scheduler.viewTasks();
                break;
            case 3:
                cout << "Enter task number to delete: ";
                cin >> index;
                scheduler.deleteTask(index);
                break;
            case 4:
                cout << "Enter task number to edit: ";
                cin >> index;
                cin.ignore();
                cout << "Enter new task description: ";
                getline(cin, description);
                cout << "Enter new task date (YYYY-MM-DD): ";
                getline(cin, date);
                cout << "Enter new task time (HH:MM): ";
                getline(cin, time);
                scheduler.editTask(index, description, date, time);
                break;
            case 5:
                scheduler.checkReminders();
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
