#ifndef Q1_H
#define Q1_H

#include<iostream>
using namespace std;

const int MAX_SKILLS = 5;
const int MAX_SPORTS = 3;
const int MAX_LEARNERS = 3;
const int MAX_MENTORS = 3;

class Skill{
    public:
    int skillID;
    string skillName;
    string skillDescription;
    
    void showSkillDetail();
    void updateSkillDescription(string newDescription);
};

class Sport{
    public:
    
    int sportID;
    string sportName;
    string sportDescription;
    Skill requiredSkill[MAX_SKILLS];
    
    void addSkill(Skill& s);
    void removeSkill(Skill& s);

};
class Mentor;

class Student{
    public:
    
    int studentID;
    int studentAge;
    string studentName;
    Sport sportInterest[MAX_SPORTS];
    Mentor* mentorAssigned;

    void registerForMentorship(Mentor& m);
    void viewMentorDetails();
    void updateSportsInterest(Sport s);
};

class Mentor{
    public:
    
    int mentorID;
    string mentorName;
    Sport sportsExpertise[MAX_SPORTS];
    int maxLearners;
    Student assignedLearners[MAX_LEARNERS];

    void assignLearner(Student& s);
    void removeLearner(Student& s);
    void viewLearners();
    void provideGuidance();
};

#endif
