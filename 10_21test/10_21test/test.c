
#include <stdio.h>
//void rotate(int* nums, int numsSize, int k) {
//
//    for (int i = 0; i < numsSize - k ; i++)
//    {
//        int tp = nums[0];
//        for (size_t i = 1; i < numsSize; i++)
//        {
//            nums[i - 1] = nums[i];
//        }
//        nums[numsSize - 1] = tp;
//    }
//}

void flip(int* nums, int start, int end)
{
	while (start < end)
	{
		int tmp = nums[start];
		nums[start] = nums[end];
		nums[end] = tmp;
		start++;
		end--;
	}
}
void rotate(int* nums, int numsSize, int k)
{
	k %= numsSize;
	flip(nums, 0, numsSize - 1);
	flip(nums, 0, k - 1);
	flip(nums, k, numsSize - 1);
}



int missingNumber(int* nums, int numsSize) {
	int compare = (numsSize * (numsSize + 1)) / 2;
	int sum = 0;
	for (int i = 0; i < numsSize; i++)
	{
		sum += nums[i];
	}
	return compare - sum;
}

int main()
{
	int tmp[] = { 1,2,3,4,5,6,7,8,9 };
	rotate(tmp, 9, 3);
	for (size_t i = 0; i < 9; i++)
	{
		printf("%d ", tmp[i]);
	}
	return 0;
}