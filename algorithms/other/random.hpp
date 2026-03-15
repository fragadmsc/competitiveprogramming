#pragma once

#include <random>
#include <chrono>

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

/*gets a random integer in the interval [l, r]*/
long long get_rng(long long l, long long r) {
    std::uniform_int_distribution<long long> dist(l, r);
    return dist(rng);
}
