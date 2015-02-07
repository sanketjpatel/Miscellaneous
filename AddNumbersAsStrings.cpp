/****************************************** 
 * Add two numbers represented as strings *
 * Author: Sanket Patel					  *
 ******************************************/
#include <iostream>
#include <string>

using namespace std;

// Reverses a string
string reverse(string s) {
	for (int i=0, j=s.length()-1; i<j; i++, j--){
		s.at(i) ^= s.at(j);
		s.at(j) ^= s.at(i);
		s.at(i) ^= s.at(j);
	}
	return s;
}

// Removes leading zeros from a number
string remLeadZeros(string s) {
	if (s == "" || s == "-") return "0";
	string ans = (s.at(0)=='-') ? "-" : "";
	for (int i = (s.at(0)=='-') ? 1 : 0; i<s.length(); i++){
		if (s.at(i) != '0' && s.at(i) != '-'){
			ans += s.substr(i);
			break;
		}
	}
	if (ans == "" || ans == "-") return "0";
	return ans;
}

/*
 * Works on positive and negative numbers
 * Input strings should be numbers (will give a wrong answer if not)
 * Approach to solve the problem: 
 * Add each char by char from unit's place onwards
 * Finally reverse to get result
 */
string add(string str1, string str2) {
	
	// Remove leading zeros. Converts empty string to "0"
	str1 = remLeadZeros(str1);
	str2 = remLeadZeros(str2);
	
	// At least one number is not empty or zero
	if (str1 == "0") return str2;
	if (str2 == "0") return str1;
	
	int size1 = str1.length();
	int size2 = str2.length();

	// Flags to maintain sign of numbers while adding
	int flag1 = (str1.at(0) == '-') ? -1 : 1;
	int flag2 = (str2.at(0) == '-') ? -1 : 1;
	
	if (flag1 == -1) size1--;
	if (flag2 == -1) size2--;
	
	// Flags will take care of negative numbers. Retain only the number part
	// num1 is the longer number to make subsequent code cleaner
	string num1, num2;
	if(size1 >= size2){
		num1 = str1;
		num2 = str2;
	}
	else{
		// num1, flag1, and size1 should represent str2. 
		// num2, flag2, and size2 should represent str1.
		num1 = str2;
		num2 = str1;
		
		// Swap flag1 and flag2.
		int x = flag1;
		flag1 = flag2;
		flag2 = x;
		
		// Swap size1 and size2. Now, size1 > size2
		x = size1;
		size1 = size2;
		size2 = x;
	}
	
	string ans = "";
	int temp = 0, carry = 0;
	char c;
	
	for (int i=0; i<size2; i++){
		temp = flag1*(num1.at(num1.length()-1-i)-'0') + flag2*(num2.at(num2.length()-1-i)-'0') + carry;
		carry = temp/10;
		if (temp < 0) {
			carry--;
			temp = (temp%10) - (carry * 10); // carry is already negative
		}
		c = (char)(temp % 10) + '0';
		ans += c;
	}
	
	for (int i=size2; i<size1; i++){
		temp = flag1*(num1.at(num1.length()-1-i)-'0') + carry;
		carry = temp/10;
		if (temp < 0){
			carry--;
			temp = (temp%10) - (carry * 10);
		}
		c = (char)(temp % 10) + '0';
		ans += c;
	}
	
	if (carry > 0){
		c = (char)carry + '0';
		ans += c;	
	}
	else if(carry < 0){
		int i = 0;
		while (ans.at(i)=='0') i++;
		if (i == ans.length()) c = (char) (-carry) + '0';
		else {
			ans.at(i) = '9' - ans.at(i) + '1';
			i++;
			while (i < ans.length()) {
				c = '9' - ans.at(i) + '0';
				ans.at(i) = c;
				i++;
			}
			c = (char)(-carry - 1) + '0';
		}
		ans += c;
		ans += '-';
	}
	
	return remLeadZeros(reverse(ans));
}

int main() {
	// your code goes here
	string s1 = "000500247527623469872034752809734658290734508276598";
	string s2 = "-050000002983745692873459827365982765982735649826345";
	cout << add(s1, s2) << endl;
	return 0;
}