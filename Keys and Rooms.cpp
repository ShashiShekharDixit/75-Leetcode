#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size = rooms.size();
        int goal = (size * (size - 1)) / 2;
        int psize = 0;
        int csize = 0;
        int sum = 0;
        unordered_map<int, int> accessibleRooms;
        for (auto room : rooms[0]) {
            accessibleRooms[room] = 1;
            sum += room;
            csize++;
        }
        while (psize != csize) {
            for (auto [key, value] : accessibleRooms) {
                for (auto room : rooms[key]) {
                    if (accessibleRooms[room] != 1) {
                        csize++;
                        accessibleRooms[room] = 1;
                        sum += room;
                    }
                }
            }
            psize++;
        }
        return ((goal != sum) ? false : true);
    }
};

int main() {
    Solution solution;
    
    vector<vector<int>> rooms1 = {{1}, {2}, {3}, {}};
    vector<vector<int>> rooms2 = {{1, 3}, {3, 0, 1}, {2}, {0}};

    cout << (solution.canVisitAllRooms(rooms1) ? "True\n" : "False\n");
    cout << (solution.canVisitAllRooms(rooms2) ? "True\n" : "False\n");

    return 0;
}
