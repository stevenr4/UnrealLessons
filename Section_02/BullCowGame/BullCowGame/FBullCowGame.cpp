//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Steven Rogers on 6/4/17.
//  Copyright © 2017 Steven Rogers. All rights reserved.
//

#include "FBullCowGame.hpp"

using int32 = int;

// Constructor, runs when new instance is created
FBullCowGame::FBullCowGame() { Reset(); }

// Getter functions
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

// Resets the variables of the class back to default
void FBullCowGame::Reset()
{
    
    MyCurrentTry = 1;
    MyMaxTries = 5;
    MyHiddenWord = "plate";
    return;
}


// Checks if the game has been won
bool FBullCowGame::IsGameWon() const
{
    return true;
}

// Makes sure that the guess is valid
bool FBullCowGame::CheckGuessValidity(FString) {
    return true;
}

// Assumes a valid guess
FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
    
    // Increment the Turn number
    MyCurrentTry++;
    
    // Setup a return structure (struct)
    FBullCowCount BCCount;
    BCCount.Bull = 0;
    BCCount.Cow = 0;
    
    // Get the length of the hidden word;
    int32 HiddenWordLength = MyHiddenWord.length();
    
    // Loop through all the letters in the hidden word
    for (int32 i = 0; i < HiddenWordLength; i++) {
        
        // Loop through all the letters in the guess
        for (int32 j = 0; j < HiddenWordLength; j++) {
            
            // If the letter matches...
            if (MyHiddenWord[i] == Guess[j]) {
                
                // Find out if the letter is in the correct spot
                if (j == i) {
                    BCCount.Bull++;
                } else {
                    BCCount.Cow++;
                }
                
                break;
            }
        }
    }
    
    
    
    return BCCount;
}
