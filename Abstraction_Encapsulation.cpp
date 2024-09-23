#include <iostream>
using namespace std;

class BankAccount{
	private:
		float balance;
	protected:
		BankAccount(float accbal = 0) : balance (accbal){}
	public:
		virtual void calculateBalance(float amount, bool isDeposit) = 0;
		float getBalance(){
			return balance;
		}
		void depositAmount(float amount) {
			balance += amount;
			cout << "Deposited: " << amount << endl;
		}
		void withdrawAmount (float amount) {
            balance -= amount; 
            cout << "Withdraw: " << amount << endl; 
		}
};

class SavingAccount : public BankAccount{
	public:
		SavingAccount (float savingbal = 1000) : BankAccount (savingbal){}
		void calculateBalance (float amount, bool isDeposit) override{
			if (isDeposit)
				depositAmount(amount);
			else if (!(isDeposit)){
				if (getBalance() - amount >= 1000) 
					withdrawAmount(amount);
				else 
					cout << "Error: Insufficient Fund" << endl;
			}
		}
};

class CurrentAccount : public BankAccount{
	public:
		CurrentAccount (float currentbal = 0) : BankAccount (currentbal){}
		void calculateBalance (float amount, bool isDeposit) override{
			if (isDeposit) 
            	depositAmount(amount);
			else if (!(isDeposit))
            	withdrawAmount(amount);	
		}
};

bool isNumeric(const string& str, string typevar) {
	bool dp = false;
    for (int i = 0; i < str.length(); i++) {
		if (str[i] == '.' && typevar == "float") {
            if (dp) 
                return false;  
			dp = true;
        } 
		else if (!isdigit(str[i])) 
            return false; 
    }
    return true;
}
float validInput(const string typevar) {
    string input;
        while (!(cin >> input)|| !isNumeric(input, typevar) || stof(input) < 1) {
            cin.clear(); 
            cin.ignore(); 
            cout << "Error: Invalid input, please try again: ";
        } 
		if (isNumeric(input, typevar) || stof(input) < 1) 
        	if (typevar == "float")
        		return stof(input);
        	else
        		return stoi(input);
}

void subMenu(int choice, BankAccount* account, string typeaccount, bool subvalid){
	float amount;
	while(!(subvalid)){
		cout << "\t"<< typeaccount <<" Menu\t" << endl;
		cout << "[1] - Deposit" << endl;
		cout << "[2] - Withdraw" << endl;
		cout << "[3] - Check Balance" << endl;
		cout << "[4] - Back" << endl;
		cout << "Enter Choice: ";
		choice = validInput("int"); cout << endl;
		system ("cls");
		switch(choice){
			case 1:
				cout << typeaccount << " Deposit" << endl;	
				cout << "Enter The Amount to Deposit: ";
				amount = validInput("float");
				account->calculateBalance(amount, true);
				system ("pause");
				system ("cls");
			break;
			case 2:
				cout << typeaccount << " Withraw" << endl;
				cout << "Enter The Amount Withdraw Amount: ";
				amount = validInput("float");
				account->calculateBalance(amount, false);
				system ("pause");
				system ("cls");
			break;
			case 3:
				cout << typeaccount <<" Balance" << endl;
				cout << "Balance Amount: " << account->getBalance() << endl;
				system ("pause");
				system ("cls");
			break;
			case 4:
				subvalid = true;
				system ("cls");
			break;
			default:
				cout << "Error: Invalid input please try again." << endl;
		}
	}
}

int main (){
	SavingAccount saving;
    CurrentAccount current;
	int choice;
	bool mainvalid = false;
	while (!(mainvalid)){
		cout << "	Account Menu	" << endl;
		cout << "[1] Saving Account" << endl;
		cout << "[2] Current Account" << endl;
		cout << "[3] Exit" << endl;
		cout << "Enter Choice: ";
		choice = validInput("int");
		system ("cls");
		
		switch (choice){
		case 1:
			subMenu(choice, &saving, "Savings", false);
		break;
		case 2:
			subMenu(choice, &current, "Current", false);
		break;	
		case 3:
			cout << "Exiting...";
			mainvalid = true;
		break;
		default:
			cout << "Error: Invalid input please try again." << endl << endl;
		}
 	}
 	return 0;
}