#ifndef SETTINGS_H
#define SETTINGS_H
#include <cmath>

const int N = 9;
const int M = 4;
const int N_SQRT = sqrt(N);
const int K = 26;//0...N*M
const int LOG_N = std::ceil(std::log2(N));
const int N_VAR = 144; // N * M * LOG_N
extern char var[N_VAR];

#endif
