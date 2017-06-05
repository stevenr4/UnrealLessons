//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Steven Rogers on 6/4/17.
//  Copyright © 2017 Steven Rogers. All rights reserved.
//

#include "FBullCowGame.hpp"

// Constructor, runs when new instance is created
FBullCowGame::FBullCowGame() { Reset(); }

// Getter functions
int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

// Resets the variables of the class back to default
void FBullCowGame::Reset()
{
    
    MyCurrentTry = 1;
    MyMaxTries = 5;
    return;
}


bool FBullCowGame::IsGameWon() const
{
    return true;
}

bool FBullCowGame::CheckGuessValidity(std::string) {
    return true;
}

