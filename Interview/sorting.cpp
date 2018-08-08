#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

void quick_sort(vector<int>& vec, int lb, int rb) {
    if(lb>=rb) return;
    int left = lb;
    for(int i=lb; i<rb; i++) {
        if(vec[i]<=vec[rb]) {
            swap(vec[i], vec[left++]);
        }
    }
    swap(vec[rb], vec[left]);
    quick_sort(vec, lb, left-1);
    quick_sort(vec, left+1, rb);
}

void merge_sort(vector<int>& vec, int lb, int rb) {
    if(lb>=rb) return;
    int mid = (lb+rb)/2;
    merge_sort(vec, lb, mid);
    merge_sort(vec, mid+1, rb);
    vector<int> tmp;
    int i = lb, j = mid+1;
    while(i<=mid && j<=rb) {
        if(vec[i]<=vec[j]) tmp.push_back(vec[i++]);
        else tmp.push_back(vec[j++]);
    }
    while(i<=mid) tmp.push_back(vec[i++]);
    while(j<=rb) tmp.push_back(vec[j++]);
    for(int i=lb; i<=rb; i++) vec[i] = tmp[i-lb];
}

//Having some performance problem when decimal numbers in the vector
void bucket_sort(vector<int>& vec) {
    int len = vec.size();
    if(len==0) return;
    vector<vector<int>> b(len, vector<int>());
    int mi = vec[0];
    int ma = vec[0];
    for(auto x: vec) {
        mi = min(mi, x);
        ma = max(ma, x+1); //to avoid interval of 0
    }
    int interval = ceil((ma-mi)*1.0/len);
    for(auto x: vec) b[floor((x-mi)*1.0/interval)].push_back(x);
    for(auto x: b) sort(x.begin(), x.end());
    vec.clear();
    for(int i=0; i<len; i++) {
        for(int j=0; j<b[i].size(); j++){
            vec.push_back(b[i][j]);
        }
    }
}

//find k-th index in the sorted array given the unsorted array.
//need to check if the index is out of bound beforehand. 
int quick_select(vector<int>& vec, int lb, int rb, int k) {
    int left = lb;
    for(int i=lb; i<rb; i++) {
        if(vec[i]<=vec[rb]) {
            swap(vec[i], vec[left++]);
        }
    }
    swap(vec[rb], vec[left]);
    if(left==k) return vec[left];
    else if(left>k) return quick_select(vec, lb, left-1, k);
    else return quick_select(vec, left+1, rb, k);
}

int main() {
    vector<int> vec{3,2,3,1,2,4,5,5,6};
    int len = vec.size()-1;
    quick_sort(vec, 0, len);
}