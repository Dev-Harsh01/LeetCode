class Solution {
public:
    int findnum(vector<int>& arr,int start,int end,int target){
        if(start<=end){
        int mid=start + (end-start)/2;
        
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]>target){
          return  findnum(arr,start,mid-1,target);
        }
        else{
          return  findnum(arr,mid+1,end,target);
        }
        }

        return -1;
    }
    
   
    int search(vector<int>& nums, int target) {

        int start=0;
        int end=nums.size()-1;

       int s=findnum(nums,start,end,target);

        return s;

        
    }
};