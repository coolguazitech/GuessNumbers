#include "GuessNumber.h"
#include <algorithm>
#include <iostream>
#include <random>
#include <set>
#include <string>

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
    cout << "The answer is ";
    for(int i = 0; i < get_level(); i++)
    {
        cout << m_target[i];
    }
    cout << " with debugging." << endl;
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
        // set_is_first_guess(true);
        return true;
    }
    return false;
}

Solver::Solver(short level) : m_level(level)
{
    m_rest_of_choices = get_all_permutations(level);
}

Solver::Solver()
{
    m_rest_of_choices = get_all_permutations(4);
}

void Solver::take_guess(void)
{
    m_guess = m_rest_of_choices[0];
}

void Solver::update(string result)
{
    vector<short> & target = m_guess;
    vector<vector<short>> & choices = m_rest_of_choices;
    short t_A = stoi(result.substr(0, 1), nullptr), t_B = stoi(result.substr(4, 1), nullptr), size = target.size(), A = 0, B = 0;

    auto it = choices.begin();
    while(it != choices.end())
    {
        A = 0, B = 0;
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(target[i] == it->at(j))
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
        if(A != t_A || B != t_B || *it == target)
        {
            it = choices.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

const vector<vector<short>> Solver::get_all_permutations(short level)
{
    vector<short> all_digits {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, rest_of_digits, temp_permutation;
    vector<vector<short>> all_permutations;
    if(level == 3)
    {
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                for(int k = 0; k < 8; k++)
                {
                    rest_of_digits = all_digits;
                    temp_permutation.push_back(rest_of_digits[i]);
                    rest_of_digits.erase(rest_of_digits.begin() + i);
                    temp_permutation.push_back(rest_of_digits[j]);
                    rest_of_digits.erase(rest_of_digits.begin() + j);
                    temp_permutation.push_back(rest_of_digits[k]);
                    all_permutations.push_back(temp_permutation);
                    temp_permutation.clear();
                }
            }
        }
    }
    else
    {
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                for(int k = 0; k < 8; k++)
                {
                    for(int l = 0; l < 7; l++)
                    {
                        rest_of_digits = all_digits;
                        temp_permutation.push_back(rest_of_digits[i]);
                        rest_of_digits.erase(rest_of_digits.begin() + i);
                        temp_permutation.push_back(rest_of_digits[j]);
                        rest_of_digits.erase(rest_of_digits.begin() + j);
                        temp_permutation.push_back(rest_of_digits[k]);
                        rest_of_digits.erase(rest_of_digits.begin() + k);
                        temp_permutation.push_back(rest_of_digits[l]);
                        all_permutations.push_back(temp_permutation);
                        temp_permutation.clear(); 
                    }

                }
            }
        }
    }
    return all_permutations;
}


string operator==(const Game_host & host, const Player & player)
{
    auto target = host.get_target();
    auto guess = player.get_guess();
    short A = 0, B = 0, size = target.size();

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
    string result = to_string(A) + " A " + to_string(B) + " B";
    return result;

}

string operator==(const Player & player, const Game_host & host)
{
    auto target = host.get_target();
    auto guess = player.get_guess();
    short A = 0, B = 0, size = target.size();

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
    string result = to_string(A) + " A " + to_string(B) + " B";
    return result;
}

string operator==(const Game_host & host, const Solver & solver)
{
    auto target = host.get_target();
    auto guess = solver.get_guess();
    short A = 0, B = 0, size = target.size();

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
    string result = to_string(A) + " A " + to_string(B) + " B";
    return result;

}

string operator==(const Solver & solver, const Game_host & host)
{
    auto target = host.get_target();
    auto guess = solver.get_guess();
    short A = 0, B = 0, size = target.size();
    
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
    string result = to_string(A) + " A " + to_string(B) + " B";
    return result;
}