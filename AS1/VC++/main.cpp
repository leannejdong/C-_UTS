#include <cstdlib>
#include <iostream>
#include "Time.h"
#include <string.h>
#include <sstream>
#include<cctype>
using namespace std;

//bool IsInvalid(int,int,int);
//const char delim = ':';

int main(int argc, char *argv[])
{
//bool Invalid_String=true;
/*char timestring[8];  //why no need const char *timestring??
cout<<"Enter a valid time flag(format hh:mm:ss): ";
cin.getline(timestring,8);
Time t = Time(timestring);
delete[] timestring;*/

/*do
{
	cout<<"Enter a valid time string in format hh:mm:ss ";
	cin>>timestring;
}while(Invalid_String);*/
//char hour_string[3];
//char minute_string[3];
//char second_string[3];

//string str("Test string");
//cout << "The length of str is "<< str.length() << "characters.\n";

//char timestring[9];

//strcat(timestring,hour_string);
//strcat(timestring,minute_string);
//strcat(timestring,second_string);

/*cout << "Enter HH:MM:SS : " ;
cin.getline(timestring,9);
Time t=Time(timestring);
bool invalid_string=true;
while (invalid_string) {
cout << "Enter s valid timestring ";
cin.getline(timestring,9);
}
//invalid_string=!(isValidTime(timestring));
cout<< timestring[9]<<endl;

/*bool isValidTime(char ....)
{

}*/

Time time1; /*if use pointer, it create problem whenrunning, "time1 is uninitialised"*/
time1.Show();
cout<<endl;

Time time2(time1);
time2.Show();
cout<<endl;

int secs = -1;
Time* time3;
while(secs != 0){
cout << "Give me some seconds (0 to finish)";
cin >> secs;
time3 = new Time(secs);
cout << "Hours = " << (*time3).GetHour() << endl; 
cout << "Minutes = " << (*time3).GetMinute() << endl; 
cout << "Seconds = " << (*time3).GetSecond() << endl; 
delete time3;
}

const char* timestring; /*the variable 'timestring' is being used without being initialised*/
char *theTime;
Time* time4;
time4= new Time(timestring);
time4.Show();
cout<<endl;

if(time2.operator!()){
	cout<<"time object is valid";
}
else
	cout<<"create a valid time object"<<endl;

if(time2.IsAM()){
	cout<<"User has enter PM time";
}
else
	cout<<"User has enter AM time"<<endl;
//Now test bool Time::operator!() const, but how to test method with bool??
//Time* time5;
/*int hrs;
int mins=0;
int secs=0;

Time* time11;
Time* time1;
while(hrs!=0){
	cout<<"Give me hrs, mins, secs ";
	cin>>hrs>>mins>>secs;
	time1.SetTime(hrs,0,0)<<endl;
	//delete time1;
}*/


system("PAUSE");
return EXIT_SUCCESS;

//Time
}

