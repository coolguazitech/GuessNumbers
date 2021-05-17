#include "GuessNumber.h"
#include <algorithm>
#include <iostream>
#include <random>
#include <chrono>
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
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(all_digits.begin(), all_digits.end(), default_random_engine(seed));
    target.insert(target.end(), all_digits.begin(), all_digits.begin() + 4);
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

// bool operator==(const Game_host & host, const Player & player)
// {
//     if(player.get_is_first_guess())
//     {
//         return host.get_target() == player.get_guess();
//     }
//     return false;
// }

// bool operator==(const Player & player, const Game_host & host)
// {
//     if(player.get_is_first_guess())
//     {
//         return player.get_guess() == host.get_target();
//     } 
//     return false;
// }