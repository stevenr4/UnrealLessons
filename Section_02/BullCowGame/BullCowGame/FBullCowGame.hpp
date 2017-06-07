//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Steven Rogers on 6/4/17.
//  Copyright © 2017 Steven Rogers. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <string>

// To make syntax Unreal friendly
using FString = std::string;
using int32 = int;

// Create a new structure for a complicated return data
struct FBullCowCount {
    int32 Bull = 0;
    int32 Cow = 0;
};

enum class EWordStatus {
    OK,
    Not_Isogram,
    Too_Long,
    Too_Short,
    Not_Lowercase,
};

class FBullCowGame {

public:
    // Constructor, called when the class is instantiated
    FBullCowGame();
    
    // Getter Functions
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    FString GetHiddenWord() const;
    int32 GetHiddenWordLength() const;
    
    // Checks if the game is won
    bool IsGameWon() const;
    
    // Resets the game back to the starting state
    void Reset();
    
    // Checks if a given string is valid
    EWordStatus CheckGuessValidity(FString) const;
    
    // Checks if a given string is valid
    bool IsIsogram(FString) const;
    
    // Checks if a given string is valid
    bool IsLowercase(FString) const;
    
    // Assumes a valid guess
    FBullCowCount SubmitGuess(FString);
    
    
// Private variables
private:
    // ALL SET IN THE Reset() METHOD!
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
    bool BHasWon;
};

#endif /* FBullCowGame_hpp */
