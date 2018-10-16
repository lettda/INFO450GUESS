//
//  main.cpp
//  Find_the_gold
//
//  Created by David Lett on 10/15/18.
//  Copyright © 2018 David Lett. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

//Declare global variables
const int ROWS = 8; //initialize number of rows
const int COLS = 8; //initialize number of columns
int guesses = 5; //Holds number of palyer's guesses
char answer;

//Initialize/Declare functions to be used
int buildGrid(char grid[COLS][ROWS]);
int displayGrid(char grid[COLS][ROWS]);
int seedGrid(char grid[COLS][ROWS]);
int explainRules();
int gameLogic(char grid[COLS][ROWS]);
//Entry point
int main()
{
    
    cout << "Would you like to play a game?" << endl;
    cin >> answer;
    
    char grid[ROWS][COLS]; //Declare game grid 8x8
    
    do {                    //Only start the game when the user selects yes
        buildGrid(grid);
        seedGrid(grid);
        explainRules();
        displayGrid(grid);
        gameLogic(grid);
        
    } while (answer == 'Y' || answer =='y');
    
    if (answer == 'N' || answer == 'n') {   //End game if user choooses not to continue
        cout << "How boring...Maybe next time" << endl;
    }
    return 0;
}

int buildGrid (char grid[COLS][ROWS]) { //Build initial grid
    
    for (int row = 0; row < ROWS; row++) {
        
        for (int col = 0; col < COLS; col++) { //Creare 8x8 grid of ?'s
            grid[col][row] = '?';
        }
    }

    return 0;
}
int displayGrid (char grid[COLS][ROWS]) { //Displays grid
    int row, col;
    
    for (col = 0; col < COLS; col++)
    {
        cout << ""<< setw(3) << col + 1;
    }
    cout << endl;
    cout << "  " << "------------------------" << endl;
    //print  multiplication table
    for (row = 0; row < ROWS; row++)
    {
        cout << " " << row + 1 << "|";
        // prints columns for my row
        for (col = 0; col < COLS; col++)
        {
            cout << setw(3) << grid[row][col];
        }
        cout << endl;
    }
    cout << "  " << "------------------------" << endl;
    return 0;
}
int seedGrid(char grid[COLS][ROWS]){ //Seed the grid with randomly placed B's and G's for bombs and gold
    
    srand(time(NULL)); //Enable true number randomization

    int goldCounter = 0;
    int bombCounter = 0;
    int xCord, yCord;
    
    do {                            //Seed grid with gold
        xCord = rand() % ROWS; //Random generated x coordinate
        yCord = rand() % COLS; //Random generated y coordinate
        
        if (grid[xCord][yCord] != 'G') { //If the position in the grid does not contain a G make it one
            grid[xCord][yCord] = 'G';
            goldCounter++;               //add one to counter
        }
    } while (goldCounter < 5); //Stop adding gold after 5 have been added
    
    do {                           //Seed grid with bombs
        xCord = rand() % ROWS;
        yCord = rand() % COLS;
        
        if (grid[xCord][yCord] != 'G' && grid[xCord][yCord] != 'B') { //If the position contains neither gold nor a bomb, add a Bomb
            grid[xCord][yCord] = 'B';
            bombCounter++;              //add one to counter
        }
    } while (bombCounter < 1); //Stop seeding after creating one bomb
    
     return 0;
}

int explainRules() {
    cout<< " ********************* " << endl;
    cout << "                       " << endl;
    cout << "      Find The Gold!   "  << endl;
    cout << "                       " << endl;
    cout <<  "You will have 5 chances" << endl;
    cout << "Input 2 grid coordinates" << endl;
    cout << "Find all 5 pieces of gold to win!" << endl;
    cout <<  "Find the bomb...and GAME OVER!" << endl;
    cout << "                       "  << endl;
    cout << "      Good Luck!       " << endl;
    cout << "                       " << endl;
    cout << " ********************* "  << endl;
    cout << endl;

    return 0;
}

int gameLogic(char grid[COLS][ROWS]) {
    int points = 0;
    int gameCol, gameRow;
    
    do
    {
        // Ask for coordinate entry from user
        cout << "Enter an X coordinate between 1 and 8: " << endl;
        cin >> gameRow;
        
        //While the input entered is not an integer, prompt the user to enter an integer.
        while (!cin || gameRow > 8 || gameRow < 1)
        {
            cout << "Please enter an X coordinate between 1 and 8: ";
            cin.clear();
            cin.ignore();
            cin >> gameRow;
        }
        gameRow--; //Subtract 1, arrays start at 0, user entered 1,1 should look at 0,0 in the array
        
        cout << endl;
        cout << "Enter a Y coordinate between 1 and 8: ";
        cin >> gameCol;
        
        //While the input entered is not an integer, prompt the user to enter an integer.
        while (!cin || gameCol > 8 || gameCol < 1)
        {
            cout << "Please enter an integer that is between 1 and 8: ";
            cin.clear();
            cin.ignore();
            cin >> gameCol;
        }
        
        gameCol--; // Subtract 1 so it matches array display ... since arrays start at 0, user would have had to guess coordinate (0,0) when they were trying to find gold at (1,1) so we fix this here.
        cout << endl;
        
        if (grid[gameCol][gameRow] == 'G') {
            cout << "You Found Gold!" << endl;
            cout << "You have have " << guesses << " guesses left!";
            grid[gameRow][gameCol] = 'F';
            points += 1; // Give user a point if they find gold!
            cout << endl;
            cout << endl;
            continue; // Go back to beginning of loop
        } else if (grid[gameCol][gameRow] == 'B') {
            cout << "BOOOOOOOM!!!. You found a bomb" << endl;
            cout << "GAME OVER!" << endl;
            break; //End game
        } else {
            cout << "No gold there. Guess again" << endl;
            guesses--;
            cout << "You have have " << guesses << " guesses left!";
        }
    }
    while (guesses == 0);
    
    cout << "You've earned " << points << " points!" << endl;
    cout << "Better luck next time!" << endl;
    
    return 0;
}
