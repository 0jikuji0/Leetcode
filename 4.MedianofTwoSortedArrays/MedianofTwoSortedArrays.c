double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if(nums1Size > nums2Size){
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    int m = nums1Size;
    int n = nums2Size;
    int left = 0, right = m;
   

    while (left <= right){
        int partition1 = (left + right) / 2;
        int partition2 = (m + n + 1) / 2 - partition1;
        int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
        int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
        int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1){
            if ((m + n) % 2 == 0){
                int maxLeft = (maxLeft1 > maxLeft2) ? maxLeft1 : maxLeft2;
                int minRight = (minRight1 < minRight2) ? minRight1 : minRight2;
                return (maxLeft + minRight) / 2.0;
            }else{
                return (maxLeft1 > maxLeft2) ? maxLeft1 : maxLeft2;

            }
        }else if (maxLeft1 > minRight2){
            right = partition1 - 1;
        }else{
            left = partition1 + 1;
        }
    }

    return 0.0;
}
