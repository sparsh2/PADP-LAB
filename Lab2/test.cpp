#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int a[10000] = {0};
    
    int sum = 0;

    for(int i=0; i<10000; i++){
        a[i] = i+1;
    }

    

    omp_set_num_threads(4);
    #pragma omp parallel for
    for(int i=0; i<1000; i++){
        printf("%d:%d\n",i,omp_get_thread_num());
    }

    cout<<omp_get_num_procs()<<'\n';

    // cout<<sum<<" ";
}