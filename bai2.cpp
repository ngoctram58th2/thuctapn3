#include <fstream>
#include<iostream>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include "console.h"
using namespace std;
	fstream fi;
	
int inputKey() //nhan phim
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)	// special key
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return key_none;
	}

	return key_none;
}


void clrscr()//xoa man hinh
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;                  
	HANDLE	hConsoleOut;
	COORD	Home = {0,0};
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}
//---------------------------------------------------------------------------------------------------------
void ShowCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
    SetConsoleCursorInfo(handle, &cursor);
}
//---------------------------------------------------------------------------------------------------------



void LuuFile(int A[50][50],int B[50][50], int &m, int &n) //luu 2 ma tran vao file
{

	fi.open("input2.txt", ios::out); //mo file de ghi
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
			fi << A[i][j] << " ";
		fi << endl;	
	}
	fi << endl;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
			fi << B[i][j] << " ";
		fi << endl;	
	}
	fi.close();
}

void LuuFile2(int C[50][50], int &m, int &n) //luu ket qua vao file
{
	fi.open("output2.txt", ios::out); //mo file de ghi
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
			fi << C[i][j] << " ";
		fi << endl;	
	}
	fi.close();
}

void Nhap(int A[50][50], int B[50][50],int &m, int &n)//nhap 2 ma tran
{
	clrscr();
	cout<<"Nhap m hang: ";
    cin >> m;
    cout<<"Nhap n cot: ";
    cin>> n;
    cout<<"Nhap ma tran A ("<<m<<" x "<<n<<")"<<endl;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++)
		{
            cout<<"A["<<i+1<<"]["<<j+1<<"]: ";
            cin>> A[i][j];
        }
    }
    
    cout<<"Nhap ma tran B ("<<m<<" x "<<n<<")"<<endl;
    for (int i=0; i<m; i++)
	{
        for (int j=0; j<n; j++)
		{
           cout<<"B["<<i+1<<"]["<<j+1<<"]: ";
            cin>> B[i][j];
        }
    }
    cout<<"Nhap thanh cong! Bam phim bat ky de thoat!";
}
void Tong(int A[50][50], int B[50][50],	int C[50][50], int &m, int &n)
{
	clrscr();
	 //tinh tong
    for (int i=0; i<m; i++)
	{
        for (int j=0; j<n; j++)
		{
            C[i][j]=A[i][j]+B[i][j];
        }
    }
    //hien
    for (int i=0; i<m; i++)
	{
        for (int j=0; j<n; j++)
        cout<< A[i][j]<<"   ";
        cout<<"\n";
    }
    printf("+\n");
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++)
        cout<< B[i][j]<<"   ";
        cout<<"\n";
    }
    printf("==============\n");
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++)
        cout<<C[i][j]<<"   ";
        cout<<"\n";
    fi.close();
    }//for
    cout<<"Bam phim bat ky de thoat!";
    getch();
}

void Hieu(int A[50][50], int B[50][50],	int C[50][50],int &m, int &n)//tinh hieu 2 ma tran
{
	clrscr();
	 //tinh tong
    for (int i=0; i<m; i++)
	{
        for (int j=0; j<n; j++)
		{
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    //hien
    for (int i=0; i<m; i++)
	{
        for (int j=0; j<n; j++)
        cout<< A[i][j]<<"   ";
        cout<<"\n";
    }
    printf("-\n");
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++)
        cout<< B[i][j]<<"   ";
        cout<<"\n";
    }
    printf("==============\n");
    for (int i=0; i<m; i++)
	{
        for (int j=0; j<n; j++)
        cout<<C[i][j]<<"   ";
        cout<<"\n";
    } 
	cout<<"Bam phim bat ky de thoat!";
    getch();
}

void Tich(int A[50][50], int B[50][50], int C[50][50], int &m, int &n)
{
	clrscr();
	for(int i = 0; i<n ; i++)
		for(int k = 0; k<n ; k++)
		{
			C[i][k] = 0;
			for(int j = 0; j<n ; j++)
				C[i][k] = C[i][k] + A[i][j]*B[j][k];
		}
	//hien thi	
	 for (int i=0; i<m; i++)
	{
        for (int j=0; j<n; j++)
        cout<< A[i][j]<<"   ";
        cout<<"\n";
    }
    printf("x\n");
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++)
        cout<< B[i][j]<<"   ";
        cout<<"\n";
    }
    printf("==============\n");
    for (int i=0; i<m; i++)
	{
        for (int j=0; j<n; j++)
        cout<<C[i][j]<<"   ";
        cout<<"\n";
    }
    cout<<"Bam phim bat ky de thoat!";
    getch();
}

void XuatKQ()//Xuat kq tu file text
{
	clrscr();
	string s;
	ifstream f("output2.txt");
	getline(f, s);// lay so tu file input2.txt
	// vong lap
	do
	{
		cout << s << endl;
		getline(f, s);
	}while(s.compare("") != 0);// neu dong cuoi cung trong file khong co gi het thi ket thuc viet doc
	f.close();	
	cout << "\nAn phim bat ki de tro lai Menu" << endl << endl;
	system("pause");
}

void menu()
{
	clrscr();
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"                                                ================="<<endl<<endl;
	cout<<"                                                    M E N U:"<<endl<<endl;
    cout<<"                                                1: Nhap ma tran"<<endl<<endl;
    cout<<"                                                2: Tong ma tran"<<endl<<endl;
    cout<<"                                                3: Hieu ma tran"<<endl<<endl;
    cout<<"                                                4: Tich ma tran"<<endl<<endl; 
	cout<<"                                                5: Xuat KQ"<<endl<<endl;                                            
    cout<<"                                                6: Thoat"<<endl<<endl;
}

int main()
{
    int A[50][50],B[50][50],C[50][50];
    int d=0;
    int  m, n;
    
    char sl; //dung de lam menu
	ShowCur(false); //an con tro
    while(1)
	{
		if(d==0) goto play;	
		play:
		menu();
		sl = _getch();
		switch(sl)
		{
			case '1':
			{
				Nhap(A,B,m,n);
				LuuFile(A, B, m, n);
				goto play;
				break;
			}
			//cac lua chon khac - cac chuc nang khac
        	case '2': 
       		{
            	Tong(A,B,C,m,n);
            	LuuFile2(C,m,n);
            	goto play;
           	 	break;
        	}
        	case '3':
        	{
           	 	Hieu(A,B,C,m,n); 
            	LuuFile2(C,m,n);
           	 	goto play;
           	 	break;
        	}
        	case '4':
        	{
           	 	Tich(A,B,C,m,n);
            	LuuFile2(C,m,n);
           	 	goto play;
           	 	break;
        	}
        	case '5':
        	{
           	 	XuatKQ();
           	 	goto play;
           	 	break;
        	}
        	case '6':
        	{
          	  	goto quit; //thoat meu
          	  	break;
        	}
       		default:
        	{
          	  	goto play;
          	  	break;
        	}
    	}
    	d++; //kiem tra so lan thuc hien cac chuc nang
	}
	quit:
	{
		clrscr();
  		cout<<"Tam biet!"; //dung menu
	}
	return 0;
}
