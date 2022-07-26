#include <stdio.h>

int containsDigit(long int num, int x);

void removeDigit(int x, int n, int* a_ptr, int* b_ptr)
{
    int a = 1;
    int b = n - a;
    
    int finished = 0;

    while (finished == 0)
    {   
        if (containsDigit(a, x) || containsDigit(b, x))
        {
            a++;
            b--;
        }
        else
        {
            finished = 1;
            *a_ptr = a;
            *b_ptr = b;
        }
    }
}


int containsDigit(long int num, int x)
{
    int digit;
    num *= 10;
    while (num > 9)
    {
        num /= 10;
        digit = num % 10;
        if (x == digit)
        {
            return 1;
        }
    }
    return 0;
}





int main(void)
{
    int a;
    int b;

    removeDigit(8, 18853983, &a, &b);
    printf("%d\n", a);
    printf("%d\n", b);

}