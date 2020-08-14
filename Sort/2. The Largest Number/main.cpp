#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string x, string y) {
    // 첫번째 패러미터를 앞으로 정렬할 것인지 아닌지 판단
    // x + y가 y + x보다 더 큰 값을 가지는 경우에만 x를 앞으로 정렬
    // 그렇지 않을 경우에는 y를 앞으로 정렬
    return (x + y > y + x);
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> toBeSorted;
    for(int num : numbers){
        toBeSorted.push_back(to_string(num));
    }
    sort(toBeSorted.begin(), toBeSorted.end(), comp);
    if(toBeSorted.at(0) == "0") return "0";
    for(string str : toBeSorted){
        answer += str;
    }
    return answer;
}
