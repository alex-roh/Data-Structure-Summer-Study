#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int yellow_width, yellow_height; // yellow_width >= yellow_height
    int widthPlusHeight = ((brown - yellow) / 2) - 2;
    
    for(yellow_width = 1; yellow_width < INT_MAX - 1; yellow_width++){
        for(yellow_height = 1; yellow_height <= yellow_width; yellow_height++){
            if(yellow_width + yellow_height == widthPlusHeight) goto end;
        }
    }
    
    end:
    
    answer.push_back(yellow_width + 2);
    answer.push_back(yellow_height + 2);
    
    return answer;
}

int main(){
	
	vector<int> sol(solution(8, 1));
	for(int i = 0; i < sol.size(); i++){
		cout << sol[i] << " ";
	}
	cout << "\n";

}
