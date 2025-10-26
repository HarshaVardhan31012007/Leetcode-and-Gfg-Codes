class Bank {
public:
    vector<long long>bank;
    int n;
    Bank(vector<long long>& balance) {
        n=balance.size();
        for(int i=0;i<balance.size();i++){
            bank.push_back(balance[i]);
        }
    }
    bool isValid(int no){
        return no>=1&&no<=n;
    }
    bool transfer(int account1, int account2, long long money) {
        if(!isValid(account1)||!isValid(account2)) return false;
        if(money>bank[account1-1]) return false;
        bank[account1-1]-=money;
        bank[account2-1]+=money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!isValid(account)) return false;
        bank[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!isValid(account)) return false;
        if(money>bank[account-1]) return  false;
        bank[account-1]-=money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */