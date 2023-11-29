#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

const int MAX_TASKS = 10;

int main() {
    string Tasks[MAX_TASKS] = {};
    int choice, index = 0, INDEX = 0;
    string task;

    cout << "______________________________" << endl;
    cout << "--------MY TO-DO LIST---------" << endl;
    cout << "______________________________" << endl;

    bool exitProgram = false;

    while (!exitProgram) {
        cout << endl << "Select\n1. Add Task\n2. View Tasks\n3. Delete Task\n4. Quit" << endl;
        cout << endl << "Choice = ";
        cin >> choice;

        cin.ignore();

        switch (choice) {
        case 1:
            cout << endl << "--- Enter Task ---" << endl << "Task = ";
            getline(cin, task);

            if (index < MAX_TASKS) {
                Tasks[index] = task;
                index++;
                cout << "Task added successfully!" << endl;
            } else {
                cout << "Task list is full. Cannot add more tasks." << endl;
            }
            break;
        case 2:
            cout << endl << "----------- TASKS -----------" << endl;
            if (index > 0) {
                for (int i = 0; i < index; i++) {
                    cout << i + 1 << ". " << Tasks[i] << endl;
                }
            } else {
                cout << "Task list is empty." << endl;
            }
            break;
        case 3:
            cout << "Enter the task number to delete: ";
            cin >> INDEX;

            if (INDEX >= 1 && INDEX <= index) {
                // Shift tasks to fill the deleted task
                for (int i = INDEX - 1; i < index - 1; ++i) {
                    Tasks[i] = Tasks[i + 1];
                }
                index--;
                cout << "Task deleted successfully!" << endl;
            } else {
                cout << "Invalid task number. No task deleted." << endl;
            }
            break;
        case 4:
            cout << "Goodbye!" << endl;
            exitProgram = true; // Set the flag to exit the loop
            break;
        default:
            cout << "--- INVALID CHOICE ---" << endl;
            break;
        }

        if (!exitProgram) {
            cout << "Press any key to continue...";
            getch();
        }
    }

    return 0;
}

