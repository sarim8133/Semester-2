#include "Q1.h"
#include"Q1.cpp"

int main() {
    cout <<"Syed Muhammad Sarim\n24K-0718" << endl;
    const int NUM_MENTORS = 3;
    const int NUM_STUDENTS = 3;
    
    Skill kicking = {1,"Kick","Kicking a football with your feet"};
    Skill batting = {2,"Batting","Hitting a ball with your bat"};
    Skill throwing = {3,"Throwing","Throwing a basketball with your hands"};

    Sport cricket = {301, "Cricket", "A bat-and-ball game", {batting}};
    Sport football = {302, "Football", "A field sport with goals", {kicking}};
    Sport basketball = {303, "Basketball", "A team sport with hoops", {throwing}};
    
    Mentor mentors[NUM_MENTORS] = {
        {1, "Ali", {cricket}, MAX_LEARNERS, {}},
        {2, "Sara", {football}, MAX_LEARNERS, {}},
        {3, "John", {basketball}, MAX_LEARNERS, {}}
    };

    Student students[NUM_STUDENTS] = {
        {101, 20, "Sarim", {cricket}, nullptr},   
        {102, 21, "Haziq", {football}, nullptr},  
        {103, 22, "Talal", {basketball}, nullptr} 
    };

    int choice;
    do {
        showMenu();
        cin>> choice;
        int studentID,mentorID,skillID;
        switch (choice) {
            case 1: { 
                studentID = idStudent(); 
                mentorID = idMentor();

                Student* student = findStudentByID(students,NUM_STUDENTS,studentID);
                Mentor* mentor = findMentorByID(mentors,NUM_MENTORS,mentorID);

                if (student&& mentor) {
                    if (hasMatchingSport(*mentor,*student)) {
                        student->registerForMentorship(*mentor);
                    } 
                    else {
                        cout << "Error: Mentor does not specialize in student's sport!" << endl;
                    }
                } 
                else {
                    cout << "Invalid student or mentor ID!" << endl;
                }
                break;
            }
            case 2: { 
                studentID = idStudent(); 

                Student* student = findStudentByID(students, NUM_STUDENTS, studentID);
                if (student) {
                    student->viewMentorDetails();
                }
                else {
                    cout << "Invalid student ID!" << endl;
                }
                break;
            }
            case 3: { 
                studentID = idStudent(); 

                Student* student = findStudentByID(students,NUM_STUDENTS, studentID);
                if (student) {
                    cout << "Select new sport (301-Cricket, 302-Football, 303-Basketball): ";
                    int sportID;
                    cin >> sportID;

                    Sport* newSport = nullptr;
                    if (sportID == 301) newSport = &cricket;
                    else if (sportID == 302) newSport = &football;
                    else if (sportID == 303) newSport = &basketball;

                    if (newSport) {
                        student->updateSportsInterest(*newSport);
                    } else {
                        cout << "Invalid sport selection!" << endl;
                    }
                } else {
                    cout << "Invalid student ID!" << endl;
                }
                break;
            }
            case 4: { 
                studentID = idStudent(); 
                mentorID = idMentor();

                Student* student = findStudentByID(students, NUM_STUDENTS, studentID);
                Mentor* mentor = findMentorByID(mentors, NUM_MENTORS, mentorID);

                if (student && mentor) {
                    if (hasMatchingSport(*mentor, *student)) {
                        mentor->assignLearner(*student);
                    } else {
                        cout << "Error: Mentor does not specialize in student's sport!" << endl;
                    }
                } else {
                    cout << "Invalid student or mentor ID!" << endl;
                }
                break;
            }
            case 5: { 
                studentID = idStudent(); 
                mentorID = idMentor();

                Student* student = findStudentByID(students, NUM_STUDENTS, studentID);
                Mentor* mentor = findMentorByID(mentors, NUM_MENTORS, mentorID);

                if (student && mentor) {
                    mentor->removeLearner(*student);
                } else {
                    cout << "Invalid student or mentor ID!" << endl;
                }
                break;
            }
            case 6: { 
                mentorID = idMentor();

                Mentor* mentor = findMentorByID(mentors, NUM_MENTORS, mentorID);
                if (mentor) {
                    mentor->viewLearners();
                } else {
                    cout << "Invalid mentor ID!" << endl;
                }
                break;
            }
            case 7: { 
                mentorID = idMentor();

                Mentor* mentor = findMentorByID(mentors, NUM_MENTORS, mentorID);
                if (mentor) {
                    mentor->provideGuidance();
                } else {
                    cout << "Invalid mentor ID!" << endl;
                }
                break;
            }
            case 8: {
               skillID = idSkill();
               if(skillID < 1 || skillID > 3){
                cout << "Invalid skill ID!" << endl;
               }
               else if(skillID == 1){
                batting.showSkillDetail();
               }
               else if(skillID == 2){
                kicking.showSkillDetail();
               }
               else{
                throwing.showSkillDetail();
               }
            }
            break;
            
            case 9:{
                skillID = idSkill();
                string newDescription;
                cout << "Enter New Description: ";
                cin >> newDescription;
                if(skillID < 1 || skillID > 3){
                cout << "Invalid skill ID!" << endl;
                }
                else if(skillID == 1){
                batting.updateSkillDescription(newDescription);
                }
                else if(skillID == 2){
                 kicking.updateSkillDescription(newDescription);
                }
                else{
                throwing.updateSkillDescription(newDescription);
                }
            break;
         }   
        case 10: 
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 10);

    return 0;
}
