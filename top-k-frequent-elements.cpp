class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        
        auto cmp = [](std::pair<int, int> a, std::pair<int, int> b) {
            return a.second > b.second;
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> minHeap(cmp);
        
        for (auto& pair : freqMap) {
            minHeap.push(pair);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        std::vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().first);
            minHeap.pop();
        }
        return result;
    }
};
