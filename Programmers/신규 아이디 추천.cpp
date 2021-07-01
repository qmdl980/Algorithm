#include <string>
#include <vector>

using namespace std;

bool isnum(char a) {
	if (a == '0' || a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9') {
		return true;
	}
	else {
		return false;
	}
}

string solution(string new_id) {
	vector<char> temp;

	//1, 2
	for (int i = 0; i < new_id.length(); i++) {
		new_id[i] = tolower(new_id[i]);
	}
	for (int i = 0; i < new_id.length(); i++) {
		if (isalpha(new_id[i]) == 1024 || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.' || isnum(new_id[i])) {
            
			temp.push_back(new_id[i]);
		}
	}
	
    
	//3
	vector<char> temp2;
	for (int i = 0; i < temp.size(); i++) {
		temp2.push_back(temp[i]);
		if (temp[i] == '.') {
			for (int j = i; j < temp.size(); j++) {
				if (temp[j] != '.') {
					i = j-1;
					break;
				}
			}
		}
	}

	//4
    while(temp2[0] == '.'){
        temp2.erase(temp2.begin());
        if(temp2.size() == 0){ break; }
    }
    while(temp2[temp2.size()-1] == '.'){
        temp2.pop_back();
        if(temp2.size() == 0){ break; }
    }
	
	//5
	if (temp2.size() == 0) {
		temp2.push_back('a');
	}

	//6
	if (temp2.size() > 15) {
		temp2.erase(temp2.begin() + 15, temp2.end());
	}
    while(temp2[temp2.size()-1] == '.'){
        temp2.pop_back();
        if(temp2.size() == 0){ break; }
    }

	//7
	while (temp2.size() < 3) {
		temp2.push_back(temp2[temp2.size() - 1]);
	}
	
	string answer{ temp2.begin(), temp2.end() };  
	return answer;
}
