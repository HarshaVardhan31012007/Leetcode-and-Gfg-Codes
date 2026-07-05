class TextEditor {
public:
    stack<char>st1;
    stack<char>st2;
    TextEditor() {
        
    }
    
    void addText(string text) {
        for(auto &each:text){
            st1.push(each);
        }
    }
    
    int deleteText(int k) {
        int ans=0;
        while(k--&&!st1.empty()){
            ans++;
            st1.pop();
        }
        return ans;
    }
    const int a=10;
    string printlast10(){
        string ans="";
        int len=min(a,(int)st1.size());
        for(int i=0;i<len;i++){
            st2.push(st1.top());
            st1.pop();
        }
        for(int i=0;i<len;i++){
            ans+=st2.top();
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
    }
    string cursorLeft(int k) {
        while(!st1.empty()&&k--){
            st2.push(st1.top());
            st1.pop();
        }
        return printlast10();
    }
    string cursorRight(int k) {
        while(!st2.empty()&&k--){
            st1.push(st2.top());
            st2.pop();
        }
        return printlast10();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */