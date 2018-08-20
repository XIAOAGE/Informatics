#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>
#include <ctime>

using namespace std;

const int N = 10;

queue<int> qu;
mutex mtx;
condition_variable cv;

int factorial(int n) {
    if(n<=1) return 1;
    else return n*factorial(n-1);
}

void consumer(int id){
    while(true){
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [](){return !qu.empty();});
        int q = qu.front(); qu.pop();
        factorial(q);
        //cout<<"Consumer "<<id<<": Factorial "<<q<<" is solved."<<endl;
        lck.unlock();
    }
}

void producer(int id){
    while(true) {
        srand(0);
        int q = rand() % N;
        unique_lock<mutex> lck(mtx);
        qu.push(q);
        cout<<"Producer "<<id<<": Question of calculating factorial of "<<q<<" is pushed."<<endl;
        lck.unlock();
        cv.notify_one();
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main()
{
    vector<thread> consumers;
    vector<thread> producers;

    for(int i=0; i<10; i++) consumers.push_back(thread(consumer, i));
    for(int i=0; i<5; i++) producers.push_back(thread(producer, i));
    for(int i=0; i<10; i++) consumers[i].join();
    for(int i=0; i<5; i++) producers[i].join();
    return 0;
}
