#include "..\head.h"

template <unsigned int n> struct sum_solution {
    enum value {N = sum_solution<n - 1>::N + n};
};

template<>struct  sum_solution<1>
{
    enum value {n = 1};
};
