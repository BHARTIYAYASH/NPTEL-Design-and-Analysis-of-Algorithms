#include <iostream>
#include <algorithm>
using namespace std;
int binarySearch(int *A,int n,int val)
{
    int start=0;
    int ends=n-1;
    while(start<ends)
    {
        int mid=(start+ends)/2;
        if(A[mid]==val)
        {
            return mid;
        }
        else if(A[mid]>val)
        {
            ends=mid-1;
        }
        else if(A[mid]<val)
        {
            start=mid+1;
        }
    }
}
int linearSearch(int *A,int n,int val)
{
    for(int i=0;i<n;i++)
    {
        if(A[i]==val)
        {
            return i;
        }
    }
}
int main()
{
    int N;
    cin>>N;
    int L[N],U[N],temp[N],dummy[N];
    for(int i=0;i<N;i++)
    {
        cin>>L[i];
        temp[i]=L[i];
        cin>>U[i];
    }
    sort(L,L+N);
    for(int i=0;i<N;i++)
    {
        int position=linearSearch(temp,N,L[i]);
        dummy[position]=(N-1-i)*2;
    }
    for(int i=0;i<N;i++)
        cout<<dummy[i]<<" ";
        cout<<endl;
    return 0;
}