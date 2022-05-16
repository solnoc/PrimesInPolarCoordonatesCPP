#include <fstream>
#include <math.h>
#include <iostream>

std::ofstream fout("prime.txt");

bool isprime(long long i)
{
    if(i<2)
        return 0;
    if(i==2)
        return 1;
    if(i%2==0)
        return 0;
    
    long long s = sqrt(i);
    for(long long d=3;d<=s+1;d+=2)
        if(i%d==0)
            return 0;
    return 1;
}

int main()
{
    for(int i=2;i<10000000000;i++)
    {
        if(isprime(i))
            fout<<i<<" ";
    }
    return 0;
}