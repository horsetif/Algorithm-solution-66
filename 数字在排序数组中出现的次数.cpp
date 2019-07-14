/*
题目描述
统计一个数字在排序数组中出现的次数。


思路：二分查找。找到数字的最左边，最右边。然后减一下就可以。注意有约束的二分查找的框架.
*/

int GetNumberOfK(vector<int> data, int k) {
	int index1 = find_first_ind(data, k);
	if (index1 >= 0 && index1 < data.size() && data[index1] == k) {
		int index2 = find_last_ind(data, k);
		return index2 - index1 + 1;
	}
	else return 0;
}
int find_first_ind(vector<int> &data, int k) {
	int start = 0, end = data.size() - 1;
	while (start <= end) {
		//取中位
		int mid = (start + end) / 2;
		//常规二分查找
		if (data[mid] > k) end = mid - 1;
		else if (data[mid] < k) start = mid + 1;
		else {//如果查到了，再往左找
			if (mid > 0 && data[mid - 1] == k) end = mid - 1;
			else return mid;
		}
	}
	return start;
}
int find_last_ind(vector<int> &data, int k) {
	int start = 0, end = data.size() - 1;
	while (start <= end) {
		//取中位
		int mid = (start + end) / 2;
		//常规二分查找
		if (data[mid] > k) end = mid - 1;
		else if (data[mid] < k) start = mid + 1;
		else {//如果查到了，再往右找
			if (mid < data.size() - 1 && data[mid + 1] == k) start = mid + 1;
			else return mid;
		}
	}
	return start;
}