#include <iostream>

using namespace std;

void bubblesort(int a[],int sz){
  for(int i=0;i<sz;i++){
    for(int j=1;j<sz-i;j++){
        if(a[j-1]>a[j]){
            swap(a[j],a[j-1]);
        }
    }
  }
}

int main()
{
    int a[]={1,2,1,6,3,45,78,0},sz=8;
    bubblesort(a,sz);
    for(int i=0;i<sz;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
