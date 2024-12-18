let maxSlidingWindow = function (nums, k) {
    const n = nums.length
    let ans = []
    const dq = new Array(k)
    let front = 0, back = k - 1
    let cnt = 0
    for (let i = 0; i < n; i++) {
        if (cnt > 0 && dq[front] <= i - k)
            front = (front + 1) % k, cnt--
        while (cnt > 0 && nums[dq[back]] <= nums[i])
            back = (k + back - 1) % k, cnt--

        back = (back + 1) % k, cnt++
        dq[back] = i
        if (i >= k - 1) ans.push(nums[dq[front]]);
    }
    return ans;
};

cc = console.log
cc(maxSlidingWindow([1, 3, -1, -3, 5, 3, 6, 7], 3))
cc(maxSlidingWindow([7, 2, 4], 2))
