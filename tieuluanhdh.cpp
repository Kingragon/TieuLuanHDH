#include<iostream>
using namespace std;
void Calculate();
void IMP();
int allocation[10][3], need[10][3], Max[10][3], available[10][3];
int p, current[3];
bool executed[10], come;
int main() {
	int keepon = 1;
	cout << " Nhap so tien trinh: ";
	cin >> p;
	cout << "\n";
	cout << " Nhap Available: ";
	cin >> current[0] >> current[1] >> current[2];
	for (int i = 0; i < p; ++i)
	{
		cout << "\n\n\t\t\tTien trinh P" << i << " la: \n";
		cout << " Nhap Allocation: ";
		cin >> allocation[i][0] >> allocation[i][1] >> allocation[i][2];
		cout << " Nhap Max :";
		cin >> Max[i][0] >> Max[i][1] >> Max[i][2];
		need[i][0] = Max[i][0] - allocation[i][0]; need[i][1] = Max[i][1] - allocation[i][1]; need[i][2] = Max[i][2] - allocation[i][2];
	}
	cout << "\n\n\t\t\t Bang giai thuat banker theo yeu cau\n\n";
	cout << "Tai nguyen con lai: " << current[0] << " " << current[1] << " " << current[2] << "\n\n";
	cout << "Tien trinh    Max       Allocation      Need\n";
	for (int i = 0; i < p; ++i)
	{
		cout << "  P" << i << "       ";
		cout << "  " << Max[i][0] << " " << Max[i][1] << " " << Max[i][2] << "     ";
		cout << " " << allocation[i][0] << " " << allocation[i][1] << " " << allocation[i][2] << "          ";
		cout << " " << need[i][0] << " " << need[i][1] << " " << need[i][2];
		cout << "\n";
	}	
	cout << "\n\n";
	cout << " Vay thu tu thuc hien so tien va work la :\n";
	Calculate();
	return 0;
}
void Calculate() {
	IMP();
	int i, j;
	for (i = 0; i < p; ++i)
	{
		for (j = 0; j < p; ++j)
		{
			while (executed[j] && j < p - 1) {
				j++;
			}
			if (need[j][0] <= current[0] && need[j][1] <= current[1] && need[j][2] <= current[2])
			{
				if (!executed[j])
				{
					executed[j] = true;
					current[0] += allocation[j][0]; current[1] += allocation[j][1]; current[2] += allocation[j][2];
					cout << "\nTien trinh P" <<j;
					cout << "\nTai nguyen thu hoi Work " << current[0] << " " << current[1] << " " << current[2] << "\n";
					come = true;
					break;
				}
			}
		}
		if (!come)
		{
			cout << "\n\t\t\tDead lock\n\n";
			break;
		}
		else {
			come = false;
		}
	}
}

void IMP() {
	come = false;
	for (int i = 0; i < 10; ++i)
	{
		executed[i] = false;
	}
}
