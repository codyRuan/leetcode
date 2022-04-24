/*
 * @lc app=leetcode id=1396 lang=cpp
 *
 * [1396] Design Underground System
 */

// @lc code=start
class UndergroundSystem {
private:
    map<int, pair<string, int>> checkin;
    map<pair<string, string>, vector<int>> data;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = checkin[id];
        data[make_pair(startStation, stationName)].push_back(t-startTime);
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto times = data[make_pair(startStation, endStation)];
        double totalTime = 0;
        for (auto t : times)
            totalTime += t;
        return totalTime / times.size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
// @lc code=end

