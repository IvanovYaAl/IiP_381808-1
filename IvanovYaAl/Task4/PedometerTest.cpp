#include "Pedometer.h"

int main() {
	int Year, Month, Day, Hour_First, Hour_Second, Minute_First, Minute_Second, Steps, Delta;
	cout << "Enter the start date and time of observation: " << endl;
	cin >> Year >> Month >> Day >> Hour_First >> Minute_First;
	cout << "Enter the Delta ( cout of improve the mas): " << endl;
	cin >> Delta;
	Pedometer Begining(Year, Month, Day, Hour_First, Minute_First, 25, Delta);
	Pedometer Ending(2000, 3, 1, 12, 30, 25, 10);

	bool Menu = true;
	while (Menu) {
		cout << "\n1. Add new observation.\n2. Starting date.\n3. How many steps at the day." <<
			"\n4. Average steps per month\n5. Average steps per all time. " <<
			"\n6. Max steps per month.\n7. Max steps all time.\n8. Exite\n";
		int v;
		cin >> v;
		switch (v)
		{
		case 1:
			cout << "\nEnter the new date and time of observation and count of steps: " << endl;
			cin >> Year >> Month >> Day >> Hour_First >> Minute_First >> Hour_Second >> Minute_Second >> Steps;
			Begining.addNewPed(Year, Month, Day, Hour_First, Hour_Second, Minute_First, Minute_Second, Steps);
			break;
		case 2:
			Begining.startDate();
			break;
		case 3:
			cout << "\nEnter the new date and time of observation for to know how many steps on this day: " << endl;
			cin >> Year >> Month >> Day;
			cout << "\n" << Begining.HowManyStepsOnThisDay(Year, Month, Day);
			break;
		case 4:
			cout << "\nEnter the month for to know average steps at this month: " << endl;
			cin >> Month;
			cout << "Average steps per month: ";
			cout << "\n" << Begining.averageStepsMonth(Month);
			break;
		case 5:
			cout << "\nAverage steps at all time: " << endl;
			cout << "\n" << Begining.averageStepsAll();
			break;
		case 6:
			cout << "\nEnter the month for to know max steps at this month: " << endl;
			cin >> Month;
			cout << "\nMax steps per month: " << endl;
			cout << Begining.maxStepsMonth(Month);
			break;
		case 7:
			cout << "\nMax steps per all time: " << endl;
			Begining.maxStepsAll();

			break;
		case 8:
			Menu = false;
			break;
		default:
			cout << "Enter right number of menu!!!";
			break;
		}
	}
	ofstream os;
	os.open("Pedometer.txt");
	os << Begining << endl;
	os.close();
	cout << Begining;
	ifstream is;
	is.open("Pedomet.txt");
	is >> Ending;
	cout << Ending;
	is.close();

	system("pause");
}