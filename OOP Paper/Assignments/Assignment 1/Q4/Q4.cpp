#include "Q4.h"


Student::Student(string n, int i, int t) : studentName(n), studentID(i), transportID(t), isCardActive(false), routeID(0) {}

Student::~Student() {}

void Student::payFees() {
    isCardActive = true;
    cout << studentName << " has paid fees. Card activated.\n";
}

void Student::tapCard() {
    if (isCardActive)
        cout << studentName << " tapped the card.\n";
    else
        cout << studentName << "'s card is inactive. Please pay fees.\n";
}

void Student::assignRoute(int route) {
    routeID = route;
    cout << studentName << " assigned to Route " << route << ".\n";
}

int Student::getStudentID() const { return studentID; }
string Student::getName() const { return studentName; }
bool Student::getCardStatus() const { return isCardActive; }
int Student::getRouteID() const { return routeID; }


BusStop::BusStop(string n, int i) : stopName(n), stopID(i) {}
BusStop::~BusStop() {}

string BusStop::getStopName() const { return stopName; }
int BusStop::getStopID() const { return stopID; }

BusRoute::BusRoute(int i, int busNo) : routeID(i), busNumber(busNo), stopCount(0) {}

BusRoute::~BusRoute() {}

void BusRoute::addStop(const BusStop& stop) {
    if (stopCount < MAX_STOPS) {
        stops[stopCount++] = stop;
        cout << "Stop " << stop.getStopName() << " added to Route " << routeID << ".\n";
    } else {
        cout << "Route " << routeID << " has reached maximum stops.\n";
    }
}

int BusRoute::getRouteID() const { return routeID; }
int BusRoute::getBusNumber() const { return busNumber; }
BusStop BusRoute::getStop(int index) const { return (index < stopCount) ? stops[index] : BusStop(); }

void BusRoute::displayStops() const {
    cout << "Route " << routeID << " (Bus " << busNumber << ") has the following stops:\n";
    for (int i = 0; i < stopCount; i++) {
        cout << "- " << stops[i].getStopName() << endl;
    }
}

System::System() : studentCount(0), routeCount(0) {}

System::~System() {
    for(int i =0 ; i < studentCount ; i++){
        delete students[i];
    }
    for(int i =0 ; i < routeCount ; i++){
        delete routes[i];
    }
}

void System::registerStudent(Student* s) {
    if (studentCount < MAX_STUDENTS) {
        students[studentCount++] = s;
        cout << "Student " << s->getName() << " registered in system.\n";
    } else {
        cout << "Maximum students reached!\n";
    }
}

void System::createBusRoute(int routeID, int busNumber) {
    if (routeCount < MAX_ROUTES) {
        routes[routeCount++] = new BusRoute(routeID, busNumber);
        cout << "Bus Route " << routeID << " with Bus " << busNumber << " created.\n";
    } else {
        cout << "Maximum bus routes reached!\n";
    }
}

void System::addStopToRoute(int routeID, const BusStop& stop) {
    for (int i = 0; i < routeCount; i++) {
        if (routes[i]->getRouteID() == routeID) {
            routes[i]->addStop(stop);
            return;
        }
    }
    cout << "Route ID not found!\n";
}

void System::assignStudentToRoute(int studentID, int routeID) {
    Student* student = findStudentByID(studentID);
    if (student) {
        student->assignRoute(routeID);
    } else {
        cout << "Student not found!\n";
    }
}

BusRoute* System::findRouteByID(int routeID) {
    for (int i = 0; i < routeCount; i++) {
        if (routes[i]->getRouteID() == routeID) {
            return routes[i];
        }
    }
    return nullptr;
}

Student* System::findStudentByID(int studentID) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i]->getStudentID() == studentID) {
            return students[i];
        }
    }
    return nullptr;
}

void System::displayRoutesAndStops() {
    cout << "\n=== Bus Routes and Stops ===\n";
    for (int i = 0; i < routeCount; i++) {
        routes[i]->displayStops();
    }
}

void System::displayAllStudents() {
    cout << "\n=== Registered Students ===\n";
    for (int i = 0; i < studentCount; i++) {
        cout << "Student: " << students[i]->getName() << " | ID: " << students[i]->getStudentID()
             << " | Route: " << (students[i]->getRouteID() != 0 ? to_string(students[i]->getRouteID()) : "None") << endl;
    }
}
