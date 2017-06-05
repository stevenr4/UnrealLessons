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

using FString = std::string;
using int32 = int;

// Create a new structure for a complicated return data
struct FBullCowCount {
    int32 Bull = 0;
    int32 Cow = 0;
};


class FBullCowGame {

public:
    // Constructor, called when the class is instantiated
    FBullCowGame();
    
    // Getter Functions
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    
    // Checks if the game is won
    bool IsGameWon() const;
    
    // Resets the game back to the starting state
    void Reset();
    
    // Checks if a given string is valid
    bool CheckGuessValidity(FString);
    
    // Assumes a valid guess
    FBullCowCount SubmitGuess(FString);
    
    
// Private variables
private:
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
};

#endif /* FBullCowGame_hpp */
