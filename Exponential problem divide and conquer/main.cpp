#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int power(int a,int n){
   if(n==1){
    return a;
   }else{
    return power(a,n/2)*power(a,ceil(n/2.00));
   }
}

int main()
{
    cout<<power(5,3);

    return 0;
}

///b-n-1 O(n)
///c-same
