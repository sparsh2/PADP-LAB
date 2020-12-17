#include<bits/stdc++.h>
#include<omp.h>

using namespace std;

const int msize = 100000000+1;

bool prime[msize];

void sieve_cache_unfriendly(int n){
    for(int i=0; i<=n; i++){
        prime[i] = 1;
    }

    // prime[2] = 1;

    double start_time = omp_get_wtime();

    
    for(int i=2; i*i<=n; i++){
        if(prime[i]){
            for(int j=i*i; j<=n; j+=i){
                prime[j] = 0;
            }
        }
    }

    // for(int i=1; i<n; i++){
    //     cout<<prime[i]<<" ";;
    // }

    double end_time = omp_get_wtime();

    vector<int> primes;

    for(int i=2; i<=n; i++){
        if(prime[i] == 1){
            primes.push_back(i);
        }
    }

    cout<<"time taken: "<<end_time-start_time<<"\n";

    cout<<"number of primes: "<<primes.size()<<'\n';
}

void sieve_cache_friendly(int n){
    long count = 0;
    long m = (long)sqrt((double)n);
    vector<bool> composite(n+1,false);
}

int main(){
    long n;
    cout<<"Enter n: ";
    cin>>n;

    sieve_cache_unfriendly(n);
}