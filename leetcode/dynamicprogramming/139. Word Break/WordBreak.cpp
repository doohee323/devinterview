//139. Word Break
class Solution {
public:
    // memoization
    unordered_map<string, bool> dp;
    bool helper(const string& s, vector<string>& wordDict)
    {
        if (s.size() == 0) return true;

        if (dp.find(s) != dp.end())
        {
            return dp[s];
        }

        for (auto& word : wordDict)
        {
            if (word.size() <= s.size() && s.substr(0, word.size()) == word)
            {
                string newStr = s.substr(word.size());
                if (helper(newStr, wordDict))
                {
                    dp[newStr] = true;
                    return true;
                }
                else
                {
                    dp[newStr] = false;
                }
            }
        }
        dp[s] = false;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0)
            return false;

        return helper(s, wordDict);
    }
};