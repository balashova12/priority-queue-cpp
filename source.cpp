#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include "PriorityQueue.h"

using namespace std;

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    PriorityQueue q;
    char choice;

    cout << "Lab work #4 - PriorityQueue (variant 0)\n";

    do {
        cout << "\n=== MENU ===\n";
        cout << "1 - Add element\n";
        cout << "2 - Extract element\n";
        cout << "3 - Peek next element\n";
        cout << "4 - Check element existence\n";
        cout << "5 - Print queue\n";
        cout << "6 - Run test scenario\n";
        cout << "0 - Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        if (choice == '1') {
            int v, p;
            cout << "Enter value and priority: ";
            cin >> v >> p;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input.\n";
            } else {
                q.add(v, p);
                cout << "Element added.\n";
            }
        }
        else if (choice == '2') {
            int v, p;
            if (q.get(v, p))
                cout << "Extracted: value = " << v << ", priority = " << p << "\n";
            else
                cout << "Queue is empty.\n";
        }
        else if (choice == '3') {
            int v, p;
            if (q.peek(v, p))
                cout << "Next element: (" << v << ", priority = " << p << ")\n";
            else
                cout << "Queue is empty.\n";
        }
        else if (choice == '4') {
            int v, p;
            cout << "Enter value and priority (0 = ignore priority): ";
            cin >> v >> p;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input.\n";
            } else {
                if (q.exist(v, p))
                    cout << "Element found.\n";
                else
                    cout << "Element not found.\n";
            }
        }
        else if (choice == '5') {
            cout << "Queue: " << q << "\n";
        }
        else if (choice == '6') {
            cout << "\n=== TEST SCENARIO ===\n" << endl;

            PriorityQueue a, b;
            a.add(10, 3);
            a.add(20, 5);
            a.add(30, 5);

            b.add(20, 5);
            b.add(40, 1);

            cout << "A = " << a << "\n";
            cout << "B = " << b << "\n";

            cout << "A + B = " << (a + b) << "\n";
            cout << "A - B = " << (a - b) << "\n";
            cout << "A & B = " << (a & b) << "\n";

            cout << "A > B ? " << (a > b ? "Yes" : "No") << "\n";

            cout << "\n=== TEST SCENARIO COMPLETE ===\n" << endl;
        }
        else if (choice == '0') {
            cout << "Exiting.\n";
        }
        else {
            cout << "Unknown command.\n";
        }

    } while (choice != '0');

    return 0;
}