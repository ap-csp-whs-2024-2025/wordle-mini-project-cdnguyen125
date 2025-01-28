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
    int random_num = rand() % 10;
    int counter = 0;
    std::vector<int> secret = {};
    while (counter < 4)
    {
        secret.push_back(random_num);
        counter = counter + 1;
    }
    return {secret};    // replace this with your code
}

std::vector<std::string> getHint(std::vector<int> secret, std::vector<int> guess) {
    int secretIndex = 1;
    int guessIndex = 1;
    while (secret != guess)
    {
        
    }
    return {"X", "X", "X", "X"};    // replace this with your code
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
    
    while (!winGame(secret_code, user_guess))    // while you have not won the game yet
    {
        std::cout << "\nEnter your guess: ";
        hint = {};    // reset the hint for the next guess
        for (int counter = 0; counter < secret_code_length; counter = counter + 1)
        {
            int input;
            std::cin >> input;
            guess.push_back(input);    // can also do append(guess, input);
        }

        hint = getHint(secret_code, user_guess);
        display(hint);
        num_guesses = num_guesses + 1;
    }

    std::cout << "Congrats!  You guessed the code!  It took you " << num_guesses << " tries.\n";
    return 0;
}
