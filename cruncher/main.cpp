#include <iostream>

#include "engine.h"
#include "standard_definitions.h"

using namespace std;

int main()
{
    int rounds = 100;
    unsigned int seed = 10;

    standard::RandomSafeAgent_S a0(seed);
    standard::SafeClockwiseBias_S a1(base::Action::UP);

    standard::Engine engine(&a0, &a1);

    for(int i = 0; i < rounds; ++i){
        engine.ResetRandom();
        engine.PerformRound();
    }

    cout << "A0 wins: " << engine.A0Wins() << endl;
    cout << "A1 wins: " << engine.A1Wins() << endl;
    cout << "Draws: " << engine.Draws() << endl;
    return 0;
}
