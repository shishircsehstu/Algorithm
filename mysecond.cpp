#include<bits/stdc++.h>
#include <sys/time.h>
using namespace std;
double mysecond()
{
    struct timeval tp;
    struct timezone tzp;
    int i;
    i = gettimeofday(&tp,&tzp);
    return ( (double) tp.tv_sec + (double) tp.tv_usec * 1.e-6); //return second

}
int main()
{
    int ck;
    double start=mysecond();
    for(int i=0; i<=1000000000; i++)
    {
        ck=1;
    }
    cout<<ck<<endl;
    double end=mysecond();
    cout<<end-start;
}
