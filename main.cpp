#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>

int main()
{
    using namespace std;

    const vector<string> WORDS = {"GUESS", "HANGMAN", "ZOMG", "VAPORIZER"};
    const int MAX_GUESSES = 6;

    srand(time(0));

    const string THE_WORD = WORDS[rand() % WORDS.size()];

    string guessed_so_far(THE_WORD.size(), '-');
    string already_used;
    int wrong = 0;

    cout << "You have " << THE_WORD.size() << "guesses" << endl;

    while (guessed_so_far != THE_WORD && wrong < MAX_GUESSES)
    {
        cout << "\nYou have " << MAX_GUESSES - wrong << " incorrect guesses left\n";
        cout << "You have used: " << already_used << '\n';
        cout << "So far, the word is: " << guessed_so_far << '\n';

        char guess;
        bool first_try = true;
        do
        {
            if (first_try)
                first_try = false;
            else
                cout << "You've already guessed: " << guess << '\n';
            cout << "Enter your guess\n";
            cin >> guess;
            guess = toupper(guess);
        }
        while (already_used.find(guess) != string::npos);

        already_used += guess;

        if (THE_WORD.find(guess) != string::npos)
        {
            cout << "That's right!\n";
            for (unsigned i = 0; i < THE_WORD.length(); ++i)
            {
                if (THE_WORD[i] == guess)
                    guessed_so_far[i] = guess;
            }
        }
        else
        {
            cout << "Sorry, you guessed wrong\n";
            ++wrong;
        }

    }

    if (wrong >= MAX_GUESSES)
        cout << "You've used up all your guesses!" << endl;
    else
        cout << "You've guessed it right!" << endl;

    return 0;
}

