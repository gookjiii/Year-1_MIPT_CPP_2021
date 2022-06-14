#include<iostream>
#include<stack>
#include<string>

int main() {
	std::string bracket_seq;
	std::stack<char> st;
	std::cin >> bracket_seq;
	for (int i = 0; i < bracket_seq.length(); i++) {
		if (bracket_seq[i] == '(' || bracket_seq[i] == '[')
		 st.push(bracket_seq[i]);
		if (bracket_seq[i] == ')' || bracket_seq[i] == ']') {
			if(st.empty()) {
				std::cout << "NO";
				return 0;
			}
			if (bracket_seq[i] == ']' && st.top() == '[' || bracket_seq[i] == ')' && st.top() == '(')
    st.pop();
   else {
   	std::cout << "NO";
   	return 0;
			} 
		}
	}
	if (!st.empty()) {
		std::cout << "NO";
  return 0;
	}
	std::cout << "YES";
	return 0;
}

