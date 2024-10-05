#ifndef BOBYERLY42_PROG4_H
#define BOBYERLY42_PROG4_H
//header guards
//all # includes
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//initializes the two structures that were required and their variables.
struct Cost
{
    double numHours = 0, 
           costPerHour = 0, 
           costFoodWeek = 0, 
           costSuppWeek = 0;
};
struct Creatures
{
    int maxCapacity = 0,
        currHousedCreatures = 0;
    string name, 
           description,
           location;
    double avgLength = 0,
           avgHeight = 0,
           totalCost = 0;
    bool danger;
    Cost members; 
};
//all functions used 
int enterCreatures(int, int, Creatures*);
int deleteCreatures(int, Creatures*);
bool moveArrayElements(string, int, Creatures*);
void printCreatures(int, Creatures*);
void printStatistics(int, Creatures*);
void saveCreaturesToFile(int, Creatures*);
#endif