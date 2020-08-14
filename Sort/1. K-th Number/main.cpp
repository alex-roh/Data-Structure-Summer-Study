#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    int i, j, k;
    int index;
    
    for(int index = 0; index < commands.size(); index++){
    
        vector<int> tempArr(array);
        vector<int>::iterator s = tempArr.begin();
        vector<int>::iterator e = tempArr.end();
        e--;
        
        i = commands.at(index).at(0) - 1;
        j = array.size() - commands.at(index).at(1) - 1; 
		k = commands.at(index).at(2) - 1;
		
        for(int temp = 0; temp < i; temp++) s++;  
        for(int temp = 0; temp < j; temp++) e--;
        
        sort(s, e);
        
        answer.push_back(tempArr.at(k + i));
        
    }
    
    return answer;
}

int main(){
	
	vector<int> arr1 = {2, 5, 3};
	vector<int> arr2 = {4, 4, 1};
	vector<int> arr3 = {1, 7, 3};
	
	vector<int> arr = {1, 5, 2, 6, 3, 7, 4};
	
	vector<vector<int>> commands; 
	commands.push_back(arr1);
	commands.push_back(arr2);
	commands.push_back(arr3);
	
	vector<int> ans = solution(arr, commands);
	
	return 0;
}
