#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
	  if(x < 0 || (x % 10 == 0 && x != 0))return false;
    int reversedNumber = 0;
    while(x > reversedNumber){
        reversedNumber = reversedNumber * 10 + (x % 10);
        x /= 10;
    }
    return x == reversedNumber || x == reversedNumber/10;
}

int main() {
	int number;
	cin >> number;
	cout << (isPalindrome(number)?"true":"false");
	return 0;
}
