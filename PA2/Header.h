//
// Created by seal on 3/21/21.
//

#ifndef PA2_HEADER_H
#define PA2_HEADER_H
using namespace std;
#include<iostream>
#include <algorithm>
#include <random>
#include<cmath>
// function to shuffle array
//Code block taken from geeks for geeks
void shuffle_array(int arr[], int n)
{

    // To obtain a time-based seed
    unsigned seed = 0;

    // Shuffling our array
    shuffle(arr, arr + n,
            default_random_engine(seed));


}
#endif //PA2_HEADER_H
