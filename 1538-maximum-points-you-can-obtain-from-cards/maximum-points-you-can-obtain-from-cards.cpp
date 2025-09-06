class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left_sum=0;
        int right_sum=0;
        int max_sum=0;

        for(int i=0;i<k;i++){
            left_sum += cardPoints[i];

        }
        max_sum=left_sum;
        int index=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            left_sum=left_sum-cardPoints[i];
            right_sum=right_sum+cardPoints[index];
            index--;

            max_sum=max(max_sum,left_sum+right_sum);
        }

        return max_sum;
        
    }
};