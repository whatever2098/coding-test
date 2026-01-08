#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isCorrect(string b) {
	int bal{ 0 };
	for(auto& c : b){
		if (c == '(') bal++;
		else { bal--; }
	}
	if (bal < 0) return false;

	return bal == 0;
}