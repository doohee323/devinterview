//1423. Maximum Points You Can Obtain from Cards

class Solution {
public:
		
    int maxScore(vector<int>& cardPoints, int k) {
    	vector<int> dp(k+1, 0);
    	
    	dp[0] = accumulate(cardPoints.begin(), cardPoints.begin()+k, 0);
    	
		//cout << dp[0] << endl;
			for(int i = 1; i<k+1; i++)
			{
				dp[i] = dp[i-1] - cardPoints[k-i] + cardPoints[cardPoints.size()-i];
          //      	cout << dp[i] << endl;
			}
			return *max_element(dp.begin(), dp.end());
    }
};