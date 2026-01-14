int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int maxWater = 0;

    while (left < right){
        int width = right - left;

        int h = (height[left] < height[right]) ? height[left] : height[right];

        int currentArea = width *h;

        if (currentArea > maxWater){
            maxWater = currentArea;
        }

        if (height[left] < height[right]){
            ++left;
        } else {
            --right;
        }
    }

    
    return maxWater;
}