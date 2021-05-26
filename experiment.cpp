#include <iostream>
#include <cstring>
#include <ctime>
#include <vector>
#include <algorithm>
#include "GuessNumber.cpp"

#define VERSION "0.0.3"

using namespace std;

float compute_mean(short[]);

int main()
{
    short level = 4, count = 0, num_trials, trials_count, ratio;
    float inference_time, mean;
    string result = ""; 
    clock_t begin_time, end_time;
    bool reach_target = false;
    short stat[15];
    memset(stat, 0, 15 * sizeof(short));

    cout << "How many trials will be run in total (increment by 1000 recommended, max 65000): ";
    cin >> num_trials;
    trials_count = num_trials;

    cout << endl << "Inferring ..." << endl << endl;

    begin_time = clock();

    while (trials_count > 0)
    {
        Game_host * host = new Game_host(level);
        Solver * solver = new Solver(level);
        reach_target = false;
        count = 0;
        
        while (!reach_target)
        {
            count++;
            solver->take_guess();
            result = *solver == *host;
            if (result == "4 A 0 B")
            {
                reach_target = true;
            }
            else
            {
                solver->update(result);
            }
        }
        if (count <= 15)
        {
            stat[count - 1]++;
        }

        delete host;
        delete solver;
        trials_count--;
    }
    
    end_time = clock();
    inference_time = (float)(end_time - begin_time) / CLOCKS_PER_SEC;

    printf("Done in %.1f s. The statistics has been gathered and resulted as below:\n\n", inference_time);

    cout << "Amongst overall " << num_trials << " trials, " << endl;

    for (int i = 0; i < 15; i++)
    {
        ratio = stat[i] * 100.0f / num_trials;
        printf("There are [ %4d (%3d %) ] trials going through [ %2d ] guess(es).\n", stat[i], ratio, i + 1);
    }

    cout << endl;

    mean = compute_mean(stat);

    printf("Furthermore, the mean equals to %.1f (times).\n\n", mean);

    std::system("PAUSE");
    return 0;
}

float compute_mean(short stat[])
{
    float sum = 0, total = 0, mean;

    for (int i = 0; i < 15; i++)
    {
        total += stat[i] * (i + 1);
        sum += stat[i];
    }

    return total / sum;
}