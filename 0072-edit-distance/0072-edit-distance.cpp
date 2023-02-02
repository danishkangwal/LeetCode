class Solution {
public:
    int minDistance(string a, string b) {
        vector<vector<int>> v(a.size()+1,vector<int>(b.size()+1,-1));
        return minDistance(a,b,v);
    }
    int minDistance(string a,string b,vector<vector<int>>& v){
	if(a==b)
		return 0;
	int n = a.size(),m=b.size();
	if(a=="" || b=="")
		return max(n,m);
	if(v[n][m] != -1)
		return v[n][m];
	
    if(a[0]==b[0]){
        return minDistance(a.substr(1),b.substr(1),v);
    }
	int ans = 0;
	int x = 1+minDistance(a.substr(1),b,v);
	int y = 1+minDistance(a.substr(1),b.substr(1),v);
	int z = 1+minDistance(a,b.substr(1),v);
	ans = min(x,min(y,z));
	return v[n][m]=ans;
}
};