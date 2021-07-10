#include "std_lib_facilities.h"

using namespace std;

//일부 함수는 벡터를 전달받을 때 호출 방식을 call-by-reference로 하여 함수 안에서 벡터의 변경이 가능하도록 했습니다.
void checkmove1(vector <int>& t1, vector <int>& t2, vector<int>& t3, int& count);
void checkmove2(vector <int>& t1, vector <int>& t2, vector<int>& t3, int i, int f, int& count);
void checkmove3(vector <int>& t1, vector <int>& t2, vector<int>& t3, int i, int f, int& count);
void movedisk(vector <int>& t1, vector <int>& t2, vector<int>& t3, int i, int f, int & count);
void showtowers(vector <int> t1, vector <int> t2, vector<int> t3);

int main()
{
	vector <int> tower1 = { 3,2,1 };
	vector <int> tower2;
	vector <int> tower3;
	int count = 1; // 이동횟수입니다.
	int exit = 1; // while문이 반복되는 조건입니다.
	showtowers(tower1, tower2, tower3);
	while (1)
	{
		checkmove1(tower1, tower2, tower3, count);
		if (tower3.size() == 3 && tower3[0] == 3 && tower3[1] == 2 && tower3[2] == 1) // 문제가 해결된 경우입니다.
		{
			char re;
			cout << endl << "Congratulation! You solved it in " << count - 1 << " moves!" << endl;
			cout << "Do you want to play again? (Y/N):";
			while (1)
			{
				cin >> re;
				if (re == 'Y')
				{
					tower1 = { 3,2,1 }; // 기둥과 이동횟수를 초기화하는 과정입니다.
					tower2.clear();
					tower3.clear();
					count = 1;
					cout << endl;
					showtowers(tower1, tower2, tower3);
					break;
				}
				else if (re == 'N')// 문제가 해결되었고 재시작을 하지 않는 경우에 exit을 0으로 만들어 프로그램이 종료되도록 합니다.
				{
					exit = 0;
					break;
				}
				else
				{
					cout << endl << "Try again. (Y/N):"; // Y나 N이 아닌 다른 문자가 입력되면 다시 입력받도록 합니다.
					continue;
				}
			}
		}
		if (exit == 0)
		{
			cout << endl << "Bye bye!" << endl;
			break;
		}
		else
			continue;
	}

	return 0;
}

void checkmove1(vector <int>&t1, vector <int>&t2, vector<int>&t3, int& count)
// 기둥 번호를 입력받고 그 번호가 올바른지 확인하는 함수입니다.
{
	int before;
	int after;
	cout << endl << "[" << count << "] " << "From which tower will you move a disk to which tower? (from=[1|2|3], to=[1|2|3]): ";
	cin >> before >> after;
	if (before == after || before < 1 || before > 3 || after < 1 || after > 3)
		cout << "=> Move failed!" << endl; // 올바르지 않은 경우는 checkmove2를 호출하지 않습니다.
	else
		checkmove2(t1, t2, t3, before, after, count); // 이상이 없다면 checkmove2를 호출합니다.
}

void checkmove2(vector <int>& t1, vector <int>& t2, vector<int>& t3, int i, int f, int& count)
// 값이 뽑히는 벡터가 이미 비어있는지 확인하는 함수입니다.
// i와 f는 수학에서 처음과 나중을 나타내는 기호입니다.
{
	if (i == 1 && t1.empty() == true) // 올바르지 않은 경우는 checkmpve3을 호출하지 않습니다.
		cout << "=> Move failed!" << endl;
	else if (i == 2 && t2.empty() == true)
		cout << "=> Move failed!" << endl;
	else if (i == 3 && t3.empty() == true)
		cout << "=> Move failed!" << endl;
	else
		checkmove3(t1, t2, t3, i, f, count); // 이상이 없다면 checkmove3을 호출합니다.
}

