//
//  main.cpp
//  GPA Estimator
//
//  Created by John Crider on 7/17/18.
//  Copyright © 2018 John Crider. All rights reserved.
//

#include <iostream>
using namespace std;


float numberPastCredits = 0;
float pastGPA = 0;

int numberOfClasses = 0;

const int maxClasses = 100;
std::string classNames[maxClasses];
float classCredits[maxClasses];
std::string gradesEarned[maxClasses];
std::string classWeight[maxClasses];
float gradePointValues[maxClasses];

const bool readFromFile = false;

int GetInputInt()
{
    int retVal;
    if (readFromFile)
    {
        //Do things to read from a file
    }
    else
    {
        cin >> retVal;
    }
    return retVal;
}

string GetInputString()
{
    string retVal;
    if (readFromFile)
    {
        //Do things to read from a file
    }
    else
    {
        cin >> retVal;
    }
    return retVal;
}

float GetInputFloat()
{
    float retVal;
    if (readFromFile)
    {
        //Do things to read from a file
    }
    else
    {
        cin >> retVal;
    }
    return retVal;
}

void showClassMaintenanceMenu()
{
    //This function displays user choices for Class Maintenance
    //on the stdout
    //inputs: none
    //returns: nothing
    std::cout << "\n\n****************\n";
    std::cout << "** Class Menu **\n";
    std::cout << "****************\n";
    std::cout << "1 - Add a class \n";
    std::cout << "2 - Remove a class \n";
    std::cout << "9 - Show all classes \n";
    std::cout << "0 - Exit Class Maintenance \n";
    
}

void showMainMenu()
{
    //This function displays user choices on the stdout
    //inputs: none
    //returns: nothing
    std::cout << "\n\n**********\n";
    std::cout << "** Menu **\n";
    std::cout << "**********\n";
    std::cout << "1 - Set the number of credits taken \n";
    std::cout << "2 - Set current GPA \n";
    std::cout << "3 - Current Class Maintenance \n";
    std::cout << "9 - Show all entries \n";
    std::cout << "0 - Exit Application \n";
}

void getNumberOfCredits()
{
    //Accept from stdin the number of credits from the user.
    //inputs: none
    //returns: nothing
    std::cout << "\n\nPlease enter the number of credits you have completed.\n";
    numberPastCredits = GetInputFloat();
}

void displayClassInfo()
{
    for (int i = 0; i< numberOfClasses;i++)
    {
        if (i==0)
        {
            cout<< "Here is all of the class info\n";
            cout<< "Class Name\tCredits\tWeight\tGrade\n";
            cout<< "**********\t*******\t******\t*****\n";
        }
        cout << classNames[i] << "\t" << classCredits[i] << "\t" << classWeight[i]<<"\t" << gradesEarned[i] << "\n";
    }
}

void showAllValues()
{
    std::cout << "\n\nHere are all of the values\n";
    std::cout << numberPastCredits << ": Number of credits earned in the past.\n";
    std::cout << pastGPA << ": current GPA.\n";
    
    displayClassInfo();
}

void getGPA()
{
    //Accept from stdin the GPA from the user.
    //inputs: none
    //returns: nothing
    std::cout << "\n\nPlease enter current GPA.\n";
    pastGPA = GetInputFloat();
}

void giveAddAClassInstructions()
{
    //Provide instructions to users so they know
    //how much data will be asked when entering a class.
    std::cout << "\nYou will be prompted for the name, class weight, credits, and estimated grade for class\n\n";
}

void getName(int whichClass)
{
    //Get class name from user and store it in array
    std::cout << "\n\nStep 1 of 4 \nEnter the name of the class.\n";
    classNames[whichClass] = GetInputString();
}

void getClassWeight(int whichClass)
{
    //Store the Weight of the class: Normal, Enriched, AP, EarlyCollege, Dual Enrollment
    std::cout << "\n\nStep 2 of 4 \nEnter the weight type of the class (Normal, AP, EarlyCollege, DualCredit.\n";
    classWeight[whichClass] = GetInputString();
}

void getCredits(int whichClass)
{
    //Get the number of credits that a class is worth from the user
    std::cout << "\n\nStep 3 of 4 \nEnter the number of credits this class is worth.\n";
    classCredits[whichClass] = GetInputFloat();
}

void getGradeEarned(int whichClass)
{
    //Get letter grade earned for class
    std::cout << "\n\nStep 4 of 4 \nEnter the letter grade for this class\n";
    gradesEarned[whichClass] = GetInputString();
}

