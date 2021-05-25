class Solution {
public:
    int countTriplets(vector<int>& arr) {

        arr.insert(arr.begin(), 0);

        int res = 0, n = arr.size();

        for (int i = 1; i < n; i++)
            arr[i] = arr[i - 1] ^ arr[i];

        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (arr[i] == arr[j])
                    res += j - i - 1;

        return res;
    }
};