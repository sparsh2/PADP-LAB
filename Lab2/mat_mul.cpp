#include <bits/stdc++.h>
#include<omp.h>
using namespace std;

int matA[1500][1500];
int matB[1500][1500];
int matC[1500][1500];

int main()
{
    srand(time(0));

    int rng = 50000;

    int sizes[] = {10, 100, 500, 1000};

    cout<<fixed<<setprecision(6);

    cout<<"size/cores\t";

    for(int i=0; i<4; i++){
        cout<<(1<<i)<<"\t";
    }cout<<'\n';

    for(int sz=0; sz<4; sz++){
        cout<<sizes[sz]<<"\t";
        for(int co=0; co<4; co++){
            for(int i=0; i<sizes[sz]; i++){
                for(int j=0; j<sizes[sz]; j++){
                    matA[i][j] = rand()%rng;
                }
            }

            for(int i=0; i<sizes[sz]; i++){
                for(int j=0; j<sizes[sz]; j++){
                    matB[i][j] = rand()%rng;
                }
            }

            double time_start = omp_get_wtime();

            int i,j,k;

            #pragma omp parallel for num_threads(1<<co) 
            for(i=0; i<sizes[sz]; i++){
                for(j=0; j<sizes[sz]; j++){
                    matC[i][j] = 0;
                    for(k=0; k<sizes[sz]; k++){
                        matC[i][j] += matA[i][k]*matB[k][j];
                    }
                }
            }

            double time_end = omp_get_wtime();

            cout<<(time_end - time_start)<<"\t";
        }
        cout<<"\n";
    }

    

    // for(int i=0; i<m; i++){
    //     for(int j=0; j<p; j++){
    //         cout<<matC[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }

}