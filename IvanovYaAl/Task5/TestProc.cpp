#include "Credit.h"
#include "ProcCenter.h"

int main() {

	ProcCenter A(10);
menu:
	cout << "What do you want to do: " << endl;
	cout << "1.Log in;\n2. Show new credits;\n3. Check live credit;\n4. Take a new credit;" << endl;
	cout << "5. Show my credit;\n6. Make a payment;\n7. Add new Client;\n8. Add money on the account;" << endl;
	int olp;
	cin >> olp;
	switch (olp)
	{
	case 1: {
		cout << "Enter you numb of accaount and password: " << endl;
		string acc, pass;
		cout << "Account: " << endl;
		cin >> acc;
		cout << "Password: " << endl;
		cin >> pass;
		if (A.Autolog(acc, pass)) {
			cout << "You log in!" << endl;
		}
		else {
			cout << "Please try again!" << endl;
		}
	}
			break;
	case 2: {
		A.ShowOpportunity();
	}
			break;
	case 3: {
		A.HaveCredit(A.ReturnCred(A.WhatNumberr()));
	}
			break;
	case 4: {
		A.CanTakeCredit(A.ReturnCred(A.WhatNumberr()));
	}
			break;
	case 5: {
		A.ShowTable(A.ReturnCred(A.WhatNumberr()));
	}
			break;
	case 6: {
		A.DownMoney(A.ReturnCred(A.WhatNumberr()));
	}
			break;
	case 7: {
		A.AddNewClient();
	}
			break;
	case 8: {
		A.ResetMoney(A.ReturnCred(A.WhatNumberr()));
	}
			break;
	default:
		break;
	}
	cout << "Continue? (1. Yes\2. No): " << endl;
	int uf;
	cin >> uf;
	if (uf == 1)goto  menu;
	system("pause");
	return 0;
}