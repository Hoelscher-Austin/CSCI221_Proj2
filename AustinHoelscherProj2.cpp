/* Do Programming Project 2 on page 611. You may watch the video note for 
 * Programming Project 1 on page 611 to get some idea. Then try to finish
 * independently by complete this sample file.
 * 
 * Author: Your Name
 * Version: Date
 */

#include <iostream>
using namespace std;

class CDAccount
{
public:
    CDAccount();
    CDAccount(double new_balance, double new_interest_rate, int new_term);
    double get_initial_balance() const;
    double get_balance_at_maturity() const;
    double get_interest_rate() const;
    int get_term() const;
    void input(istream& in);
    void output(ostream& out);
    
private:
    int dollar;
    int cent;
    double interest_rate;
    int term; // months until maturity
};

int main()
{
    // You implement the test code here
    CDAccount account;

    cout << "\nAccount 1\n";

    cout << "-----------\n\n";

    cout << "Enter account information - \n";
    
    account.input(cin);

    account.output(cout);

    cout << "---------------------\n";
    
    cout << "\nAccount 2\n";

    cout << "-----------\n";

    CDAccount account2(567.99, 0.05, 12);

    account2.output(cout);
    
    cout << "---------------------\n";


    


    return 0;

    // You may watch the video note to get the idea
    // notice that user will only enter balance as a double value
    // You may implement it as a menu oriented testing program
    // which be able to test constructors, methods of CDAccount class
}

// Implement the class definition here. Notice that the interfaces are the
// same as in Programming Project 1. However, the implementation will be
// different since the private information balance is stored differently
// for example, the input function will only read the balance, itnerest rate
// and term from the user. So it should be modified as following

CDAccount::CDAccount(){
    dollar = 0;
    cent = 0;
    interest_rate = 0;
    term = 0;
}

CDAccount::CDAccount(double new_balance, double new_interest_rate, int new_term){
    dollar = (int) new_balance;
    cent = (int) ((new_balance - dollar)*100);
    interest_rate = new_interest_rate;
    term = new_term;

}
void CDAccount::input(istream& in)
{
    double balance;
    cout << "Enter the starting balance: $";
    in >> balance; // get initial balance from user
    
    // convert balance to dollars and cents since this is how balance stored
    dollar = (int) balance; // dollar is the interger part of balace
    cent = (int) ((balance - dollar)*100); // cent is the fraction part * 100
    cout << "Enter the interest rate (5% would be entered as 0.05) :";
    in >> interest_rate; // get interest rate from user
    cout << "Enter the term length in months: ";
    in >> term; // get term from user
}

void CDAccount::output(ostream& out){
    cout << "\nInitial Balance: ";
    out << get_initial_balance();
    cout << "\nBalance at maturity: ";
    out << get_balance_at_maturity();
    cout << "\nInterest rate: ";
    out << get_interest_rate();
    cout << "\nTerm Length: ";
    out << get_term();
    cout << endl;
}

    double CDAccount::get_initial_balance() const{
        return dollar + cent/100.0; 
    }

    double CDAccount::get_balance_at_maturity() const{
            double balance = get_initial_balance();
            return balance * (1 + balance * term/12.0); 
    }

    double CDAccount::get_interest_rate() const{
            return interest_rate; 
    }
    int CDAccount::get_term() const{
            return term; 
    }