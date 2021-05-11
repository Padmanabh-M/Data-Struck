// There's an algorithms tournament taking place in which teams of programmers compete against each other to solve algorithmic
// problems as fast as possible. Teams compete in a round robin, where each team faces off against all other teams. Only two teams
// compete against each other at a time, and for each competition, one team is designated the home team, while the other team is the
// away team. In each competition there's always one winner and one loser, there are no ties. A team receives 3 points if it wins and 0
// points if it loses. The winner of the tournament is the team that receives the most amount of points.

// Write a function that returns the winner of the tournament, the competition array has elements in the [homeTeam, awayTeam], 
// results array is info about the winner of each corresponding team in competition array, where 1 means that the homeTeam won, 
// and 0 for awayTeam

// Sample 

// competitions = [
// ["HTML", "C#"],
// ["C#", "Python"],
// ["Python", "HTML"],

// results = [0, 0, 1]

// Sample output

// "Python"
// C# beats HTML, Python Beats C#, and Python Beats HTML.

// HTML - @ points
// C# - 3 points
// Python - 6 points


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


const int HOME_TEAM_WON = 1;

void inner_update(string team, int points, unordered_map<string, int> &scores);



string tally(vector<vector<string>> compi, vector<int> results){
    string currentBest = "";
    unordered_map<string, int> scores = {{currentBest, 0}};

    for (int id = 0 ; id < compi.size() ; id++){
        auto result = results[id];
        auto competition = compi[id];
        auto home = competition[0];
        auto away = competition[1];
        auto winning = result == HOME_TEAM_WON ? home : away;


        inner_update(winning, 3, scores);

        if (scores[winning] > scores[currentBest]){
            currentBest = winning;
        }

    }
    return currentBest;
}


void inner_update(string team, int points, unordered_map<string,int> &scores){
    if (scores.find(team) == scores.end()){
        scores[team] = 0;
    }
    scores[team] += points;
}
