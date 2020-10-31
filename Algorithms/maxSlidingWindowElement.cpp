vector<int> maxSlidingWindowElemnt(vector<int>& nums, int k)
{
	deque<int> dq;
	vector<int> res;

	for (int i = 0; i < nums.size(); ++i)
	{
		// Remove elements out of window
		if (!dq.empty() && dq.front() == i - k)
			dq.pop_front();

		// dq is in descending order (invariant)
		while (!dq.empty() && nums[dq.back()] < nums[i])
			dq.pop_back();

		// push the current element to the deque
		dq.push_back(i);
		if (i >= k - 1)
			res.push_back(nums[dq.front()]);
	}

	return res;
}
