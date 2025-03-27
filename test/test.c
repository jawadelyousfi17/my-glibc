#include "../string/f_string.h"
#include <stdio.h>
#include <time.h>
#include <assert.h>

# define N_ITER 10000000
# define LEN 1000

void __print_d_to_word(int d)
{
    int millions = d / 1000000;
    int thousands = (d - millions * 1000000) / 1000;
    int hundreds = d - millions * 1000000 - thousands * 1000;
    printf("%d,%03d,%03d ITER\n", millions, thousands, hundreds);
}

double __strlen_benchmark(size_t (*f)(const char *))
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    const char *str = malloc(LEN + 1);
    memset((char *)str, 'a', LEN);
    ((char *)str)[LEN] = '\0';
    for (size_t i = 0; i < N_ITER; i++)
    {
        f(str);
    }
    size_t len = f(str);
    assert(len == LEN);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    free((char *)str);
    return cpu_time_used;
}

int main()
{
    printf("Benchmarking strlen...\n");
    double sys_time = __strlen_benchmark(strlen);
    printf("Benchmarking f_strlen...\n");
    double f_time =  __strlen_benchmark(f_strlen);
    __print_d_to_word(N_ITER * LEN);
    printf("difference: %d%%\n",(int) (f_time / sys_time * 100));
    printf("sys time: %f\n", sys_time);
    printf("f time: %f\n", f_time);
    return 0;
}