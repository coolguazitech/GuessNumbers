#include "GuessNumber.h"
#include <algorithm>
#include <iostream>
#include <random>
#include <set>

Game_host::Game_host()
{
    set_level(3);
    m_target = generate_target_digtis(m_level);
}

Game_host::Game_host(short level) : m_level(level)
{
    m_target = generate_target_digtis(m_level);
}

vector<short> Game_host::generate_target_digtis(short level)
{
    vector<short> all_digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<short> target;
    shuffle(all_digits.begin(), all_digits.end(), default_random_engine(time(0)));
    target.assign(all_digits.begin(), all_digits.begin() + level);
    return target;
}

void Game_host::print_target(void)
{
    for(int i = 0; i < get_level(); i++)
    {
        cout << m_target[i];
    }
    cout << endl;
}

void Game_host::remake_target(void)
{
    m_target = generate_target_digtis(m_level);    
}


bool Player::validate_digits(const vector<short> & digits)
{
    set<short> cmp_digits (digits.begin(), digits.end());
    return cmp_digits.size() == digits.size();
}

bool Player::set_guess(const vector<short> & guess)
{
    if(validate_digits(guess))
    {
        m_guess = guess;
        set_is_first_guess(true);
        return true;
    }
    return false;
}

string operator==(const Game_host & host, const Player & player)
{
    auto target = host.get_target();
    auto guess = player.get_guess();
    int A = 0, B = 0, size = target.size();
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(guess[i] == target[j])
            {
                if(i == j)
                {
                    A++;
                    break;
                }
                else
                {
                    B++;
                    break;
                }
            }
        }
    }
    string result = to_string(A) + " A " + to_string(B) + " B ";
    return result;

}

string operator==(const Player & player, const Game_host & host)
{
    auto target = host.get_target();
    auto guess = player.get_guess();
    int A = 0, B = 0, size = target.size();
    
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(guess[i] == target[j])
            {
                if(i == j)
                {
                    A++;
                    break;
                }
                else
                {
                    B++;
                    break;
                }
            }
        }
    }
    string result = to_string(A) + " A " + to_string(B) + " B ";
    return result;
}