#include "GuessNumber.h"
#include <algorithm>
#include <iostream>
#include <random>
#include <chrono>

Game::Game()
{
    setLevel(3);
    m_answer = _generate_target_digtis(m_level);
}

Game::Game(short level) : m_level(level)
{
    m_answer = _generate_target_digtis(m_level);
}

vector<short> Game::_generate_target_digtis(short level)
{
    vector<short> allDigits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<short> target;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(allDigits.begin(), allDigits.end(), default_random_engine(seed));
    for(int i = 0; i < level; i++)
    {
        target.push_back(allDigits[i]);
    }
    return target;
}

void Game::print_answer(void)
{
    for(int i = 0; i < getLevel(); i++)
    {
        cout << m_answer[i];
    }
    cout << endl;
}

void Game::remake_target(void)
{
    m_answer = _generate_target_digtis(m_level);    
}