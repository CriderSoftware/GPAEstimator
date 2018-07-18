//
//  main.cpp
//  GPA Estimator
//
//  Created by John Crider on 7/17/18.
//  Copyright © 2018 John Crider. All rights reserved.
//

#include <iostream>

float numberPastCredits = 0;
float pastGPA = 0;

int numberOfClasses = 0;

std::string classNames[100];
float classCredits[100];
std::string gradesEarned[100];
float gradePointValues[100];

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
    std::cin >> numberPastCredits;
}

void showAllValues()
{
    std::cout << "\n\nHere are all of the values\n";
    std::cout << numberPastCredits << ": Number of credits earned in the past.\n";
    std::cout << pastGPA << ": current GPA.\n";
}

void getGPA()
{
    //Accept from stdin the GPA from the user.
    //inputs: none
    //returns: nothing
    std::cout << "\n\nPlease enter current GPA.\n";
    std::cin >> pastGPA;
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
            //addAClass();
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
        std::cin >> userChoice;
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
        std::cin >> userChoice;
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


