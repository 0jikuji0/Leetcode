char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len == 0){
        return "";
    }
    
    int start = 0;
    int maxLen = 1;

    for (int i =0; i < len; ++i){
        int left = i;
        int right = i;
        while (left >= 0 && right < len && s[left] == s[right]){
            int currentLen = right - left + 1;

            if (currentLen > maxLen){
                start = left;
                maxLen = currentLen;
            }
            --left;
            ++right;
        }

        left = i;
        right = i + 1;
        while (left >= 0 && right < len && s[left] == s[right]){
            int currentLen  = right - left + 1;

            if (currentLen > maxLen){
                start = left;
                maxLen = currentLen;
            }
            --left;
            ++right;
        }
    }

    char * result = (char*)malloc((maxLen + 1) * sizeof(char));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';

    return result;
}