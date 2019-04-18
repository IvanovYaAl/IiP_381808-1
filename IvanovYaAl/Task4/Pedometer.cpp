#include "Pedometer.h";

Pedometer::Pedometer(int _year, int _month, int _day, int _hour_first, int _minute_first, int _max_size, int _delta) {
	current = 0;
	max_size = _max_size;
	start_year = _year;
	start_month = _month;
	start_day = _day;
	start_hour = _hour_first;
	start_minute = _minute_first;
	delta = _delta;

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
	start_minute = 0;
	delta = 0;
	delete[] year;
	delete[] month;
	delete[] day ;
	delete[] hour_first;
	delete[] hour_second;
	delete[] minute_first;
	delete[] minute_second;
	delete[] steps;
}
void Pedometer::addNewPed(int _year, int _month, int _day, int _hour_first, int _hour_second, int _minute_first, int _minute_second, int _steps) {
	if (current < max_size) {
		year[current] = _year;
		month[current] = _month;
		day[current] = _day;
		hour_first[current] = _hour_first;
		hour_second[current] = _hour_second;
		minute_first[current] = _minute_first;
		minute_second[current] = _minute_second;
		steps[current] = _steps;
		current++;
	}
	else {
		max_size+=delta;
		int* coppy_year = year;
		int* coppy_month = month;
		int* coppy_day = day;
		int* coppy_hour_first = hour_first;
		int* coppy_hour_second = hour_second;
		int* coppy_minute_first = minute_first;
		int* coppy_minute_second = minute_second;
		int* coppy_steps = steps;

		coppy_year[current] = _year;
		coppy_month[current] = _month;
		coppy_day[current] = _day;
		coppy_hour_first[current] = _hour_first;
		coppy_hour_second[current] = _hour_second;
		coppy_minute_first[current] = _minute_first;
		coppy_minute_second[current] = _minute_second;
		coppy_steps[current] = _steps;

		delete[] year;
		delete[] month;
		delete[] day;
		delete[] hour_first;
		delete[] hour_second;
		delete[] minute_first;
		delete[] minute_second;
		delete[] steps;

		year = coppy_year;
		month = coppy_month;
		day = coppy_day;
		hour_first = coppy_hour_first;
		hour_second = coppy_hour_second;
		minute_first = coppy_minute_first;
		minute_second = coppy_minute_second;
		steps = coppy_steps;
	}
}
void Pedometer::startDate() {
	cout << "Starting Date:\nYear " <<
	start_year << "\nMonth " << start_month <<
	"\nDay " << start_day << "\nHour start " <<
	start_hour << "\nMinute start " << start_minute <<
	endl;
}
int Pedometer::HowManyStepsOnThisDay(int _year, int _month, int _day) {
	for (int i = 0; i <= current; i++)
	{
		if ((_year == year[i] || _year == start_year)
		&& (_month == month[i] || _month == start_month) 
		&& (_day == day[i] || _day == start_day))
		{
			return steps[i];
		}
		else if (i == max_size) {
			cout << "Observation not found!!!\n";
			return false;
		}
	}
}
int Pedometer::averageStepsMonth(int _month) {
	int all = 0;
	int kol_vo = 0;
	for (int i = 0; i <= current; i++) {
		if (_month == month[i]) {
			kol_vo++;
			all += steps[i];
		}
	}
	if (all == 0 && kol_vo == 0) {
		cout << "No Observation!!!" << endl;
		return false;
	}
	else {
		return all / kol_vo;
	}
}
int Pedometer::averageStepsAll() {
	int all = 0;
	for (int i = 0; i <= current; i++) {
		all += steps[i];
	}
	if (all == 0) {
		cout << "You haven't observations all this time" << endl;
		return false;
	}
	else {
		return all / current;
	}
}
int Pedometer::maxStepsMonth(int _month) {
	int max_steps = 0;
	for (int i = 0; i <= current; i++) {
		if (_month == month[i]) {
			if (max_steps < steps[i]) {
				max_steps = steps[i];
			}
		}
	}
	if (max_steps == 0) {
		cout << "No observations at this month!!" << endl;
		return false;
	}
	else {
		return max_steps;
	}
}
void Pedometer::maxStepsAll() {
	int max_steps = 0;
	int max_year = 0, max_month = 0, max_day = 0;
	for (int i = 0; i <= current; i++) {
		if (max_steps < steps[i]) {
			max_steps = steps[i];
			max_year = year[i];
			max_month = month[i];
			max_day = day[i];
		}
	}
	if (max_steps == 0) {
		cout << "You haven't observations all this time" << endl;
	}
	else {
		cout << "Max steps was in " <<
		max_year << " " << max_month <<
		" " << max_day << "\nSteps: " <<
		max_steps << endl;
	}
}

ostream& operator<<(ostream& stream, const Pedometer &c) {
	stream << c.current << " " << c.max_size << " " <<
		c.start_year << " " << c.start_month << " " <<
		c.start_day << " " << c.start_hour << " " <<
		c.start_minute << " ";
	for (int i = 0; i < c.current; i++) {
		stream << c.day[i] << " ";
		stream << c.month[i] << " ";
		stream << c.year[i] << " ";
		stream << c.hour_first[i] << " ";
		stream << c.hour_second[i] << " ";
		stream << c.minute_first[i] << " ";
		stream << c.minute_second[i] << " ";
		stream << c.steps[i] << " ";
	}
	return stream;
}
istream& operator>>(istream& stream, Pedometer& c) {
	stream >> c.current >> c.max_size >>
		c.start_year >> c.start_month >>
		c.start_day >> c.start_hour >>
		c.start_minute;

	c.year = new int[c.max_size];
	c.month = new int[c.max_size];
	c.day = new int[c.max_size];
	c.hour_first = new int[c.max_size];
	c.hour_second = new int[c.max_size];
	c.minute_first = new int[c.max_size];
	c.minute_second = new int[c.max_size];
	c.steps = new int[c.max_size];

	for (int i = 0; i < c.current; i++) {
		stream >> c.day[i] ;
		stream >> c.month[i] ;
		stream >> c.year[i] ;
		stream >> c.hour_first[i] ;
		stream >> c.hour_second[i] ;
		stream >> c.minute_first[i] ;
		stream >> c.minute_second[i] ;
		stream >> c.steps[i] ;
	}
	return stream;
}