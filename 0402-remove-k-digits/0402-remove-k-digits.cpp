class Solution {
public:
    string removeKdigits(string num, int k) {
        string answer;

        for (char digit : num) {

            while (k > 0 &&
                   !answer.empty() &&
                   answer.back() > digit) {

                answer.pop_back();
                k--;
            }

            answer.push_back(digit);
        }

        // If removals are still left,
        // remove digits from the end
        while (k > 0 && !answer.empty()) {
            answer.pop_back();
            k--;
        }

        // Remove leading zeros
        int index = 0;

        while (index < answer.size() &&
               answer[index] == '0') {
            index++;
        }

        answer = answer.substr(index);

        // If all digits were removed
        if (answer.empty()) {
            return "0";
        }

        return answer;
        
    }
};