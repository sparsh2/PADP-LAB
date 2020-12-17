#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>

using namespace std;

#define SEED 35453535

int main(){
    cout<<fixed<<setprecision(6);
    int n;
    int count = 0;

    double z,pi,x,y;

    int iter[] = {100000, 1000000, 10000000, 20000000, 30000000};
    srand(time(0));

    cout<<"Iterations\t\t1\t\t2\t\t4\t\t8\n";

    for(int j=0; j<5; j++){
        cout<<iter[j]<<"\t";
        for(int i=0; i<=3; i++){
            count = 0;

            double time_start = omp_get_wtime();

            #pragma omp parallel for num_threads(1<<i)
            for(int i=0; i<iter[j]; i++){
                x = (double)rand()/RAND_MAX;
                y = (double)rand()/RAND_MAX;
                z = x*x+y*y;
                if(z <= 1) 
                    count++;
            }

            pi = ((double)count)/iter[j]*4;

            double time_stop = omp_get_wtime();

            cout<<pi<<","<<(time_stop-time_start)<<'\t';
        }
        cout<<'\n';
    }

    return 0;
}