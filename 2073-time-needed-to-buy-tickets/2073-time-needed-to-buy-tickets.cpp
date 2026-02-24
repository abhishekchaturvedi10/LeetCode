class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        queue<pair<int,int>> q;
        int time=0;

        for(int i=0;i<tickets.size();i++) {
            if(i==k) {
                q.push({tickets[i],1});
            } else {
                q.push({tickets[i],0});
            }
        }

        while(!q.empty()) {
            pair<int,int> firstPerson = q.front();
            q.pop();
            time++;
            int ticketOfFirstPerson = firstPerson.first;
            if(firstPerson.second==1) {
                if(ticketOfFirstPerson==1) {
                    return time;
                }
            }
            ticketOfFirstPerson--;
            if(ticketOfFirstPerson>0) {
                q.push({ticketOfFirstPerson,firstPerson.second});
            }
        }

        return time;
    }
};