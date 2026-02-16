class Solution {
    public int almostPalindromic(String s) {

        if(s.length()<3) {
            return s.length();
        }

        if (ispal(s)) return s.length();
        
        int n = s.length();
        int ans = 1;
        int[][] dp = new int[n][n];
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        for (int i = 0; i < n - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                dp[i][i + 1] = 2;
            } else {
                dp[i][i + 1] = 1;
            }
            if (dp[i][i + 1] >= 1) {
                ans = Math.max(ans, 2);
            }
        }
        
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
                }
                
                if (dp[i][j] >= len - 1) {
                    ans = Math.max(ans, len);
                }
            }
        }

        return ans;
    }
    
    public boolean ispal(String s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s.charAt(l++) != s.charAt(r--)) return false;
        }
        return true;
    }
}