class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        queue<pair<int,int>> q;
        int time=0, kthPersonTickets;

        for(int i=0;i<tickets.size();i++) {
            if(i<=k) {
                time += min(tickets[i],tickets[k]);
            } else {
                time += min(tickets[i],tickets[k]-1);
            }
        }

        // while(!q.empty()) {
        //     pair<int,int> firstPerson = q.front();
        //     q.pop();
        //     int ticketOfFirstPerson = firstPerson.first, index=firstPerson.second;
        //     if(index<=k) {
        //         time += min(ticketOfFirstPerson,kthPersonTickets);
        //     } else {
        //         time += min(ticketOfFirstPerson,kthPersonTickets-1);
        //     }
        //     // 1,2,3,4  k=1

        //     // time++;
        //     // int ticketOfFirstPerson = firstPerson.first;
        //     // if(firstPerson.second==1) {
        //     //     if(ticketOfFirstPerson==1) {
        //     //         return time;
        //     //     }
        //     // }
        //     // ticketOfFirstPerson--;
        //     // if(ticketOfFirstPerson>0) {
        //     //     q.push({ticketOfFirstPerson,firstPerson.second});
        //     // }
        // }

        return time;
    }
};