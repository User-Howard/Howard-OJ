class Solution {
public:
    string multiply(string num1, string num2) {
        const int n = num1.size();
        const int m = num2.size();
        vector<int> dts(n+m);
        for(int i=0;i<n;++i) {
            int a = num1[n-i-1] - '0';
            for(int j=0;j<m;++j) {
                char b = num2[m-j-1] - '0';
                dts[i+j] += a * b;
                dts[i+j+1] += dts[i+j] / 10;
                dts[i+j] %= 10;
            }
        }
        string ans = "";
        bool flag = true;
        for(int i=n+m-1;i>=0;--i) {
            if(flag and dts[i]==0) continue;
            flag = false;
            ans += dts[i] + '0';
        }
        if(ans.size() == 0) ans = "0";
        return ans;
    }
};

