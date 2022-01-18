#include <stdio.h>
#include <math.h>
void runtime_increment(int N);
void runtime_print(int N);
void runtime_print_long(int N, char *long_str);
void runtime_pow(int N);
int main(void)
{
    int L = 1000, i;
    char str[L + 1];
    /* even if str is not used in runtime_increment and runtime_print, keep it to
make the comparison for runtime_print_long fair. */
    for (i = 0; i < L; i++)
    {
        str[i] = 'A';
    }
    str[i] = '\0';
    // call the functions here and record the time they take.
    //runtime_increment(300);
    //runtime_print(1000);
    //runtime_print_long(100, str);
    runtime_pow(30);
}
void runtime_increment(int N)
{
    int i, k, t, res = 0;
    for (i = 1; i <= N; i = i + 1)
        for (k = 1; k <= N; k++)
            for (t = 1; t <= N; t++)
                res = res + 1;
}
void runtime_print(int N)
{
    int i, k, t;
    for (i = 1; i <= N; i = i + 1)
        for (k = 1; k <= N; k++)
            for (t = 1; t <= N; t++)
                printf("A");
}
void runtime_print_long(int N, char *long_str)
{
    int i, k, t;
    for (i = 1; i <= N; i = i + 1)
        for (k = 1; k <= N; k++)
            for (t = 1; t <= N; t++)
                printf("%s\n", long_str);
}
void runtime_pow(int N)
{
    int i, res = 0;
    for (i = 1; i <= pow(2.0, (double)N); i = i + 1)
        res = res + 1;
}