#include "bobyerly42_prog4.h"

 
int main (){
//all data points used in main, and the ones sent to functions
Creatures max, housed, *creature = nullptr;
char fileChoice;
int menuChoice;

cout << "What is the maximum capacity of your magical creature zoo? ";
cin >> max.maxCapacity;
creature = new Creatures[max.maxCapacity];
while(max.maxCapacity <= 0) //validates user choice
{
    cout << "\nYour zoo can't have a max capacity of 0";
    cout << "\nWhat is the maximum capacity of your magical creature zoo? ";
    cin >> max.maxCapacity;
}
do //runs the menu choice once, until the users choice == 5
{
    cout << "\n\nWhat would you like to do?";
    cout << "\n\t1. Enter some Magical Creatures.";
    cout << "\n\t2. Delete a Magical Creature.";
    cout << "\n\t3. List/Print Creatures";
    cout << "\n\t4. Print Creature Costs.";
    cout << "\n\t5. End Program.";
    cout << "\n\tEnter 1, 2, 3, 4, or 5.\nCHOICE: ";
    cin >> menuChoice;
    while(menuChoice < 1 || menuChoice > 5) 
    {   //validates to see if user choice is in between 1 and 5
        cout << "\nYour choice was invalid. Choose a number 1 through 5.\nCHOICE: ";
        cin >> menuChoice;
    }
    switch(menuChoice)
    {   //creates a switch statement for the 5 options 
        case 1:
        {   //calls the enterCreaturesFunction and returns the number of creatures housed and stores it in housed.currHousedCreatures
            housed.currHousedCreatures = enterCreatures(max.maxCapacity, housed.currHousedCreatures, creature);
            //breaks after housed it updated
            break;
        }
        case 2:
        {
            //calls the deleteCreatures function and returns an update on the number 
                //of creatures housed and stores it in housed.currHousedCreatures
            housed.currHousedCreatures = deleteCreatures(housed.currHousedCreatures, creature);
            //subtracts the number of housed creatures after function returns, if it is false the function adds one to cancel out the subtraction.
            --housed.currHousedCreatures;
            //breaks after housed is updated
            break;
        }
        case 3:
        {
            //calls the print creatures function 
            //prints out list of current creatures in the housed arra, and their data.
            printCreatures(housed.currHousedCreatures, creature);
            //breaks after creatures are printed
            break;
        }
        case 4:
        {
            //calls the print stats function
            //prints out list of current creatures and their numbers data.
            printStatistics(housed.currHousedCreatures, creature);
            //breaks after completion
            break;
        }
        case 5:
        {
            if(housed.currHousedCreatures != 0)
            {
                //The goal of case 5 is to ask the user if they want to save the creature list to a file. 
                cout << "Would you like to save your creature list to a file? (y or n) ";
                cin >> fileChoice;
                if(fileChoice == 'y')
                {
                    //This is testing to see if the users choice == y, if it is it calls the saveCreaturesToFile function.
                    saveCreaturesToFile(housed.currHousedCreatures, creature);
                    //after completion the function it prints goodbye and deletes the allocated array and ends the program.
                    cout << "Goodbye!";
                    delete[] creature;
                    return 0;
                }
                else if(fileChoice == 'n')
                {
                    //if users choice is == n, then prints goodbye, deletes allocated memory, then ends program.
                    cout << "Goodbye!";
                    delete [] creature;
                    return 0;
                }
                else 
                {
                    //If the users choice is not y or n, then it prints invalid option and returns back to the menu.
                    cout << "Invalid option Choose again.";
                }
            }
            else if(housed.currHousedCreatures == 0)
            {
                //prints if the housed variable is 0.
                cout << "\nThere are currently zero creatures in the zoo. Nothing is able to be printed to a file.";
            }
        }
    }
    
} while(menuChoice > 1 || menuChoice < 5);
//while portion of a do while that tests to see if their menu choice is > 1 or < 5 if it is then it runs menu again. 
//if it breaks loop with choice 5, then it deletes allocated memory and ends the program.
delete [] creature;

    return 0;
}