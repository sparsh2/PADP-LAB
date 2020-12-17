#include<omp.h>
#include<stdio.h>

int main(){

    omp_set_num_threads(4);
    #pragma omp parallel for schedule(static,1)
    for(int i=0; i<1000; i++){
        printf("%d:%d", i, omp_get_thread_num());
    }

    // cout<<omp_get_num_procs()<<'\n';

    return 0;
}