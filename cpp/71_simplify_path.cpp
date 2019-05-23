//  给定Path /a/../b// 这种，让我们简化，处理.. , . , path后面去除 / 
//  遍历，取//之间的字符串，进栈，如果是..进行一次出栈，.什么也不做
class Solution {
public:
    string simplifyPath(string path) {
        if (path[path.size()-1] != '/') { path += '/'; }
		stack<string> s;
		int j = 1;
		for (int i = 1; i < path.size(); ++i) {
			if (path[i] != '/') { continue; }
			string subPath = path.substr(j, i-j);
			j = i+1;
			
			if (subPath.empty() || subPath == ".") { continue; }
			if (subPath == "..") {
				if (!s.empty()) { s.pop(); }
			} else {
				s.push(subPath);
			}
		}
		
		stack<string> as;
		while(!s.empty()) {
			as.push(s.top());
			s.pop();
		}
		
		string res = "/";
		auto nsize = as.size();
		for (int i = 0; i < nsize; ++i) {
			res += as.top();
			if (i < nsize-1) { res += "/"; }
			as.pop();
		}
		return res;
    }
};
