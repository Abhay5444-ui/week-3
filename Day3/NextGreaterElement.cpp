class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> mp;
        stack<int> s;

        for (int i = nums2.size() - 1; i >= 0; i--) {

            int element = nums2[i];

            if (s.empty()) {
                mp[element] = -1;
                s.push(element);
            }
            else {

                if (s.top() > element) {
                    mp[element] = s.top();
                    s.push(element);
                }
                else {

                    while (!s.empty()) {

                        if (s.top() > element) {
                            mp[element] = s.top();
                            s.push(element);
                            break;
                        }

                        s.pop();
                    }

                    if (s.empty()) {
                        mp[element] = -1;
                        s.push(element);
                    }
                }
            }
        }

        vector<int> result;

        for (auto i : nums1) {
            result.push_back(mp[i]);
        }

        return result;
    }
};
