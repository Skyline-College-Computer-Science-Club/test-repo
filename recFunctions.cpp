    /*
        Copyright ©️ Lance Ruiz
        02/24/2022
    
        .\"resursion.cpp"
    
        A program that:
            [1] has a recursive function recurseReverse
                [1.1] requires a string argument 'text'
                [1.2] returns text but with its sequence reversed
            [2] has a recursive function maxDigit
                [2.1] requires an integer argument 'num'
                [2.2] returns largest digit from num
    */
    
    #include <iostream>
    using namespace std;
    
    string recurseReverse(string text) {
        int text_Length = text.length();
        if (text_Length == 0) { // base case
            return text;
        }
        char last_char = text[text_Length - 1];
        return last_char + recurseReverse(text.substr(0, text_Length - 1));
    }
    
    int maxDigit(int num, int current_largest_digit = 0) {
        num = abs(num);
        if (num < 10) { // base case
            return current_largest_digit;
        }
        if (num % 10 >= current_largest_digit) {
            return maxDigit(num / 10, num % 10);
        }
        return maxDigit(num / 10, current_largest_digit);
    }
    
    int main() {
        // Part 1 //
        string input;
        cout << "Please enter a string to recurseReverse: " << endl;
        cin >> input;
        cout << recurseReverse(input);
        
        
        cout << endl << endl;
        
        // Part 2 //
        int input2;
        cout << "Please enter a positive integer to get maxDigit: " << endl;
        cout << "(Remember the range for integers: [-2147483647, 2147483647])" << endl;
        cin >> input2;
        cout << maxDigit(input2);
    
        return 0;
    }