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

// To make code unreal friendly
using int32 = int;
using FText = std::string;

// Prototyping the main functions
void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
FText GetValidGuess();
void PrintGameSummary();

// Instantiate a new game
FBullCowGame BCGame;

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

    // Output the title message
    std::cout << "Welcome to Bulls and Cows!\n";
}

// Runs through the core of the game
void PlayGame()
{
    // Reset the game as it starts
    BCGame.Reset();
    
    // Output start of game text
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n";
    
    // Loop for the number of turns while the game is NOT won and there are still tries remaining
    while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= BCGame.GetMaxTries())
    {
        
        // TODO: Make sure that the guess is valid
        FText Guess = GetValidGuess();
        
        // Send the guess to the game
        FBullCowCount BCCount = BCGame.SubmitGuess(Guess);
        
        // Print out to the user the bulls and cows
        std::cout << "Bulls: " << BCCount.Bull << "\nCows: " << BCCount.Cow << "\n\n";
    }
    
    PrintGameSummary();
    
}

// Asks the user if they want to play again.
bool AskToPlayAgain()
{
    std::cout << "Do you want to play again? (y/n) \n> ";
    FText Response = "";
    getline(std::cin, Response);
    return (Response[0] == 'y' || Response[0] == 'Y');
}

// Loop continually until the user gets a valid guess
FText GetValidGuess() {
    
    // Initialize the Status
    EWordStatus Status;
    
    // Initialize the guess to send back to the user.
    FText Guess = "";
    
    do {
        
        // Print out to the user to enter a guess.
        std::cout << "\nTry " << BCGame.GetCurrentTry() << ".\nEnter your guess: \n> ";

        
        // Get a guess from the player
        getline(std::cin, Guess);
        
        // Check the status of the word
        Status = BCGame.CheckGuessValidity(Guess);
        
        // Print out the correct error message for the word
        switch (Status) {
            case EWordStatus::Not_Lowercase:
                std::cout << "The word must be all lowercase letters.\n";
                break;
            case EWordStatus::Not_Isogram:
                std::cout << "The word must be an 'Isogram' (No repeating letters)\n";
                break;
            case EWordStatus::Too_Short:
                std::cout << "The word is too short! It must be " << BCGame.GetHiddenWordLength() << " letters long.\n";
                break;
            case EWordStatus::Too_Long:
                std::cout << "The word is too long! It must be " << BCGame.GetHiddenWordLength() << " letters long.\n";
                break;
            default:
                break;
        }
    } while (Status != EWordStatus::OK);
    
    // Return The Guess
    return Guess;
}

void PrintGameSummary() {
    if (BCGame.IsGameWon()) {
        std::cout << "\n\nCongrats!\nYou Win!\nYou guessed the hidden word: " << BCGame.GetHiddenWord() << "!\n\n";
    } else {
        std::cout << "\n\nSorry!\nYou were unable to guess the hidden word: " << BCGame.GetHiddenWord() << ".\n\n";
    }
}








