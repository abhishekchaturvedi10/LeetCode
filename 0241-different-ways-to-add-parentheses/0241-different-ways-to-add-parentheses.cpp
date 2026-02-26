class Solution {
public:

    vector<int> diffWaysToCompute(string expression) {
        
        vector<int> res;
        int n=expression.size();

        for(int i=0;i<n;i++) {
            char cur = expression[i];
            if(cur=='+' || cur=='-' || cur=='*') {
                vector<int> res1 = diffWaysToCompute(expression.substr(0,i));
                vector<int> res2 = diffWaysToCompute(expression.substr(i+1));
                for(int n1:res1) {
                    for(int n2:res2) {
                        if(cur=='+') {
                            res.push_back(n1+n2);
                        } else if(cur=='-') {
                            res.push_back(n1-n2);
                        } else {
                            res.push_back(n1*n2);
                        }
                    }
                }
            }
        }

        if(res.size()==0) {
            res.push_back(stoi(expression));
        }

        return res;
    }
};