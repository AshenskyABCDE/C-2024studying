class Solution {
public:
    int qs(vector<int>& vec,int l,int r) {
        if(l >= r){
            return l;
        }
        int ii=l;
        int jj=r+1;
        int t = vec[l];
        while (ii < jj) {
            do ii++; while(vec[ii] < t && ii < r);
            do jj--; while(vec[jj] > t && jj > l);
            if(ii > jj) {
                break;
            }
            swap(vec[ii], vec[jj]);
        }
        swap(vec[l], vec[jj]);
        return jj;
    }
    void sortVec(vector<int>&vec, int l,int r) {
        if(l >= r) {
            return ;
        }
        int mid = qs(vec,l,r);
        sortVec(vec,l,mid-1);
        sortVec(vec,mid+1,r);
    }
    int findKthLargest(vector<int>& nums, int k) {
        sortVec(nums,0,nums.size()-1);
        return nums[nums.size()-k];
    }
};