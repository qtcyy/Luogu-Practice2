#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

bool is_prime(int n){
    if (n <= 1) return false;
    for (int i=2;i*i<=n;i++){
        if (n%i == 0) return false;
    }
    return true;
}

void process(int data){
    int sum=0;
    mtx.lock();
    std::cout << "Processing " << data << std::endl;
    mtx.unlock();
    for (int i=2;i<=20000000;i++){
        if (is_prime(i)){
            sum+=i;
            sum%=1000000007;
        }
    }
    mtx.lock();
    cout<<"End "<<sum<<endl;
    mtx.unlock();
}

int main() {
    vector<std::thread> threads;
    for(int i=0;i<4;i++){
        threads.push_back(std::thread(process,i));
    }
    for (auto& t : threads){
        if (t.joinable()){
            t.join();
        }
    }

    return 0;
}