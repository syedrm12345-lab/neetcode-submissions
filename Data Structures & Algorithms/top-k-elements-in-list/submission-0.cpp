class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums) {
            freq[n]++;
        }
        
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> heap;

        for (auto& [val, cnt] : freq) {
            heap.push({cnt, val});
            if ((int)heap.size() > k) {
                heap.pop();
            }
        }

        vector<int> result;
        while (!heap.empty()) {
            result.push_back(heap.top().second);
            heap.pop();
        }
        return result;
    }
};
