#include "Pedometer.h";

Pedometer::Pedometer(int _year, int _month, int _day, int _hour_first, int _minute_first, int _max_size) {
	current = 0;
	max_size = _max_size;
	start_year = _year;
	start_month = _month;
	start_day = _day;
	start_hour = _hour_first;
	start_minute = _minute_first;
	year = new int[max_size];
	month = new int[max_size];
	day = new int[max_size];
	hour_first = new int[max_size];
	hour_second = new int[max_size];
	minute_first = new int[max_size];
	minute_second = new int[max_size];
	steps = new int[max_size];
}
Pedometer::~Pedometer() {
	current = 0;
	max_size = 0;
	start_year = 0;
	start_month = 0;
	start_day = 0;
	start_hour = 0;
	start_minute = 0 ;
	delete[] year;
	delete[] month ;
	delete[] day ;
	delete[] hour_first;
	delete[] hour_second;
	delete[] minute_first;
	delete[] minute_second;
	delete[] steps;
}
void Pedometer::addNew(int _year, int _month, int _day, int _hour_first, int _hour_second, int _minute_first, int _minute_second, int  _max_size) {
	if (current < max_size) {
		year[current] = _year;
		month[current] = _month;
		day[current] = _day;
		hour_first[current] = _hour_first;
		hour_second[current] = _hour_second;
		minute_first[current] = _minute_first;
		minute_second[current] = _minute_second;
	}
	else {

	}
}