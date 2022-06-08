int maxSubArray(vector<int>& nums) {
        int sum=nums[0];
        int curr=nums[0];
        for(int i=1;i<nums.size();i++){
            if((curr+nums[i])>=nums[i]){
                curr+=nums[i];
                sum=max(sum,curr);
            }
            else{
                curr=nums[i];
                sum=max(sum,curr);
            }
        }
        return sum;
    }
