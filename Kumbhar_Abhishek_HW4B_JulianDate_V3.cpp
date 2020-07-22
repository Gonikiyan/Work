/*
    HW4B - JulianDate.
    Author - Abhishek Kumbhar.
    CITE - Class Notes and google and both the tutors for CPE-553.
    Note : I have used int as professor made so my calender or the date thing is accurate from 1933 to 2067. Before and after these days it goes into overflow.

*/

#include <time.h>
#include <iostream>

using namespace std;

class JulianDate {
private:
	static int EPOCH;
	int year, mon, day, hour, min, second, julianday;
	// this representation would make difference VERY UGLY
	// diff between Jan. 1 2001 12:03:04  and Feb 26 2028 11:19:02
	// number of days since epoch
	bool is_before_2000=0;
	int Month[13] ={0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
	int LeapMonth[13] ={0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};

public:

JulianDate(int years, int month, int days, int hours, int minutes, int seconds){
year= years;
mon= month;
day= days;
hour= hours;
min= minutes;
second= seconds;
}

JulianDate(){
time_t now= time(0);
tm* ltm= localtime(&now);

year=1900 + ltm->tm_year;
mon= 1 + ltm->tm_mon;
day= ltm->tm_mday;
hour= ltm->tm_hour;
min= ltm->tm_min;
second= ltm->tm_sec;
}

friend ostream& operator <<(ostream& s, JulianDate A);

double jday(){
if(year>=EPOCH){
return (year-EPOCH)*(365*24*60*60) + Month[mon-1]*(24*60*60) + day*(24*60*60) + ((year-EPOCH)/4 -(year-EPOCH)/100 + (year-EPOCH)/400)*(24*60*60) + hour*(60*60) + min*60 + second ;
}
else{
return -((EPOCH-year)*(365*24*60*60) + ((EPOCH-year)/4 -(EPOCH-year)/100 + (EPOCH-year)/400)*(24*60*60) - Month[mon-1]*(24*60*60) - day*(24*60*60) - hour*(60*60) - min*60 - second ) ;
}
}

double operator -(JulianDate A){
double x=(this->jday()- A.jday());
second = int(x)%60;
min=int(x)%(60*60);
day = x/(24*60*60);
return day;
}

JulianDate jday2jdate(int A){
if(A>=0){
    julianday = A;
    second = julianday%60;
    julianday = julianday/60;
    min = julianday%60;
    julianday = julianday/60;
    hour = julianday%24;
    julianday = julianday/24;
    julianday = (julianday - ((year-EPOCH)/4 -(year-EPOCH)/100 + (year-EPOCH)/400));
    year = julianday/365;

    year= year + EPOCH;
    day = julianday%365;

    if(day==0){
        return JulianDate(year-1, 12, 31, hour, min, second);
    }

    else{
    bool is_leap=0;
    if((year%4==0 && year%100!=0) || (year%400==0)){  //%400==0 ||(%4==0 && %100 != 0)
        is_leap=1;
    }
    if(is_leap){
        for(int i=0; i<=13 ; i++){
        if(day<LeapMonth[i]){
        day=day-LeapMonth[i-1];
        if(day==0){
        day=LeapMonth[i-1]-LeapMonth[i-2];
        mon=i-1;
        break;
        }
        day=day;
        mon= i;
        break;
        }
        }
    }
    else{
        for(int i=0; i<=13 ; i++){
        if(day<Month[i]){
        day=day-Month[i-1];
        if(day==0){
        day=Month[i-1]-Month[i-2];
        mon=i-1;
        break;
        }
        day=day;
        mon= i;
        break;
        }
        }
        }

    return JulianDate(year, mon, day, hour, min, second);
    }
}
else{
    julianday=-A;
    second =59 - julianday%60;
    julianday = julianday/60;
    min =59 - julianday%60;
    julianday = julianday/60;
    hour =23 - julianday%24;
    julianday = julianday/24;
    julianday = (julianday - ((year-EPOCH)/4 -(year-EPOCH)/100 + (year-EPOCH)/400));
    year = julianday/365;
    year= EPOCH - (year+ 1);
    day = 365 - julianday%365;

    if(day==0){
        return JulianDate(year-1, 12, 31, hour, min, second);
    }
    else{
    bool is_leap=0;
    if((year%4==0 && year%100!=0) || (year%400==0)){  //%400==0 ||(%4==0 && %100 != 0)
        is_leap=1;
    }
    if(is_leap){
        for(int i=0; i<=13 ; i++){
        if(day<LeapMonth[i]){
        day=day-LeapMonth[i-1];
        if(day==0){
        day=LeapMonth[i-1]-LeapMonth[i-2];
        mon=i-1;
        break;
        }
        day=day;
        mon= i;
        break;
        }
        }
    }
    else{
        for(int i=0; i<=13 ; i++){
        if(day<Month[i]){
        day=day-Month[i-1];
        if(day==0){
        day=Month[i-1]-Month[i-2];
        mon=i-1;
        break;
        }
        day=day;
        mon= i;
        break;
        }
        }
        }

    return JulianDate(year, mon, day, hour, min, second);
    }
}
}


/*JulianDate operator +(int A){
double x=this->jday() + (A*24*60*60);
JulianDate X=jday2jdate(x);
return X;
}*/

int getYear(){
return year;
}

int getMonth(){
return mon;
}

int getDay(){
return day;
}

int getHour(){
return hour;
}

int getMin(){
return min;
}

int getSec(){
return second;
}

friend JulianDate operator +(JulianDate B, int A);

friend JulianDate operator -(JulianDate B, int A);

};

ostream& operator <<(ostream& s, JulianDate A){
return s<<"Year = "<<A.year<<'\t'<<"Month = "<<A.mon<<'\t'<<"Date = "<<A.day<<'\t'<<"Hour = "<<A.hour<<'\t'<<"Minutes = "<<A.min<<'\t'<<"Seconds = "<<A.second<<endl;
}

//http://aa.usno.navy.mil/faq/docs/JD_Formula.php
//http://www.math.harvard.edu/~knill/3dprinter/exhibits/bc/Meeus1988.pdf

JulianDate operator +(JulianDate B, int A){
int x=B.jday() + (A*24*60*60);
return (B.jday2jdate(x));
}

JulianDate operator -(JulianDate B, int A){
int x=B.jday() - (A*24*60*60);
return (B.jday2jdate(x));
}

int JulianDate::EPOCH = 2000; // Jan.1 2000, 00:00:00 = 0

int main() {

	JulianDate newyear(2018, 1, 1, 0,0,0);

	JulianDate valentine(2018, 2, 14, 12,0,0); // 0.5

	JulianDate today; // get it from the system time: time(nullptr)

	                  // localtime



	double days = valentine - newyear;

	JulianDate due = today + 7;

	cout << due << '\n';



	cout << "\nyear: " << newyear.getYear()

			 << "\nmonth: " << newyear.getMonth()

			 << "\nday: " << newyear.getDay()

			 << "\nhour: " << newyear.getHour()

			 << "\nmin: " << newyear.getMin()

			 << "\nsec: " << newyear.getSec() << '\n';

	JulianDate d1(2019, 1, 1, 0,0,0);

	for (int i = 0; i < 100; i++)

		cout << d1 + i;



}
