/*
题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。


思路：二分查找。不停遍历条件：num[start] >= num[end]。说明拐点还在数组里面。否则说明拐点已经在数组外面了。
	  当 num[mid] > num[start], 说明 数组的左边是有序的，应该检查右边。那么 start = mid;
	  当 num[mid] <= num[end], 说明数组右边是有序的，应该检查左边。那么 end = mid;
	  有一种特殊情况，在num[start] >= num[end] 的时候，他们的长度已经只有2了，那么还是降序的，那么铁定最小值就是num[end].
*/

int minNumberInRotateArray(vector<int> rotateArray) {
	int n = rotateArray.size();
	if (n == 0) return 0;
	if (n == 1) return rotateArray[0];
	int start = 0, end = n - 1, mid = (start + end) / 2;//设置三个指针
	while (rotateArray[start] >= rotateArray[end]) {//说明混乱数组还存在里面
		if (end - start == 1) {
			mid = end; break; //只有两个长度了，没有检查必要了。
		}
		mid = (start + end) / 2;
		//说明左边有序，那么就检查右边
		if (rotateArray[mid] >= rotateArray[start]) start = mid;
		//说明右边有序，那么就检查左边
		else end = mid;
	}
	return rotateArray[mid];
}