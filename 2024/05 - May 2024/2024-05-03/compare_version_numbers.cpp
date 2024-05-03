int compareVersion(string version1, string version2) {
    // Initialize indices for traversing both strings
    int i = 0; 
    int j = 0;
    // Get the sizes of both strings
    int n1 = version1.size(); 
    int n2 = version2.size();

    // Initialize variables to store numeric segments of version numbers
    int num1 = 0;
    int num2 = 0;

    // Traverse both strings until one of them ends
    while(i < n1 || j < n2) {
        // Extract numeric segments from version1
        while(i < n1 && version1[i] != '.') {
            num1 = num1 * 10 + (version1[i] - '0');
            i++;
        }

        // Extract numeric segments from version2
        while(j < n2 && version2[j] != '.') {
            num2 = num2 * 10 + (version2[j] - '0');
            j++;
        }

        // Compare the numeric segments
        if(num1 > num2) 
            return 1;
        else if(num1 < num2) 
            return -1;

        // Reset numeric segment variables
        num1 = 0;
        num2 = 0;

        // Move to the next segment
        i++;
        j++;
    }

    // Both version numbers are equal
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/