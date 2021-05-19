#include <iostream>
#include <cstring>
#include <ctime>
#include <vector>
#include <algorithm>
#include "GuessNumber.cpp"

#define VERSION "0.0.3"

#define BEGINNER 3
#define VETERAN 4
#define CHANCES 10


using namespace std;

short set_level(short);

int main()
{
    short num, level;
    short chances = CHANCES;

    cout << "please select a number of digits you'd like to guess (3 or 4): ";
    cin >> num;

    level = set_level(num);

    Game_host * host = new Game_host(level);
    // host->print_target(); // for debug

    Player * player = new Player();

    bool is_succeed;
    string result;

    while (chances > 0 && ((level == 4 && result != "4 A 0 B") || (level == 3 && result != "3 A 0 B")))
    {
        do
        {   
            cin.clear();
            cin.ignore(INT_MAX, '\n');

            is_succeed = false;

            cout << "please take a guess (" << chances << " chances left): ";

            vector<short> guess (level);

            if(level == BEGINNER)
            {
                cin >> guess[0] >> guess[1] >> guess[2]; 
            }
            else if(level == VETERAN)
            {
                cin >> guess[0] >> guess[1] >> guess[2] >> guess[3]; 
            }

            is_succeed = player->set_guess(guess);

            if(!is_succeed)
            {
                cout << "input error!" << endl;
            }
        
        } while (!is_succeed);

        result = *player == *host;
        string show = "";
        auto cur_guess = player->get_guess();

        for(auto digit: cur_guess)
        {
            show = show + to_string(digit) + " ";
        }
        show = show + ">> " + result;
        
        cout << show << endl;

        chances--;
    }

    cout << endl;

    if((level == 4 && result == "4 A 0 B") || (level == 3 && result == "3 A 0 B"))
    {
        result = "You win!";
    }
    else
    {
        result = "You lose!";
    }
    
    cout << result << endl << endl;

    delete host;
    delete player;

    system("PAUSE");
    return 0;
}

short set_level(short num)
{
    switch(num)
    {
        case 3:
            return BEGINNER;
            break;
        case 4:
            return VETERAN;
            break;
        default:
            cout << "Illegal input.";
    }
    return -1;
}

