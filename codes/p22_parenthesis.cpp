class Solution{
public:
	vector<string> generateParenthesis(int n){
		vector<string> res;
		adding(res,"",n,n);
		return res;
	}

	void adding(vector<string> &v, string s, int left, int right){
		if (left==0 && right==0){
			v.push_back(str);
			return;
		}
		if (m>0)
			adding (v, s+"(",left-1,right);
		if (n>0)	
			adding (v, s+")",left, right-1);


	}
};