class Solution {
public:
    bool canPartition(string s, int target) {
        if (s == "" && target == 0) return true;
        for (int i = 0; i < s.size(); i++) {
            string left = s.substr(0, i + 1);
            string right = s.substr(i + 1);
            int leftNum = stoi(left);
            if(leftNum>target) {
                return false;;
            }
            bool isPossible = canPartition(right, target - leftNum);
            if (isPossible) {
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int sum = 0;
        for (int num = 1; num <= n; num++) {
            int sqr = num * num;
            if (canPartition(to_string(sqr), num)) {
                sum += sqr;
            }
        }
        return sum;
    }
};