// 给定两个单词和一个单词数组，让我们找出从开始单词每次只能变换一个字母，而且变换后的单词需要在数组中存在，直到变换到endWord，求变换次数；
// 没有什么特别好的办法，只能对每次需要变换的单词进行按位替换，如果新的单词存在数组中，将其加入下一次变换的队列中，直到变换的单词就是endWord；

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> us = {wordList.begin(), wordList.end()};
        if (us.count(endWord) == 0) { return 0; }
        
        unordered_set<string> selected;
        queue<string> q;
        q.push(beginWord);
        selected.insert(beginWord);
        int level = 0;
        
        while(!q.empty()) {
            level++;
            auto nsize = q.size();
            for (int i = 0; i < nsize; ++i) {
                string word = q.front();
                q.pop();
                if (word == endWord) { return level; }
                for (int i = 0; i < word.size(); ++i) {
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c != word[i]) {
                            string tmp = word;
                            tmp[i] = c;
                            if (us.count(tmp)) {
                                q.push(tmp);
                                us.erase(tmp);
                            }
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};
