class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> freq(2001,0);
        for(int num: nums){
            freq[num + 1000]++;
        }

        vector<vector<int>> buckets(nums.size()+1);

        for(int i = 0; i<freq.size(); i++){
            if(freq[i]>0){
                buckets[freq[i]].push_back(i-1000);
            }
        }
        vector<int> result;

        for(int i =  buckets.size()-1; i>=0 && result.size()<k; i--){
            for(int num : buckets[i]){
                result.push_back(num);
                if(result.size()==k) break;
            }
        }

        return result;
    }
};
