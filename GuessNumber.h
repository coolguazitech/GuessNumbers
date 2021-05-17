#include <vector>

using namespace std;

class Game_host
{
    private:
        short m_level; // trial's level
        vector<short> m_target; // trial's target
        vector<short> generate_target_digtis(short); // generate a trial's target

    public:
        Game_host();
        Game_host(short);
        void remake_target(void); // remake a new trial's target 
        void change_level(int); // change the level at which the trial is
        const vector<short> & get_target(void) const {return m_target;} // get target
        void print_target(void); // print the digits of answer
        short get_level(void){return m_level;} // get level
        void set_level(int level){m_level = level;} // set level
};

class Player
{
    private:
        vector<short> m_guess; // the taken guess
        bool is_first_guess = false; // check if first guess is taken
        bool validate_digits(const vector<short>&); // validate if digits are legal

    public:
        bool set_guess(const vector<short> &); // set guess, return true if succeed
        const vector<short> & get_guess(void) const {return m_guess;} // get guess
        bool get_is_first_guess(void) const {return is_first_guess;} // get is_first_guess
        void set_is_first_guess(bool flag){is_first_guess = flag;} // set is_first_guess
        friend bool operator==(const Player &, const Game_host &); // compare Player's guess to Game_host's target 
        friend bool operator==(const Game_host &, const Player &); // compare Game_host's target to Player's guess
};