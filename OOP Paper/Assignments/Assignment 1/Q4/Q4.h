#ifndef Q4_H
#define Q4_H

#include <iostream>
using namespace std;

const int MAX_STUDENTS = 10;
const int MAX_STOPS = 5;
const int MAX_ROUTES = 5;

class Student {
private:
    string studentName;
    int studentID;
    int transportID;
    bool isCardActive;
    int routeID;  

public:
    Student(string n, int i, int t);
    ~Student();

    void payFees();
    void tapCard();
    void assignRoute(int route);

    int getStudentID() const;
    string getName() const;
    bool getCardStatus() const;
    int getRouteID() const;
};

class BusStop {
private:
    string stopName;
    int stopID;

public:
    BusStop(){
        stopID = 0;
        stopName = "";
    }
    BusStop(string n, int i);
    ~BusStop();

    string getStopName() const;
    int getStopID() const;
};

class BusRoute {
private:
    int routeID;
    int busNumber;
    int stopCount;
    BusStop stops[MAX_STOPS];

public:
    BusRoute(int i, int busNo);
    ~BusRoute();

    void addStop(const BusStop& stop);
    int getRouteID() const;
    int getBusNumber() const;
    BusStop getStop(int index) const;
    void displayStops() const; 
};


class System {
private:
    Student* students[MAX_STUDENTS];
    BusRoute* routes[MAX_ROUTES];
    int studentCount;
    int routeCount;

public:
    System();
    ~System();

    void registerStudent(Student* s);
    void createBusRoute(int routeID, int busNumber);
    void addStopToRoute(int routeID, const BusStop& stop);
    void assignStudentToRoute(int studentID, int routeID);

    BusRoute* findRouteByID(int routeID);
    Student* findStudentByID(int studentID);
    void displayRoutesAndStops();  
    void displayAllStudents();  
};

#endif
