#include "bobyerly42_prog4.h"
/************************************************************************************
* Name of function: enterCreatures                                                  *
* Purpose:         Grab data that the user wishs to store into the creatures array  *
************************************************************************************/
int enterCreatures(int max, int housed, Creatures *creature)
{
    //initialized all variables for function
    int menuChoice;
    ifstream creatureList;
    //each str is set for the stod functions
        //set in order to not overwrite the data if there was just one str
        //there are 7 str for each value that needs to be changed from string to a double.
    string filename, str, str2, str3, str4, str5, str6, str7;
    Creatures lineDataFile;
    char dangerTest, runAgain;

//validates function to check if the zoo is at max capacity
    while(housed >= max)
    {
        cout << "The zoo is at full capacity. You are not able to add any creatures.";
        return housed;
    }
//a menu choice of what they would like to do 
    cout << "What do you want to do?";
    cout << "\n\t1. Load my creatures from a file.";
    cout << "\n\t2. Enter one creature manually.";
    cout << "\n\tChoose 1 or 2.\nCHOICE: ";
    cin >> menuChoice;
    while(menuChoice < 1 || menuChoice > 2)
{
    //validation of the menuChoice to see if it is within bounds.
    cout << "\nYour choice was invalid. Choose a number 1 through 2.\nCHOICE: ";
    cin >> menuChoice;
}
switch(menuChoice)
{
    //creates a switch statement for the users choice.
    case 1: //case 1 is supposed to read data from a file that the user wishes.
    {
        if(housed > 0)
        {
            //if loop to test if housed is greater than 0, makes it to where the data will not over write itself in the array.
            cout << "\nWhat is the name of the file with you list of creatures? (ex: filename.txt)\nFILENAME: ";
            cin >> filename;
            creatureList.open(filename); // tests to see if file is open.
            if(creatureList.is_open())
            {
                cout << endl;
                //sets i = housed, to find the index number of where to start adding on creatures in order to not 
                    //overwrite data in the array
                for(int i=housed; i < max; i++)
                {
                    //grabs data from file with a delimiter of '#' and stores in creature arrays.
                    getline(creatureList, creature[i].name, '#');
                    getline(creatureList, creature[i].description, '#');
                    getline(creatureList, str, '#');
                    creature[i].avgLength = stod(str);
                        //stod() is a function that sets the string into a double. 
                    getline(creatureList, str2, '#');
                    creature[i].avgHeight = stod(str2);
                    getline(creatureList, creature[i].location, '#');
                    getline(creatureList, str3, '#');
                    creature[i].danger = stod(str3);
                    getline(creatureList, str4, '#');
                    creature[i].members.numHours = stod(str4);
                    getline(creatureList, str5, '#');
                    creature[i].members.costPerHour = stod(str5);
                    getline(creatureList, str6, '#');
                    creature[i].members.costFoodWeek = stod(str6);
                    getline(creatureList, str7, '#');
                    creature[i].members.costSuppWeek = stod(str7);
                    if(creature[i].name == "")
                    {
                        //short loop that tests if the first element in file is "" - nothing, if it is it breaks.
                        break;
                    }
                    housed++; 
                    //increments number of housed each time it runs. And outputs to the screen the name of each creature that was added.
                    cout << creature[i].name << " has been added." << endl;
                }
                if(housed == max)
                {
                    //tests to see if the number of housed creatures is == max capacity of the zoo.
                    cout << "\nYou are now at maximum capacity of " << max << " in your zoo.\n";
                }
                //confirms to the user how many creatures were added to the which file they wanted. And closes the file. 
                cout << endl << housed << " creatures from " << filename << " have been added to the zoo.";
                creatureList.close();
            }
        }
        else if(housed == 0)
        {
            //this loop test if housed == 0. If it is, it runs as normal. 
            //The purpose is the same as above, to grab data with a delimiter and store into array.
            cout << "\nWhat is the name of the file with you list of creatures? (ex: filename.txt)\nFILENAME: ";
            cin >> filename;
            creatureList.open(filename);
            if(creatureList.is_open())
            {
                cout << endl;
                for(int i=0; i < max; i++)
                {
                    getline(creatureList, creature[i].name, '#');
                    getline(creatureList, creature[i].description, '#');
                    getline(creatureList, str, '#');
                    creature[i].avgLength = stod(str);
                    getline(creatureList, str2, '#');
                    creature[i].avgHeight = stod(str2);
                    getline(creatureList, creature[i].location, '#');
                    getline(creatureList, str3, '#');
                    creature[i].danger = stod(str3);
                    getline(creatureList, str4, '#');
                    creature[i].members.numHours = stod(str4);
                    getline(creatureList, str5, '#');
                    creature[i].members.costPerHour = stod(str5);
                    getline(creatureList, str6, '#');
                    creature[i].members.costFoodWeek = stod(str6);
                    getline(creatureList, str7, '#');
                    creature[i].members.costSuppWeek = stod(str7);
                    if(creature[i].name == "")
                    {
                        break;
                    }
                    housed++;
                    cout << creature[i].name << " has been added." << endl;
                }
                if(housed == max)
                {
                    cout << "\nYou are now at maximum capacity of " << max << " in your zoo.\n";
                }
                cout << endl << housed << " creatures from " << filename << " have been added to the zoo.";
                creatureList.close();
            }
        }
        //if file is unable to be opened the it outputs this statement and breaks.
        else cout << filename << " does not exist or is corrupt. Sorry. Can't load creatures.";
        break;
    }
    case 2: //case 2 allows the user to manually enter data into the arrays
    {
        do
        {
            if(housed > 0)
            {
                //loop that iterates through data that the user is able to enter.
                //and makes it to where the data will not over write itself if there is already data stored in the array.
                for(int i=housed; i<max; i++)
                {
                    cin.ignore();
                    cout << "\nNAME: ";
                    getline(cin, creature[i].name);
                    cout << "DESCRIPTION: ";
                    getline(cin, creature[i].description);
                    cout << "AVERAGE LENGTH (in feet): ";
                    cin >> creature[i].avgLength;
                    cout << "AVERAGE HEIGHT (in feet): ";
                    cin >> creature[i].avgHeight;
                    cin.ignore();
                    cout << "LOCATION: ";
                    getline(cin, creature[i].location);
                    cout << "IS IT A DANGEROUS CREATURE? (y or n): ";
                    cin >> dangerTest;
                        if(dangerTest == 'n')
                            creature[i].danger = false;
                        else
                        {
                            creature[i].danger = true;
                        }
                    cin.ignore();
                    cout << "How many hours do you spend caring for the " << creature[i].name << "?";
                    cout << "\nNUM HOURS: ";
                    cin >> creature[i].members.numHours;
                    cout << "What is the cost per hour for caring for the " << creature[i].name << "?";
                    cout << "\nCOST PER HOUR: ";
                    cin >> creature[i].members.costPerHour;
                    cout << "How much money do you spend on food for the " << creature[i].name << "?";
                    cout << "\nFOOD COST: ";
                    cin >> creature[i].members.costFoodWeek;
                    cout << "How much money do you spend on grooming and medical supplies for the " << creature[i].name << "?";
                    cout << "\nSUPPLY COST: ";
                    cin >> creature[i].members.costSuppWeek;
                    cout << endl << creature[i].name << " has been added.";
                    housed++;
                    if(housed == max)
                    {
                        //test to see if zoo is at max capacity and return housed
                        cout << "\nYou are now at maximum capacity of " << max << " in your zoo.\n";
                        return housed;
                    }
                    else if(housed < max)
                    {
                        //test to see if housd is less than max (it should always be if above test doesnt pass.)
                        cout << "\n\nWant to add more creatures? (y or n): ";
                        cin >> runAgain;
                        //asks user if they want to run again, and validates their answer
                        while(runAgain != 'y' && runAgain != 'n')
                        {
                            cout << "Must enter y or n. \nChoice: ";
                            cin >> runAgain;
                        }
                    }
                    if(runAgain == 'n')
                    {
                        //returns housed if runAgain == 'n'
                        return housed;
                    }
                }
            }
            else if(housed == 0)
            {
                //similar to case 1, this is just a else if loop that does the exact same thing as the first if loop, this portion overwrites data 
                    //that is stored in there, just in case they wish to over write the data in a file and as long as housed == 0.
                for(int i=0; i<max; i++)
                {
                    cin.ignore();
                    cout << "\nNAME: ";
                    getline(cin, creature[i].name);
                    cout << "DESCRIPTION: ";
                    getline(cin, creature[i].description);
                    cout << "AVERAGE LENGTH (in feet): ";
                    cin >> creature[i].avgLength;
                    cout << "AVERAGE HEIGHT (in feet): ";
                    cin >> creature[i].avgHeight;
                    cin.ignore();
                    cout << "LOCATION: ";
                    getline(cin, creature[i].location);
                    cout << "IS IT A DANGEROUS CREATURE? (y or n): ";
                    cin >> dangerTest;
                        if(dangerTest == 'n')
                            creature[i].danger = false;
                        else
                        {
                            creature[i].danger = true;
                        }
                    cin.ignore();
                    cout << "How many hours do you spend caring for the " << creature[i].name << "?";
                    cout << "\nNUM HOURS: ";
                    cin >> creature[i].members.numHours;
                    cout << "What is the cost per hour for caring for the " << creature[i].name << "?";
                    cout << "\nCOST PER HOUR: ";
                    cin >> creature[i].members.costPerHour;
                    cout << "How much money do you spend on food for the " << creature[i].name << "?";
                    cout << "\nFOOD COST: ";
                    cin >> creature[i].members.costFoodWeek;
                    cout << "How much money do you spend on grooming and medical supplies for the " << creature[i].name << "?";
                    cout << "\nSUPPLY COST: ";
                    cin >> creature[i].members.costSuppWeek;
                    cout << endl << creature[i].name << " has been added.";
                    housed++;
                    if(housed == max)
                    {
                        cout << "\nYou are now at maximum capacity of " << max << " in your zoo.\n";
                        return housed;
                    }
                    else if(housed < max)
                    {
                        cout << "\n\nWant to add more creatures? (y or n): ";
                        cin >> runAgain;
                        while(runAgain != 'y' && runAgain != 'n')
                        {
                            cout << "Must enter y or n. \nChoice: ";
                            cin >> runAgain;
                        }
                    }
                    if(runAgain == 'n')
                    {
                        return housed;
                    }
                }
            } 
        }while(runAgain == 'y');
    }
}
    return housed;//if function fails for whatever reason (c++ who knows) it returns housed.
}
/*****************************************************************************************
* Name of function: deleteCreatures                                                      *
* Purpose:          allow the user to delete any creature and its data out of the array  *
*****************************************************************************************/
int deleteCreatures(int housed, Creatures *creature)
{
    //intitialize variables used.
    Creatures max;
    string removeCreature;
    if(housed > 0) 
    {
        //validates to make sure that there is data that is able to be deleted.
        cout << "The following is a list of all the creatures you take care of:\n";
        for(int i=0; i < housed; i++)
        {
            cout << creature[i].name << endl;
        }
    } 
    else if (housed <=0)
    {
        //if there is no data in the creatures array then it outputs there is no data and ends.
        cout << "\nThere are currently zero creatures in the zoo. None can be deleted.";
        ++housed;
        //adds one to housed to counter what is in main. In main after delete creatures function housed gets subtracted by one.
        return 0;
    }
    //asks the user to output the name of the creature they wish to remove.
    cout << "\nWhat creature do you wish to remove? ";
    cout << "\nCREATURE NAME: ";
    cin.ignore();
    getline(cin, removeCreature);

    if((moveArrayElements(removeCreature, housed, creature))==true)
    {
        //tests to see if what the user inputed is in the creature array and if it is, it get removed.
        cout << "You have removed " << removeCreature << ".";
        //housed gets deducted in main.
    }
    else if((moveArrayElements(removeCreature, housed, creature))==false)
    {
        //if what the user inputed is not in the creature array then it outputs what is below.
        cout << "Sorry a creature by the name " << removeCreature << " could not be found";
        //adds one to housed to counter what is in main.
        housed++;
    }
    //returns updated housed number.
    return housed;
}
/***************************************************************************************************************
* Name of function: moveArrayElements                                                                          *
* Purpose:          This function actually is what takes care of removing the creature from the array          *
***************************************************************************************************************/
bool moveArrayElements(string removeCreature, int housed, Creatures *creature)
{
    //initializes varibles.
    Creatures max;
    int e = -1, i = 0; 
    //e is == -1, because if it is equal to 0, then interferes with the below if loop and the index numbers of arrays.
    for(i = 0; i < housed; i++)
    {
        //iterates through the creatures array to find if the creature the user wanted to remove is in the array.
        //if it is in the array then it sets e == the index number of the name and breaks.
        if(creature[i].name == removeCreature)
        {
            e = i;
            break;
        }
    }
    if( e != -1)
    {
        //this checks to see if e != 1, if it does, it sets i=the index number of the 
                //creature that the user wants to remove (e). Then it moves each element left one index number. 
        //which essentially overwrites the data in the original index #.
        //then it returns true
        for(i = e; i < housed-1; i++)
        {
            //iterates through the array starting at the index number that the user wishes to remove.
            creature[i].name = creature[i+1].name;
            creature[i].description = creature[i+1].description;
            creature[i].avgLength = creature[i+1].avgLength;
            creature[i].avgHeight = creature[i+1].avgHeight;
            creature[i].location = creature[i+1].location;
            creature[i].danger = creature[i+1].danger;
            creature[i].members.numHours = creature[i+1].members.numHours;
            creature[i].members.costPerHour = creature[i+1].members.costPerHour;
            creature[i].members.costFoodWeek = creature[i+1].members.costFoodWeek;
            creature[i].members.costSuppWeek = creature[i+1].members.costSuppWeek;
        } 
        return true;
    }
    if(e ==-1)
    //if previous loops dont pass the condition then it return false.
    {
        return false;
    }
    //returns true because a bool function needs a return type. but one of the two previous function will always be true.
    return true;
}
/*********************************************************************************************
* Name of function: printCreatures                                                           *
* Purpose:          Prints the creatures name and all of the data that is involved with it.  *
*********************************************************************************************/
void printCreatures(int housed, Creatures *creature)
{
    if(housed == 0)
    {
        //if housed is == 0 then outputs a line and tells user there arent in creatures in zoo and returns.
        cout << setw(75) << setfill('-') << ""; 
        cout << "\nTHERE ARE NO CREATURES IN YOUR ZOO!";
        return;
    }
    else
    {
        //for loop to iterate and print the creatures and their data then returns to main.
        for(int i=0; i<housed; i++)
        {
        cout << setw(75) << setfill('-') << "";
        cout << endl << "CREATURE: " << i+1 << endl;
        cout << "Name: \t\t" << creature[i].name << endl;
        cout << "Description:\n\t" << setw(8) << setfill(' ') << "" << creature[i].description << endl;
        cout << "\nLength:\t\t" << creature[i].avgLength << " feet" << endl;
        cout << "Height:\t\t" << creature[i].avgHeight << " feet" << endl;
        cout << "Location:\t" << creature[i].location << endl;
        cout << "Dangerous?\t";
        //if else if loop to correctly output a yes or no if the creature is dangerous. Because it is stored and entered in integers
            if(creature[i].danger == 0)
                cout << "no" << endl;
            else if(creature[i].danger == 1)
             cout << "yes" << endl;
        cout << "Number of Hours to Care for Creature:\t\t" << "$ " << creature[i].members.numHours << endl;
        cout << "Cost Per Hour of Taking Care of Creatures:\t" << "$ " << creature[i].members.costPerHour << endl;
        cout << "Cost to Feed Creature;\t\t\t\t" << "$ " << creature[i].members.costFoodWeek << endl;
        cout << "Grooming & Supplies Cost:\t\t\t" << "$ " << creature[i].members.costSuppWeek << endl << endl;
        }
    }
}
/**************************************************************************************************************************************************
* Name of function: printStatistics                                                                                                               *
* Purpose:          Prints all creatures name and how much money each of them require to keep alive.                                              *
*                        formula for the total of each creature is ( numHours)(costPerHour+costOfFood+costOfSupplies, also keeps a running total. *
**************************************************************************************************************************************************/
void printStatistics(int housed, Creatures *creature)
{
    //initializes running total variable
    double runningTotal = 0;
    if(housed <= 0)
    {
        cout << setw(75) << setfill('-') << ""; 
        cout << "\nTHERE ARE NO CREATURES IN YOUR ZOO!";
    }
    else if (housed > 0 )
    {
        cout << "\nCOST OF EACH CREATURE FOR ONE WEEK:" << endl;
        cout << "CREATURE:" << setw(20) <<  setfill(' ')  << "\tCOST:" << endl;
        for(int i=0; i<housed; i++)
        {
            creature[i].totalCost = creature[i].members.numHours * (creature[i].members.costPerHour + creature[i].members.costFoodWeek + creature[i].members.costSuppWeek);
            cout << endl << fixed << setprecision(2);
            cout << left << setw(24) << creature[i].name << '$' << creature[i].totalCost;
            runningTotal += creature[i].totalCost;
        }
        cout << endl << endl << left << setw(24) << "TOTAL COST: " <<'$' << runningTotal;
    }
}
void saveCreaturesToFile(int housed, Creatures* creature)
{
    //initilizes variables.
    string filename;
    ofstream outFile;
//asks user what they want their file name to be in .txt format
    cout << "\nWhat is the name of the file you would like to save the data to? (example.txt): ";
    cin >> filename;
    //tests to see if file is open.
    outFile.open(filename);
    for(int i=0; i<housed; i++)
    {
        //outputs data in the text file separated by a '#'
        outFile << creature[i].name << '#' << creature[i].description << '#' << creature[i].avgLength << '#' << creature[i].avgHeight << '#'
                << creature[i].location << '#' << creature[i].danger << '#' << creature[i].members.numHours << '#' << creature[i].members.costPerHour   
                << '#' << creature[i].members.costFoodWeek << '#' << creature[i].members.costSuppWeek << '#';
    }
    //prints after data is printed to file
    cout << "\nYour creatures were successfully saved to the " << filename << " file.\n";
    //close .txt file
    outFile.close();
}