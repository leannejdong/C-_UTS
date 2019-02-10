#include "Time.h"
#include<iostream>
#include<cctype>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<sstream>
using namespace std;
Time::Time()
{
	hours=minutes=seconds=0;
}

Time::Time(const Time& time)
{
	hours=time.hours;
	minutes=time.minutes;
	seconds=time.seconds;
}


Time::Time(long secondsAfterMidnight){
	sfm = secondsAfterMidnight;
}


	
Time::~Time(){}

Time::Time(char const* tstring){
	string MyInputString(tstring);
	bool validityflag=true;
/*Now let test whether the string is in right format by checking the length of string*/
do
{
theTime=new char[strlen(tstring)+1];
	if(strlen(tstring)!=8){
		validityflag=false;
		cout<<"validityflag is false" ;
		hours=0;
		minutes=0;
		seconds=0;
	}
	else
	{
	cout<<"validityflag is true";
	strcpy(theTime,tstring);
	char* timeTokenisedByColons=strtok(theTime,":");
	hours=atoi(timeTokenisedByColons);
	timeTokenisedByColons=strtok(NULL,":");
	minutes=atoi(timeTokenisedByColons);
	timeTokenisedByColons=strtok(NULL,":");
	seconds=atoi(timeTokenisedByColons);
	timeTokenisedByColons=strtok(NULL,":"); 
	}*/
}while(validityflag);
}

/*	if (str.length()!=8)
		validityflag=false;
	else
	{ 
	char hour_string[3];
	char min_string[3];
	char sec_string[3];*/

//cout<<MyInputString<<endl;
//not sure whether this has sucessfully converted Const Char* to string
//I have not added a method/function within the class does error checking        

/*char* Time::GetTime(bool military = false) const{
}*/


int Time::GetHour()const{
return sfm / SEC_IN_HOUR;
}

int Time::GetMinute()const{
return (sfm% SEC_IN_HOUR) / SEC_IN_MINUTE;
}

int Time::GetSecond()const{
	return (sfm % SEC_IN_HOUR)% SEC_IN_MINUTE;
}
bool Time::operator!() const{
	bool IsInvalid(int,int,int);
	return IsInvalid;
}
//Declaration of the function
bool IsInvalid(int hr, int min, int sec)//should be char???
{
	return(((hr>=0)&&(hr<24))&&((min>=0)&&(min<60))&&((sec>=0)&&(sec<60)));
}


bool Time::IsAM() const{	//Is time AM?
//	int hours, minutes, seconds;
	if (hours>=12)
		return true;
	else
		return false;
	return 0;
}
bool Time::operator ==(Time const& time) const{
	return((time.hours==hours)
		&& (time.minutes==minutes)
		&& (time.seconds==seconds));
}

Time Time::operator+(Time const& time) const{
	Time sum;
	sum.minutes=minutes+time.minutes;
	sum.hours=hours+time.hours+sum.minutes/60;
	sum.minutes%=60;
	return sum;
}

Time Time::operator-(Time const& time) const{
	Time diff;
	int tot1,tot2;
	tot1=time.minutes+60*time.hours;
	tot2=minutes+60*hours;
	diff.minutes=(tot2-tot1)%60;
	diff.hours=(tot2-tot1)/60;
	return diff;
}
 void Time:: SetTime(int hrs, int mins, int secs)

{
	bool   valid;
	long int seconds_passed_in=hrs*60*60+mins*60+secs;
	long int seconds_per_day=60*60*24;
		if (seconds_passed_in>seconds_per_day)
		{
			valid=false;
	
		//	return "GetTime():INVALID ARGUMENTS";
		}
		if (mins>59||mins<0||secs>59||secs<0)
		{
			valid=false;
	
		//	return "GetTime():INVALID ARGUMENTS";
		}
		
		
	hours=hrs;
	minutes=mins;
	seconds=secs;
}

void Time::AddHours(int hours){
	hours += hours;
}

void Time::AddMinutes(int minutes){
	minutes += minutes;
	hours += minutes/60;
	minutes %=60;

}

void Time::AddSeconds(int seconds){
	seconds += seconds;
	minutes += seconds/60;
	seconds %=60;
}

void Time::Show() const
{
	std::cout<<hours<<minutes<<seconds;
}






		