// https://leetcode.com/problems/design-twitter/submissions/
class Twitter
{

private:
    int time = 0;
    unordered_map<int, set<int>> friends;
    unordered_map<int, vector<pair<int, int>>> user;

public:
    Twitter()
    {
        // initialize time with 0
        time = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        // post the twitter as a user
        user[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {

        /// get top 10 news
        priority_queue<pair<int, int>> maxHeap;
        for (auto it = user[userId].begin(); it != user[userId].end(); it++)
        {
            maxHeap.push(*it);
        }

        for (auto it1 = friends[userId].begin(); it1 != friends[userId].end(); it1++)
        {
            int usr = *it1; // get the target user
            for (auto it2 = user[usr].begin(); it2 != user[usr].end(); it2++)
            {
                maxHeap.push(*it2);
            }
        }

        vector<int> res;
        while (maxHeap.size() > 0)
        {
            res.push_back(maxHeap.top().second);
            if (res.size() == 10)
                break;
            maxHeap.pop();
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        // check if follwerId should not equal to followeeId
        if (followerId != followeeId)
        {
            friends[followerId].insert(followeeId);
        }
    }
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */

    void unfollow(int followerId, int followeeId)
    {

        friends[followerId].erase(followeeId);
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