#include<bits/stdc++.h>
using namespace std;

string replace_str(string &str,string from,string to){
	const unsigned int pos=str.find(from);
	const int len=from.length();
	if(pos==string::npos || from.empty()) return str;
	return str.replace(pos,len,to);
}

/*
sample

replace_str(string,from,to);

stringの中にあるfromの文字列をtoに置換
 */
