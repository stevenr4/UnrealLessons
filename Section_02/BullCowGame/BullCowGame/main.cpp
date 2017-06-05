//
//  main.cpp
//  BullCowGame
//
//  Created by Steven Rogers on 6/2/17.
//  Copyright © 2017 Steven Rogers. All rights reserved.
//

#include <iostream>
#include <string>

#include "FBullCowGame.hpp"


void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
std::string GetGuess(int Number);


// TESTING GIT'S DIFFERENCES


// The main function
int main(int argc, const char * argv[])
{
    // Print out the introduction
    PrintIntro();
    
    // Loop through the game multiple times
    do {
        
        // Play the core of the game
        PlayGame();
        
        
        // TODO: Summarize game
        
        
    } while (AskToPlayAgain());
    
    std::cout << "Thanks for playing!";
    std::cout << std::endl;
    return 0;
}

// Prints the game introduction
void PrintIntro()
{
    
    // Define the constant word length
    constexpr int WORD_LENGTH = 5;
    
    // Output the title message
    std::cout << "Welcome to Bulls and Cows!\n";
    std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
}

// Runs through the core of the game
void PlayGame()
{
    FBullCowGame BCGame;
    int MaxTries = BCGame.GetMaxTries();
    std::cout << "TRIES!! : " << MaxTries << std::endl;
    
    // Loop for the number of turns
    for (int Count = 0; Count < MaxTries; Count++)
    {
        
        // TODO: Make sure that the guess is valid
        std::string Guess = GetGuess(Count);
        
        // TODO: Send the guess to the game and display the bulls and cows
        
        std::cout << "Your guess was " << Guess << std::endl;
    }
}

// Asks the user if they want to play again.
bool AskToPlayAgain()
{
    std::cout << "Do you want to play again? (y/n) \n> ";
    std::string Response = "";
    getline(std::cin, Response);
    return (Response[0] == 'y' || Response[0] == 'Y');
}

// Gets the guess from the user.
std::string GetGuess(int GuessNumber) {
    std::cout << "Try " << (GuessNumber + 1) << ".\nEnter your guess: \n> ";

    
    // Get a guess from the player
    std::string Guess = "";
    getline(std::cin, Guess);
    
    // Return The Guess
    return Guess;
}









