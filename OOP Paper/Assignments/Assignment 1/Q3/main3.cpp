#include "Q3.h"
#include "Q3.cpp"

int main() {
    User* user = nullptr;
    const int numVehicles = 3;

    Vehicle* vehicles[numVehicles] = {
        new Vehicle("Alto", 40.0, "Learner",false),
        new Vehicle("Fortuner", 60.0, "Intermediate",false),
        new Vehicle("Ferrari", 100.0, "Full",false)
    };
    cout <<"Syed Muhammad Sarim\n24K-0718" << endl;
    int choice;
    do {
        cout << endl;
        cout << "1. Register User " << endl;
        cout << "2. Update User Details"<< endl;
        cout << "3. View Available Vehicles"<< endl;
        cout << "4. Rent a Vehicle"<< endl;
        cout << "5. Exit"<< endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: { 
                if (user) {
                    cout << "User already registered! " << endl;
                    break;
                }
                string name, license, contact;
                int age, userID;

                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Age: ";
                cin >> age;
                cin.ignore();
                cout << "Enter License Type (Learner/Intermediate/Full): ";
                cin >> license;
                cout << "Enter Contact Number: ";
                cin >> contact;
                cout << "Enter User ID: ";
                cin >> userID;

                user = new User(name, age, license, contact, userID);
                cout << "User registered successfully!\n";
                cout << endl;
                user->display();
                break;
            }
            case 2: { 
                if (!user) {
                    cout << "No user registered. Please register first.\n";
                    break;
                }
                string newName, newLicense, newContact;
                int newAge;

                cout << "Enter New Name: ";
                cin >> newName;
                cout << "Enter New Age: ";
                cin >> newAge;
                cout << "Enter New License Type (Learner/Intermediate/Full): ";
                cin >> newLicense;
                cout << "Enter New Contact Number: ";
                cin >> newContact; 

                user->updateDetails(newName, newAge, newLicense, newContact);
                break;
            }

            case 3: { 
                
                    cout << "\nAvailable Vehicles:\n";
                    bool foundAvailable = false;
                    for (int i = 0; i < numVehicles; i++) {
                        if (vehicles[i]->isAvailable()) {
                            cout << "\nVehicle " << (i + 1) << ":\n";
                            vehicles[i]->display();
                            foundAvailable = true;
                        }
                    }
                    if (!foundAvailable) {
                        cout << "No vehicles available for rent.\n";
                    }
                    break;
            }

            case 4: { 
                if (!user) {
                    cout << "No user registered. Please register first.\n";
                    break;
                }
                cout << "\nAvailable Vehicles:\n";
                bool foundAvailable = false;
                for (int i = 0; i < numVehicles; i++) {
                    if (vehicles[i]->isAvailable()) {
                        cout << "\nVehicle " << (i + 1) << ":\n";
                        vehicles[i]->display();
                        foundAvailable = true;
                    }
                }

                if (!foundAvailable) {
                    cout << "No vehicles available for rent.\n";
                    break;
                }

                int vehicleChoice;
                cout << "\nEnter the vehicle number to rent: ";
                cin >> vehicleChoice;

                if (vehicleChoice < 1 || vehicleChoice > numVehicles) {
                    cout << "Invalid choice!\n";
                } 
                else {
                    Vehicle* selectedVehicle = vehicles[vehicleChoice - 1];

                    if (!selectedVehicle->isAvailable()) {
                        cout << "Sorry, this vehicle is already rented.\n";
                    } 
                    else if (selectedVehicle->Eligible(user->getLicense())) {
                        selectedVehicle->rentVehicle();
                        cout << "Rental successful! You have rented: " << selectedVehicle->getModel() << endl;
                    } 
                    else {
                        cout << "Sorry, you are not eligible to rent this vehicle.\n";
                    }
                }
                break;
            }
            case 5: 
                cout << "Exiting system...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    delete user;
    for (int i = 0; i < numVehicles; i++) {
        delete vehicles[i];
    }

    return 0;
}
