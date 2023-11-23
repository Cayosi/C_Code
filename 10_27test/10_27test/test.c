
#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int a = 0, b = 0;
    while (a < numsSize)
    {
        if (nums[a] == val)
        {
            a++;
        }
        else
        {
            nums[b++] = nums[a++];
        }
    }
    return b;
}


int removeDuplicates(int* nums, int numsSize)
{
    int a = 0, b = 1;
    while (b < numsSize)
    {
        if (nums[a] == nums[b])
        {
            b++;
        }
        else
        {
            nums[++a] = nums[b++];
        }
    }
    return a+1;
}



void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    if (m>0)
    {
        int a = m - 1, b = n - 1, c = m + n - 1;
        while ((a >= 0) && (b >= 0))
        {
            if (nums1[a] > nums2[b])
            {
                nums1[c--] = nums1[a--];
            }
            else
            {
                nums1[c--] = nums2[b--];
            }
        }

        while (a >= 0)
        {
            nums1[c--] = nums1[a--];
        }
        while (b >= 0)
        {
            nums1[c--] = nums2[b--];
        }

    }
    else
    {
        for (size_t i = 0; i < nums1Size; i++)
        {
            nums1[i] = nums2[i];
        }
    }
   
}
int main()
{
    //int nums[] = { 0,0,1,1 };
    //int res = removeElement(nums, 4, 3);
   //int res = removeDuplicates(nums, 4);

    int nums1[] = { 2,0 }; int m = 1; int nums2[] = { 1 }; int n = 1;
    merge(nums1, 2, m, nums2, 1, n);

    for (size_t i = 0; i < 2; i++)
    {
        printf("%d", nums1[i]);
    }
    return 0;
}