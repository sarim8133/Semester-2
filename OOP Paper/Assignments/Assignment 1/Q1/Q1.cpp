#include "Q1.h"

void Skill::showSkillDetail(){
    cout << "Skill ID: " << skillID << endl;
    cout << "Skill Name: "<< skillName << endl;
    cout << "Description: "<< skillDescription << endl;
}

void Skill::updateSkillDescription(string newDescription){
    skillDescription = newDescription;
}

void Sport::addSkill(Skill& s){
    for(int i =0;i < MAX_SKILLS ; i++){
        if(requiredSkill[i].skillID == 0){
            requiredSkill[i] = s;
            cout << "Skill added to sport " << sportName << endl;
            return;
        }
    }
    cout << "Limit Reached!" << endl;
}

void Sport::removeSkill(Skill& s){
    for(int i = 0; i < MAX_SKILLS; i++){
        if(requiredSkill[i].skillID == s.skillID){
            requiredSkill[i] = Skill();
            cout << "Skill removed from sport " << sportName << endl;
            return;
            }
    }
    cout << "Skill Not Found!" << endl;
}

void Student::registerForMentorship(Mentor& m){
    for(int i = 0; i < MAX_LEARNERS; i++){
        if(m.assignedLearners[i].studentID == 0){
            mentorAssigned = &m; 
            m.assignedLearners[i] = *this;
            cout << studentName << " has registered under mentor " << m.mentorName << endl;
            return;
        }
        cout << "Mentor " << m.mentorName << " is at full capacity!" << endl;
        
}
}

void Student::viewMentorDetails(){
    if(mentorAssigned){
        cout <<"Mentor: " << mentorAssigned->mentorName <<endl;
        cout << "Mentor ID: " << mentorAssigned->mentorID << endl;
    }
    else{
        cout << "No mentor assigned!" << endl;
    }
}

void Student::updateSportsInterest(Sport s){
    for(int i = 0; i < MAX_SPORTS; i++){
        if(sportInterest[i].sportID == 0){
            sportInterest[i] = s;
            cout << "Added " << s.sportName << " to " << studentName << "'s interests." << endl;
            return;
        }
    }
    cout << "Sports interests limit reached!" << endl;
}

void Mentor::assignLearner(Student& s){
    for(int i=0;i < MAX_LEARNERS;i++){
        if(assignedLearners[i].studentID == 0){
            assignedLearners[i] = s;
            s.mentorAssigned = this;
            cout << "Student " << s.studentName << " assigned to mentor " << mentorName << endl;
            return;
        }
    }
    cout << "Mentor " << mentorName << " is at full capacity!" << endl;
}

void Mentor::removeLearner(Student& s) {
    for (int i = 0; i < MAX_LEARNERS; i++) {
        if (assignedLearners[i].studentID == s.studentID) {
            assignedLearners[i] = Student(); 
            s.mentorAssigned = nullptr;
            cout << s.studentName << " removed from mentor " << mentorName << endl;
            return;
        }
    }
    cout << s.studentName << " is not assigned to this mentor." << endl;
}

void Mentor::viewLearners() {
    cout << "Mentor " << mentorName << " has the following learners:\n";
    bool hasLearners = false;
    for (int i = 0; i < MAX_LEARNERS; i++) {
        if (assignedLearners[i].studentID != 0) {
            cout << assignedLearners[i].studentName << endl;
            hasLearners = true;
        }
    }
    if (!hasLearners) cout << "  No learners assigned.\n";
}

void Mentor::provideGuidance() {
    cout << mentorName << " is providing guidance to learners about "<<sportsExpertise->requiredSkill->skillName << endl;
    cout << sportsExpertise->requiredSkill->skillDescription << endl;
}

void showMenu() {
    cout << "1. Register Student for Mentorship" << endl;
    cout << "2. View Mentor Details" << endl;
    cout << "3. Update Student Sports Interest" << endl;
    cout << "4. Assign Learner to Mentor" << endl;
    cout << "5. Remove Learner from Mentor" << endl;
    cout << "6. View Learners of Mentor" << endl;
    cout << "7. Mentor Provides Guidance" << endl;
    cout << "8. Show Skill Details" << endl;
    cout << "9. Change Skill Description" << endl;
    cout << "10. Exit" << endl;
    cout << "Enter your choice: ";
}

bool hasMatchingSport(Mentor& mentor, Student& student) {
    for (int i = 0; i < MAX_SPORTS; i++) {
        for (int j = 0; j < MAX_SPORTS; j++) {
            if (mentor.sportsExpertise[i].sportID != 0 && student.sportInterest[j].sportID != 0) {
                if (mentor.sportsExpertise[i].sportID == student.sportInterest[j].sportID) {
                    return true;  
                }
            }
        }
    }
    return false;  
}

Mentor* findMentorByID(Mentor mentors[], int numMentors, int id) {
    for (int i = 0; i < numMentors; i++) {
        if (mentors[i].mentorID == id)
            return &mentors[i];
    }
    return nullptr;
}

Student* findStudentByID(Student students[], int numStudents, int id) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].studentID == id)
            return &students[i];
    }
    return nullptr;
}
int idStudent(){
    int studentID;
    cout << "Enter student ID (101-Sarim, 102-Haziq, 103-Talal): ";
    cin >> studentID;
    return studentID;
}
int idMentor(){
    int mentorID;
    cout << "Enter mentor ID (1-Ali, 2-Sara, 3-John): ";
    cin >> mentorID;
    return mentorID;
}
int idSkill(){
    int skillID;
    cout << "Enter Skill ID (1-Batting, 2-Kicking, 3-Throwing): ";
    cin >> skillID;
    return skillID;
}
