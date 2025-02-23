#include "Q4.h"
#include "Q4.cpp"
int main() {
    System transportSystem;
    cout << "Syed Muhammad Sarim\n24K-0718" << endl;

    while (true) {
        cout << "\n=== TRANSPORTATION SYSTEM MENU ===\n";
        cout << "1. Register a Student\n";
        cout << "2. Create a Bus Route\n";
        cout << "3. Add a Stop to a Route\n";
        cout << "4. Assign Student to a Bus Route\n";
        cout << "5. Pay Semester Fee\n";
        cout << "6. Tap Card for Attendance\n";
        cout << "7. Display Routes and Stops\n";
        cout << "8. Display all Students\n";
        cout << "9. Exit\n";

        int choice;
        cout << "Enter Your Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string name;
            int id, transportID;
            cout << "Enter Student Name: ";
            getline(cin, name);
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Transport ID: ";
            cin >> transportID;

            Student* s = new Student(name, id, transportID);
            transportSystem.registerStudent(s);
        } 
        else if (choice == 2) {
            int routeID, busNumber;
            cout << "Enter Route ID: ";
            cin >> routeID;
            cout << "Enter Bus Number: ";
            cin >> busNumber;

            transportSystem.createBusRoute(routeID, busNumber);
        } 
        else if (choice == 3) {
            int routeID;
            string stopName;
            cout << "Enter Route ID: ";
            cin >> routeID;
            cin.ignore();
            cout << "Enter Bus Stop Name: ";
            getline(cin, stopName);

            BusStop stop(stopName, routeID);
            transportSystem.addStopToRoute(routeID, stop);
        } 
        else if (choice == 4) {
            int studentID, routeID;
            cout << "Enter Student ID: ";
            cin >> studentID;
            cout << "Enter Route ID: ";
            cin >> routeID;

            transportSystem.assignStudentToRoute(studentID, routeID);
        } 
        else if (choice == 5) {
            int studentID;
            cout << "Enter Student ID: ";
            cin >> studentID;

            Student* s = transportSystem.findStudentByID(studentID);
            if (s) {
                s->payFees();
            } else {
                cout << "Student not found!\n";
            }
        } 
        else if (choice == 6) {
            int studentID;
            cout << "Enter Student ID: ";
            cin >> studentID;

            Student* s = transportSystem.findStudentByID(studentID);
            if (s) {
                s->tapCard();
            } else {
                cout << "Student not found!\n";
            }
        } 
        else if(choice == 7){
            transportSystem.displayRoutesAndStops();
        }
        else if(choice == 8){
            transportSystem.displayAllStudents();
        }
        else if (choice == 9) {
            cout << "Exiting system...\n";
            break;
        } 
        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
