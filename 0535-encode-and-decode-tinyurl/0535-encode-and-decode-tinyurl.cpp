class Solution {
public:

    // Encodes a URL to a shortened URL.
    unordered_map<string,string>mpp;
    long long i=0;
    string encode(string longUrl) {
        char ch=(i+'0');
        string temp="";temp+=ch;
        mpp[temp]=longUrl;
        return "http://tinyurl.com/"+temp;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int index=(int)shortUrl.size()-1;
        while(shortUrl[index]!='/') index--;
        string s=shortUrl.substr(index+1);
        return mpp[s];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));