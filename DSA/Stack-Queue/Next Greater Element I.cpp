// withput stack
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;
        unordered_map<int, int> mpp;
        // store nums2in mapp for index based access
        for (int i = 0; i < m; i++)
        {
            mpp[nums2[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            int A = nums1[i];
            // finding index here
            int index = mpp[A];
            // if index is at last
            if (index == m - 1)
            {
                ans.push_back(-1);
            }
            // iteration to find ans in nums2
            for (int j = index + 1; j < m; j++)
            {
                if (nums2[j] > A)
                {
                    ans.push_back(nums2[j]);
                    break;
                }
                // when smallets not found in array
                else if (nums2[j] < A && j == m - 1)
                {
                    ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};