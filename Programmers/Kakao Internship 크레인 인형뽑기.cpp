#include <string>
#include <vector>
//#include <iostream>

using namespace std;

//주석처리된 부분은 Visual Studio에서 디버깅을 위한 출력
int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<int> bucket;
	for (int i = 0; i < moves.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[j][moves[i] - 1]) {
				bucket.push_back(board[j][moves[i] - 1]);
				//cout << moves[i] - 1 << ": "<< board[j][moves[i] - 1] << '\n';
				board[j][moves[i] - 1] = 0;
				if (bucket.size() >= 2
					&& bucket[bucket.size() - 1] == bucket[bucket.size() - 2]) {
					answer = answer + 2;
					//cout << bucket[bucket.size() - 1];
					//cout << bucket[bucket.size() - 2];
					bucket.pop_back();
					bucket.pop_back();
				}
				break;
			}
		}
	}
	return answer;
}

//main은 Programmers 사이트에선 작성 안해도 된다
int main() {
	vector<vector<int>> board = { {0, 0, 0, 0, 0} ,{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
	vector<int> move = { 1, 5, 3, 5, 1, 2, 1, 4 };

	//solution(board, move);
	cout << solution(board, move);
}
