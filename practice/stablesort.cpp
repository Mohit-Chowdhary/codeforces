

int stablePart(vector<int> & nums, int l, int r){
    if( r - l == 1){
        return nums[l]%2 ? l:r;
    }

    int mid = l + (r-l)/2;

    int leftOdd  = stablePart(nums,l,mid);
    int rightEven = stablePart(nums,mid,r);

    rotate(nums.begin()+leftOdd, nums.begin()+mid, nums.begin()+rightEven);

    return leftOdd + rightEven - mid;
}