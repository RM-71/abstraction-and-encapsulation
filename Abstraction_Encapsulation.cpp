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
			if (isDeposit){
				depositAmount(amount);
			}
			else if (!(isDeposit)){
				if (getBalance() - amount >= 1000) {
					withdrawAmount(amount);
				}
				else {
					cout << "Error: Insufficient Fund" << endl;
				}
			}
		}
};

class CurrentAccount : public BankAccount{
	public:
		CurrentAccount (float currentbal = 0) : BankAccount (currentbal){}
		void calculateBalance (float amount, bool isDeposit) override{
			if (isDeposit) {
            	depositAmount(amount);
        	} 
			else if (!(isDeposit)){
            	withdrawAmount(amount);
        	}		
		}
};

void subMenu(int choice, BankAccount* account, string typeaccount){
	bool subvalid = false;
	float amount;
	while(!(subvalid)){
		cout << "\t"<< typeaccount <<" Menu\t" << endl;
		cout << "[1] - Deposit" << endl;
		cout << "[2] - Withdraw" << endl;
		cout << "[3] - Check Balance" << endl;
		cout << "[4] - Back" << endl;
		cout << "Enter Choice: ";
		cin >> choice; cout << endl;
		
		switch(choice){
			case 1:
				cout << typeaccount << " Deposit" << endl;	
				cout << "Enter Deposit Amount: ";
				cin >> amount;
				account->calculateBalance(amount, true);
				system ("pause");
				system ("cls");
				break;
			case 2:
				cout << typeaccount << " Withraw" << endl;
				cout << "Enter Withdraw Amount: ";
				cin >> amount;
				account->calculateBalance(amount, false);
				system ("pause");
				system ("cls");
				break;
			case 3:
				cout << typeaccount <<" Balance" << endl;
				cout << "Balance: " <<account->getBalance() << endl;
				system ("pause");
				system ("cls");
				break;
			case 4:
				cout << "Proceeding to Account Menu..." << endl;
				subvalid = true;
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
		cin >> choice;
		system ("cls");
		switch (choice){
		case 1:
			cout <<"Proceeding to Saving Account..." << endl;
			subMenu(choice, &saving, "Saving");
		break;
		case 2:
			cout <<"Proceeding to Current Account..." << endl;
			subMenu(choice, &current, "Current");
		break;	
		case 3:
			cout << "Exiting...";
			mainvalid = true;
		break;
		default:
			cout << "Error: Invalid input please try again." << endl;
		}
 }
}