float letterGradeToNumber(string letterGrade)
{
    //Turn a letter grade into a number for computing a GPA
    //inputs: letterGrade - string holding a grade value (ie A, A-, B+, B, B-...)
    //returns: GPA translated number
    float returnNumber = -100;
    
    char letterOnly = toupper(letterGrade[0]);
   switch (letterOnly) {
        case 'A':
            returnNumber = 4.0;
            break;
        case 'B':
            returnNumber = 3.0;
            break;
        case 'C':
            returnNumber = 2.0;
            break;
        case 'D':
            returnNumber = 1.0;
            break;
        case 'F':
            returnNumber = 0.0;
            break;

        default:
            break;
    }
    if (letterGrade.length() == 2)
    {
        if (letterGrade[1] == '-')
        {
            returnNumber -= 0.25;
        }
        if (letterGrade[1] == '+')
        {
            returnNumber += 0.25;
        }
    }
    return returnNumber;
}

float weightToNumber(string weightName)
{
    //Turn a description of a weighting (ie Normal, AP, Early College, ...) into
    //a weight that can be used to modify a GPA
    //input: index into the classWeight array
    //output: weight converted into a floating point number ready to modify the course GPA amount
    
    float returnWeight = -1000;
    
    if (weightName == "Normal")
    {
        returnWeight = 0;
    } else if (weightName == "AP" || weightName == "EarlyCollege" || weightName == "DualCredit")
    {
        returnWeight = 1;
    } else if (weightName == "Enriched")
    {
        returnWeight = 0.5;
    }
    return returnWeight;
}

void storeGradePoint(int whichClass)
{
    float unweightedGrade = letterGradeToNumber(gradesEarned[whichClass]);
    float weightingToUse = weightToNumber(classWeight[whichClass]);
    
    gradePointValues[whichClass] = unweightedGrade + weightingToUse;

}

void addAClass()
{
    giveAddAClassInstructions();
    getName(numberOfClasses);
    getClassWeight(numberOfClasses);
    getCredits(numberOfClasses);
    getGradeEarned(numberOfClasses);
    storeGradePoint(numberOfClasses);
    numberOfClasses++;
}

void completeClassMaintenance(int userChoice)
{
    /*
     Based on the users choice, this routine calls others to
     take actions the user wants to do for class maintenance.
     These actions relate directly to shwat was shown to the
     user in the showClassMaintenanceMenu() function
     */
    
    //inputs: userChoice - integer that was entered by the user to indicate the menu selection
    //returns: nothing
    
    //validate that userChoice entries are valid
    if (userChoice < 0 || userChoice > 9)
    {
        //userchoice should only be a number 0-9. If any other value is found, exit the function
        return;
    }
    
    switch (userChoice) {
        case 1:
            addAClass();
            break;
            
        case 2:
            //removeAClass();
            break;
            
        case 9:
            //showAllClasses();
            break;
            
        default:
            break;
    }
    
}

void executeClassMaintenance()
{
    //Loops until the user enteres a zero.
    //This is for Class maintenance
    //inputs: none
    //returns: nothing
    
    int userChoice = -1;
    while (userChoice != 0)
    {
        showClassMaintenanceMenu();
        userChoice = GetInputInt();
        completeClassMaintenance(userChoice);
    }
    
}

void completeUserSelection(int userChoice)
{
    //Based on the users choice, this routine calls others to
    //take actions the user wants to do. THese actions relate
    //directly to shwat was show to the user in the showMenu()
    //function
    
    //inputs: userChoice - integer that was entered by the user to indicate the menu selection
    //returns: nothing
    
    //validate that userChoice entries are valid
    if (userChoice < 0 || userChoice > 9)
    {
        //userchoice should only be a number 0-9. If any other value is found, exit the function
        return;
    }
    
    switch (userChoice) {
        case 1:
            getNumberOfCredits();
            break;
            
        case 2:
            getGPA();
            break;
            
        case 3:
            executeClassMaintenance();
            break;
            
        case 9:
            showAllValues();
            break;
            
        default:
            break;
    }
    
}

void executeUntilUserFinishes()
{
    //Loops until the user enteres a zero
    //inputs: none
    //returns: nothing
    
    int userChoice = -1;
    while (userChoice != 0)
    {
        showMainMenu();
        userChoice = GetInputInt();
        completeUserSelection(userChoice);
    }
    
}

int main() {
    // This is the function that runs wehn the application starts
    //inputs: none
    //returns: an integer representing whether an error was encountered
    std::cout << "Hello, World!\n";
    executeUntilUserFinishes();
    
    return 0;
}



