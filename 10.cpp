#include<iostream>
#include<vector>
using namespace std;
bool isprime(long int i,vector<long int>v)
{
    for(vector<long int>::iterator it=v.begin();it!=v.end();it++)
    {
        if(i%(*it)==0)
            return false;
    }
    return true;
}
void add(long int *A,long int i)
{
    int j=0;
    while(i>0)
    {
        int rem=i%10;
        A[j++]+=rem;
        i/=10;
    }
}
int main()
{
    long int A[20];
    for(int i=0;i<2000000;i++)
        A[i]=0;
    A[0]=2;
    
    vector<long int> v;
    for(long int i=3;i<10;i+=2)
    {
        if(isprime(i,v)){
            //cout<<i<<endl;
            v.push_back(i);
            add(A,i);
        }
    }
    int index;
    for(int i=19;i>=0;i--)
    {
        if(A[i]!=0)
        {
            index=i;
            break;
        }
    }
    for(int i=index;i>=0;i--)
        cout<<A[i];
    return 0;
}
