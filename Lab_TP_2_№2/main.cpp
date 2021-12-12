#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isVowel(char x) {
	return (tolower(x) == 'a' || tolower(x) == 'e' || tolower(x) == 'i' ||
		tolower(x) == 'o' || tolower(x) == 'u');	
}

int main() {
	string line = "";
	string sec;
	ifstream in("eng.txt");
	if (in.is_open()) 
	{

		while (getline(in, sec))
		{
			line += sec;
			line += "\n";
		}
		cout << line << endl;

			bool isWord = false;
		for (int i = 0; i < line.size(); i++) {
			if (!isalpha(line[i]))
				isWord = false;
			else {
				if (!isWord) {
					isWord = true;
					if (isVowel(line[i]))
						line[i] = tolower(line[i]);
				}
			}
		}
		cout << line << endl;
	}
	in.close();
}