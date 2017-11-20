#include "rangen.h"

#include <random>

static std::random_device rd;  //Will be used to obtain a seed for the random number engine
static std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
static std::uniform_real_distribution<> dis(0.0, 1.0);

float drand48()
{
    return dis(gen);
}
