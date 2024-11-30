using System.Runtime.InteropServices;

namespace RandomNet
{
    /// <summary>
    /// the random class whitch use std c++ to make random numbers
    /// the generators is mt19937,the seed is the local time
    /// </summary>
    public partial class RandomCppLibWrapper
    {
        /// <summary>
        /// make normal random numbers
        /// </summary>
        /// <param name="arr">the results</param>
        /// <param name="mean">the expected mean</param>
        /// <param name="std_dev">the expected standard deviation</param>
        /// <param name="range">the range of results</param>
        unsafe public void MakeNormalRandom(int[] arr,int mean,int std_dev,Range range)
        {
            fixed (int* arrPtr = arr)
            {
                make_normal_random(arrPtr, arr.Length, mean, std_dev, range.Start.Value, range.End.Value);
            }
        }

        /// <summary>
        /// make uniform random numbers
        /// </summary>
        /// <param name="arr">the results</param>
        /// <param name="range">the range of results</param>
        unsafe public void MakeUniformRandom(int[] arr,Range range)
        {
            fixed(int* arrPtr = arr)
            {
                make_uniform_random(arrPtr,arr.Length,range.Start.Value, range.End.Value);
            }
        }

        /// <summary>
        /// make common random numbers
        /// </summary>
        /// <param name="arr">the results</param>
        /// <param name="range">the range of results</param>
        unsafe public void MakeRandom(int[] arr,Range range)
        {
            fixed(int* arrPtr = arr)
            {
                make_random(arrPtr,arr.Length,range.Start.Value,range.End.Value);
            }
        }

        /// <summary>
        /// make double random numbers
        /// </summary>
        /// <param name="arr">the results</param>
        /// <param name="min">the minimum</param>
        /// <param name="max">the maximum</param>
        unsafe public void MakeFloatingRandom(double[] arr, double min, double max)
        {
            fixed(double* arrPtr = arr)
            {
                make_floating_random(arrPtr, arr.Length, min, max);
            }
        }
    }
}