void checkmove3(vector <int>& t1, vector <int>& t2, vector<int>& t3, int i, int f, int& count)
// 벡터에서 새로 들어오는 값이 이미 있는 값보다 작은지를 확인하는 함수입니다.
// 입력받은 벡터들의 번호에 따라서 if문을 구성했습니다.
{
	if (i == 1)
	{
		if (f == 2)
		{
			if (t2.empty() == true) // 값이 들어오는 벡터가 비어있는 경우입니다. 이 경우는 movedisk를 호출합니다.
			{
				cout << "=> Move succeeded!" << endl << endl;
				movedisk(t1, t2, t3, i, f, count);
			}
			else
			{
				if (t1.back() > t2.back())// 들어오는 값이 이미 있는 값보다 큰 경우입니다. 이 경우는 movedisk를 호출하지 않습니다.
					cout << "=> Move failed!" << endl;
				else // 이상이 없는 경우에는 movedisk를 호출합니다.
				{
					cout << "=> Move succeeded!" << endl << endl;
					movedisk(t1, t2, t3, i, f, count);
				}
			}
		}
		if (f == 3)
		{
			if (t3.empty() == true)
			{
				cout << "=> Move succeeded!" << endl << endl;
				movedisk(t1, t2, t3, i, f, count);
			}
			else
			{
				if (t1.back() > t3.back())
					cout << "=> Move failed!" << endl;
				else
				{
					cout << "=> Move succeeded!" << endl << endl;
					movedisk(t1, t2, t3, i, f, count);
				}
			}
		}
	}
	if (i == 2)
	{
		if (f == 1)
		{
			if (t1.empty() == true)
			{
				cout << "=> Move succeeded!" << endl << endl;
				movedisk(t1, t2, t3, i, f, count);
			}
			else
			{
				if (t2.back() > t1.back())
					cout << "=> Move failed!" << endl;
				else
				{
					cout << "=> Move succeeded!" << endl << endl;
					movedisk(t1, t2, t3, i, f, count);
				}
			}
		}
		if (f == 3)
		{
			if (t3.empty() == true)
			{
				cout << "=> Move succeeded!" << endl << endl;
				movedisk(t1, t2, t3, i, f, count);
			}
			else
			{
				if (t2.back() > t3.back())
					cout << "=> Move failed!" << endl;
				else
				{
					cout << "=> Move succeeded!" << endl << endl;
					movedisk(t1, t2, t3, i, f, count);
				}
			}
		}
	}
	if (i == 3)
	{
		if (f == 1)
		{
			if (t1.empty() == true)
			{
				cout << "=> Move succeeded!" << endl << endl;
				movedisk(t1, t2, t3, i, f, count);
			}
			else
			{
				if (t3.back() > t1.back())
					cout << "=> Move failed!" << endl;
				else
				{
					cout << "=> Move succeeded!" << endl << endl;
					movedisk(t1, t2, t3, i, f, count);
				}
			}
		}
		if (f == 2)
		{
			if (t2.empty() == true)
			{
				cout << "=> Move succeeded!" << endl << endl;
				movedisk(t1, t2, t3, i, f, count);
			}
			else
			{
				if (t3.back() > t2.back())
					cout << "=> Move failed!" << endl;
				else
				{
					cout << "=> Move succeeded!" << endl << endl;
					movedisk(t1, t2, t3, i, f, count);
				}
			}
		}
	}
}

void movedisk(vector <int>& t1, vector <int>& t2, vector<int>& t3, int i, int f, int& count)
// 벡터들간의 값이 변경이 실제로 일어나는 함수입니다.
// push_back함수를 이용해 값이 들어오는 벡터에 값을 집어넣고 pop_back함수를 통해 값이 뽑히는 벡터에서 값을 제거합니다.
// 입력받은 벡터들의 번호에 따라 switch문을 구성했습니다.
{
	switch (i)
	{
	case 1:
		switch (f)
		{
		case 2:
			t2.push_back(t1.back());
			t1.pop_back();
			break;
		case 3:
			t3.push_back(t1.back());
			t1.pop_back();
			break;
		}
		break;
	case 2:
		switch (f)
		{
		case 1:
			t1.push_back(t2.back());
			t2.pop_back();
			break;
		case 3:
			t3.push_back(t2.back());
			t2.pop_back();
			break;
		}
		break;
	case 3:
		switch (f)
		{
		case 1:
			t1.push_back(t3.back());
			t3.pop_back();
			break;
		case 2:
			t2.push_back(t3.back());
			t3.pop_back();
			break;
		}
		break;
	}
	showtowers(t1, t2, t3);
	count++; // 이동 횟수를 1씩 증가시킵니다.
}

void showtowers(vector <int> t1, vector <int> t2, vector<int> t3)
//진행 상황을 보여주는 함수입니다.
{
	cout << "[1] ";
	for (int x : t1)
		cout << x << ' ';
	cout << endl;
	cout << "[2] ";
	for (int y : t2)
		cout << y << ' ';
	cout << endl;
	cout << "[3] ";
	for (int z : t3)
		cout << z << ' ';
	cout << endl;
}



