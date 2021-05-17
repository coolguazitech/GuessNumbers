#include <iostream>
#include <cstring>
#include <ctime>
#include <vector>
#include <algorithm>
#include "GuessNumber.cpp"

#define BEGINNER 3
#define VETERAN 4

using namespace std;

vector<char> generate_target_digtis(void);


int validate_digits(const vector<short>& digits)
{
    for(short digit : digits)
    {  
        if(digit > 9 && digit < 0)
        {
            return 0;
        }
    }

    for(vector<short>::const_iterator iter1 = digits.begin(); iter1 != digits.end() - 1; ++iter1)
    {
        for(vector<short>::const_iterator iter2 = digits.begin() + 1; iter2 != digits.end(); ++iter2)
        {
                if(*iter1 == *iter2) return 0;
        }
    }

    return 1;
}

// void print_answer (const short answer[])
// {
//     for(int i = 0 ; i < NUMBER ; i++)
//     {
//         cout << answer[i];
//     }
//     cout << endl;
// }



int main()
{
    Game * game = new Game(BEGINNER);

    game->print_answer();

    delete game;
    // srand(time(NULL));
    // char answer[4];
    // int r = rand() % 10;
    // answer[0] = r;
    // int index = 1;

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



