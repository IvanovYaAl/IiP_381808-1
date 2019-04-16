#include <iostream>

using namespace std;

class Pedometer {
private:
	int* year;
	int* month;
	int* day;
	int* hour_first;
	int* hour_second;
	int* minute_first;
	int* minute_second;
	int* steps;

	int start_year;
	int start_month;
	int start_day;
	int start_hour;
	int start_minute;
	int max_size;
	int current;
public:
	Pedometer(int _year, int _month, int _day, int _hour_start, int _minute_start, int _max_size);
	~Pedometer();
	void addNew(int _year, int _month, int _day, int _hour_first, int _hour_second, int _minute_first, int _minute_second, int  _max_size);

};