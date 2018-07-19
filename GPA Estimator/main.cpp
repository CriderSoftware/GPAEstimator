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
    cout << "\n\n**********\n";
    cout << "** Menu **\n";
    cout << "**********\n";
    cout << "1 - Set the number of credits taken \n";
    cout << "2 - Set current GPA \n";
    cout << "3 - Current Class Maintenance \n";
    cout << "4 - Estimate GPA (include current classes)\n";
    cout << "9 - Show all entries \n";
    cout << "0 - Exit Application \n";
}

void getNumberOfCredits()
{
    //Accept from stdin the number of credits from the user.
    //inputs: none
    //returns: nothing
    std::cout << "\n\nPlease enter the number of credits you have completed.\n";
    numberPastCredits = GetInputFloat();
}

void displayOneClass(int whichClass)
{
    cout << whichClass + 1 << "\t" << classNames[whichClass] << "\t\t" <<
    classCredits[whichClass] << "\t" << classWeight[whichClass]<<"\t" <<
    gradesEarned[whichClass] << gradePointValues[whichClass] << "\n";
}

void displayClassInfoHeader()
{
    //Display the headers for the list of classes entered
    cout<< "ClassID\tClass Name\tCredits\tWeight\tGrade\n";
    cout<< "*******\t**********\t*******\t******\t*****\n";
}

