//
//  main.cpp
//  Find_the_gold
//
//  Created by David Lett on 10/15/18.
//  Copyright © 2018 David Lett. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

//Declare global variables
const int ROWS = 8; //initialize number of rows
const int COLS = 8; //initialize number of columns
int guesses = 5; //Holds number of palyer's guesses



int main()
{

    char grid[ROWS][COLS];
    
    int buildGrid(char grid);
    void displayGrid(char grid);
    
}
int buildGrid (char grid[COLS][ROWS]) {
    
    for (int row = 0; row < ROWS; row++) {
        
        for (int col = 0; col < COLS; col++) {
            grid[col][row] = '?';
        }
    }

    return 0;
}
void displayGrid (char grid[COLS][ROWS]) {
    int row, col;
    
    //print  multiplication table
    for (row = 0; row < ROWS; row++)
    {
        // prints columns for my row
        for (col = 0; col < COLS; col++)
        {
            cout << setw(3) << grid[row][col];
            
        }
        cout << endl;
    }
}
