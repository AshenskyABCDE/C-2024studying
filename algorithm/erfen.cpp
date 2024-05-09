#include <bits/stdc++.h>
using namespace std;
const int N= 1e5 +20;
vector<int>vec;
int Count(vector<int>& arr,int target){
    int pos1 = 0;
    int pos2 = 0;
    int l = 0, r = arr.size()-1;
    while(l<=r) {
        int mid = l + (r-l)/2;
        if( vec[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
            if(vec[mid] == target) {
                pos1 = mid;
            }
        }
    }
    // while(vec[pos1] < target) pos1++;
    l = 0 , r = arr.size()-1;
    while(l<=r) {
        int mid = l + (r-l)/2;
        if(vec[mid] > target) {
            r = mid-1;
        } else {
            l = mid + 1;
            if(vec[mid] == target) {
                pos2 = mid;
            }
        }
    }
    std::cout<<target<<" "<<pos1<<" "<<pos2<<endl;
    return pos2 - pos1 + 1;
}
int main() {
    int n = 10;
    for(int i=1;i<=n;i+=2){
        vec.push_back((i+1)/2);
        vec.push_back((i+1)/2);
    }
    for(auto x:vec) {
        cout<<x<<endl;
    }
    for(int i=1 ;i<= n/2;i++){
        cout<<Count(vec, i)<<endl;
    }
}