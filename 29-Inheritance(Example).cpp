//29-Inheritance(Example)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Simple Bank Account Class
class Account{
	friend ostream &operator<<(ostream &os, const Account &account);
	
private:
	static constexpr const char* def_name = "Unnamed Account"; //definition of constant expression in a class.
	static constexpr double def_balance = 0.0;
	
protected:
	string name;
	double balance;
	
public:
	Account(string name=def_name, double balance=def_balance); //default initialization
	
	bool Deposit(double amount);
	bool Withdraw(double amount);
	double GetBalance() const;
};

Account::Account(string name, double balance): name{name}, balance{balance}{}

//Deposit Money to Account
bool Account::Deposit(double amount){
	if(amount < 0)
		return false;
	balance += amount;
	return true;
}

//Withdraw Money from Account
bool Account::Withdraw(double amount){
	if(balance - amount < 0)
		return false;
	balance -= amount;
	return true;
}

//Total Cash in Account
double Account::GetBalance() const{
	return balance;
}

//Account Information Stream
ostream &operator<<(ostream &os, const Account &account){
	os << "Account: " << account.name << ", Balance: " << account.balance;
	return os;
}

class SavingsAccount: public Account{
	friend ostream &operator<<(ostream &os, const SavingsAccount &account);
	
private:
	static constexpr const char* def_name = "Unnamed Savings Account"; //private members are not accessible, same name can be used.
	static constexpr double def_balance = 0.0;
	static constexpr double def_int_rate = 0.0;
	
protected:
	double int_rate; //interest rate
	
public:
	SavingsAccount(string name=def_name, double balance=def_balance, double int_rate=def_int_rate);
	bool Deposit(double amount);
};

SavingsAccount::SavingsAccount(string name, double balance, double int_rate): Account{name, balance}, int_rate{int_rate}{}

bool SavingsAccount::Deposit(double amount){
	amount += amount * (int_rate/100);
	return Account::Deposit(amount); //calling method of base class.
}

ostream &operator<<(ostream &os, const SavingsAccount &account){
	os << "Savings Account: " << account.name << ", Balance: " << account.balance << ", Interest Rate: %" << account.int_rate;
	return os;
}

void Display(const vector<Account> &accounts);
void Deposit(vector<Account> &accounts, double amount);
void Withdraw(vector<Account> &accounts, double amount);

void Display(const vector<SavingsAccount> &accounts);
void Deposit(vector<SavingsAccount> &accounts, double amount);
void Withdraw(vector<SavingsAccount> &accounts, double amount);

void Display(const vector<Account> &accounts){
	cout << endl << "--- ACCOUNTS ---" << endl;
	for(const auto &acc: accounts)
		cout << acc << endl;
}

void Deposit(vector<Account> &accounts, double amount){
	cout << endl << "--- DEPOSIT ACCOUNTS ---" << endl;
	for(auto &acc: accounts){
		if(acc.Deposit(amount))
			cout << amount << " deposited to " << acc << endl;
		else
			cout << amount << " failed to deposit to " << acc << endl;
	}
}

void Withdraw(vector<Account> &accounts, double amount){
	cout << endl << "--- WITHDRAW ACCOUNTS ---" << endl;
	for(auto &acc: accounts){
		if(acc.Withdraw(amount))
			cout << amount << " withdrew from " << acc << endl;
		else
			cout << amount << " failed to withdraw from " << acc << endl;
	}
}

void Display(const vector<SavingsAccount> &accounts){
	cout << endl << "--- SAVINGS ACCOUNTS ---" << endl;
	for(const auto &acc: accounts)
		cout << acc << endl;
}

void Deposit(vector<SavingsAccount> &accounts, double amount){
	cout << endl << "--- DEPOSIT SAVINGS_ACCOUNTS ---" << endl;
	for(auto &acc: accounts){
		if(acc.Deposit(amount))
			cout << amount << " deposited to " << acc << endl;
		else
			cout << amount << " failed to deposit to " << acc << endl;
	}
}

void Withdraw(vector<SavingsAccount> &accounts, double amount){
	cout << endl << "--- WITHDRAW SAVINGS ACCOUNTS ---" << endl;
	for(auto &acc: accounts){
		if(acc.Withdraw(amount))
			cout << amount << " withdrew from " << acc << endl;
		else
			cout << amount << " failed to withdraw from " << acc << endl;
	}
}

int main(){
	cout.precision(2);
	cout << fixed;
	
	vector<Account> accounts;
	accounts.push_back(Account{});
	accounts.push_back(Account{"Ali"});
	accounts.push_back(Account{"Burhan", 100});
	accounts.push_back(Account{"Cemal", 200});	
	Display(accounts);
	Deposit(accounts, 10);
	Withdraw(accounts, 5);
	
	vector<SavingsAccount> sav_accounts;
	sav_accounts.push_back(SavingsAccount{});
	sav_accounts.push_back(SavingsAccount{"Duran"});
	sav_accounts.push_back(SavingsAccount{"Ediz", 300});
	sav_accounts.push_back(SavingsAccount{"Fatma", 400, 10.0});	
	Display(sav_accounts);
	Deposit(sav_accounts, 40);
	Withdraw(sav_accounts, 50);
	cout << endl;
	return 0;
}
