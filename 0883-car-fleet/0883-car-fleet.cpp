class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        vector<pair<int,double>> cars;
        cars.reserve(n);
        for (int i = 0; i < n; ++i) {
            double time = double(target - position[i]) / double(speed[i]);
            cars.emplace_back(position[i], time);
        }

        // sort(cars.begin(), cars.end(), [](const pair<int,double>& a, const pair<int,double>& b){
        //     return a.first > b.first;
        // });
        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double curFleetTime = -1.0;
        for (const auto &c : cars) {
            double t = c.second;
            if (t > curFleetTime) {
                ++fleets;
                curFleetTime = t;
            }
        }
        return fleets;
    }
};