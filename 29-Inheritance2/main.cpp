//29- Inheritance 2

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Account{
	friend ostream &operator<<(ostream &os, const Account &account);
private:
	static constexpr const char* def_name = "Unnamed Account";
	static constexpr double def_balance = 0.0;
protected:
	string name;
	double balance;
public:
	Account(string name = def_name, double balance = def_balance);
	bool Deposit(double amount);
	bool Withdraw(double amount);
	double GetBalance() const;
};

Account::Account(string name, double balance):name{name}, balance{balance}{
	
}

bool Account::Deposit(double amount){
	if(amount < 0)
		return false;
	balance += amount;
	return true;
}

bool Account::Withdraw(double amount){
	if(balance - amount < 0)
		return false;
	balance -= amount;
	return true;
}

double Account::GetBalance() const{
	return balance;
}

ostream &operator<<(ostream &os, const Account &account){
	os << "Account: " << account.name << ", Balance: " << account.balance;
	return os;
}

class Savings_Account : public Account{
	friend ostream &operator<<(ostream &os, const Savings_Account &account);
private:
	static constexpr const char* def_name = "Unnamed Savings Account";
	static constexpr double def_balance = 0.0;
	static constexpr double def_int_rate = 0.0;
protected:
	double int_rate;
public:
	Savings_Account(string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
	bool Deposit(double amount);
};

Savings_Account::Savings_Account(string name, double balance, double int_rate):Account{name, balance}, int_rate{int_rate}{
	
}

bool Savings_Account::Deposit(double amount){
	amount += amount * (int_rate / 100);
	return Account::Deposit(amount); //Account:Deposit recursive call
}

ostream &operator<<(ostream &os, const Savings_Account &account){
	os << "Savings Account: " << account.name << ", Balance: " << account.balance << ", Interest Rate: %" << account.int_rate;
	return os;
}

void Display(const vector<Account> &accounts);
void Deposit(vector<Account> &accounts, double amount);
void Withdraw(vector<Account> &accounts, double amount);

void Display(const vector<Savings_Account> &accounts);
void Deposit(vector<Savings_Account> &accounts, double amount);
void Withdraw(vector<Savings_Account> &accounts, double amount);

void Display(const vector<Account> &accounts){
	cout << "-ACCOUNTS-" << endl;
	for(const auto &acc: accounts)
		cout << acc << endl;
}

void Deposit(vector<Account> &accounts, double amount){
	cout << "-DEPOSIT ACCOUNTS-" << endl;
	for(auto &acc: accounts){
		if(acc.Deposit(amount))
			cout << amount << " deposited to " << acc << endl;
		else
			cout << amount << " failed to deposit to " << acc << endl;
	}
}

void Withdraw(vector<Account> &accounts, double amount){
	cout << "-WITHDRAW ACCOUNTS-" << endl;
	for(auto &acc: accounts){
		if(acc.Withdraw(amount))
			cout << amount << " withdrew from " << acc << endl;
		else
			cout << amount << " failed to withdraw from " << acc << endl;
	}
}

void Display(const vector<Savings_Account> &accounts){
	cout << "-SAVINGS_ACCOUNTS-" << endl;
	for(const auto &acc: accounts)
		cout << acc << endl;
}

void Deposit(vector<Savings_Account> &accounts, double amount){
	cout << "-DEPOSIT SAVINGS_ACCOUNTS-" << endl;
	for(auto &acc: accounts){
		if(acc.Deposit(amount))
			cout << amount << " deposited to " << acc << endl;
		else
			cout << amount << " failed to deposit to " << acc << endl;
	}
}

void Withdraw(vector<Savings_Account> &accounts, double amount){
	cout << "-WITHDRAW SAVINGS_ACCOUNTS-" << endl;
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
	accounts.push_back(Account{"Baris"});
	accounts.push_back(Account{"Bruce", 100});
	accounts.push_back(Account{"Boris", 200});	
	Display(accounts);
	Deposit(accounts, 10);
	Withdraw(accounts, 5);	
	cout << endl;
	
	vector<Savings_Account> sav_accounts;
	sav_accounts.push_back(Savings_Account{});
	sav_accounts.push_back(Savings_Account{"Aslan"});
	sav_accounts.push_back(Savings_Account{"Kaplan", 300});
	sav_accounts.push_back(Savings_Account{"Leopar", 400, 10.0});	
	Display(sav_accounts);
	Deposit(sav_accounts, 40);
	Withdraw(sav_accounts, 50);
	cout << endl;
	return 0;
}
