#include <iostream>
#include <stdio.h>
#include <cstring>
#include <fstream>
#include <string>
using namespace std;
class Sdat{
public:
int ch;
int ch1;
ofstream filefile;
ifstream filefile1;
ifstream file_f;
string srg;
string make_cmd,report_m, m="make",c=" -C ",path;
string take_ti,report_s,report_v;
string val_cmd,splint_cmd;
string vl="valgrind --log-file=";
string file_path,sp="splint",splint_time;
string take_ti1;
string val,file_name;
void take_time(){
	time_t t = time(0);
        struct tm * now = localtime(&t);
        char buffer [80];
        strftime (buffer,80,"%T.",now);
        take_ti=buffer;
	char buffer1 [100];
        strftime (buffer1,100," %c.",now);
	take_ti1=buffer1;
}
void splint_tool(){
	take_time();
	cout<<"<><>-----------------------------------*****-----------------------------------<><>\n";
	cout<<"Enter the path to perform Splint\n";
	cin>>file_path;
	report_s="splint_"+take_ti+"txt";
        splint_cmd=sp+" "+file_path+" |tee "+report_s+"; "+"date"+" >>"+report_s;
        const char *command=splint_cmd.c_str();
        system(command);
	cout<<take_ti<<endl;
	ch1=1;
	logfile();
        cout<<"<><>-----------------------------------*****-----------------------------------<><>\n";
//	sleep(1);
}
void val_list(){
        int c;
        cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
        cout<<"Do you want give optional arguments:\n";
        cout<<"1. Yes\n";
        cout<<"2. No\n";
        cout<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
        cout<<"Enter your choice: ";
        cin>>c;
        switch(c)
        {
        case 1:
	cout<<"\n---------------------------------------------------------------------------------\n";
        cout<<"-> --leak-check=full|summary|no\n";
        cout<<"-> -v\n";
        cout<<"-> --time-stamp=no|yes\n";
        cout<<"-> --show-leak-kinds=all\n";
        cout<<"-> --tool=cachegrind\n";
        cout<<"\n------------------------------------------------------------------------------------\n";
        cout<<"\n Enter the Valgrind command you want to perform:";
        cin>>val;
        break;
        case 2:
        break;
        }
}
void val_tool(){
	take_time();
	cout<<"\n----------------------***:::::**************************::::***----------------------\n";
	cout<<"Enter the object file of .c file: ";
	cin>>file_name;
        cout<<"\n----------------------***:::::**************************::::***-----------------------\n";
	file_f.open(file_name);
        if(file_f)
	{
	val_list();
	report_v="Valgrind"+take_ti+"txt";
        val_cmd=vl+ report_v+" "+val+" "+file_name+" ; "+" date" +" >>" +report_v;
        const char *command=val_cmd.c_str();
	system(command);
        cout<<endl;
        file_f.close();
	ch1=2;
	logfile();
}
else
{
cout<<"\nNO Such files !!!Please  Enter Again!!!\n";
val_tool();
}
}
void make(){
	take_time();
	report_m="makefile"+take_ti+"txt";
	cout<<"\nEnter the path where u want to run make command\n";
	cin>>path;
	make_cmd=m+" "+c+ path+" > "+report_m+" 2>&1 "+" ; "+"date"+" >>"+report_m;
	const char *command=make_cmd.c_str();
        system(command);
	ch1=3;
	logfile();
}
void logfile(){
take_time();
filefile.open("logfile.txt", ios::app);
if(filefile)
{

    filefile<<"\n--------------<><><<><><><><><><><><><><><><><><><><><><><><<><><><><><<><><-----------.\n";
    if(ch1==1){
    filefile<< sp+" "+file_path+" "+report_s+"; "+take_ti1+" >>"+report_v;
    }
    else if(ch1==2){
    filefile<< vl+report_v+" "+val+" "+file_name+"; "+take_ti1+" >>"+report_v;
    }
    else if(ch1==3){
    filefile<< m+" > "+report_m+" 2>&1 "+" ; "+"date"+" >>"+report_m;
    }

    filefile<<"\n---------------<><><<><><><><><><><><><><><><><><><><><><><><<><><><><><<><><-----------.\n";

 filefile.close();
}
}

void read_logfile(){
filefile1.open("logfile.txt");
if(filefile1)
{
    while ( getline (filefile1,srg) )
    {
      cout << srg <<endl;
    }
    filefile1.close();
}

}

public:
void Dashboard(){
cout<<"*******************************::::::::::::::::::::::::********************************\n";
cout<<"                             Welcome to Tools World\n";
cout<<"*******************************:::::::::::::::::::::::::********************************\n";
cout<<"::::::::::::::::::::::::::::::::<><><><><><><><><><>::::::::::::::::::::::::::::\n";
cout<<"1. Splint the c program\n";
cout<<"2. Valgrind the c program\n";
cout<<"3. Makefile the c program\n";
cout<<"4. View log file details\n";
cout<<"5. Exit\n";
cout<<"::::::::::::::::::::::::::::::::<><><><><><><><><><>::::::::::::::::::::::::::::\n";
cout<<"  Enter you choice: ";
cin>>ch;
switch(ch)
{
	case 1:
	splint_tool();
	Dashboard();
	break;
	case 2:	
	val_tool();
	Dashboard();
	break;
	case 3:
	make();
	Dashboard();
	break;
	case 4:
	cout<<"\n...........................Log File Details............................. ";
	read_logfile();
	Dashboard();
	break;
	case 5:
	exit(0);
	break;
	default:
	cout<<"Invaild input";

}
}
};
int main()
{
Sdat s;
s.Dashboard();
return 0;
}

