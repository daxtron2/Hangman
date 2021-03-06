// hangman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "hangman.h"
#include <iostream>
using namespace std;
int main()
{
    char toBeGuessed[50]{ "CLASSICAL" };//solution word
    char correct[50]{"_______\0"};//correctly guessed letters
    char incorrect[8]{};//incorrectly guessed letters
    
    cout << "Let's play Hangman!\nYour word has " << strlen(toBeGuessed) << " letters in it.\n\n";
    
    while (strlen(incorrect) <= 8)//while we still have guesses left
    {
        //print how many guesses we have left
        cout << 8 - strlen(incorrect) << " tries left." << endl;
        cout << "What letter do you guess next? ";
        char guess;
        cin >> guess;//get user guess
        guess = toupper(guess);
        cout << "Guess: " << guess << endl;

        bool wasCorrect = false;
        for (int i = 0; i < strlen(toBeGuessed); i++)//loop through the sol'n word
        {
            if (toBeGuessed[i] == guess)//if word contains the guessed character
            {
                correct[i] = guess;//add the guess to the correctly guessed letters
                wasCorrect = true;//it was a correct guess
            }
        }
        if (!wasCorrect)//if wrong guess
        {
            
            bool alreadyExists = false;
            for (int i = 0; i < strlen(incorrect); i++)//loop through incorrect guess
            {
                if (incorrect[i] == guess)//if already guessed
                {
                    alreadyExists = true;
                }
            }
            if (!alreadyExists)//if wasn't already guessed
            {
                //add to the end of incorrectly guessed letters, to preserve guess order
                incorrect[strlen(incorrect)] = guess;
            }
            else
            {
                //inform user they already guessed
                cout << "You've already guessed that letter!" << endl;
            }
        }
        //get number of incorrect guesses
        int numIncorrect = strlen(incorrect);
        //show the gallows based on how many
        ShowGallows(numIncorrect);

        cout << "Wrong Guesses: ";
        for (int i = 0; i < numIncorrect; i++)
        {
            //loop through and print out all their wrong guesses
            cout << incorrect[i];
        }
        cout << endl;
        //show the letters correctly guessed so far
        ShowSolved(toBeGuessed, correct);
        //if the correctly guessed letters is the same length as the word to be guessed
        //it must be the correct word, end game
        if (strcmp(correct,toBeGuessed) == 0) break;
    }
    if (strlen(incorrect) >= 8)//if 8 wrong guesses
    {//lose
        cout << "You ran out of guesses!\nGame Over!\n";
        return 0;
    }
    else
    {//win
        cout << "You won!\n";
    }

    return 0;
}

//draws gallows based on amount of wrong guesses
void ShowGallows(int guessLimit)
{
	switch (guessLimit)
	{
        case 0:
            cout << "_______\n"
                << "|\n"
                << "|\n"
                << "|\n"
                << "|\n"
                << "|\n"
                << "|\n";
            break;
        case 1: 
            cout << "_______\n"
                      << "|   |  \n"
                      << "|   0  \n"
                      << "|\n"
                      << "|\n"
                      << "|\n"
                      << "|\n";
            break;
        case 2:
            cout << "_______\n"
                      << "|   |  \n"
                      << "|   0  \n"
                      << "|   |  \n"
                      << "|      \n"
                      << "|\n"
                      << "|\n";
            break;
        case 3:
            cout << "_______\n"
                      << "|   |  \n"
                      << "|   0  \n"
                      << "|  /|  \n"
                      << "|      \n"
                      << "|\n"
                      << "|\n";
            break;
        case 4:
            cout << "_______\n"
                      << "|   |  \n"
                      << "|   0  \n"
                      << "|  /|\\ \n"
                      << "|      \n"
                      << "|\n"
                      << "|\n";
            break;
        case 5:
            cout << "_______\n"
                      << "|   |  \n"
                      << "|   0  \n"
                      << "|  /|\\ \n"
                      << "|   |  \n"
                      << "|   \n"
                      << "|\n";
            break;
        case 6:
            cout << "_______\n"
                      << "|   |  \n"
                      << "|   0  \n"
                      << "|  /|\\ \n"
                      << "|   |  \n"
                      << "|  /   \n"
                      << "|\n";
            break;
        case 7:
            cout << "_______\n"
                << "|   |  \n"
                << "|   0  \n"
                << "|  /|\\ \n"
                << "|   |  \n"
                << "|  / \\\n"
                << "|\n";
            break;
        
	}
}

//compares the guessed letters with the word to solve
//then prints out what letters have been correctly guessed in the right order
void ShowSolved(char word[], char guesses[])
{
    char correctLetters[50]{};
    cout << "Word to Solve: ";
    for (int i = 0; i < strlen(word); i++)
    {
        for (int j = 0; j < strlen(guesses); j++)
        {
            if (word[i] == guesses[j])
            {
                correctLetters[i] = word[i];
            }
        }
        if (correctLetters[i] != word[i])
        {
            correctLetters[i] = '-';
        }
    }
    cout << correctLetters << endl;
}