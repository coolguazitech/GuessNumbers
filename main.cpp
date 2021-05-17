#include <iostream>
#include <cstring>
#include <ctime>
#include <vector>
#include <algorithm>
#include "GuessNumber.cpp"

#define BEGINNER 3
#define VETERAN 4
#define VERSION "0.0.1"

using namespace std;

short set_level(short);

int main()
{
    short num;
    cout << "please select how many number of digits you'd like to guess (3 or 4): ";
    cin >> num;

    short level = set_level(num);

    Game_host * host = new Game_host(level);
    host->print_target(); // for debug

    Player * player = new Player();

    bool is_succeed = false;
    do
    {
        cout << "please take a guess: ";
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
        if(is_succeed == false)
        {
            cout << "input error!" << endl;
        }
    } while (is_succeed == false);
    

    delete host;
    delete player;

    // while(index < 4)
    // {
    //     int r = rand() % 10;
    //     int count = 0;
    //     for(int j = 0 ; j < index ; j++)
    //     {
    //         if(answer[j] == r)
    //         {
    //             break;
    //         }
    //         else
    //         {
    //             count++;
    //         }
    //     }
    //     if(count == index)
    //     {
    //         answer[index] = r;
    //         index++;
    //     }
    // }

    // // print_answer(answer);

    // int guess_count = 0;

    // while(true)
    // {
    //     if(guess_count >= 10)
    //     {
    //         cout << "You have no chances so lose the game!";
    //         break;
    //     }

    //     cout << "Please guess 4 distinct digits: " << "(" << 10 - guess_count << " chances)" << endl;

    //     vector<short> guess(4);

    //     // cout >> guess[0] >> guess[1] >> guess[2] >> guess[3];

    //     guess_count++;

    //     int A = 0, B = 0;
        
    //     if(validate_digits(guess))
    //     {
    //         for(int i = 0 ; i < NUMBER ; i++)
    //         {
    //             for(int j = 0 ; j < NUMBER ; j++)
    //             {
    //                 if(guess[i] == answer[j])
    //                 {
    //                     if(i == j)
    //                     {
    //                         A++;
    //                     }
    //                     else
    //                     {
    //                         B++;
    //                     }
    //                 }
    //             }
    //         }
    //         if(A < 4)
    //         {
    //             cout << A << 'A' << B << 'B' << endl;
    //         }
    //         else 
    //         {
    //             cout << "You win!";
    //             break;
    //         }
    //     }
    //     else
    //     {
    //         cout << "input error" << endl;
    //         guess_count--;
    //     }
    // }
    getchar();
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

