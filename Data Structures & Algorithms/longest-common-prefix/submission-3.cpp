class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int totalStrings = strs.size();

        // Initially assume the first string is the common prefix.
        string prefix = strs[0];

        // Compare the current prefix with every other string.
        for (int i = 1; i < totalStrings; i++) {

            int prefixLength = prefix.length();

            string currentString = strs[i];
            int currentLength = currentString.length();

            // If any string is empty, the answer is "".
            if (currentString.empty()) {
                return "";
            }

            // Store the common part between prefix and currentString.
            string commonPrefix = "";

            // Compare characters until a mismatch or one string ends.
            for (int j = 0; j < prefixLength && j < currentLength; j++) {

                if (prefix[j] != currentString[j]) {
                    break;
                }

                commonPrefix += prefix[j];
            }

            // Update the prefix for the next comparison.
            prefix = commonPrefix;

            // No common prefix left.
            if (prefix.empty()) {
                return "";
            }
        }

        return prefix;
    }
};