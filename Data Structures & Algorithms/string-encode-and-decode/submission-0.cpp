class Solution {
   public:
    string encode(vector<string>& strs) {
        string encoded;

        for (auto str : strs) {
            encoded += to_string(str.length()) + "#" + str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        for(int i = 0 ; i < s.length(); ) {
            string str_len = "";  
            while(s[i] != '#') {
                str_len += s[i];
                i++;
            }
            int len = stoi(str_len);
            // skip # character
            i++;
            string str = "";
            for(int j = 0; j < len; j++) {
                str += s[i+j];
            }
            i += len;
            decoded.push_back(str);
        }
        return decoded;
    }
};
