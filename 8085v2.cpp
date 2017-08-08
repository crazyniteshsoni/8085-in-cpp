#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include <string>         
#include <sstream>
#include<fstream>
using namespace std;

int a,b,c,d,e,h,l,w,z;
int zf,cf,pf,sf,acf;
int pc,sp;
char addr[9999][10];
char tempaddr;
char tpc[4];
char temp1[4],temp2[4],temp3[4];
int tempc,tempreg,tempo;
void make();
void mp();
void load();
void save();
void setflag();
int checkzero();
int checkcarry();
void exmem();
void exreg();
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
void setflag()
{
	
}
void make()
{ 
	cout<<"Enter Address:";
	cin>>tpc;
	pc=strtol(tpc, NULL, 16);
	cout<<"\n"<<hex<<pc<<":";
	cin>>addr[pc];
	while(strcmp(addr[pc],"RESET")!=0)
	{
		
	pc++;
	cout<<"\n"<<hex<<pc<<":";
	cin>>addr[pc];	
	}
	
}
void load()
{   char locfile[100];
	char* tempstr;
	cout<<"Enter File Name:";
	cin>>locfile;
	cout<<"Enter Starting Address:";
	cin>>tpc;
	pc=strtol(tpc, NULL, 16);
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
	cout<<"\n"<<hex<<pc<<":";
	cout<<addr[pc];
	pc++;
	}
	else
	break;	
	}
}}

void exmem()
{
	cout<<"Enter Address:";
	cin>>tpc;
	pc=strtol(tpc, NULL, 16);
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
		case 'a':cout<<hex<<a;getch();
		break;
		case 'b':cout<<hex<<b;getch();
		break;
		case 'c':cout<<hex<<c;getch();
		break;
		case 'd':cout<<hex<<d;getch();
		break;
		case 'e':cout<<hex<<e;getch();
		break;
		case 'h':cout<<hex<<h;getch();
		break;
		case 'l':cout<<hex<<l;getch();
		break;
		default:main();
	}
	
}

