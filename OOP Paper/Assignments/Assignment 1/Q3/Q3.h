#ifndef Q3_H
#define Q3_H

#include<iostream>
using namespace std;

class User{
private:
    string name;
    int age;
    string licenseType;
    string contact;
    int userID;
public:
    User(string n,int a, string l, string c, int u);
    void updateDetails(string newName,int newAge,string newLicense,string newContact);
    void display();
    int getAge();
    string getLicense();
    int getUserID();
};

class Vehicle{
private:
    string model;
    double rentalPrice;
    string reqLicense;
    bool isRented;
public:
    Vehicle(string m,double r,string req,bool i);
    void display();
    bool Eligible(const string& userLicense);
    string getModel();
    bool isAvailable();
    void rentVehicle();
};

#endif
