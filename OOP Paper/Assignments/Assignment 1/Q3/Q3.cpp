#include "Q3.h"
User::User(string n,int a, string l, string c, int u):name(n),age(a),licenseType(l),contact(c),userID(u){}
void User::updateDetails(string newName,int newAge,string newLicense,string newContact){
    name = newName;
    age = newAge;
    licenseType = newLicense;
    contact = newContact;
    cout << "User details updated successfully!" << endl;
}

void User::display(){
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "License Type: " << licenseType << endl;
    cout << "Contact: " << contact << endl;
    cout << "User ID: " << userID << endl;
    cout << endl;
}
int User::getAge(){return age;}
string User::getLicense(){return licenseType;}
int User::getUserID(){return userID;}

Vehicle:: Vehicle(string m,double r,string req, bool i):model(m),rentalPrice(r),reqLicense(req),isRented(i){}

void Vehicle::display(){
    cout << "Model: " << model << endl;
    cout << "Rental Price: " << rentalPrice << endl;
    cout << "Required License: " << reqLicense << endl;
    cout << endl;
}

bool Vehicle::Eligible(const string& userLicense){
    if (userLicense == "Full") {
        return true; 
    }
    if (userLicense == "Intermediate" && (reqLicense == "Intermediate" || reqLicense == "Learner")) {
        return true;  
    }
    if (userLicense == "Learner" && reqLicense == "Learner") {
        return true;  
    }
    return false; 
}

string Vehicle::getModel(){return model;}
bool Vehicle::isAvailable() { return !isRented; }
void Vehicle::rentVehicle() { isRented = true; }
