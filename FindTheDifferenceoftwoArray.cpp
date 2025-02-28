#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        set<int> st;
        vector<vector<int>> ans;
        for(int a : nums1)
        {
            int f=1;
            for(int b : nums2)
            {
                if(a==b) f=0;
            }
            if(f) st.insert(a);
        }
        vector<int> tp;
        for(int a : st)
        {
            tp.push_back(a);
        }
        ans.push_back(tp);
        st.clear();
        tp.clear();
        for(int a : nums2)
        {
            int f=1;
            for(int b : nums1)
            {
                if(a==b) f=0;
            }
            if(f) st.insert(a);
        }
        for(int a : st)
        {
            tp.push_back(a);
        }
        ans.push_back(tp);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 3};
    vector<int> nums2 = {1, 1, 2, 2};
    vector<vector<int>> result = sol.findDifference(nums1, nums2);
    
    cout << "Unique in nums1: ";
    for (int num : result[0]) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "Unique in nums2: ";
    for (int num : result[1]) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}