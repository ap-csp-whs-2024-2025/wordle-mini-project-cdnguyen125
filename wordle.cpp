/**
* listhelpers.hpp has been provided by the instructor as starter code
* contains the following procedures to work with lists:
* display, append, insert, remove, length
*/
#include "listhelpers.hpp"

#include <cstdlib>   // srand, rand
#include <ctime>     // time
#include <iostream>  // std::cin, std::cout
#include <string>    // std::string, std::getline
#include <vector>    // std::vector

std::vector<int> createSecret() {
    srand(time(0)); 
    int counter = 0;
    std::vector<int> secret = {};
    while (counter < 4)
    {
        int random_num = rand() % 10;
        secret.push_back(random_num);
        counter = counter + 1;
    }
    return {secret};    // replace this with your code
}

std::vector<std::string> getHint(std::vector<int> secret, std::vector<int> guess) {
    int secretIndex = 0;
    int guessIndex = 0;
    std::vector<std::string> hint = {};
    while (secret != guess)
    {
        while (guessIndex < 4)
        {
            if (guess[guessIndex] == secret[secretIndex])
            {
                hint.push_back("O");
            }
            else
            {
                hint.push_back("X");
            }
            secretIndex = secretIndex + 1;
            guessIndex = guessIndex + 1;
        }
    }
    return {hint};    // replace this with your code
}

bool winGame(std::vector<int> secret, std::vector<int> guess) {

    
    if (guess == secret)
    {
        return true;
    }
    return false;    // replace this with your code
}

int main()
{
     srand(time(0)); 
     int random_num = rand() % 10;
    
    
    std::vector<int> secret_code = createSecret();
    std::vector<int> user_guess = {};
    std::vector<std::string> hint = {};    // an empty list

    int secret_code_length = 4;
    int num_guesses = 0;

    std::cout << "Welcome to Number Wordle!\n";
    display(secret_code);
    
    while (!winGame(secret_code, user_guess))    // while you have not won the game yet
    {
        std::cout << "\nEnter your guess: ";
        user_guess.clear();
        hint = {};    // reset the hint for the next guess
        int counter = 0;
        std::cout << "about to enter while loop" << std::endl;
        while (counter < secret_code_length)
        {
         int input;
         std::cin >> input;
         user_guess.push_back(input);
         counter = counter + 1;
         // ONLY WHILE the guess is immediately correct can you exit the loop.... so weird
        }
        
        display(user_guess);
        std::cout << "Test";
        std::cout << "Exited input loop" << std::endl;
        
       
        hint = getHint(secret_code, user_guess);
        display(hint);
        num_guesses = num_guesses + 1;
    }
    std::cout << "Congrats!  You guessed the code!  It took you " << num_guesses << " tries.\n";
    return 0;
}
