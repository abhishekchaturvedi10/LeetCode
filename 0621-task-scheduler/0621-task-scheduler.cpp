class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> freq(26);

        for(char c:tasks) {
            freq[c-'A']++;
        }

        sort(begin(freq),end(freq));
        int chunk = freq[25]-1;
        int idle = n*(freq[25]-1);
        

        for(int i=24;i>=0;i--) {
            idle -= min(chunk,freq[i]);
        }

        return idle<0?tasks.size():tasks.size()+idle;
    }
};