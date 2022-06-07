void nextPermutation(vector<int>& nums) {
        int size=nums.size();
        int p=size-1;
        while(p!=0 && nums[p-1]>=nums[p]){
            p--;
        }
        p--;
        if(p<0){
            reverse(nums.begin(),nums.end());     
        }
        else{
            int b=size-1;
            while(nums[b]<=nums[p]){
                b--;
            }
            swap(nums[p],nums[b]);
            reverse(nums.begin()+p+1,nums.end());
        }
    }
