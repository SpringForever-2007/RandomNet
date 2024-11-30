using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace RandomNet
{
    partial class RandomCppLibWrapper
    {
        //dll import
        [DllImport("randomcpplib.dll", CallingConvention = CallingConvention.Cdecl)]
        unsafe protected static extern void exchange(int* a, int* b);

        [DllImport("randomcpplib.dll", CallingConvention = CallingConvention.Cdecl)]
        unsafe protected static extern void exchange_f(double* a, double* b);

        [DllImport("randomcpplib.dll", CallingConvention = CallingConvention.Cdecl)]
        unsafe protected static extern void check_max_min(int* max, int* min);

        [DllImport("randomcpplib.dll", CallingConvention = CallingConvention.Cdecl)]
        unsafe protected static extern void check_max_min_f(double* max, double* min);

        [DllImport("randomcpplib.dll", CallingConvention = CallingConvention.Cdecl)]
        unsafe protected static extern bool has_same(int* arr, int size, int dest);

        [DllImport("randomcpplib.dll", CallingConvention = CallingConvention.Cdecl)]
        unsafe protected static extern bool has_same_f(double* arr, int size, double dest);

        [DllImport("randomcpplib.dll", CallingConvention = CallingConvention.Cdecl)]
        unsafe protected static extern void make_normal_random(int* arr, int size, int mean, int std_dev, int min, int max);

        [DllImport("randomcpplib.dll", CallingConvention = CallingConvention.Cdecl)]
        unsafe protected static extern void make_uniform_random(int* arr, int size, int min, int max);

        [DllImport("randomcpplib.dll", CallingConvention = CallingConvention.Cdecl)]
        unsafe protected static extern void make_random(int* arr, int size, int min, int max);

        [DllImport("randomcpplib.dll", CallingConvention = CallingConvention.Cdecl)]
        unsafe protected static extern void make_floating_random(double* arr, int size, double min, double max);
    }
}
