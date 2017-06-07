//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Steven Rogers on 6/4/17.
//  Copyright © 2017 Steven Rogers. All rights reserved.
//

#include <stdlib.h>
#include <map>
#define TMap std::map // To make code Unreal friendly

#include "FBullCowGame.hpp"

// To make code Unreal friendly
using int32 = int;

// Constructor, runs when new instance is created
FBullCowGame::FBullCowGame() { Reset(); }

// Getter functions
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
FString FBullCowGame::GetHiddenWord() const { return MyHiddenWord; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return BHasWon; }

// Resets the variables of the class back to default
void FBullCowGame::Reset()
{
    // These words MUST be isograms (no duplicate same letters)
    FString WordList[9] = {
        "explain",
        "fated",
        "truck",
        "neat",
        "unite",
        "branch",
        "tenuous",
        "hum",
        "notice"
    };
    
    MyCurrentTry = 1;
    MyMaxTries = 5;
    MyHiddenWord = WordList[rand() % 9];
    BHasWon = false;
    return;
}

// Makes sure that the guess is valid
EWordStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
    int32 HiddenLength = MyHiddenWord.length();
    int32 GuessLength = Guess.length();
    
    // Check if the guess length is too short
    if (GuessLength < HiddenLength) {
        return EWordStatus::Too_Short;
        
    // Check if the guess length is too long
    } else if (GuessLength > HiddenLength) {
        return EWordStatus::Too_Long;
        
    // Check if the guess is all lowercase
    } else if (!IsLowercase(Guess)) {
        return EWordStatus::Not_Lowercase;
    
    // Check if the guess is an isogram
    } else if (!IsIsogram(Guess)) {
        return EWordStatus::Not_Isogram;
        
    }
    
    // None of the failed checks occured
    return EWordStatus::OK;
}

// Check if the guess is an isogram
bool FBullCowGame::IsIsogram(FString Guess) const {
    
    // Make a struct right here.
    TMap<char, bool> LetterSeen;
    
    // For all the letters of the guess
    for (auto Letter : Guess) {
        
        Letter = tolower(Letter);
        
        // If the letter is in the map
        if (LetterSeen[Letter]) {
            return false;
        }
        
        // The letter hasn't been seen at this point, so set it to true
        LetterSeen[Letter] = true;
        
    }
    return true;
}

// Check if the guess is all lowercase
bool FBullCowGame::IsLowercase(FString Guess) const {
    
    // For all the letters of the guess
    for (auto Letter : Guess) {
        
        // If the letter isn't
        if (!islower(Letter)) {
            return false;
        }
    }
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
    
    // Check for the win condition
    if (BCCount.Bull == HiddenWordLength) {
        BHasWon = true;
    }
    
    // Give back the complicated struct
    return BCCount;
}
