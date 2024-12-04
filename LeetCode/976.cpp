class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(),
             [](const int &a, const int &b) -> bool
             { return a > b; });
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int s = nums[i + 1] + nums[i + 2];
            if (nums[i] < s)
                return nums[i] + s;
        }
        return 0;
    }
};