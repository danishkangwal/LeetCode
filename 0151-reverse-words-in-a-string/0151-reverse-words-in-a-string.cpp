class Solution {
public:
    string reverseWords(string str) {
        vector<string> vs;
	string tmp = "";
	for(int i = 0;i < str.size();i++){
		if(str[i]==' '){
			if(tmp != "")
				vs.push_back(tmp);
			tmp = "";
		}
		else
			tmp += str[i];
	}
	if(tmp != "")
		vs.push_back(tmp);

	string s = "";
	for(int i = vs.size()-1;i >= 0;i--){
		s += vs[i];
		if(i>0)
            s += ' ';
	}
	return s;
    }
};