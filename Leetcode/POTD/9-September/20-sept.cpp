// Leetcode 3508. Implement Router
#include <iostream>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;
class Router
{
public:
    deque<array<int, 3>> fifo_queue;
    set<array<int, 3>> packets_set;
    map<int, pair<int, vector<int>>> dest_to_timestamps;
    size_t memoryLimit;
    Router(size_t memoryLimit) : memoryLimit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp)
    {
        array<int, 3> packet = {source, destination, timestamp};
        if (packets_set.count(packet))
        {
            return false;
        }
        if (fifo_queue.size() >= memoryLimit)
        {
            array<int, 3> oldest = fifo_queue.front();
            fifo_queue.pop_front();
            packets_set.erase(oldest);
            auto &[head, timestamps] = dest_to_timestamps.at(oldest[1]);
            head++;
        }

        fifo_queue.push_back(packet);
        packets_set.insert(packet);
        dest_to_timestamps[destination].second.push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket()
    {
        if (fifo_queue.empty())
        {
            return {};
        }

        array<int, 3> oldest = fifo_queue.front();
        fifo_queue.pop_front();
        packets_set.erase(oldest);
        auto &[head, timestamps] = dest_to_timestamps.at(oldest[1]);
        head++;
        return {oldest[0], oldest[1], oldest[2]};
    }
    int getCount(int destination, int startTime, int endTime)
    {
        auto it = dest_to_timestamps.find(destination);
        if (it == dest_to_timestamps.end())
        {
            return 0;
        }
        auto &[head, timestamps] = it->second;
        auto start_it = lower_bound(timestamps.begin() + head, timestamps.end(), startTime);
        auto end_it = upper_bound(timestamps.begin() + head, timestamps.end(), endTime);

        return distance(start_it, end_it);
    }
};

int main()
{
    Router router(3);
    cout << router.addPacket(1, 2, 100) << endl; // true
    cout << router.addPacket(1, 2, 100) << endl; // false
    cout << router.addPacket(2, 3, 200) << endl; // true
    cout << router.addPacket(3, 4, 300) << endl; // true
    cout << router.addPacket(4, 5, 400) << endl; // true (removes oldest packet)
    vector<int> packet = router.forwardPacket();
    if (!packet.empty())
    {
        cout << "Forwarded Packet: [" << packet[0] << ", " << packet[1] << ", " << packet[2] << "]" << endl;
    }
    else
    {
        cout << "No packet to forward" << endl;
    }
    cout << router.getCount(2, 50, 150) << endl;  // 1
    cout << router.getCount(3, 50, 250) << endl;  // 1
    cout << router.getCount(5, 350, 450) << endl; // 1
    return 0;
}