void displayClassInfo()
{
    for (int i = 0; i< numberOfClasses;i++)
    {
        if (i==0)
        {
            cout<< "Here is all of the class info\n";
            displayClassInfoHeader();
        }
        displayOneClass(i);
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
    
    cout << "Class has been added\n";
    displayClassInfoHeader();
    displayOneClass(numberOfClasses-1);
}

void RemoveClassFromInternalstructure(int whichClass)
{
    //Remove the indexed item from all the arrays in
    //the class and change the number of classes in the system.
    //input: whichClass - integer representing the index of the class to be removed.
    //outputs: nothing
    
    for (int i = whichClass; i< numberOfClasses; i++)
    {
        classNames[i] = classNames[i+1];
        classCredits[i] = classCredits[i+1];
        gradesEarned[i] = gradesEarned[i+1];
        classWeight[i] = classWeight[i+1];
        gradePointValues[i] = gradePointValues[i+1];
    }
    numberOfClasses--;
}

void removeAClass()
{
    bool userHasSelectedClass = false;
    int classIDToRemove =-10;
    int classIndexToRemove= -10;
    while(!userHasSelectedClass)
    {
    cout << "Here is the list of classes. Please enter the ClassID of the class to be removed.\n";
    displayClassInfo();
     classIDToRemove = GetInputInt();
     classIndexToRemove = classIDToRemove -1;
        cout << "you have selected this class:\n";
        displayOneClass(classIndexToRemove);
        cout << "Please enter a Y to confirm\n";
        string userConfirm = GetInputString();
        char letterEntered = userConfirm[0];
        if (toupper(letterEntered) == 'Y')
        {
            userHasSelectedClass = true;
        }
    }
    RemoveClassFromInternalstructure(classIndexToRemove);
    cout << "Class has been removed\n";
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
            removeAClass();
            break;
            
        case 9:
            displayClassInfo();
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

void estimateGPA()
{
    float newGPANumerator = numberPastCredits * pastGPA;
    float newCredits = numberPastCredits;
    for (int i=0;i<numberOfClasses;i++)
    {
        newGPANumerator += gradePointValues[i] * classCredits[i];
        newCredits += classCredits[i];
    }
    float retVal = newGPANumerator / newCredits;
    cout << "Estimated GPA based on current classes is: " << retVal;
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
        case 4:
            estimateGPA();
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


/*
 Test Input
 
 3
 1
 Algebra
 AP
 1
 B+
 1
 Physics
 Normal
 1
 A-
 1
 Gym
 DualCredit
 1
 C+
 9
 2
 2
 Y
 9
 0
 9
 0
 
 Expected Output
 Hello, World!
 
 
 **********
 ** Menu **
 **********
 1 - Set the number of credits taken
 2 - Set current GPA
 3 - Current Class Maintenance
 9 - Show all entries
 0 - Exit Application
 
 
 ****************
 ** Class Menu **
 ****************
 1 - Add a class
 2 - Remove a class
 9 - Show all classes
 0 - Exit Class Maintenance
 
 You will be prompted for the name, class weight, credits, and estimated grade for class
 
 
 
 Step 1 of 4
 Enter the name of the class.
 
 
 Step 2 of 4
 Enter the weight type of the class (Normal, AP, EarlyCollege, DualCredit.
 
 
 Step 3 of 4
 Enter the number of credits this class is worth.
 
 
 Step 4 of 4
 Enter the letter grade for this class
 Class has been added
 ClassID    Class Name    Credits    Weight    Grade
 *******    **********    *******    ******    *****
 1    Algebra        1    AP    B+
 
 
 ****************
 ** Class Menu **
 ****************
 1 - Add a class
 2 - Remove a class
 9 - Show all classes
 0 - Exit Class Maintenance
 
 You will be prompted for the name, class weight, credits, and estimated grade for class
 
 
 
 Step 1 of 4
 Enter the name of the class.
 
 
 Step 2 of 4
 Enter the weight type of the class (Normal, AP, EarlyCollege, DualCredit.
 
 
 Step 3 of 4
 Enter the number of credits this class is worth.
 
 
 Step 4 of 4
 Enter the letter grade for this class
 Class has been added
 ClassID    Class Name    Credits    Weight    Grade
 *******    **********    *******    ******    *****
 2    Physics        1    Normal    A-
 
 
 ****************
 ** Class Menu **
 ****************
 1 - Add a class
 2 - Remove a class
 9 - Show all classes
 0 - Exit Class Maintenance
 
 You will be prompted for the name, class weight, credits, and estimated grade for class
 
 
 
 Step 1 of 4
 Enter the name of the class.
 
 
 Step 2 of 4
 Enter the weight type of the class (Normal, AP, EarlyCollege, DualCredit.
 
 
 Step 3 of 4
 Enter the number of credits this class is worth.
 
 
 Step 4 of 4
 Enter the letter grade for this class
 Class has been added
 ClassID    Class Name    Credits    Weight    Grade
 *******    **********    *******    ******    *****
 3    Gym        1    DualCredit    C+
 
 
 ****************
 ** Class Menu **
 ****************
 1 - Add a class
 2 - Remove a class
 9 - Show all classes
 0 - Exit Class Maintenance
 Here is all of the class info
 ClassID    Class Name    Credits    Weight    Grade
 *******    **********    *******    ******    *****
 1    Algebra        1    AP    B+
 2    Physics        1    Normal    A-
 3    Gym        1    DualCredit    C+
 
 
 ****************
 ** Class Menu **
 ****************
 1 - Add a class
 2 - Remove a class
 9 - Show all classes
 0 - Exit Class Maintenance
 Here is the list of classes. Please enter the ClassID of the class to be removed.
 Here is all of the class info
 ClassID    Class Name    Credits    Weight    Grade
 *******    **********    *******    ******    *****
 1    Algebra        1    AP    B+
 2    Physics        1    Normal    A-
 3    Gym        1    DualCredit    C+
 you have selected this class:
 2    Physics        1    Normal    A-
 Please enter a Y to confirm
 Class has been removed
 
 
 ****************
 ** Class Menu **
 ****************
 1 - Add a class
 2 - Remove a class
 9 - Show all classes
 0 - Exit Class Maintenance
 Here is all of the class info
 ClassID    Class Name    Credits    Weight    Grade
 *******    **********    *******    ******    *****
 1    Algebra        1    AP    B+
 2    Gym        1    DualCredit    C+
 
 
 ****************
 ** Class Menu **
 ****************
 1 - Add a class
 2 - Remove a class
 9 - Show all classes
 0 - Exit Class Maintenance
 
 
 **********
 ** Menu **
 **********
 1 - Set the number of credits taken
 2 - Set current GPA
 3 - Current Class Maintenance
 9 - Show all entries
 0 - Exit Application
 
 
 Here are all of the values
 0: Number of credits earned in the past.
 0: current GPA.
 Here is all of the class info
 ClassID    Class Name    Credits    Weight    Grade
 *******    **********    *******    ******    *****
 1    Algebra        1    AP    B+
 2    Gym        1    DualCredit    C+
 
 
 **********
 ** Menu **
 **********
 1 - Set the number of credits taken
 2 - Set current GPA
 3 - Current Class Maintenance
 9 - Show all entries
 0 - Exit Application
*/
