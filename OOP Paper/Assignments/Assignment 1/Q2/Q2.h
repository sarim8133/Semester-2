#ifndef Q2_H
#define Q2_H

#include <iostream>
using namespace std;

class Ball {
private:
    int x;
    int y;
public:
    Ball();
    int getX() ;
    int getY();
    void move(int dx, int dy);
    pair<int, int> getPosition();
};
 
class Robot {
private:
    string name;
    int hits;
public:
    Robot(string n);
    int getHits();
    string getName();
    void hitBall(int &ballX ,int &ballY,const string &direction);
};

class Team {
private:
    string teamName;
    Robot* robot;
public:
    Team(string name,Robot* r);
    string getTeamName();
    Robot* getRobot();
};

class Game {
private:
    Team* teamOne;
    Team* teamTwo;
    Ball ball;
    pair<int, int> goal;
public:
    Game(Team* t1,Team* t2);
    bool isGoalReached(int ballX,int ballY);
    void play(Team* team);
    void startGame();
    void declareWinner();
};
#endif 
