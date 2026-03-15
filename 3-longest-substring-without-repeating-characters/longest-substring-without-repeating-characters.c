int lengthOfLongestSubstring(char* s) {
    //find the length of a string.
    //check if any character's are duplicates
    //count the length of the string with unique letters.
    int length = strlen(s);
    int max = 0;
    int left = 0;
    
    //Array to store the last seen index of each character, initialized to -1
    int lastseen[128];
    for(int i = 0; i < 128 ; i++) lastseen[i] = -1;
    //For loop making the right go the length of the string.
    for(int right = 0; right < length; right++){
        unsigned char currentChar = s[right];
        if(lastseen[currentChar] >= left){
            left = lastseen[currentChar]+1;
        }
        lastseen[currentChar] = right;

        max = MAX(max, right - left + 1);
    }
    
    //if the character was seen and is within the current window
    //move the left boundary past the last occurrence of the duplicate

    //update the last seen position of the current character
    return max;
}