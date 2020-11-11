#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<fstream>
#include<strings.h>
using namespace std;
void gotoxy(short y,short x)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void start( )
{
	system("cls");
	gotoxy(20,50);
	cout<<"LIBRARY";
	gotoxy(21,50);
	cout<<"MANAGEMENT";
	gotoxy(22,50);
	cout<<"SYSTEM";
	getch();
}
// BOOK START HERE 
class book
{
	char bknumber[20];
	char bkname[200];
	char authorname[100];
	public :
		void createbook();
		void showbook();
		void modifybook();
		char* returnbooknumber();
		void report();
		
		
};
void book::createbook()
{    system("cls") ;
     gotoxy(20,50);
	cout<<" NEW BOOK ENTRY";
	gotoxy(21,50);
	cout<<" ENTER THE BOOK NUMBER : ";
	cin>>bknumber;
	gotoxy(22,50);
	cout<<" ENTER BOOK NAME : ";
	cin.ignore();
	cin.getline(bkname,200);
	gotoxy(23,50);
	cout<<" ENTER AUTHOR NAME : ";
	//cin.ignore();
	cin.getline(authorname,100);
	gotoxy(24,50);
	cout<<" BOOK IS SUCCESSFULL REGISTERED ";
	getch();
	system("cls");
}
void book::showbook()
{      gotoxy(20,50);
	cout<<"BOOK NUMBER : "<<bknumber;
	   gotoxy(21,50);
	cout<<"BOOK NAME : "<<bkname;
	   gotoxy(22,50);
	cout<<"AUTHOR NAME :"<<authorname;
}
void book::modifybook( )
{
	system("cls") ;
     gotoxy(20,50);
	cout<<" CURRENT BOOK NUMBER       :  "<<bknumber;
	gotoxy(21,50);
	cout<<" ENTER MODIFED BOOK NUMBER : ";
	cin>>bknumber;
	gotoxy(22,50);
	cout<<" CURRENT BOOK NAME         : "<<bkname;
	gotoxy(23,50);
	cout<<" MODIFIED BOOK NAME        : ";
	cin.ignore();
	cin.getline(bkname,200);
	gotoxy(24,50);
	cout<<"CURRENT AUTHORE NAME       : "<<authorname;
	gotoxy(25,50);
	cout<<" ENTER AUTHOR NAME         : ";
	//cin.ignore();
	cin.getline(authorname,100);
	gotoxy(26,50);
	cout<<" BOOK IS SUCCESSFULL MODIFIED ";
	getch();
	system("cls");
}
char* book::returnbooknumber()
{
	return bknumber;
}
void book::report()
{
	cout<<bknumber<<setw(40)<<bkname<<setw(30)<<authorname<<endl;
}
//book class ends here

