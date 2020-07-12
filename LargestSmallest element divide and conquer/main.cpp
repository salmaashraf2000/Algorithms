#include <iostream>

using namespace std;

struct Pair{
   int mn;
   int mx;
};

int Min=999999999,Max=0;

/// brute force O(n) T(n)=2T(n/2)+2 a=2 b=2 a>b^d O(n^log 2 2) O(n)
void LargestSmallest(int a[],int l,int r){
   if(l!=r){
    int m=(l+r)/2;
    LargestSmallest(a,l,m);
    if(Min>a[l]){
        Min=a[l];
    }else if(Max<a[l]){
        Max=a[l];
    }
    LargestSmallest(a,m+1,r);
     if(Min>a[m+1]){
        Min=a[m+1];
    }else if(Max<a[m+1]){
        Max=a[m+1];
    }
   }
}

///T(n)=2T(n/2)+2
struct Pair MinMax(int a[],int r,int l){
    struct Pair Minmax,mml,mmr;
    if(r==l){
        Minmax.mn=a[l];
        Minmax.mx=a[l];
        return Minmax;
    }
     if(r-l==1){
        if(a[l]<a[r]){
            Minmax.mn=a[l];
            Minmax.mx=a[r];
        }else{
            Minmax.mn=a[r];
            Minmax.mx=a[l];
        }
        return Minmax;
    }

       int m=(l+r)/2;
       mml=MinMax(a,l,m);
       mmr=MinMax(a,m+1,r);
       if(mml.mn<mmr.mn){
        Minmax.mn=mml.mn;
       }else{
        Minmax.mn=mmr.mn;
       }
       if(mml.mx>mmr.mx){
        Minmax.mx=mml.mx;
       }else{
        Minmax.mx=mmr.mx;
       }
       return Minmax;


}

int main()
{
    int a[]={6,2,86,7,77,1},sz=6;
    //LargestSmallest(a,0,sz-1);
    //cout<<Min<<" "<<Min<<endl;
    struct Pair p=MinMax(a,0,sz-1);
    cout<<p.mn<<" "<<p.mx;
    return 0;
}


///b-T(2^k)=2T(2^k-1)+2= 2(2T(2^(k-2)+2)+2)
///2^i(T(2^(k-i)+2^i)= 2^i*T(2^k)
///
///c-This algorithm makes about 25% fewer comparisons
/// because recursion stop when there is 2 elements
