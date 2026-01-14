char* intToRoman(int num) {
    char* result = (char*)malloc(16 * sizeof(char));

    result[0] = '\0';

    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    int index = 0;

    for (int i = 0; i < 13; ++i){
        while(num >= values[i]){
            strcat(result, symbols[i]);

            num -= values[i];
        }
    }

    return result;
}