// STUDENT CLASS START HERE
class student
{
	char admnumber[20];
	char name[100];
	char stdbknumber[20];
	int token;
	public :
		void  createstudent();
		void showstudent();
		void modifystudent();
		void report();
		char* returnadmitionnumber();
		 int returntoken();
		char* returnbooknumber();
		void addtoken();
		void resettoken();
		void getstdbknumber(char t[]);
		
};
void student::getstdbknumber(char t[])
{
	strcpy(stdbknumber,t);
}
void student::resettoken()
{
	token=0;
}
void student::addtoken()
{
	token=1;
}
char* student::returnbooknumber()
{
	return stdbknumber;
}
int student::returntoken()
{
	return token;
}
char* student::returnadmitionnumber()
{
	return admnumber;
}
void student::report()
{
	cout<<admnumber<<setw(23)<<name<<setw(30)<<token<<endl;
}
void student::createstudent()
{
	system("cls");
	gotoxy(20,50);
	cout<<" NEW STUDENT REGISTRATION";
	gotoxy(21,50);
	cout<<"ENTER ADMITION NUMBER : ";
	cin>>admnumber;
	gotoxy(22,50);
	cout<<"ENTER STUDENT NAME : ";
	cin.ignore();
	cin.getline(name,100);
	gotoxy(23,50);
	token=0;
	cout<<"STUDENT REGISTERED SUCCESSFULLY ";
	getch();
	system("cls");	
}
void student::showstudent()
{
	system("cls");
	gotoxy(20,50);
	cout<<"STUDENT ADMITION NUMBER : "<<admnumber;
	gotoxy(21,50);
	cout<<"STUDENT NAME : "<<name;
	gotoxy(22,50);
	cout<<"NO.OF BOOKS ISSUED TO THE STUDENT : "<<token;
	if(token==1)
	{
		cout<<"BOOK NO. : "<<stdbknumber;
	}
	getch();
	system("cls");
}
void student::modifystudent()
{
	system("cls");
	gotoxy(20,50);
	cout<<"  CURRENT STUDENT ADMITION NUMBER        : "<<admnumber;
	gotoxy(21,50);
	 cout<<" ENTER MODIFIED STUDENT ADMITION NUMBER : ";
	 cin>>admnumber;
	 gotoxy(22,50);
	cout<<" CURRENT STUDENT NAME                    : "<<name;
	 gotoxy(23,50);
	 cout<< "ENTER MODIFIED STUDENT NAME            :";
	  cin.ignore();
	cin.getline(name,100);
	gotoxy(24,50);
	cout<<"STUDENT RECORD IS MODIFIED SUCCESSFULLY. ";
	getch();
	//system("cls");
}

