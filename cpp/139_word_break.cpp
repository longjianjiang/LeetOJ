// 给定字符串s，和一个数组，判断能否将字符串拆分，拆分的段需要在数组中，允许相同段使用多次。
// 开始尝试的是从头开始遍历字符串，每次截取子串，判断是否在数组中，如果存在直接将该段移出，当数组为空，原字符串还没有为空，则返回false；
// 上面的方式的问题在于，当需要使用到多次的时候有问题，还有在于数组中的段可能根本不是某个子串，这个时候跳出循环也存在问题，所以这种方式行不通。
// 一种可行的方式是，在字符串中某个子串在数组中时，在该位置标记一下，最后只要字符串最后被标记了，那么证明可以拆分，
// 算是动态规划，dp长度为字符串长加1，定一个截子串的开始索引数组，默认加入0。当某次截取子串存在数组中，将改次索引加入数组，以后每次尝试从索引数组中进行截取。最后返回dp[nsize] 是否为1即可。

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
		if (wordDict.empty()) { return false; }
		unordered_set<string> us = {wordDict.begin(), wordDict.end()};
		int nsize = (int)s.size();
		vector<int> arr = {0};
		vector<int> dp(nsize+1, 0);
		for (int i = 0; i <= nsize; ++i) {
			for (auto p: arr) {
				string seg = s.substr(p, i-p);
				if (us.count(seg)) {
					dp[i] = 1;
					arr.push_back(i);
					break;
				}
			}
		}
		return dp[nsize] == 1;
     
    }
};
