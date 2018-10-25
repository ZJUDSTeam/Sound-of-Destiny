//
// Created by 59932 on 2018/10/23.
//
int foo(int n);
#include <stdio.h>
int main(void)
{
    printf("%d",foo(10));

}


int foo(int n)
{
    static int a = 0;
    if( n != 0 )
    {
        a++;
        foo(n-1);
    }
    return a;
}




