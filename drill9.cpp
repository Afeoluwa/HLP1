#include "std_lib_facilities.h"
//9.4.1
struct Date {
    int y;
    int m;
    int d;
};
	
void init_day(Date& dd, int y, int m, int d)
{
    if (m < 1 || m > 12) error("invalid month");
    if (d < 1 || d > 31) error("impossible day");
	
    dd.y = y;
    dd.m = m;
    dd.d = d;
}
	
void add_day(Date& dd, int n)
{
    dd.d += n;
    if (dd.d > 31) dd.d %= 31;
}
	
ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';	
}
	
int main()
{
    Date today;	
    init_day(today, 1978, 6, 25);
	//Date bad_day;
    //init_day(bad_day, 2004, 13, -5);
    Date tomorrow = today;
    add_day(tomorrow, 1);
    cout << today << '\n'
         << tomorrow << '\n';
         //<< bad_day << '\n';
}

/*//9.4.2
struct Date {
    int y, m, d;                    
    Date(int y, int m, int d);      	
    void add_day(int n);           
};
	
Date::Date(int yy, int mm, int dd)
     :y{yy}, m{mm}, d{dd}

{
    if (m < 1 || 12 < m) error("invalid month");
    if (d < 1 || 31 < d) error("impossible day");
}
	
void Date::add_day(int n)
{
    d += n;
    if (d > 31) d %= 31;
}
	
ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}
	
int main()
try {
    Date today(1978, 6, 25);
    Date tomorrow = today;
    tomorrow.add_day(1);
    //Date bad_day(2004, 13, -5);
    cout << today << '\n'
         << tomorrow << '\n';
         << //bad_day << '\n';

    
}

catch(exception& e) {
    cerr << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "unknown error" << '\n';
    return 2;
}*/

/*//9.4.3
class Date{
    int y, m, d;
public:
    Date(int y, int m, int d);
    void add_day(int n);
    int month(){return m;};
    int day(){return d;};
    int year(){return y;};
};

Date::Date (int yy, int mm, int dd) {
    if(yy < 0 || dd < 0 || dd > 31 || mm < 1 || mm > 12) error("invalid date!");
    y = yy;
    m = mm;
    d = dd;
}

void Date::add_day(int n) {
    d += n;
    for (;d > 31;)
    {
        d -= 31;
        ++m;
    }
    for (;m > 12;)
    {
        m -= 12;
        ++y;
    }
    for (;d < 1;)
    {
        d += 31;
        --m;
    }
    for (;m < 1;)
    {
        m += 12;
        --y;
    }
}

ostream& operator<<(ostream& os, Date& dd)
{
    return os << dd.year() << ' '
              << dd.month() << ' '
              << dd.day();
}

int main() {
    Date today{1978, 6, 25};
    Date tommorow {today};
    tommorow.add_day(1);
    cout << today << endl;
    cout << tommorow << endl;
    //Date t_1{2006, 17, -9}; "invalid date!"
    
    //Date t_2{2021, 12, 31};
    //t_2.add_day(32);
    //cout << t_2 << endl;
    //output "2022 2 1"
    


    return 0;
} */

