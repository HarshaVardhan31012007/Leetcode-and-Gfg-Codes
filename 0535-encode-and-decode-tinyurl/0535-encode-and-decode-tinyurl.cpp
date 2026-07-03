class Solution {
public:

    // Encodes a URL to a shortened URL.
    unordered_map<string,string>mpp;
    char i=0;
    string encode(string longUrl) {
        string temp="";
        temp+=i;i++;
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