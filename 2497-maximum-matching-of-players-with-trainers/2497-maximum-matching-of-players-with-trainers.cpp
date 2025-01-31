class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int m=players.size(), n=trainers.size(), i=0, j=0, matches=0;
        while(i<m&&j<n) {
            if(trainers[j]>=players[i]) {
                matches++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return matches;
    }
};