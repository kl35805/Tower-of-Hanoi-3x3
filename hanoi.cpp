#include "std_lib_facilities.h"

using namespace std;

//�Ϻ� �Լ��� ���͸� ���޹��� �� ȣ�� ����� call-by-reference�� �Ͽ� �Լ� �ȿ��� ������ ������ �����ϵ��� �߽��ϴ�.
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
	int count = 1; // �̵�Ƚ���Դϴ�.
	int exit = 1; // while���� �ݺ��Ǵ� �����Դϴ�.
	showtowers(tower1, tower2, tower3);
	while (1)
	{
		checkmove1(tower1, tower2, tower3, count);
		if (tower3.size() == 3 && tower3[0] == 3 && tower3[1] == 2 && tower3[2] == 1) // ������ �ذ�� ����Դϴ�.
		{
			char re;
			cout << endl << "Congratulation! You solved it in " << count - 1 << " moves!" << endl;
			cout << "Do you want to play again? (Y/N):";
			while (1)
			{
				cin >> re;
				if (re == 'Y')
				{
					tower1 = { 3,2,1 }; // ��հ� �̵�Ƚ���� �ʱ�ȭ�ϴ� �����Դϴ�.
					tower2.clear();
					tower3.clear();
					count = 1;
					cout << endl;
					showtowers(tower1, tower2, tower3);
					break;
				}
				else if (re == 'N')// ������ �ذ�Ǿ��� ������� ���� �ʴ� ��쿡 exit�� 0���� ����� ���α׷��� ����ǵ��� �մϴ�.
				{
					exit = 0;
					break;
				}
				else
				{
					cout << endl << "Try again. (Y/N):"; // Y�� N�� �ƴ� �ٸ� ���ڰ� �ԷµǸ� �ٽ� �Է¹޵��� �մϴ�.
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
// ��� ��ȣ�� �Է¹ް� �� ��ȣ�� �ùٸ��� Ȯ���ϴ� �Լ��Դϴ�.
{
	int before;
	int after;
	cout << endl << "[" << count << "] " << "From which tower will you move a disk to which tower? (from=[1|2|3], to=[1|2|3]): ";
	cin >> before >> after;
	if (before == after || before < 1 || before > 3 || after < 1 || after > 3)
		cout << "=> Move failed!" << endl; // �ùٸ��� ���� ���� checkmove2�� ȣ������ �ʽ��ϴ�.
	else
		checkmove2(t1, t2, t3, before, after, count); // �̻��� ���ٸ� checkmove2�� ȣ���մϴ�.
}

void checkmove2(vector <int>& t1, vector <int>& t2, vector<int>& t3, int i, int f, int& count)
// ���� ������ ���Ͱ� �̹� ����ִ��� Ȯ���ϴ� �Լ��Դϴ�.
// i�� f�� ���п��� ó���� ������ ��Ÿ���� ��ȣ�Դϴ�.
{
	if (i == 1 && t1.empty() == true) // �ùٸ��� ���� ���� checkmpve3�� ȣ������ �ʽ��ϴ�.
		cout << "=> Move failed!" << endl;
	else if (i == 2 && t2.empty() == true)
		cout << "=> Move failed!" << endl;
	else if (i == 3 && t3.empty() == true)
		cout << "=> Move failed!" << endl;
	else
		checkmove3(t1, t2, t3, i, f, count); // �̻��� ���ٸ� checkmove3�� ȣ���մϴ�.
}

void checkmove3(vector <int>& t1, vector <int>& t2, vector<int>& t3, int i, int f, int& count)
// ���Ϳ��� ���� ������ ���� �̹� �ִ� ������ �������� Ȯ���ϴ� �Լ��Դϴ�.
// �Է¹��� ���͵��� ��ȣ�� ���� if���� �����߽��ϴ�.
{
	if (i == 1)
	{
		if (f == 2)
		{
			if (t2.empty() == true) // ���� ������ ���Ͱ� ����ִ� ����Դϴ�. �� ���� movedisk�� ȣ���մϴ�.
			{
				cout << "=> Move succeeded!" << endl << endl;
				movedisk(t1, t2, t3, i, f, count);
			}
			else
			{
				if (t1.back() > t2.back())// ������ ���� �̹� �ִ� ������ ū ����Դϴ�. �� ���� movedisk�� ȣ������ �ʽ��ϴ�.
					cout << "=> Move failed!" << endl;
				else // �̻��� ���� ��쿡�� movedisk�� ȣ���մϴ�.
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
// ���͵鰣�� ���� ������ ������ �Ͼ�� �Լ��Դϴ�.
// push_back�Լ��� �̿��� ���� ������ ���Ϳ� ���� ����ְ� pop_back�Լ��� ���� ���� ������ ���Ϳ��� ���� �����մϴ�.
// �Է¹��� ���͵��� ��ȣ�� ���� switch���� �����߽��ϴ�.
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
	count++; // �̵� Ƚ���� 1�� ������ŵ�ϴ�.
}

void showtowers(vector <int> t1, vector <int> t2, vector<int> t3)
//���� ��Ȳ�� �����ִ� �Լ��Դϴ�.
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