void mp()
{	stringstream ss;
	int flag=0;
	cout<<"Enter Address:";
	cin>>tpc;
	pc=strtol(tpc, NULL, 16);
	while(flag!=1)
	{ 
		
		if(strcmp(addr[pc],"76")==0)//HLT
		{
			flag=1;
			pc++;
			cout<<"done";
		}
		else if(strcmp(addr[pc],"32")==0)//STA address
		{	
			pc++;
			strcpy(temp1,addr[pc]);
			pc++;
			strcpy(temp2,addr[pc]);
			strcat(temp2,temp1);
			tempo=strtol(temp2,NULL,16);
			ss.clear();
  			ss <<hex<<a;
  			ss >> addr[tempo];
			pc++;
		}
		else if(strcmp(addr[pc],"87")==0)//Add A
		{	
			a=a+a;
			pc++;
		}
		else if(strcmp(addr[pc],"80")==0)//ADD B
		{
			a=a+b;
			pc++;
		}
		else if(strcmp(addr[pc],"81")==0)//Add C
		{	
			a=a+c;
			pc++;
		}
		else if(strcmp(addr[pc],"82")==0)//Add D
		{	
			a=a+d;
			pc++;
		}
		else if(strcmp(addr[pc],"83")==0)//Add E
		{	
			a=a+e;
			pc++;
		}
		else if(strcmp(addr[pc],"84")==0)//Add H
		{	
			a=a+h;
			pc++;
		}
		else if(strcmp(addr[pc],"85")==0)//Add L
		{	
			a=a+l;
			pc++;
		}
		else if(strcmp(addr[pc],"86")==0)//Add M
		{   
			ss.clear();
  			ss <<hex<<h<<hex<<l;
  			ss >> tempc;
  			a=a+atoi(addr[tempc]);
  			pc++;
		}
		else if(strcmp(addr[pc],"3C")==0)//INR A
		{	
			a++;
			pc++;
		}
		else if(strcmp(addr[pc],"04")==0)//INR B
		{	
			b++;
			pc++;
		}
		else if(strcmp(addr[pc],"0C")==0)//INR C
		{	
			c++;
			pc++;
		}
		else if(strcmp(addr[pc],"14")==0)//INR D
		{	
			d++;
			pc++;
		}
		else if(strcmp(addr[pc],"1C")==0)//INR E
		{	
			e++;
			pc++;
		
		}
		else if(strcmp(addr[pc],"24")==0)//INR H
		{	
			h++;
			pc++;
		}
		else if(strcmp(addr[pc],"2C")==0)//INR L
		{   
			l++;
			pc++;
		}
		else if(strcmp(addr[pc],"34")==0)//INR M
		{	
			ss.clear();
  			ss <<hex<<h<<hex<<l;
  			ss >> tempc;
  			tempo=atoi(addr[tempc]);
  			tempo++;
  			ss.clear();
  			ss<<hex<<tempo;
  			ss>>addr[tempc];
  			pc++;
  			
		}
		else if(strcmp(addr[pc],"78")==0)//Mov a,b
		{	
			a=b;
			pc++;
		}
		else if(strcmp(addr[pc],"79")==0)//MOV A,C
		{	
			a=c;
			pc++;
		}
		else if(strcmp(addr[pc],"7A")==0)//MOV A,D
		{	
			a=d;
			pc++;
		}
		else if(strcmp(addr[pc],"7B")==0)//MOV A,E
		{	
			a=e;
			pc++;
		}
		else if(strcmp(addr[pc],"7C")==0)//MOV A,H
		{	
			a=h;
			pc++;
		}
		else if(strcmp(addr[pc],"7D")==0)//MOV A,L
		{	
			a=l;
			pc++;
		}
		else if(strcmp(addr[pc],"47")==0)//MOV B,A
		{	
			b=a;
			pc++;
		}
		else if(strcmp(addr[pc],"41")==0)//MOV B,C
		{	
			b=c;
			pc++;
		}
		else if(strcmp(addr[pc],"42")==0)//MOV B,D
		{	
			b=d;
			pc++;
		}
		else if(strcmp(addr[pc],"43")==0)//MOV B,E
		{	
			b=e;
			pc++;
		}
		else if(strcmp(addr[pc],"44")==0)//MOV B,H
		{	
			b=h;
			pc++;
		}
		else if(strcmp(addr[pc],"45")==0)//MOV B,L
		{	
			b=l;
			pc++;
		}
		else if(strcmp(addr[pc],"4F")==0)//MOV C,A
		{	
			c=a;
			pc++;
		}
		else if(strcmp(addr[pc],"48")==0)//MOV C,B
		{	
			c=b;
			pc++;
		}
		else if(strcmp(addr[pc],"4A")==0)//MOV C,D
		{	
			c=d;
			pc++;
		}
		else if(strcmp(addr[pc],"4B")==0)//MOV C,E
		{	
			c=e;
			pc++;
		}
		else if(strcmp(addr[pc],"4C")==0)//MOV C,H
		{	
			c=h;
			pc++;
		}
		else if(strcmp(addr[pc],"4D")==0)//MOV C,L
		{	
			c=l;
			pc++;
		}
		else if(strcmp(addr[pc],"57")==0)//MOV D,A
		{	
			d=a;
			pc++;
		}
		else if(strcmp(addr[pc],"50")==0)//MOV D,B
		{	
			d=b;
			pc++;
		}
		else if(strcmp(addr[pc],"51")==0)//MOV D,C
		{	
			d=c;
			pc++;
		}
		else if(strcmp(addr[pc],"52")==0)//MOV D,D
		{	
			d=d;
			pc++;
		}
		else if(strcmp(addr[pc],"53")==0)//MOV D,E
		{	
			d=e;
			pc++;
		}
		else if(strcmp(addr[pc],"54")==0)//MOV D,H
		{	
			d=h;
			pc++;
		}
		else if(strcmp(addr[pc],"55")==0)//MOV D,L
		{	
			d=l;
			pc++;
		}
		else if(strcmp(addr[pc],"5F")==0)//MOV E,A
		{	
			e=a;
			pc++;
		}
		else if(strcmp(addr[pc],"58")==0)//MOV E,B
		{	
			e=b;
			pc++;
		}
		else if(strcmp(addr[pc],"59")==0)//MOV E,C
		{	
			e=c;
			pc++;
		}
		else if(strcmp(addr[pc],"5A")==0)//MOV E,D
		{	
			e=d;
			pc++;
		}
		else if(strcmp(addr[pc],"5B")==0)//MOV E,E
		{	
			e=e;
			pc++;
		}
		else if(strcmp(addr[pc],"5C")==0)//MOV E,H
		{	
			e=h;
			pc++;
		}
		else if(strcmp(addr[pc],"5D")==0)//MOV E,L
		{	
			e=l;
			pc++;
		}
		else if(strcmp(addr[pc],"67")==0)//MOV H,A
		{	
			
		}
		else if(strcmp(addr[pc],"60")==0)//MOV H,B
		{	h=b;
			pc++;
		}
		else if(strcmp(addr[pc],"61")==0)//MOV H,C
		{	h=c;
			pc++;
		}
		else if(strcmp(addr[pc],"62")==0)//MOV H,D
		{	
			h=d;
			pc++;
		}
		else if(strcmp(addr[pc],"63")==0)//MOV H,E
		{	
			h=e;
			pc++;
		}
		else if(strcmp(addr[pc],"64")==0)//MOV H,H
		{	
			h=h;
			pc++;
		}
		else if(strcmp(addr[pc],"65")==0)//MOV H,L
		{	
			h=l;
			pc++;
		}
		else if(strcmp(addr[pc],"6F")==0)//MOV L,A
		{	
			l=a;
			pc++;
		}
		else if(strcmp(addr[pc],"68")==0)//MOV L,B
		{	
			l=b;
			pc++;
		}
		else if(strcmp(addr[pc],"69")==0)//MOV L,C
		{	
			l=c;
			pc++;
		}
		else if(strcmp(addr[pc],"6A")==0)//MOV L,D
		{	
			l=d;
			pc++;
		}
		else if(strcmp(addr[pc],"6B")==0)//MOV L,E
		{	
			l=e;
			pc++;
		}
		else if(strcmp(addr[pc],"6C")==0)//MOV L,H
		{	
			l=h;
			pc++;
		}
		else if(strcmp(addr[pc],"6D")==0)//MOV L,L
		{	
			l=l;
			pc++;
		}
		else if(strcmp(addr[pc],"77")==0)//MOV M,A
		{	ss.clear();
			ss <<hex<<h<<hex<<l;
  			ss >> tempc;
			ss.clear();  		
  			ss<<hex<<a;
  			ss>>addr[tempc];
  			pc++;
			
		}
		else if(strcmp(addr[pc],"70")==0)//MOV M,B
		{	ss.clear();
			ss <<hex<<h<<hex<<l;
  			ss >> tempc;
  			ss.clear();
  			ss<<hex<<b;
  			ss>>addr[tempc];
  			pc++;
		}
		else if(strcmp(addr[pc],"71")==0)//MOV M,C
		{	ss.clear();
			ss <<hex<<h<<hex<<l;
  			ss >> tempc;
  			ss.clear();
  			ss<<hex<<c;
  			ss>>addr[tempc];
  			pc++;
		}
		else if(strcmp(addr[pc],"72")==0)//MOV M,D
		{	ss.clear();
			ss <<hex<<h<<hex<<l;
  			ss >> tempc;
  		ss.clear();
  			ss<<hex<<d;
  			ss>>addr[tempc];
  			pc++;
		}
		else if(strcmp(addr[pc],"73")==0)//MOV M,E
		{	ss.clear();
			ss <<hex<<h<<hex<<l;
  			ss >> tempc;
  		ss.clear();
  			ss<<hex<<e;
  			ss>>addr[tempc];
  			pc++;
		}
		else if(strcmp(addr[pc],"74")==0)//MOV M,H
		{	ss.clear();
			ss <<hex<<h<<hex<<l;
  			ss >> tempc;
  		ss.clear();
  			ss<<hex<<h;
  			ss>>addr[tempc];
  			pc++;
		}
		else if(strcmp(addr[pc],"75")==0)//MOV M,L
		{	ss.clear();
			ss <<hex<<h<<hex<<l;
  			ss >> tempc;
  		ss.clear();
  			ss<<hex<<l;
  			ss>>addr[tempc];
  			pc++;
		}
		else if(strcmp(addr[pc],"3E")==0)//MVI A,data
		{
			pc++;
			strcpy(temp1,addr[pc]);
			tempo=strtol(temp1,NULL,16);
				a=tempo;
				pc++;
		}
		else if(strcmp(addr[pc],"06")==0)//MVI B,data
		{
			pc++;
			strcpy(temp1,addr[pc]);
			tempo=strtol(temp1,NULL,16);
				b=tempo;
				pc++;
		}
		else if(strcmp(addr[pc],"0E")==0)//MVI C,data
		{	
		pc++;
			strcpy(temp1,addr[pc]);
			tempo=strtol(temp1,NULL,16);
				c=tempo;
				pc++;
		}
		else if(strcmp(addr[pc],"16")==0)//MVI D,data
		{	
			pc++;
			strcpy(temp1,addr[pc]);
			tempo=strtol(temp1,NULL,16);
				d=tempo;
				pc++;
		}
		else if(strcmp(addr[pc],"1E")==0)//MVI E,data
		{	
			pc++;
			strcpy(temp1,addr[pc]);
			tempo=strtol(temp1,NULL,16);
				e=tempo;
				pc++;
		}
		else if(strcmp(addr[pc],"26")==0)//MVI H,data
		{	
			pc++;
			strcpy(temp1,addr[pc]);
			tempo=strtol(temp1,NULL,16);
				h=tempo;
				pc++;
		}
		else if(strcmp(addr[pc],"2E")==0)//MVI L,data
		{	
		pc++;
			strcpy(temp1,addr[pc]);
			tempo=strtol(temp1,NULL,16);
				l=tempo;
				pc++;
		}
		else if(strcmp(addr[pc],"36")==0)//MVI M,data
		{	
			pc++;
			strcpy(temp1,addr[pc]);
			tempo=strtol(temp1,NULL,16);
			ss.clear();
			ss <<hex<<h<<hex<<l;
  			ss >> tempc;
  			ss.clear();
  			ss<<hex<<tempo;
  			ss>>addr[tempc];
				pc++;
		}
		else if(strcmp(addr[pc],"3A")==0)//LDA address
		{	
			pc++;
			strcpy(temp1,addr[pc]);
			pc++;
			strcpy(temp2,addr[pc]);
			strcat(temp2,temp1);
			tempo=strtol(temp2,NULL,16);
			ss.clear();
  			ss <<hex<<addr[tempo];
  			ss >> a;
			pc++;
		}
		
		else if(strcmp(addr[pc],"8F")==0)//ADC A
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"88")==0)//ADC B
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"89")==0)//ADC C
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"8A")==0)//ADC D
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"8B")==0)//ADC E
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"8C")==0)//ADC H
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"8D")==0)//ADC L
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"8E")==0)//ADC M
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"C6")==0)//ADI DATA
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"A7")==0)//ANA A
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"A0")==0)//ANA B
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"A1")==0)//ANA C
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"A2")==0)//ANA D
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"A3")==0)//ANA E
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"A4")==0)//ANA H
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"A5")==0)//ANA L
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"A6")==0)//ANA M
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"E6")==0)//ANI DATA
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"CD")==0)//CALL LABEL
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"DC")==0)//CC LABEL
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"FC")==0)//CM LABEL
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"2F")==0)//CMA
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"3F")==0)//CMC
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"BF")==0)//CMP A
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"B8")==0)//CMP B
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"B9")==0)//CMP C
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"BA")==0)//CMP D
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"BB")==0)//CMP E
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"BC")==0)//CMP H
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"BD")==0)//CMP L
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"BE")==0)//CMP M
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"D4")==0)//CNC LABEL
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"C4")==0)//CNZ LABEL
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"F4")==0)//CP LABEL
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"EC")==0)//CPE LABEL
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"FE")==0)//CPI DATA
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"E4")==0)//CPO LABEL
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"CC")==0)//CZ LABEL
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"27")==0)//DAA
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"09")==0)//DAD B
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"19")==0)//DAD D
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"29")==0)//DAD H
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"39")==0)//DAD SP
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"3D")==0)//DCR A
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"05")==0)//DCR B
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"0D")==0)//DCR C
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"15")==0)//DCR D
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"1D")==0)//DRC E
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"25")==0)//DCR H
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"2D")==0)//DCR L
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"35")==0)//DCR M
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"0B")==0)//DCX B
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"1B")==0)//DCX D
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"2B")==0)//DCX H
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"3B")==0)//DCX SP
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"F3")==0)//DI
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"FB")==0)//EI
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"DB")==0)//IN PORT ADDR
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"03")==0)//INX B
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"13")==0)//INX D
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"23")==0)//INX H
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"33")==0)//INX SP
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"DA")==0)//JC LABEL
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"FA")==0)//JM LABEL
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"C3")==0)//JMP LABEL
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"D2")==0)//JNC LABEL
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"C2")==0)//JNZ LABEL
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"F2")==0)//JP LABEL
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"EA")==0)//JPE LABEL
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"E2")==0)//JPO LABEL
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"CA")==0)//JZ LABEL
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"0A")==0)//LDAX B
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"1A")==0)//LDAX D
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"2A")==0)//LHLD ADDR
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"01")==0)//LXI B
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"11")==0)//LXI D
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"21")==0)//LXI H
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"31")==0)//LXI SP
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"00")==0)//NOP
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"B7")==0)//ORA A
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"B0")==0)//ORA B
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"B1")==0)//ORA C
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"B2")==0)//ORA D
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"B3")==0)//ORA E
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"B4")==0)//ORA H
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"B5")==0)//ORA L
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"B6")==0)//ORA M
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"F6")==0)//ORI DATA
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"D3")==0)//OUT PORT ADDR
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"E9")==0)//PCHL
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"C1")==0)//POP B
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"D1")==0)//POP D
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"E1")==0)//POP H
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"F1")==0)//POP PSW
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"C5")==0)//PUSH B
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"D5")==0)//PUSH D
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"E5")==0)//PUSH H
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"F5")==0)//PUSH PSW
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"17")==0)//RAL
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"1F")==0)//RAR
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"D8")==0)//RC
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"C9")==0)//RET
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"20")==0)//RIM
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"07")==0)//RLC
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"F8")==0)//RM
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"D0")==0)//RNC
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"C0")==0)//RNZ
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"F0")==0)//RP
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"E8")==0)//RPE
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"E0")==0)//RPO
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"0F")==0)//RRC
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"C7")==0)//RST 0
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"CF")==0)//RST 1
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"D7")==0)//RST 2
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"DF")==0)//RST 3
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"E7")==0)//RST 4
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"EF")==0)//RST 5
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"F7")==0)//RST 6
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"FF")==0)//RST 7
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"C8")==0)//RZ
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"9F")==0)//SBB A
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"98")==0)//SBB B
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"99")==0)//SBB C
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"9A")==0)//SBB D
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"9B")==0)//SBB E
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"9C")==0)//SBB H
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"9D")==0)//SBB L
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"9E")==0)//SBB M
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"DE")==0)//SBI DATA 
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"22")==0)//SHLD ADD
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"30")==0)//SIM
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"F9")==0)//SPHL
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"02")==0)//STAX B
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"12")==0)//STAX D
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"37")==0)//STC
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"97")==0)//SUB A
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"90")==0)//SUB B
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"91")==0)//SUB C
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"92")==0)//SUB D
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"93")==0)//SUB E
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"94")==0)//SUB H
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"95")==0)//SUB L
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"96")==0)//SUB M
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"D6")==0)//SUI DATA
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"EB")==0)//XCHG
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"AF")==0)//XRA A
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"A8")==0)//XRA B
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"A9")==0)//XRA C
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"AA")==0)//XRA D
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"AB")==0)//XRA E
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"AC")==0)//XRA H
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"AD")==0)//XRA L
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"AE")==0)//XRA M
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"EE")==0)//XRI DATA
		{	
			pc++;
		}
		else if(strcmp(addr[pc],"E3")==0)//XTHL
		{	
			pc++;
		}
	
		
	}

}
