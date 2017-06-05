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

class FBullCowGame {

public:
    // Constructor, called when the class is instantiated
    FBullCowGame();
    
    // Getter Functions
    int GetMaxTries() const;
    int GetCurrentTry() const;
    
    // Checks if the game is won
    bool IsGameWon() const;
    
    // Resets the game back to the starting state
    void Reset();
    
    // Checks if a given string is valid
    bool CheckGuessValidity(std::string);
    
    
// Private variables
private:
    int MyCurrentTry;
    int MyMaxTries;
};

#endif /* FBullCowGame_hpp */
