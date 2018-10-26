#include <iostream>
#include <queue>
using namespace std;
struct Node {
	int r, c;//位置
	int t;//查克拉剩余
	int level;//所在层数，路径长度
};
char map[200][200];
int visited[200][200][10] = { 0 };
int M, N, T;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int main() {
	int startr, startc;
	int endr, endc;
	cin >> M >> N >> T;
	for (int i = 0;i < M;++i) {
		for (int j = 0;j < N;++j) {
			cin >> map[i][j];
			if (map[i][j] == '@') {
				startr = i;
				startc = j;
			}
			if (map[i][j] == '+') {
				endr = i;
				endc = j;
			}
		}
	}
	visited[startr][startc][T] = 1;
	queue<Node>q;
	Node node;
	node.r = startr;node.c = startc;node.level = 0;node.t = T;
	q.push(node);
	while (!q.empty()) {
		Node temp = q.front();
		q.pop();
		if (temp.r == endr && temp.c == endc) {
			cout << temp.level;
			return 0;
		}
		else {
			for (int i = 0;i < 4;i++) {
				Node temp2;
				temp2.r = temp.r + dir[i][0];
				temp2.c = temp.c + dir[i][1];
				if (temp2.r >= 0 && temp2.r < M&&temp2.c >= 0 && temp2.c < N) {
					if (map[temp2.r][temp2.c] == '#'&&temp.t >= 1 && visited[temp2.r][temp2.c][temp.t - 1] == 0) {
						temp2.t = temp.t - 1;
						temp2.level = temp.level + 1;
						q.push(temp2);
						visited[temp2.r][temp2.c][temp.t - 1] = 1;
					}
					else if (map[temp2.r][temp2.c] != '#'&&visited[temp2.r][temp2.c][temp.t] == 0) {
						temp2.t = temp.t;
						temp2.level = temp.level + 1;
						q.push(temp2);
						visited[temp2.r][temp2.c][temp.t] = 1;
					}
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
