#include <random>
#include <ctime>
#include <vector>
#include <iostream>

using namespace std;

vector<int> reservoir_sampling(vector<int>& vec, int k) {
    random_device rd;
    mt19937 rng(rd());
    vector<int> ret(vec.begin(), vec.begin()+k);
    for(int i=k; i<vec.size(); i++) {
        uniform_int_distribution<int> uni(0, i);
        int idx = uni(rng);
        if(idx<k) ret[idx] = vec[i]; 
    }
    return ret;
}

int main() {
    //srand(time(nullptr));
    //rand()
    vector<int> vec;
    for(int i=0; i<1000000; i++) 
        vec.push_back(i+1);
    
    vector<int> sampling = reservoir_sampling(vec, 10);
    for(auto x: sampling) cout<<x<<" ";
    cout<<endl;
    return 0;
}