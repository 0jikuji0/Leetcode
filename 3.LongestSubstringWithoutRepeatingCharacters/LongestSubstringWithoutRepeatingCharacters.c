int lengthOfLongestSubstring(char* s) {

    int lastSeen[128];

    for (int i = 0; i < 128; i++){

        lastSeen[i] = -1;

    }


    int maxLength = 0;

    int left = 0;

    int len = strlen(s);


    for (int right = 0; right < len; right++){

        char current = s[right];


        if (lastSeen[current] >= left){

            left = lastSeen[current] + 1 ;

        }


        lastSeen[current] = right;


        int currentLength = right - left + 1;

        if (currentLength > maxLength){

            maxLength = currentLength;

        }


    }


    return maxLength;

}