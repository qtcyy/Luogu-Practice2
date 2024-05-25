#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
using namespace std::chrono;

mutex mtx;
int sum=0;
int sum2=0,sum3=0,sum4=0,sum5=0;

inline bool is_prime(int n){
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

void prime_thread(int n){
    for(int i = 2; i < n ; i++){
        if(is_prime(i)){
            sum4+=i;
            sum%=1000000007;
        }
    }
}

void prime_thread2(int n){
    for(int i = 2; i < n ; i++){
        if(is_prime(i)){
            sum+=i;
            sum%=1000000007;
        }
    }
}

void prime_thread3(int n){
    for(int i = 2; i < n ; i++){
        if(is_prime(i)){
            sum2+=i;
            sum2%=1000000007;
        }
    }
}

void prime_thread4(int n){
    for(int i = 2; i < n ; i++){
        if(is_prime(i)){
            sum3+=i;
            sum3%=1000000007;
        }
    }
}

void prime_thread5(int n){
    for(int i = 2; i < n ; i++){
        if(is_prime(i)){
            sum5+=i;
            sum5%=1000000007;
        }
    }
}



int main(){
    freopen("output.txt", "w", stdout);
    auto start = high_resolution_clock::now();
    // thread t1(prime_thread, 20000000);
    // thread t2(prime_thread2, 20000000);
    // thread t3(prime_thread3, 20000000);
    // thread t4(prime_thread4, 20000000);
    // thread t5(prime_thread5, 20000000);

    // t1.join();
    // t2.join();
    // t3.join();
    // t4.join();
    // t5.join();

    prime_thread(20000000);
    prime_thread(20000000);
    prime_thread(20000000);
    prime_thread(20000000);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout<<endl<<"Time used: "<<duration.count()<<" microseconds"<<endl;
    return 0;
}