/* Chapter 27, exercise 14: write a function that takes an array of int as input
   and finds the smallest and the largest elements as well as the median and
   mean; return the result in a struct holding the values */

#include<stddef.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>

struct Result {
    int min;
    int max;
    double median;
    double mean;
};

int cmpint(const void* a, const void* b)
{
    int aa = *(int*)a;
    int bb = *(int*)b;
    if (aa<bb)
        return -1;
    else if (bb<aa)
        return 1;
    else
        return 0;
}

int array_sum(int* int_array, size_t size)
{
    int sum = 0;
    int i;
    for (i = 0; i<size; ++i)
        sum += int_array[i];
    return sum;
}

struct Result* array_data(int* int_array, size_t size)
{
    assert(int_array);
    assert(size > 0);
    {
        int* array_cpy = (int*)malloc(size*sizeof(int));    /* copy to play with */
        struct Result* res = (struct Result*)malloc(sizeof(struct Result));
        memcpy(array_cpy,int_array,size*sizeof(int));
        qsort(array_cpy,size,sizeof(int),cmpint);

        res->min = array_cpy[0];
        res->max = array_cpy[size-1];
        if (size % 2)   /* odd number of elements */
            res->median = array_cpy[size/2];
        else    /* even number - median is mean of two elements */
            res->median = (array_cpy[size/2-1] + array_cpy[size/2]) / 2.0;
        res->mean = (double)array_sum(int_array,size) / size;
        free(array_cpy);
        return res;
    }
}

void print_result(struct Result* res)
{
    printf("min: %d\nmax: %d\nmean: %f\nmedian: %f\n",
           res->min,res->max,res->mean,res->median);
}

int main()
{
    int arr1[] = { 3, 2, 5, 4, 1 };
    int arr2[] = { 5, 1, 7, 4, 8, 4 };
    struct Result* res1 = array_data(arr1,sizeof(arr1)/sizeof(int));
    struct Result* res2 = array_data(arr2,sizeof(arr2)/sizeof(int));
    printf("arr1:\n");
    print_result(res1);
    printf("\narr2:\n");
    print_result(res2);

    free(res1);
    free(res2);
}
