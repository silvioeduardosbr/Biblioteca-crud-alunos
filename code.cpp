#include <bits/stdc++.h>

using namespace std; 

int main(){

	vector<int> a;
	vector<int> b(4,100);
	vector<int> c(b.begin(),b.end());
	vector<int> d(c);
	
	a.push_back(300);
	a.push_back(200);
	a.front() = b.back();	
	
	return 0;
}

