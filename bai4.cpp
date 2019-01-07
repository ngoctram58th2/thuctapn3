#include<iostream>
using namespace std;
fstream fi;

void DocFile(int a[10][10], int n) //doc file
{
	fi.open("Bai4.inp.txt", ios::in);//mo file de doc
	for(int i = 0; i < n; i++)
	{
		for(int j=0;j < n; j++)
			fi>>a[i][j];
	}
	fi.close();
}

void LuuFile(int a[10][10], int n)
{
	fi.open("Bai4.out.txt", ios::out);//mo file de ghi
	for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			fi<<a[i][j];
		}
	fi.close();
}
