class Twitter {
private:
    int time=0;
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int,int>>> tweets;

public:

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> all;

        for(auto user:followers[userId]){
            for(auto t:tweets[user]){
                all.push_back(t);
            }
        }
        for (auto t : tweets[userId]) {
            all.push_back(t);
        }
        sort(all.rbegin(), all.rend());
        vector<int> ans;
        for (int i = 0; i < min(10, (int)all.size()); i++) {
            ans.push_back(all[i].second);
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */