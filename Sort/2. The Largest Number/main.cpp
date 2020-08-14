#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string x, string y) {
    // ù��° �з����͸� ������ ������ ������ �ƴ��� �Ǵ�
    // x + y�� y + x���� �� ū ���� ������ ��쿡�� x�� ������ ����
    // �׷��� ���� ��쿡�� y�� ������ ����
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
