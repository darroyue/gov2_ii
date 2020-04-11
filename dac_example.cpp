#include <iostream>
#include <sdsl/vectors.hpp>
#include <sdsl/coder.hpp>

#include "randomer.hpp"

using namespace sdsl;
using namespace std;

#define N 1000


int main()
{
    int_vector<> G(N);

    Randomer randomer{0, 9};  // random number generator for the interval [0, 9]

    // gaps must be estored in G first

    for (int i = 0; i < N; i++ )
        G[i] = randomer();

    dac_vector<> dv(G);  // encodes G using dac 

    for (int i = 0; i < N; i++)
        cout << dv[i] << endl;

    cout << endl << "Space usage: " << (float) size_in_bytes(dv)*8 / N << " bits per element" << endl;
    return 0;
}
