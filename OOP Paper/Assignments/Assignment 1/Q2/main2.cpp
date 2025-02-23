#include "Q2.h"
#include "Q2.cpp"

int main(){
    cout <<"Syed Muhammad Sarim\n24K-0718" << endl;
    string team1Name,team2Name, robot1Name,robot2Name;
    cout << "Enter Team 1 Name: ";
    cin >> team1Name;
    cout << "Enter Robot Name for " <<team1Name << ": ";
    cin >> robot1Name;
    cout << "Enter Team 2 Name: ";
    cin >> team2Name;
    cout << "Enter Robot Name for " <<team2Name << ": ";
    cin >> robot2Name;

    Robot r1(robot1Name),r2(robot2Name);
    Team t1(team1Name,&r1),t2(team2Name,&r2);
    Game game(&t1,&t2);
    game.startGame();
    return 0;
}

