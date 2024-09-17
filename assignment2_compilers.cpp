#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

int evaluate(int num1, int num2, string op){
        if(op == "+") return num1 + num2;
        if(op == "-") return num2 - num1;
        if(op == "*") return num1 * num2;
        return num2 / num1;
}

int eval(vector<string>& tokens){
    stack<int> stack;
        for(auto token : tokens){
            if(
                token == "+" ||
                token == "-" ||
                token == "*" ||
                token == "/"
            ){
                int num1 = stack.top();
                stack.pop();
                int num2 = stack.top();
                stack.pop();
                int ans = evaluate(num1, num2, token);
                stack.push(ans);
            }
            else {
                stack.push(stoi(token));
            }
        }
        return stack.top();
}

int main(){
    vector<string> words;
    vector<string> input_str;
    
    // Read input from the user
    string input;
    cout << "Enter a postfix expression with a $ at the end:\n";
    getline(cin, input); // Read the full line of input from the user

    // Create a stream object from the input string
    istringstream stream(input);
    string word;

    // Extract and store each word from stream
    while (stream >> word) {
        input_str.push_back(word);
        if(isalpha(word[0])) words.push_back(word);
    }

    for(auto word : words){
        string val;
        cout << "Enter the value of " << word << ": ";
        cin >> val;
        
        // Search for word in original input string and replace word with user provided value
        for(int i = 0; i < input_str.size(); i++){
            if(input_str[i] == word)
                input_str[i] = val;
        }

    }

    input_str.pop_back(); // Eliminate terminating character for final processing ('$')

    int result = eval(input_str);
    cout << "Expressions value is " << result << '\n';

    return 0;
}
