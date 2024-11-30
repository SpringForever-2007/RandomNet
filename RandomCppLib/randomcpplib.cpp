// Copyright (c) 2020, Jiang Xinghua
// All rights reserved.
// randomcpplib.cpp
#include "randomcpplib.h"

void exchange(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void exchange_f(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

void check_max_min(int *max, int *min)
{
    if (*max < *min)
    {
        exchange(max, min);
    }
}

void check_max_min_f(double *max, double *min)
{
    if (*max < *min)
    {
        exchange_f(max, min);
    }
}

bool has_same(int *arr, int size, int dest)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == dest)
            return true;
    }
    return false;
}

bool has_same_f(double *arr, int size, double dest)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == dest)
            return true;
    }
    return false;
}

void make_normal_random(int *arr, int size, int mean, int std_dev, int min, int max)
{
    check_max_min(&min, &max);
    if (max - min == 0)
        return;
    if (max - min + 1 < size)
        return;
    mt19937 gen(time(0));
    uniform_real_distribution<double> dis(mean - std_dev, mean + std_dev);
    int num = 0;
    for (int i = 0; i < size;)
    {
        num = dis(gen);
        num = num % (max - min + 1) + min;
        if (has_same(arr, i, num))
            continue;
        arr[i] = num;
        i++;
    }
}

void make_uniform_random(int *arr, int size, int min, int max)
{
    check_max_min(&min, &max);
    if (max - min == 0)
        return;
    if (max - min + 1 < size)
        return;
    mt19937 gen(time(0));
    uniform_int_distribution<int> dis(min, max);
    int num = 0;
    for (int i = 0; i < size;)
    {
        num = dis(gen);
        if (has_same(arr, i, num))
            continue;
        arr[i] = num;
        i++;
    }
}

void make_random(int *arr, int size, int min, int max)
{
    check_max_min(&min, &max);
    if (max - min == 0)
        return;
    if (max - min + 1 < size)
        return;
    srand(time(0));
    int num = 0;
    for (int i = 0; i < size;)
    {
        num = rand() % (max - min + 1) + min;
        if (has_same(arr, i, num))
            continue;
        arr[i] = num;
        i++;
    }
}

void make_doubleing_random(double *arr, int size, double min, double max)
{
    check_max_min_f(&min, &max);
    if (max - min == 0)
        return;
    mt19937 gen(time(0));
    uniform_real_distribution<double> dis(min, max);
    double num = 0;
    for (int i = 0; i < size;)
    {
        num = dis(gen);
        if (has_same_f(arr, i, num))
            continue;
        arr[i] = num;
        i++;
    }
}
