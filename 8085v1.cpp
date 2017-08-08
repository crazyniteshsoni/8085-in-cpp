#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<string>
using namespace std;

int pc;
char addr[9999][20];
int a,b,c,d,e,h,l;
int zf,cf,pf,acf,sf;
void read();
void write();
void make();
void exmem();
void exreg();
void mp();
void load();
int main()
{
int cho;
cout<<"\n1.make\n2.exmem\n3.mp\n4.exreg\n5.load\n";
cin>>cho;
switch(cho)
{
	case 1:make();
	break;
	case 2:exmem();
	break;
	case 3:mp();
	break;
	case 4:exreg();
	break;
	case 5:load();
	break;
	default:main();
}
main();
}
int tr;
void make()
{ 
	cout<<"Enter Address:";
	cin>>pc;
	cout<<"\n"<<pc<<":";
	cin>>addr[pc];
	while(strcmp(addr[pc],"RESET")!=0)
	{
	pc++;
	cout<<"\n"<<pc<<":";
	cin>>addr[pc];	
	}
	
}
void exmem()
{
	cout<<"Enter Address:";
	cin>>pc;
	cout<<addr[pc];
	getch();
}
void exreg()
{
	char y;
	cout<<"Enter reg:";
	cin>>y;
	switch(y)
	{
		case 'a':cout<<a;getch();
		break;
		case 'b':cout<<b;getch();
		break;
		case 'c':cout<<c;getch();
		break;
		case 'd':cout<<d;getch();
		break;
		case 'e':cout<<e;getch();
		break;
		case 'h':cout<<h;getch();
		break;
		case 'l':cout<<l;getch();
		break;
		default:main();
	}
}
void load()
{   char locfile[100];
	char* tempstr;
	cout<<"Enter File Name:";
	cin>>locfile;
	cout<<"Enter Starting Address:";
	cin>>pc;
	ifstream infile(locfile);
	if(!infile)
	{
		cout<<"file not found";
}
else{

	while(infile.getline(addr[pc],3)!=NULL)
	{
	if(strcmp(addr[pc],"RESET")!=0)
	{
	cout<<"\n"<<pc<<":";
	cout<<addr[pc];
	pc++;
	}
	else
	break;	
	}
}}
void mp()
{	int temp;
  int flag=0;
	cout<<"Enter Address:";
	cin>>pc;
	while(flag!=1)
	{ 
		if(strcmp(addr[pc],"3E")==0)//MVI A,data
		{
			pc++;
			a=atoi(addr[pc]);
			pc++;	
		}
		else if(strcmp(addr[pc],"06")==0)//MVI B,data
		{
			pc++;
			b=atoi(addr[pc]);
			pc++;
		}
		else if(strcmp(addr[pc],"80")==0)//ADD B
		{
			a=a+b;
			pc++;
		}
		else if(strcmp(addr[pc],"32")==0)//STA address
		{
			pc++;
			l=atoi(addr[pc]);
			pc++;
			h=atoi(addr[pc]);
			temp=(h*100)+l;
			sprintf(addr[temp], "%d", a);
			pc++;
		}
		else if(strcmp(addr[pc],"76")==0)//HLT
		{
			flag=1;
			pc++;
			cout<<"done";
		}
		else if(strcmp(addr[pc],"87")==0)//HLT
		{	a=a+a;
			pc++;
		}
		else if(strcmp(addr[pc],"81")==0)//HLT
		{	a=a+c;
			pc++;
		}
		else if(strcmp(addr[pc],"82")==0)//HLT
		{	a=a+d;
			pc++;
		}
		else if(strcmp(addr[pc],"83")==0)//HLT
		{	a=a+e;
			pc++;
		}
		else if(strcmp(addr[pc],"84")==0)//HLT
		{	a=a+h;
			pc++;
		}
		else if(strcmp(addr[pc],"85")==0)//HLT
		{	a=a+l;
			pc++;
		}
		else if(strcmp(addr[pc],"86")==0)//HLT
		{   
			temp=(h*100)+l;
			a=a+atoi(addr[temp]);
			pc++;
		}
		else if(strcmp(addr[pc],"3C")==0)//HLT
		{	a++;
			pc++;
		}
		else if(strcmp(addr[pc],"04")==0)//HLT
		{	b++;
			pc++;
		}
		else if(strcmp(addr[pc],"0C")==0)//HLT
		{	c++;
			pc++;
		}
		else if(strcmp(addr[pc],"14")==0)//HLT
		{	d++;
			pc++;
		}
		else if(strcmp(addr[pc],"1C")==0)//HLT
		{	e++;
			pc++;
		}
		else if(strcmp(addr[pc],"24")==0)//HLT
		{	h++;
			pc++;
		}
		else if(strcmp(addr[pc],"2C")==0)//HLT
		{   l++;
			pc++;
		}
		else if(strcmp(addr[pc],"34")==0)//HLT
		{	
			temp=(h*100)+l;
			tr=atoi(addr[temp]);
			tr++;
			sprintf(addr[temp], "%d", tr);
			pc++;
		}
		else if(strcmp(addr[pc],"78")==0)//HLT
		{	a=b;
			pc++;
		}
		else if(strcmp(addr[pc],"79")==0)//HLT
		{	a=c;
			pc++;
		}
		else if(strcmp(addr[pc],"7A")==0)//HLT
		{	a=d;
			pc++;
		}
		else if(strcmp(addr[pc],"7B")==0)//HLT
		{	a=e;
			pc++;
		}
		else if(strcmp(addr[pc],"7C")==0)//HLT
		{	a=h;
			pc++;
		}
		else if(strcmp(addr[pc],"7D")==0)//HLT
		{	a=l;
			pc++;
		}
		else if(strcmp(addr[pc],"47")==0)//HLT
		{	b=a;
			pc++;
		}
		else if(strcmp(addr[pc],"41")==0)//HLT
		{	b=c;
			pc++;
		}
		else if(strcmp(addr[pc],"42")==0)//HLT
		{	b=d;
			pc++;
		}
		else if(strcmp(addr[pc],"43")==0)//HLT
		{	b=e;
			pc++;
		}
		else if(strcmp(addr[pc],"44")==0)//HLT
		{	b=h;
			pc++;
		}
		else if(strcmp(addr[pc],"45")==0)//HLT
		{	b=l;
			pc++;
		}
		else if(strcmp(addr[pc],"4F")==0)//HLT
		{	c=a;
			pc++;
		}
		else if(strcmp(addr[pc],"48")==0)//HLT
		{	c=b;
			pc++;
		}
		else if(strcmp(addr[pc],"4A")==0)//HLT
		{	c=d;
			pc++;
		}
		else if(strcmp(addr[pc],"4B")==0)//HLT
		{	c=e;
			pc++;
		}
		else if(strcmp(addr[pc],"4C")==0)//HLT
		{	c=h;
			pc++;
		}
		else if(strcmp(addr[pc],"4D")==0)//HLT
		{	c=l;
			pc++;
		}
		else if(strcmp(addr[pc],"57")==0)//HLT
		{	d=a;
			pc++;
		}
		else if(strcmp(addr[pc],"50")==0)//HLT
		{	d=b;
			pc++;
		}
		else if(strcmp(addr[pc],"51")==0)//HLT
		{	d=c;
			pc++;
		}
		else if(strcmp(addr[pc],"52")==0)//HLT
		{	d=d;
			pc++;
		}
		else if(strcmp(addr[pc],"53")==0)//HLT
		{	d=e;
			pc++;
		}
		else if(strcmp(addr[pc],"54")==0)//HLT
		{	d=h;
			pc++;
		}
		else if(strcmp(addr[pc],"55")==0)//HLT
		{	d=l;
			pc++;
		}
		else if(strcmp(addr[pc],"5F")==0)//HLT
		{	e=a;
			pc++;
		}
		else if(strcmp(addr[pc],"58")==0)//HLT
		{	e=b;
			pc++;
		}
		else if(strcmp(addr[pc],"59")==0)//HLT
		{	e=c;
			pc++;
		}
		else if(strcmp(addr[pc],"5A")==0)//HLT
		{	e=d;
			pc++;
		}
		else if(strcmp(addr[pc],"5B")==0)//HLT
		{	e=e;
			pc++;
		}
		else if(strcmp(addr[pc],"5C")==0)//HLT
		{	e=h;
			pc++;
		}
		else if(strcmp(addr[pc],"5D")==0)//HLT
		{	e=l;
			pc++;
		}
		else if(strcmp(addr[pc],"67")==0)//HLT
		{	h=a;
			pc++;
		}
		else if(strcmp(addr[pc],"60")==0)//HLT
		{	h=b;
			pc++;
		}
		else if(strcmp(addr[pc],"61")==0)//HLT
		{	h=c;
			pc++;
		}
		else if(strcmp(addr[pc],"62")==0)//HLT
		{	h=d;
			pc++;
		}
		else if(strcmp(addr[pc],"63")==0)//HLT
		{	h=e;
			pc++;
		}
		else if(strcmp(addr[pc],"64")==0)//HLT
		{	h=h;
			pc++;
		}
		else if(strcmp(addr[pc],"65")==0)//HLT
		{	h=l;
			pc++;
		}
		else if(strcmp(addr[pc],"6F")==0)//HLT
		{	l=a;
			pc++;
		}
		else if(strcmp(addr[pc],"68")==0)//HLT
		{	l=b;
			pc++;
		}
		else if(strcmp(addr[pc],"69")==0)//HLT
		{	l=c;
			pc++;
		}
		else if(strcmp(addr[pc],"6A")==0)//HLT
		{	l=d;
			pc++;
		}
		else if(strcmp(addr[pc],"6B")==0)//HLT
		{	l=e;
			pc++;
		}
		else if(strcmp(addr[pc],"6C")==0)//HLT
		{	l=h;
			pc++;
		}
		else if(strcmp(addr[pc],"6D")==0)//HLT
		{	l=l;
			pc++;
		}
		/*else if(strcmp(addr[pc],"77")==0)//HLT
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"70")==0)//HLT
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"71")==0)//HLT
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"72")==0)//HLT
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"73")==0)//HLT
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"74")==0)//HLT
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"75")==0)//HLT
		{	
			pc++;
		}*/
		else if(strcmp(addr[pc],"0E")==0)//HLT
		{	pc++;
			c=atoi(addr[pc]);
			pc++;
		}
		else if(strcmp(addr[pc],"16")==0)//HLT
		{	pc++;
			d=atoi(addr[pc]);
			pc++;
		}
		else if(strcmp(addr[pc],"1E")==0)//HLT
		{	pc++;
			e=atoi(addr[pc]);
			pc++;
		}
		else if(strcmp(addr[pc],"26")==0)//HLT
		{	pc++;
			h=atoi(addr[pc]);
			pc++;
		}
		else if(strcmp(addr[pc],"2E")==0)//HLT
		{	pc++;
			l=atoi(addr[pc]);
			pc++;
		}
		else if(strcmp(addr[pc],"3A")==0)//HLT
		{	pc++;
		    l=atoi(addr[pc]);
		    pc++;
		    h=atoi(addr[pc]);
		    temp=(h*100)+l;
		    a=atoi(addr[temp]);
			pc++;
		}
		/*
		else if(strcmp(addr[pc],"7D")==0)//HLT
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"7D")==0)//HLT
		{	
			pc++;
		}
		*/
	}
}
