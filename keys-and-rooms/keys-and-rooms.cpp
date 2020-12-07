class Solution {
public:
    map<int, int> vis;
    void dfs(vector<vector<int>>& rooms, int room) {
        if(!vis[room]) {
            vis[room]++;
            for(int i=0;i<rooms[room].size();i++) {
                if(!vis[rooms[room][i]]) dfs(rooms, rooms[room][i]);
            }
        }
     }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        dfs(rooms, 0);
        if(vis.size()==rooms.size()) return true;
        return false;
    }
};