//student class ends here
fstream fp,fp1,tp;
student st;
book bk;
// enter book records into library.
void writebook()
{
	char ch;
	fp.open("book.dat",ios::binary|ios::out|ios::app);
	do
	{
		system("cls");
		bk.createbook();
		fp.write((char*)&bk,sizeof(book));
		gotoxy(15,50);
		cout<<"DO YOU WANT TO ADD MORE RECORDS...?(Y/N) ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}
//entering student records here
void writestudent()
{
	char ch;
	fp.open("student.dat",ios::out|ios::app);
	do
	{  system("cls");
		st.createstudent();
		fp.write((char*)&st,sizeof(student));
		gotoxy(15,50);
		cout<<"DO YOU WANT TO ADD MORE  RECCORDS...?(Y/N)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}
//to get specific student details
void displayspb(char n[])
{   system("cls");
	gotoxy(20,50);
	cout<<"...BOOK DETAILS...";
	fp.open("book.dat",ios::binary|ios::in);
	int flag=1;
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(n,bk.returnbooknumber())==0)
		{  
			bk.showbook();
			flag=0;
			break;
		}
	}
	if(flag)
	{
		gotoxy(21,50);
		cout<<"NOT AVAILABLE";
	}
	getch();
	system("cls");
}
//to get specific student detail
void displaysps(char n[])
{
	system("cls");
	gotoxy(20,50);
	cout<<"...STUDENT DETAILS...";
	fp.open("student.dat",ios::binary|ios::in);
	int flag=1;
	while(fp.read((char*)&st,sizeof(student)))
	{  
		if(strcmpi(n,st.returnadmitionnumber())==0)
		{  
			st.showstudent();
			flag=0;
			break;
		}
	}
	fp.close();
	if(flag)
	{
		gotoxy(21,50);
		cout<<"NOT AVAILABLE";
	}
	getch();
	system("cls");

}

// modify book details
 
void modifybook()
{
	system("cls");
	char n[6];
	int found=1;
	gotoxy(18,50);
	cout<<"MODIFY BOOK DATA... ";
	gotoxy(19,50);
	cout<<"ENTER THE BOOK NUMBER : ";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	while(!fp.eof())
	{    fp.read((char*)&bk,sizeof(book));
		if(strcmpi(bk.returnbooknumber(),n)==0)
		{
			found=0;
			bk.showbook();
			gotoxy(20,50);
			//cout<<"ENTER MODIFIED DATA .";
			bk.modifybook();
			int pos=-1*sizeof(bk);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&bk,sizeof(book));
			gotoxy(21,50);
			//cout<<"DATA MODIFIED";
			break;
			
		}
	}
	fp.close();
	if(found)
	{    gotoxy(20,50);
		cout<<"BOOK NOT AVAILABLE .";
	}
	getch();
	system("cls");
}
// modify the student details
void modifystudent()
{
	system("cls");
	char n[6];
	int found=1;
	gotoxy(18,50);
	cout<<".......MODIFY STUDENT DATA........ ";
	gotoxy(19,50);
	cout<<"ENTER THE ADMITION NUMBER : ";
	cin>>n;
	fp.open("student.dat",ios::binary|ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if(strcmpi(st.returnadmitionnumber(),n)==0)
		{
			found=0;
			//st.showstudent();
			gotoxy(26,50);
			cout<<"....ENTER MODIFIED DATA....";
			st.modifystudent();
			int pos=-1*sizeof(st);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&st,sizeof(student));
			//cout<<"DATA MODIFIED";
			//getch();
			break;
			
		}
	}
	fp.close();
	if(found)
	{    gotoxy(20,50);
		cout<<"STUDENT DATA  NOT AVAILABLE .";
	}
	getch();
	system("cls");
}
// delete student record based on the admission number
void deletestudent()
{
	system("cls");
	char n[6];
	int flag=0;
	gotoxy(15,50);
	cout<<"DELETE STUDENT RECORD...";
	gotoxy(16,50);
	cout<<"ENTER THE STUDENT ADMISSION NUMBER : ";
	cin>>n;
	 tp.open("temp.dat",ios::binary|ios::in|ios::out|ios::app);
	fp.open("student.dat",ios::binary|ios::in|ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if(strcmpi(st.returnadmitionnumber(),n)!=0)
		{
			tp.write((char*)&st,sizeof(student));
		}
		else
		flag=1;
	}
	tp.close();
	fp.close();
	remove("student.dat");
	rename("temp.dat","student.dat");
	if(flag==1)
	{
		gotoxy(17,50);
		cout<<"YOUR STUDENT RECORD DELETED SUCCESSFULLY .";
	}
	else
	{   gotoxy(17,50);
	cout<<"STUDENT DATA IS NOT AVAILABLE ";
    }
    getch();
    system("cls");
    
}
// deleting book record
void deletebook()
{
	system("cls");
	char n[6];
	int flag=0;
	gotoxy(15,50);
	cout<<"DELETE BOOK RECORD...";
	gotoxy(16,50);
	cout<<"ENTER THE BOOK NUMBER : ";
	cin>>n;
	tp.open("temp.dat",ios::binary|ios::in|ios::out|ios::app);
	fp.open("book.dat",ios::binary|ios::in|ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.returnbooknumber(),n)!=0)
		{
			tp.write((char*)&bk,sizeof(book));
		}
		else
		flag=1;
	}
	tp.close();
	fp.close();
	remove("book.dat");
	rename("temp.dat","book.dat");
	if(flag==1)
	{
		gotoxy(17,50);
		cout<<"YOUR BOOK RECORD DELETED SUCCESSFULLY .";
	}
	else
	{   gotoxy(17,50);
	cout<<"BOOK DATA IS NOT AVAILABLE ";
    }
    getch();
    system("cls");
}
//DISPLAY ALL STUDENT RECORDS
void displayalls()
{   system("cls");
	fp.open("student.dat",ios::binary|ios::in);
	if(!fp)
	{
		gotoxy(15,50);
		cout<<"YOU MAY NOT HAVE STUDENT DATA.";
		getch();
		return;
	}
	cout<<"ADMITION NO."<<setw(15)<<"NAME"<<setw(36)<<"NO.OF BOOKS ISUUED"<<endl;
	while(fp.read((char*)&st,sizeof(student)))
	{    
		st.report();
	}
	fp.close();
	getch();
	
	
}
// TO DISPLAY ALL BOOKS
void displayallb()
{
      system("cls");
	fp.open("book.dat",ios::binary|ios::in);
	if(!fp)
	{
		gotoxy(15,50);
		cout<<"YOU MAY NOT HAVE STUDENT DATA.";
		getch();
		return;
	}
	cout<<"BOOK NO."<<setw(30)<<"BOOK NAME"<<setw(35)<<"AUTHOR NAME"<<endl;
	while(fp.read((char*)&bk,sizeof(book)))
	{ 
		bk.report();
	}
	fp.close();
	getch();	
}
// BOOK ISSUE
void bookissue()
{
	system("cls");
	char sn[6],bn[6];
	int flag=0,found=0;
	gotoxy(16,50);
	cout<<".....BOOK ISSUE......";
	gotoxy(17,50);
	cout<<"ENTER STUDENT ADMISSION NUMBER : ";
	cin>>sn;
	fp.open("student.dat",ios::binary|ios::out|ios::in);
	fp1.open("book.dat",ios::binary|ios::out|ios::in);
	while(fp.read((char*)&st,sizeof(student))&&found==0)
	{
		if(strcmpi(sn,st.returnadmitionnumber())==0)
		{
			found=1;
			gotoxy(18,50);
			cout<<"ENTER BOOK NUMBER : ";
			cin>>bn;
			while(fp1.read((char*)&bk,sizeof(book))&&flag==0)
			{
				if(strcmpi(bn,bk.returnbooknumber())==0)
				{
					flag=1;
					if(st.returntoken()==0)
					{
						st.addtoken();
						st.getstdbknumber(bk.returnbooknumber());
						int pos=-1*sizeof(st);
						fp.seekp(pos,ios::cur);
						fp.write((char*)&st,sizeof(student));
						gotoxy(19,50);
						cout<<".....BOOK ISSUED SUCCESSFULLY..... ";
						gotoxy(21,50);
						cout<<"PLEASE NOTE THE DATE OF ISSUE";
						
					}
					else
					{
						gotoxy(19,50);
						cout<<"YOU HAVEN'T DEPOSITED THE BOOK ISSUED TO YOU LAST TIME. SO THIS BOOK CANNOT BE ISSUED TO YOU";
					}
				}
			}
			if(flag==0)
			{
				gotoxy(19,50);
				cout<<"BOOK DOESNOT EXIST IN LIBRARY ";
			}
		}	
	}
		if(found==0)
		{
			gotoxy(19,50);
			cout<<"STUDENT IS NOT REGISTERED IN LIBRARY ,PLEASE REGISTER FIRST..";
		}
		fp.close();
		fp1.close();
		getch();
		system("cls");
}
// book deposite
void bookdeposite()
{
	system("cls");
	char sn[6],bn[6];
	int flag=0,found=0,days,fine;
	gotoxy(15,50);
	cout<<".....BOOK DEPOSITE......";
	gotoxy(16,50);
	cout<<"ENTER STUDENT ADMISSION NUMBER : ";
	cin>>sn;
	fp.open("student.dat",ios::out|ios::in);
	fp1.open("book.dat",ios::out|ios::in);
	while(fp.read((char*)&st,sizeof(student))&&found==0)
	{
		if(strcmpi(sn,st.returnadmitionnumber())==0)
		{
			found=1;
			gotoxy(17,50);
			cout<<"ENTER BOOK NUMBER : ";
			cin>>bn;
			while(fp1.read((char*)&bk,sizeof(book))&&flag==0)
			{
				if(strcmpi(bn,bk.returnbooknumber())==0)
				{
					flag=1;
					if(st.returntoken()==1)
					{  gotoxy(18,50);
					   cout<<"ENTER THE NUMBER OF DAYS TAKEN TO DEPOSITE THE BOOK : ";
					   cin>>days;
					   if(days>15)
					   {
					   	fine=days-15;
					   	gotoxy(19,50);
					   	cout<<"PLEASE PAY FINE OF RS."<<fine;
					   	getch();
					   }
					   
						st.resettoken();
						int pos=-1*sizeof(st);
						fp.seekp(pos,ios::cur);
						fp.write((char*)&st,sizeof(student));
						gotoxy(21,50);
						cout<<".....BOOK DEPOSITED SUCCESSFULLY..... ";
						
					}
					else
					{
						gotoxy(19,50);
						cout<<"YOU ARE NOT ISSUED ANY BOOK ";
					}
				}
			}
			if(flag==0)
			{
				gotoxy(20,50);
				cout<<"BOOK DOESNOT EXIST IN LIBRARY ";
			}
		}	
	}
		if(found==0)
		{
			gotoxy(18,50);
			cout<<"STUDENT IS NOT REGISTERED IN LIBRARY ,PLEASE REGISTER FIRST..";
		}
		fp.close();
		fp1.close();
		getch();
		system("cls");
}
//ADMINISTRATIVE MENU
void administrativemenu()
{
	system("cls");
	gotoxy(20,50);
	cout<<"SELECT ONE OF FOLLOWING OPTIONS (BETWEEN 1-11) : ";
	gotoxy(21,50);
	cout<<" 1.CREATE STUDENT RECORD ";
	gotoxy(22,50);
	cout<<" 2.DISPLAY ALL STUDENT RECORDS ";
	gotoxy(23,50);
	cout<<" 3.DISPLAY SPECIFIC STUDENT RECORD ";
     gotoxy(24,50);
	cout<<" 4.MODIFY STUDENT RECORD ";
     gotoxy(25,50);
	cout<<" 5.DELETE STUDENT RECORD ";
	gotoxy(26,50);
	cout<<" 6.CREATE BOOK ";
  gotoxy(27,50);
	cout<<" 7.DISPLAY ALL BOOKS ";
 gotoxy(28,50);
	cout<<" 8.DISPLAY SPECIFIC BOOK ";
gotoxy(29,50);
	cout<<" 9.MODIFY BOOK RECORD. ";
gotoxy(30,50);
	cout<<" 10.DELETE BOOK RECORD. ";
gotoxy(31,50);
	cout<<" 11.BACK TO MAIN MENU";
	gotoxy(33,50);
	cout<<"enter option : ";
int ch2;
cin>>ch2;
char n[6];
switch(ch2)
{  
	case 1: writestudent();
		break;
	case 2: 
	      displayalls();
		break;
	case 3:  system("cls");
		    gotoxy(20,50);
	       cout<<"ENTER THE ADMITION NUMBER OF STUDENT : ";
	       cin>>n;
	       displaysps(n);
		break;
	case 4:
		modifystudent();
		break;
	case 5:deletestudent();
		break;
		
	case 6: writebook();
		break;
	case 7:displayallb();
		break;
	case 8: system("cls");
		    gotoxy(20,50);
	       cout<<"ENTER BOOK NUMBER : ";
	       cin>>n;
	       displayspb(n);
		break;
	case 9: 
	       modifybook();
		   break;
	case 10:
		deletebook();
		break;
	case 11:  
	    return;
		break;
 default:
		cout<<"ENTERED INCORRECT OPTION, TRY AGAIN : ";
	

}
}
int main( )
{
	start();
	do
	{
	system("cls");
	gotoxy(11,60);
	cout<<" MAIN MENU ";
	gotoxy(13,50);
	cout<<"1.BOOK ISSUE";
	gotoxy(14,50);
	 cout<<"2.BOOK DEPOSITE";
	gotoxy(15,50);
	cout<<"3.ADMINISTRATOR MENU";
	gotoxy(16,50);
	cout<<"4.exit";
	gotoxy(17,50);
	cout<<" PLSEASE ENTER VALUE BETWEEN 1-4";
	char ch;
	cout<<" : ";
	ch=getche();
	
	switch(ch)
	{
		case '1': bookissue();
		           break;
		case '2':  bookdeposite();
		          break;
		case '3': administrativemenu();
		           break;
		case '4': exit(0);
		default : cout<<"ENTER CORRECT OPTION BETWEEN 1-4";
		           getch();
		
			
		
	}
}while(1);
}
