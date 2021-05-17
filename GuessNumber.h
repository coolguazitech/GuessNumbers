#include <vector>

using namespace std;

class Game
{
    private:
    short m_level;
    vector<short> m_answer;
    vector<short> _generate_target_digtis(short);

    public:
    Game();
    Game(short);
    void remake_target(void);
    void print_answer(void);
    short getLevel(void){return m_level;}
    void setLevel(int level){m_level = level;}
};