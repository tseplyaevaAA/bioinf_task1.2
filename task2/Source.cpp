#include "stdio.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string PatternCount(string text, int n){

	string str;
	string result_str;
	int count = 1;
	int max = 0;
	int length1 = text.length();
	int length2 = n;
	int k = 0;
	int l;

	for (int c = 0; c < (length1 - length2 + 1); c++){
		
		int pat = 0;
		int tind = c;

		while (pat < length2){ 
			str += text[tind];
			tind++;
			pat++;
		}
		
		const char* pattern = str.c_str();
		
		
		int i = c + 1;
		for ( i  ; i < (length1 - length2 +1); i++){
			int j = 0;
			l = i;
			k = 0;
			while (j < length2){
				if (text[l] == pattern[j]){
					k++;
				}
				l++;
				j++;
			}
			if (k == length2){
				count++;
			}
		}

		if (count > max){
			result_str = "";
			result_str += pattern;
			max = count;
		}
		else{
			if (count == max){
				result_str += " ";
				result_str += pattern;

			}
		}
		count = 1;
		pattern = "";
		str = "";
		
	}

	return result_str;
}

int main(){

	FILE* input_file;
	input_file = fopen("input.txt", "r");
	string* str1 = new string[2];
	input_file = fopen("input.txt", "rb");
	if (getc(input_file) == EOF){
		cout << "empty file";
		fclose(input_file);
	}
	else{
		fclose(input_file);
		ifstream input("input.txt", ios_base::in);
		for (int i = 0; i < 2; i++) {
			getline(input, str1[i]);
		}

		string chislo = string(str1[1]);
		int m = atoi(chislo.c_str());
		
		
		string res;
		res = PatternCount(str1[0], m);
		ofstream new_file("output.txt");
		new_file << res;
		new_file.close();
	}
	delete[] str1;
	return 0;
}