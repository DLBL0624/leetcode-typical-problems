class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = nums.size()-1;
        if(index==-1)return;
        while(index!=0&&nums[index]<=nums[index-1])
        {
            index--;
        }
        if(index==0)
        {
            sort(nums.begin(),nums.end());
            return ;
        }
        int repl = nums[--index];
        int idx = nums.size()-1;
        while(nums[idx]<=repl)
        {
            idx--;
        }
        nums[index] = nums[idx];
        nums[idx] = repl;
        sort(nums.begin()+index+1, nums.end());
    }
};


//if the number is in a descending order: it has been reached the final version -> sort it to ascending order
//else find the longest descending part in the array. Suppose it starts at index i, switch nums[i-1] and nums[j] //j is the index of element that is the lowest element greater than nums [i-1]
//sort i to the end in ascending order;