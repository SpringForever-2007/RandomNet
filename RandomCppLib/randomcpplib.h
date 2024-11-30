// Copyright (c) 2024, Jiang Xinghua
// All rights reserved.
// randomcpplib.h
#ifndef RANDOMCPLLIB_H
#define RANDOMCPLLIB_H

#include <random>
#include <ctime>
#include <list>

using namespace std;

#ifdef _EXPORT
#define RANDOMCPPAPI __declspec(dllexport)
extern "C"
{
#else
#define RANDOMCPPAPI __declspec(dllimport)
#endif

    // exchange two elements
    RANDOMCPPAPI void exchange(int *a, int *b);
    RANDOMCPPAPI void exchange_f(double *a, double *b);
    // check the max and min value,if the max is less than min, exchange them
    RANDOMCPPAPI void check_max_min(int *max, int *min);
    RANDOMCPPAPI void check_max_min_f(double *max, double *min);
    // check whether the dest is in the arr,if not,return false
    RANDOMCPPAPI bool has_same(int *arr, int size, int dest);
    RANDOMCPPAPI bool has_same_f(double *arr, int size, double dest);

    // random API
    // note:the arry must be sorted,and the size must be the size of the array

    // make a random array with normal distribution
    // param: arr(the array to be filled), size(the size of the array), mean(the mean of the normal distribution), std_dev(the standard deviation of the normal distribution), min(the minimum value of the array), max(the maximum value of the array)
    RANDOMCPPAPI void make_normal_random(int *arr, int size, int mean, int std_dev, int min, int max);
    // make a random array with uniform distribution
    // param: arr(the array to be filled), size(the size of the array), min(the minimum value of the array), max(the maximum value of the array)
    RANDOMCPPAPI void make_uniform_random(int *arr, int size, int min, int max);
    // make a random array with exponential distribution
    // param: arr(the array to be filled), size(the size of the array), lambda(the lambda of the exponential distribution), min(the minimum value of the array), max(the maximum value of the array)
    RANDOMCPPAPI void make_random(int *arr, int size, int min, int max);
    // make a random array with doubleing point numbers
    // param: arr(the array to be filled), size(the size of the array), min(the minimum value of the array), max(the maximum value of the array)
    RANDOMCPPAPI void make_doubleing_random(double *arr, int size, double min, double max);
#ifdef _EXPORT
}
#endif // _EXPORT
#endif // RANDOMCPLLIB_H