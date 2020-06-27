/*
5. 最长回文子串
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

示例 2：
输入: "cbbd"
输出: "bb"
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 暴力法 
class Solution {
private:
	bool valid(string s, int left, int right) {
		//验证子串s[left,right]是否为回文串
		while(left < right) {
			if (s[left] != s[right]) {
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
public:
	string longestPalindrome(string s) {
		int size = s.size();
		if (size < 2) {
			return s;
		}

		int maxLen = 1, maxLeft = 0, maxRight = 1;
		string res = s.substr(0, 1);
		string temp;
		int left = 0, right = 0;
		for (left = 0; left < size - 1; left++) {
			for (right = left + 1; right < size; right++) {
				if ((maxLen < right - left + 1) && (true == valid(s, left, right))) {
					maxLen = right - left + 1;
					maxLeft = left;
					maxRight = right;
				}
			}
		}
		if (maxLen > 1) {
			return s.substr(maxLeft, maxRight - maxLeft + 1);
		}
		else {
			return res;
		}
	}
};
*/

/* 动态规划 */
class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		vector<vector<int>> dp(n, vector<int>(n));
		string ans = s.substr(0,1);
		int maxLen = 1;
		int i = 0, j = 0;

		for (i = 0; i < n; i++) {
			dp[i][i] = 1;
		}

		for (j = 1; j < n; j++) {
			for (i = 0; i < j; i++) {
				if (s[i] != s[j]) {
					dp[i][j] = 0;
				}
				else {
					if (((j - 1) - (i + 1) + 1) < 2) {
						dp[i][j] = 1;
					}
					else {
						dp[i][j] = dp[i + 1][j - 1];
					}
					if (dp[i][j] == 1) {
						if (maxLen < j - i + 1) {
							maxLen = j - i + 1;
							ans = s.substr(i, j - i + 1);
						}
					}
				}
			}
		}
		return ans;
	}
};

/*
int main(int argc, char** argv) {
	Solution solution;
	string res = "";
	res = solution.longestPalindrome("abca");
	cout << res << endl;
	return 0;
}
*/
