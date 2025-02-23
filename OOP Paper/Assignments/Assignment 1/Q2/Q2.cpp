#include "Q2.h"

Ball::Ball():x(0), y(0){}
Robot::Robot(string n):name(n),hits(0) {}
Team::Team(string name, Robot* r):teamName(name),robot(r){}
Game::Game(Team* t1, Team* t2):teamOne(t1),teamTwo(t2),goal(3, 3) {}

int Ball::getX(){
    return x; 
}
int Ball::getY(){
    return y; 
}

void Ball::move(int dx,int dy) {
    x +=dx;
    y +=dy;
}

pair<int, int> Ball::getPosition() {
    return {x, y};
}


int Robot::getHits(){ 
    return hits; 
}
string Robot::getName(){                                                             
    return name; 
}

void Robot::hitBall(int &ballX, int &ballY, const string &direction) {
    if (direction == "up") {
        ballY += 1;
    } 
    else if (direction == "down") {
        ballY -= 1;
    } 
    else if (direction == "left") {
        ballX -= 1;
    } 
    else if (direction == "right") {
        ballX += 1;
    } 
    else {
        cout << "Invalid direction! Try again.\n";
        return; 
    }
    hits++; 
}

string Team::getTeamName() { 
    return teamName; 
}
Robot* Team::getRobot(){ 
    return robot; 
}

bool Game::isGoalReached(int ballX, int ballY) {
    return (ballX == goal.first && ballY == goal.second);
}

void Game::play(Team* team) {
    Robot* robot = team->getRobot();
    int ballX = 0; 
    int ballY = 0; 
    cout << "\n" << team->getTeamName() << "'s turn with robot " << robot->getName() << "!" << endl;
    while (!isGoalReached(ballX, ballY)) {
        cout << "Ball position: (" << ballX << ", " << ballY << ")" << endl;
        cout << "Move the ball (up, down, left, right): ";

        string direction;
        cin >> direction;

        robot->hitBall(ballX, ballY, direction); 

        ball.move(ballX, ballY);
    }

    cout << team->getTeamName() << " reached the goal in " << robot->getHits() << " hits!\n" << endl;
}

void Game::startGame() {
    play(teamOne);
    play(teamTwo);
    declareWinner();
}

void Game::declareWinner() {
    int hitsOne =teamOne->getRobot()->getHits();
    int hitsTwo =teamTwo->getRobot()->getHits();

    cout << "Results:\n";
    cout << teamOne->getTeamName() << " - Hits: " << hitsOne << endl;
    cout << teamTwo->getTeamName() << " - Hits: " << hitsTwo << endl;

    if (hitsOne < hitsTwo) {
        cout << teamOne->getTeamName() << " wins!\n";
    } else if (hitsTwo < hitsOne) {
        cout << teamTwo->getTeamName() << " wins!\n";
    } else {
        cout << "It's a tie!\n";
    }
}
