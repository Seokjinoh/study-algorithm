#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>

/*
백준 12100번 2048(Easy)

DFS 문제

*/



#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

using namespace std;

int N;
int board[21][21] = { 0, };
int MaxValue = 0;
bool fusion[21][21] = { 0, };
int cnt = 0;
vector<int> st;

void print(int step, int Max)
{
	cout <<"Step size: "<< step<<", Max: "<<Max<<"======print map=======\n";
	for (int i = 0; i < N; i++)
	{
		cout << '\n';
		for (int j = 0; j < N; j++)
		{
			cout << board[i][j] << " ";
		}
	}
	cout << "\n======print map=======\n";
}

void Move(int dir)
{
	switch (dir)
	{
	case UP:
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int origin = board[i][j];
				int ci = i;
				int cj = j;
				int ni = i - 1;
				int nj = j;
				while (ni >= 0 && ni < N && nj >= 0 && nj < N)
				{
					//print();
					if (board[ni][nj] == 0)
					{
						board[ni][nj] = origin;
						board[ci][cj] = 0;
						ci = ni;
						ni--;
						continue;
					}
					else if (board[ni][nj] == board[ci][cj] && !fusion[ni][nj])
					{
						board[ci][cj] = 0;
						board[ni][nj] *= 2;
						fusion[ni][nj] = 1;
						break;
					}
					
					break;
				}
			}
		}
		break;
	case DOWN:
		for (int i = N - 1; i >= 0; i--)
		{
			for (int j = 0; j < N; j++)
			{

				int origin = board[i][j];
				int ci = i;
				int cj = j;
				int ni = i + 1;
				int nj = j;
				while (ni >= 0 && ni < N && nj >= 0 && nj < N)
				{
					//print();
					if (board[ni][nj] == 0)
					{
						board[ni][nj] = origin;
						board[ci][cj] = 0;
						ci = ni;
						ni++;
						continue;
					}
					else if (board[ni][nj] == board[ci][cj] && !fusion[ni][nj])
					{
						board[ci][cj] = 0;
						board[ni][nj] *= 2;
						fusion[ni][nj] = 1;
						break;
					}

					break;
				}
			}
		}
		break;
	case LEFT:
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{

				int origin = board[i][j];
				int ci = i;
				int cj = j;
				int ni = i;
				int nj = j-1;
				while (ni >= 0 && ni < N && nj >= 0 && nj < N)
				{
					//print();
					if (board[ni][nj] == 0)
					{
						board[ni][nj] = origin;
						board[ci][cj] = 0;
						cj = nj;
						nj--;
						continue;
					}
					else if (board[ni][nj] == board[ci][cj] && !fusion[ni][nj])
					{
						board[ci][cj] = 0;
						board[ni][nj] *= 2;
						fusion[ni][nj] = 1;
						break;
					}

					break;
				}
			}
		}
		break;
	case RIGHT:
		for (int i = 0; i < N; i++)
		{
			for (int j = N - 1; j >= 0; j--)
			{

				int origin = board[i][j];
				int ci = i;
				int cj = j;
				int ni = i;
				int nj = j+1;
				while (ni >= 0 && ni < N && nj >= 0 && nj < N)
				{
					//print();
					if (board[ni][nj] == 0)
					{
						board[ni][nj] = origin;
						board[ci][cj] = 0;
						cj = nj;
						nj++;
						continue;
					}
					else if (board[ni][nj] == board[ci][cj] && !fusion[ni][nj])
					{
						board[ci][cj] = 0;
						board[ni][nj] *= 2;
						fusion[ni][nj] = 1;
						break;
					}

					break;
				}
			}
		}
		break;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			fusion[i][j] = false;
		}
	}
}

int FindMax(void)
{
	int Max = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Max = max(Max, board[i][j]);
		}
	}
	return Max;
}

void dfs(int step)
{
	if (step >= 5)
	{
		MaxValue = max(MaxValue, FindMax());

		/*cout << ++cnt << '\n';
		if (MaxValue == 4096)
		{
			for (int k = 0; k < st.size(); k++)
			{
				switch (st[k])
				{
				case UP:
					cout << " UP ";
					break;
				case DOWN:
					cout << " DOWN ";
					break;
				case LEFT:
					cout << "LEFT ";
					break;
				case RIGHT:
					cout << " RIGHT ";
					break;
				default:
					break;
				}
				cout<<st[k];
			}
			//print(step, MaxValue);
		}*/
		return;
	}

	int tmp_board[21][21];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			tmp_board[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		st.push_back(i);
		Move(i);
		//print();
		dfs(step + 1);
		st.pop_back();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				board[i][j] = tmp_board[i][j];
			}
		}
	}

}



int main()
{
	freopen("text.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	dfs(0);
	cout << MaxValue;
	return 0;
}