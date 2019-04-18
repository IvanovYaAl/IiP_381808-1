#include <iostream>
#include <fstream>

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
	
	int delta;
	int start_year;
	int start_month;
	int start_day;
	int start_hour;
	int start_minute;
	int max_size;
	int current;
public:
	Pedometer(int _year, int _month, int _day, int _hour_start, int _minute_start, int _max_size, int _delta);
	~Pedometer();
	void addNewPed(int _year, int _month, int _day, int _hour_first, int _hour_second, int _minute_first, int _minute_second, int _steps);
	void startDate();
	int HowManyStepsOnThisDay(int _year, int _month, int _day);
	int averageStepsMonth(int _month);
	int averageStepsAll();
	int maxStepsMonth(int _month);
	void maxStepsAll();

	friend ostream &operator << (ostream &stream, const Pedometer &c);
	friend istream &operator >> (istream &stream, Pedometer &c);
};

ostream& operator << (ostream & stream, const Pedometer &c);
istream& operator >> (istream & stream, Pedometer &c);
