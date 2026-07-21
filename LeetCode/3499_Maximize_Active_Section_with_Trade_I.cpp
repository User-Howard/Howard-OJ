class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        // Run-length encoding: even index = 1-blocks, odd index = 0-blocks
        vector<int> runs = {0};
        for (char c : s) {
            if ((c - '0') != (int)runs.size() % 2) {
                runs.push_back(0);
            }
            runs.back()++;
        }
        if (s.back() == '0') runs.push_back(0);

        int result = 0;
        int windowSum = 0;
        int maxGain = 0;

        for (int i = 0; i < (int)runs.size(); i++) {
            if (i % 2 == 0) {
                result += runs[i];
            } else {
                windowSum += runs[i];
                if (i >= 4) windowSum -= runs[i - 4];
                if (i >= 3) maxGain = max(windowSum, maxGain);
            }
        }

        return result + maxGain;
    }
};
