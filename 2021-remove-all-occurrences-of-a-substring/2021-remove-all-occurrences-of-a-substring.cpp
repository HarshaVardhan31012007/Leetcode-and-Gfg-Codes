class Solution {
public:
    string removeOccurrences(string s, string part) {//while(s.length()!=0&&s.find(part)<s.length())
        // while(s.find(part)!=string::npos){
        //     s.erase(s.find(part),part.length());
        // }
        // return s;
        // while(s.find(part)!=-1){
        //     s.erase(s.find(part),part.length());
        // }
        // return s;
        // int findkaIndex=s.find(part);
        // while(findkaIndex!=-1){
        //     s.erase(s.find(part),part.length());
        //     findkaIndex=s.find(part);
        // }
        // return s;
    //     string x = s;
	// int n = s.size(), m = part.size(), i, j;
	// for (i = 0, j = 0; i < n; i++) {
	// 	x[j++] = s[i];
	// 	if (j >= m && x.substr(j - m, m) == part)
	// 		j -= m;
	// }
	// return x.substr(0, j);
int findkaIndex=s.find(part);
        while(1){
            if(findkaIndex==string::npos)
            return s;
            else
            s.erase(s.find(part),part.length());
            findkaIndex=s.find(part);
        }
        return s;



    }
};