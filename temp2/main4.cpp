#include <bits/stdc++.h>
using namespace std;

int main() {
    atomic<int> sum(0);
    auto f = [&sum](){
        for(int i = 0; i < 1000000; i++)
            sum+=1;
    };
    thread t(f);
    thread t2(f);
    thread t3(f);
    t.join();
    t2.join();
    t3.join();
    cout << sum << endl;
    return 0;
}