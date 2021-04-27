double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int *nums;
    int i = 0;
    int j = 0;
    int k = 0;
    
    nums = (int *)malloc(sizeof(int) * (nums1Size + nums2Size));
    if (nums == NULL)
        return (0);
    while(i < nums1Size + nums2Size)
    {
        if (j < nums1Size && k < nums2Size)
        {
            if (nums1[j] <= nums2[k])
            {
                nums[i] = nums1[j];
                j++;
            }
            else
            {
                nums[i] = nums2[k];
                k++;
            }
        }
        else if (j >= nums1Size)
        {
            nums[i] = nums2[k];
            k++;
        }
        else
        {
            nums[i] = nums1[j];
            j++;
        }
        i++;
    }
    if ((nums1Size + nums2Size) % 2 == 1)
        return ((double)nums[(nums1Size + nums2Size) / 2]);
    else
    {
        i = nums[(nums1Size + nums2Size) / 2];
        j = nums[(nums1Size + nums2Size) / 2 - 1];
        return ((double)(i + j) / 2);
    }
}