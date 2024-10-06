#include <iostream>
#include <vector>
#include<cstring>
#include <stdexcept>
#include<cmath>
#include<cstdlib>
using namespace std;

void home();
int mobile_length(long long mobile);

void introduction()
{
    cout << "          ";
    cout << "                                                     \033[1mKUBER : YOUR PERSONAL WEALTH ASSISTANT\033[0m" << endl<<endl;
}

//----------------------------------------------------------ACCOUNT DETAILS---------------------------------------------------------------------

class Bank
{
public:
    long long acc_no;
    string ifsc;
    string bank_name;
    long long balance;
    string acc_type;

    Bank()
    {
        acc_no = 0;
        ifsc = " ";
        bank_name = " ";
        balance = 0.0;
    }
    long long getAccountNumber() const
    {
        return acc_no;
    }
    string getIFSC() const
    {
        return ifsc;
    }
    string getBankName() const
    {
        return bank_name;
    }
    long long getBalance() const
    {
        return balance;
    }
    string getAccountType() const
    {
        return acc_type;
    }
};

int acc_no_length(long long number)
{
    int length = 0;
    if (number < 0)
    {
        length++;
        number = -number;
    }

    do
    {
        length++;
        number /= 10;
    }
    while (number != 0);

    return length;
}

string toUpper(string str)
{
    for (char &r : str)
    {
        r = toupper(r);
    }
    return str;
}


class UserDetails : public Bank
{
public:
    void input()
    {
        cout << "Enter Bank Name : ";
        cin.ignore();
        getline(cin, bank_name);
        bank_name=toUpper(bank_name);
        cout << "Enter IFSC code : ";
        getline(cin, ifsc);
        cout << "Enter Account Type ( S / C ) : ";
        cin >> acc_type;
        cin.ignore();
        try
        {
            cout << "Enter Account Number : ";
            cin >> acc_no;
            if (acc_no <= 0 || acc_no_length(acc_no)<10)
            {
                throw std::invalid_argument("Invalid Account Number,Account Number can't be of less than 10 digits !! ");
            }
            cout << "Current Balance : ";
            cin >> balance;
            while (balance <= 0)
            {
                throw std::invalid_argument("Balance cannot be zero !!");
            }
        }
        catch (const invalid_argument &e)
        {
            cout << "ERROR !! " << e.what() << endl;
            cout <<endl;
            input();
        }
        cin.clear();
        cin.ignore();

    }

    void displayDetails() const
    {
        cout << "Account Number: " << getAccountNumber() << endl;
        cout << "Bank Name: " << getBankName() << endl;
        cout << "IFSC Code: " << getIFSC() << endl;
        cout << "Account Type: " << getAccountType() << endl;
        cout << "Balance: " << getBalance() << endl;
        cout << endl;
    }
};


void addAccount(vector<UserDetails> &accounts)
{
    UserDetails ud;
    ud.input();
    accounts.push_back(ud);
}

//----------------------------------------------------------PORTFOLIO---------------------------------------------------------------------

class Portfolio
{
public:
    Portfolio()
    {
        cout<<"                                                                             Summary of Unrealized Capital Gain                   \n \n" ;
        cout<<" _________________________________________________\n";
        cout<<"|             INVESTMENT SNAPSHOT                 |                   ______________________________________________\n" ;
        cout<<"|_|                  |                                              |\n" ;

        cout<<"|   Net Investment  "<<"      |   "<<"70,26,000           | "<<"                "<<" | "<< "          ALLOCATION BY APPLICANT            | \n" ;
        cout<<"|||                  ||\n" ;
        cout<<"|   Current Value  "<<"       |   "<<"83,43,000           | "<<"                "<<" |   Applicant |"<<"  Current Value"<<"  | Allocation(%)|\n"   ;
        cout<<"|||                  ||||\n" ;
        cout<<"|      Net Gain     "<<"      | "<<"  13,17,000           |"<<"                  "<<"|      1      |"<<"   83,43,000   "<<"  |      100%    |\n";
        cout<<"|||                  ||||\n" ;
        cout<<"|      XIRR       "<<"        |"<<"     25.15%            |"<<"                  "<<"|    Total    |"<<"   83,43,000   "<<"  |      100%    |\n" ;
        cout<<"|||                  ||||\n" ;


    }
    friend void MutualfundsAllocation() ;
    friend void MutualfundsCap();
    friend void MutualfundsScheme();
};

void MutualfundsAllocation()
{
    cout<<"\n\nMUTUAL FUND AllOCATION BY AMC :\n\n" ;
    cout<<"            FUND        "<<"                    CURRENT VALUE   "<<"   AllOCATION(%)  \n" ;
    cout<<"1) Aditya Birla Sun Life Mutual Fund         11,14,608           11.99\n";
    cout<<"2) Quant Mutual Fund                          5,00,403           10.09\n";
    cout<<"3) DSP Mutual Fund                           11,67,840           12.91\n";
    cout<<"4) Franklin Templeton Mutual Fund            10,99,284           13.46\n";
    cout<<"5) HDFC Mutual Fund                          19,97,858           17.33\n";
    cout<<"6) ICICI Prudential Mutual Fund               2,10,555           23.66\n";
    cout<<"7) Kotak Mutual Fund                          2,17,331            3.77\n";
    cout<<"8) Nippon India Mutual Fund                  20,35,121            6.79\n\n";
    cout<<"            TOTAL :                          83,43,000          100.00\n\n\n";
}
void MutualfundsCap()
{
    cout<<"\n\nMUTUAL FUND (Equity) CAP ALLOCATION :\n\n" ;

    cout<<"CAP     CURRENT VALUE     ALLOCATION (%)\n";
    cout<<"Large     14,64,256           44.67\n" ;
    cout<<"Mid       6,62,569            20.21\n" ;
    cout<<"Small     11,51,334           35.12\n" ;
    cout<<"TOTAL     32,78,159          100.00\n\n\n" ;
}
void MutualfundsScheme()
{
    cout<<"\n\nMUTUAL FUND ALLOCATION BY SCHEME :\n\n" ;
    cout<<"               Scheme                          Current Value          Allocation (%)\n" ;
    cout<<"Aditya Birla SL Digital India Fund Reg (G)      1,14,608                  11.99\n" ;
    cout<<"Quant Manufacturing Fund Reg (G)                2,55,403                  10.09\n";
    cout<<"DSP Flexi Cap Fund Reg (G)                      1,62,459                   2.82\n";
    cout<<"Franklin India Smaller Companies Fund (G)       10,99,284                 13.46\n" ;
    cout<<"HDFC Dynamic Debt Fund (G)                      16,01,336                 10.44\n" ;
    cout<<"ICICI Pru Asset Allocator Fund (FOF) (G)        12,05,268                  3.56\n" ;
    cout<<"Kotak Emerging Equity (G)                       11,51,581                  8.54\n" ;
    cout<<"Nippon India Banking & Financial Services Fund  12,12,005                 13.68\n" ;
    cout<<"Nippon India Pharma Fund (G)                    11,62,409                 11.08\n" ;
    cout<<"Nippon India Small Cap Fund (G)                 3,78,647                  14.34\n\n\n";
}

//----------------------------------------------------------VIEW CURRENT MARKET STATUS---------------------------------------------------------------------

void stock_market_status()
{
    cout<<endl<<endl;
    cout<<"1) Nippon India Large Cap Fund Direct Growth             --->    1Y Returns - 43.27%          3Y Return - 26.56%          5Y Return - 18.04%              Price - 88.74 INR\n";
    cout<<"2) ICICI Prudential Bluechip Fund Direct Growth          --->    1Y Returns - 38.89%          3Y Return - 22.37%          5Y Return - 18.06%              Price - 104.17 INR\n";
    cout<<"3) Canara Robeco Bluechip Equity Fund Direct Growth      --->    1Y Returns - 31.49%          3Y Return - 17.36%          5Y Return - 18.31%              Price - 61.52 INR\n";
    cout<<"4) SBI Bluechip Equity Direct Growth                     --->    1Y Returns - 26.24%          3Y Return - 16.88%          5Y Return - 15.92%              Price - 87.81 INR\n";
    cout<<"5) Bandhan Nifty 50 Index Fund Direct Growth             --->    1Y Returns - 25.93%          3Y Return - 16.28%          5Y Return - 14.68%              Price - 48.61 INR\n";
    cout<<"6) Motilal Oswal Fund Direct Growth                      --->    1Y Returns - 60.99%          3Y Return - 38.36%          5Y Return - 27.68%              Price - 47.38 INR\n";
    cout<<"7) Quant Mid Cap Fund Direct Growth                      --->    1Y Returns - 67.61%          3Y Return - 37.94%          5Y Return - 32.67%              Price - 238.87 INR\n";
    cout<<"8) Quant Large and Mid Cap Fund Direct Growth            --->    1Y Returns - 63.98%          3Y Return - 32.12%          5Y Return - 26.80%              Price - 123.36 INR\n";
    cout<<"9) HDFC Mid Cap Direct Plan Growth                       --->    1Y Returns - 57.12%          3Y Return - 31.00%          5Y Return - 26.15%              Price - 174.76 INR\n";
    cout<<"10) Nippon India Growth Fund Direct Growth               --->    1Y Returns - 56.51%          3Y Return - 30.45%          5Y Return - 25.56%              Price - 3618.81 INR\n";
    cout<<"11) Quant Small Cap Fund Direct Plan Growth              --->    1Y Returns - 69.98%          3Y Return - 42.03%          5Y Return - 26.44%              Price - 259.88 INR\n";
    cout<<"12) Nippon India Small Cap Fund Direct Growth            --->    1Y Returns - 56.00%          3Y Return - 36.23%          5Y Return - 38.33%              Price - 161.46 INR\n";
    cout<<"13) TATA Small Cap Fund Direct Growth                    --->    1Y Returns - 43.97%          3Y Return - 33.02%          5Y Return - 30.48%              Price - 37.21  INR\n";
    cout<<"14) Canara Robeco Small Cap Fund Direct Growth           --->    1Y Returns - 42.62%          3Y Return - 32.05%          5Y Return - 22.23%              Price - 36.96  INR\n";
    cout<<"15) ICICI Prudential Smallcap Fund Direct Growth         --->    1Y Returns - 44.42%          3Y Return - 30.76%          5Y Return - 26.56%              Price - 85.22. INR\n";
}

void fd_rates()
{
    cout<<endl<<"INTEREST RATES PROVIDED BY BANKS AT PRESENT ARE :"<<endl<<endl;
    cout<<"  ________________________________________________________________________________________"<<endl;
    cout<<" |    BANK NAME    |    1 Year    |    2 Years    |    3 Years    |    4 Years or more    |"<<endl;
    cout<<" |                 |              |               |               |                       |"<<endl;
    cout<<" |      HDFC       |     6.6 %    |      7 %      |      7 %      |         7.2 %         |"<<endl;
    cout<<" |      SBI        |     6.8 %    |      7 %      |      7 %      |         6.8 %         |"<<endl;
    cout<<" |     ICICI       |     6.5 %    |     7.3 %     |     7.3 %     |         7.3 %         |"<<endl;
    cout<<" |      PNB        |     6.8 %    |     6.9 %     |     7.5 %     |         6.6 %         |"<<endl;
    cout<<" |      AXIS       |     6.7 %    |     7.1 %     |      7 %      |          7 %          |"<<endl;
    cout<<" ||"<<endl;
}


void view_rates()
{
    int ch;
i:
    cout<<endl;
    cout<<"1.) View Current Market Status"<<endl;
    cout<<"2.) View Interest Rates for Fixed Deposit(FD) of different banks"<<endl;
    cout<<"Enter your Choice : ";
    cin>>ch;

    switch(ch)
    {
    case 1:
        stock_market_status();
        break;

    case 2:
        fd_rates();
        break;

    default:
        cout<<"Invalid Option !!"<<endl;
        goto i;
        break;
    }
}

void see_rates_again()
{
    int ch;
h:
    cout<<endl;
    cout<<"Do You Want to see other rates as well ?"<<endl;
    cout<<"If Yes Press 1 or If you want to go to Homepage press 2 : ";
    cin>>ch;
    if(ch==1)
    {
        view_rates();
    }
    /*else if(ch==2)
    {

    }
    else
    {
        cout<<"Wrong Option !! "<<endl;
        goto h;
    }*/
}
//----------------------------------------------------------INVEST MORE---------------------------------------------------------------------

void access_account_for_investing(vector<UserDetails> &accs,long long acc_investing)
{

    bool found=false;

    for(UserDetails &account : accs)
    {
        if(account.getAccountNumber() == acc_investing)
        {
            found=true;
            cout<<"Bank Name : "<<account.getBankName()<<endl;
            cout << "Balance Available in Account Number " << account.getAccountNumber() << " is: " << account.getBalance() << endl;
        }
    }
    if(!found)
    {
        cout<<"Account Not Found , Try Again !"<<endl;
    }
}



long long Nippon_large_cap(long double q,int t)
{
    double rate=0.0;
    long double principal= q*88.74;
    long double return_amt=0.0;
    if(t==1)
    {
        rate=43.27/100;
        return_amt=principal * pow(1 + rate, 1);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else if (t>1 && t<=3)
    {
        rate=26.56/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else
    {
        rate=18.04/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;
    }
    return principal;
}

long long ICICI_Prudential_Bluechip(long double q,int t)
{
    double rate=0.0;
    long double principal= q*104.17;
    long double return_amt=0.0;
    if(t==1)
    {
        rate=38.89/100;
        return_amt=principal * pow(1 + rate, 1);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else if (t>1 && t<=3)
    {
        rate=22.37/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else
    {
        rate=18.06/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;
    }
    return principal;
}

long long Canara_Robeco_Bluechip(long double q,int t)
{
    double rate=0.0;
    long double principal= q*61.52;
    long double return_amt=0.0;
    if(t==1)
    {
        rate=31.49/100;
        return_amt=principal * pow(1 + rate, 1);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else if (t>1 && t<=3)
    {
        rate=17.36/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else
    {
        rate=18.31/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;
    }
    return principal;
}

long long SBI_Bluechip_Equity(long double q,int t)
{
    double rate=0.0;
    long double principal= q*87.81;
    long double return_amt=0.0;
    if(t==1)
    {
        rate=26.24/100;
        return_amt=principal * pow(1 + rate, 1);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else if (t>1 && t<=3)
    {
        rate=16.88/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else
    {
        rate=15.92/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;
    }
    return principal;
}

long long Bandhan_Nifty(long double q,int t)
{
    double rate=0.0;
    long double principal= q*48.61;
    long double return_amt=0.0;
    if(t==1)
    {
        rate=25.93/100;
        return_amt=principal * pow(1 + rate, 1);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else if (t>1 && t<=3)
    {
        rate=16.28/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else
    {
        rate=14.68/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;
    }
    return principal;
}

long long Motilal_Oswal_Fund(long double q,int t)
{
    double rate=0.0;
    long double principal= q*47.38;
    long double return_amt=0.0;
    if(t==1)
    {
        rate=60.99/100;
        return_amt=principal * pow(1 + rate, 1);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else if (t>1 && t<=3)
    {
        rate=38.36/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else
    {
        rate=27.68/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;
    }
    return principal;
}

long long Quant_Mid_Cap(long double q,int t)
{
    double rate=0.0;
    long double principal= q*238.87;
    long double return_amt=0.0;
    if(t==1)
    {
        rate=67.61/100;
        return_amt=principal * pow(1 + rate, 1);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else if (t>1 && t<=3)
    {
        rate=37.94/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else
    {
        rate=32.67/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;
    }
    return principal;
}

long long Quant_Large_and_Mid_Cap(long double q,int t)
{
    double rate=0.0;
    long double principal= q*123.36;
    long double return_amt=0.0;
    if(t==1)
    {
        rate=63.98/100;
        return_amt=principal * pow(1 + rate, 1);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else if (t>1 && t<=3)
    {
        rate=32.12/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else
    {
        rate=26.80/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;
    }
    return principal;
}

long long HDFC_Mid_Cap(long double q,int t)
{
    double rate=0.0;
    long double principal= q*174.76;
    long double return_amt=0.0;
    if(t==1)
    {
        rate=57.12/100;
        return_amt=principal * pow(1 + rate, 1);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else if (t>1 && t<=3)
    {
        rate=31.00/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else
    {
        rate=26.15/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;
    }
    return principal;
}

long long Nippon_India_Growth_Fund(long double q,int t)
{
    double rate=0.0;
    long double principal= q*3618.81;
    long double return_amt=0.0;
    if(t==1)
    {
        rate=56.51/100;
        return_amt=principal * pow(1 + rate, 1);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else if (t>1 && t<=3)
    {
        rate=30.45/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else
    {
        rate=25.56/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;
    }
    return principal;
}

long long Quant_Small_Cap_Fund(long double q,int t)
{
    double rate=0.0;
    long double principal= q*259.88;
    long double return_amt=0.0;
    if(t==1)
    {
        rate=69.98/100;
        return_amt=principal * pow(1 + rate, 1);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else if (t>1 && t<=3)
    {
        rate=42.03/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else
    {
        rate=26.44/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;
    }
    return principal;
}

long long Nippon_India_Small_Cap(long double q,int t)
{
    double rate=0.0;
    long double principal= q*161.46;
    long double return_amt=0.0;
    if(t==1)
    {
        rate= 56.00/100;
        return_amt=principal * pow(1 + rate, 1);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else if (t>1 && t<=3)
    {
        rate=36.23/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else
    {
        rate=38.33/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;
    }
    return principal;
}

long long TATA_Small_Cap (long double q,int t)
{
    double rate=0.0;
    long double principal= q*37.21;
    long double return_amt=0.0;
    if(t==1)
    {
        rate= 43.97/100;
        return_amt=principal * pow(1 + rate, 1);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else if (t>1 && t<=3)
    {
        rate=33.02/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else
    {
        rate=30.48/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;
    }
    return principal;
}

long long Canara_Robeco_Small_Cap(long double q,int t)
{
    double rate=0.0;
    long double principal= q*36.96;
    long double return_amt=0.0;
    if(t==1)
    {
        rate= 42.62/100;
        return_amt=principal * pow(1 + rate, 1);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else if (t>1 && t<=3)
    {
        rate=32.05/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else
    {
        rate=22.23/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;
    }
    return principal;
}

long long ICICI_Prudential_Smallcap(long double q,int t)
{
    double rate=0.0;
    long long principal= q*85.22;
    long double return_amt=0.0;
    if(t==1)
    {
        rate= 44.42/100;
        return_amt=principal * pow(1 + rate, 1);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;
    }
    else if (t>1 && t<=3)
    {
        rate=30.76/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;

    }
    else
    {
        rate=26.56/100;
        return_amt=principal * pow(1 + rate, t);
        cout<<"After "<<t<<" year(s) you will get a return of : "<<"Rs."<<return_amt<<endl;
    }
    return principal;
}

void remaining_balance(vector<UserDetails> &accs,long long account_investing,long long principal)
{
    bool found=false;
    for(UserDetails &account : accs)
    {
        if(account.getAccountNumber() == account_investing)
        {
            found=true;
            cout<<endl;
            cout<<"Balance left In account Number "<<account.getAccountNumber()<<" is Rs. "<<account.balance-principal;
        }
    }
}

void check_stock_name(string s,long double q,int t,vector<UserDetails> &accounts,long long account_investing)
{
    if(s == "Nippon India Large Cap Fund Direct Growth")
    {
        long long p= Nippon_large_cap(q,t);
        remaining_balance(accounts,account_investing,p);
    }
    else if(s == "ICICI Prudential Bluechip Fund Direct Growth")
    {

        long long p= ICICI_Prudential_Bluechip(q,t);
        remaining_balance(accounts,account_investing,p);
    }
    else if(s == "Canara Robeco Bluechip Equity Fund Direct Growth")
    {

        long long p= Canara_Robeco_Bluechip(q,t);
        remaining_balance(accounts,account_investing,p);
    }
    else if(s == "SBI Bluechip Equity Direct Growth")
    {

        long long p= SBI_Bluechip_Equity(q,t);
        remaining_balance(accounts,account_investing,p);
    }
    else if(s == "Bandhan Nifty 50 Index Fund Direct Growth")
    {
        long long p= Bandhan_Nifty(q,t);
        remaining_balance(accounts,account_investing,p);
    }
    else if(s == "Motilal Oswal Fund Direct Growth")
    {
        long long p= Motilal_Oswal_Fund(q,t);
        remaining_balance(accounts,account_investing,p);
    }
    else if(s == "Quant Mid Cap Fund Direct Growth")
    {
        long long p= Quant_Mid_Cap(q,t);
        remaining_balance(accounts,account_investing,p);
    }
    else if(s == "Quant Large and Mid Cap Fund Direct Growth")
    {

        long long p= Quant_Large_and_Mid_Cap(q,t);
        remaining_balance(accounts,account_investing,p);
    }
    else if(s == "HDFC Mid Cap Direct Plan Growth")
    {
        long long p= HDFC_Mid_Cap(q,t);
        remaining_balance(accounts,account_investing,p);
    }
    else if(s == "Nippon India Growth Fund Direct Growth")
    {
        long long p= Nippon_India_Growth_Fund(q,t);
        remaining_balance(accounts,account_investing,p);
    }
    else if(s == "Quant Small Cap Fund Direct Plan Growth")
    {
        long long p= Quant_Small_Cap_Fund(q,t);
        remaining_balance(accounts,account_investing,p);
    }
    else if(s == "Nippon India Small Cap Fund Direct Growth")
    {

        long long p= Nippon_India_Small_Cap(q,t);
        remaining_balance(accounts,account_investing,p);
    }
    else if(s == "TATA Small Cap Fund Direct Growth")
    {
        long long p=TATA_Small_Cap(q,t);
        remaining_balance(accounts,account_investing,p);
    }
    else if(s == "Canara Robeco Small Cap Fund Direct Growth")
    {

        long long p= Canara_Robeco_Small_Cap(q,t);
        remaining_balance(accounts,account_investing,p);
    }
    else if(s == "ICICI Prudential Smallcap Fund Direct Growth")
    {
        long long p= ICICI_Prudential_Smallcap(q,t);
        remaining_balance(accounts,account_investing,p);
    }
}

void invest_in_stocks(vector<UserDetails> &accounts)
{
    string stock_name;
    int tenure;
    long double quantity;
    long long acc_investing;
    cout<<endl;
    cout<<"Enter Account Number you want to Use for Investing : ";
    cin>>acc_investing;
    access_account_for_investing(accounts,acc_investing);
    cout<<"Choose The Stock you Want to Invest in : ";
    cin.ignore();
    getline(cin,stock_name);
    cout<<"Enter tenure of your Investment : ";
    cin>>tenure;
    cout<<"Enter the quantity you want to purchase : ";
    cin>>quantity;
    check_stock_name(stock_name,quantity,tenure,accounts,acc_investing);
}

class investmore
{
public :
    investmore()
    {

    }
    void stocks(vector<UserDetails> &accounts);
    void createDEMATAccount();
    void investInDigitalGold(vector<UserDetails> &accounts);
};
void investmore::stocks(vector<UserDetails> &accounts)
{
quit :
    cout<<"\nDo you want to :\n" ;
    cout<<"1) Filter by Market Capital\n2) View all Stocks\n" ;
    int q,w ;
    cout<<"Option : " ;
    cin>>q ;
    if(q==1)
    {
start :
        cout<<"\nSelect from the Following : \n 1) Large CAP \n 2) Mid CAP \n 3) Small Cap\n " ;
        cout<<"Option : " ;
        cin>>w ;
        if(w==1)
        {
            cout<<"Select : \n" ;
            cout<<"1) Nippon India Large Cap Fund Direct Growth             --->    1Y Returns - 43.27%          3Y Return - 26.56%          5Y Return - 18.04%              Price - 88.74 INR\n";
            cout<<"2) ICICI Prudential Bluechip Fund Direct Growth          --->    1Y Returns - 38.89%          3Y Return - 22.37%          5Y Return - 18.06%              Price - 104.17 INR\n";
            cout<<"3) Canara Robeco Bluechip Equity Fund Direct Growth      --->    1Y Returns - 31.49%          3Y Return - 17.36%          5Y Return - 18.31%              Price - 61.52 INR\n";
            cout<<"4) SBI Bluechip Equity Direct Growth                     --->    1Y Returns - 26.24%          3Y Return - 16.88%          5Y Return - 15.92%              Price - 87.81 INR\n";
            cout<<"5) Bandhan Nifty 50 Index Fund Direct Growth             --->    1Y Returns - 25.93%          3Y Return - 16.28%          5Y Return - 14.68%              Price - 48.61 INR\n";
            /*
             int e, r  ;
             cout<<"\nChoose a stock you want to purchase : ";
             cin>>e ;
             cout<<"Enter the number of stocks you want to purchase : " ;
             cin>>r ;
             cout<<"\nYou have Successfully Purchased "<<r<<" stocks. \n\n";
             */
            invest_in_stocks(accounts);


        }
        else if(w==2)
        {
            cout<<"Select : \n" ;
            cout<<"1) Motilal Oswal Fund Direct Growth                      --->    1Y Returns - 60.99%          3Y Return - 38.36%          5Y Return - 27.68%              Price - 47.38 INR\n";
            cout<<"2) Quant Mid Cap Fund Direct Growth                      --->    1Y Returns - 67.61%          3Y Return - 37.94%          5Y Return - 32.67%              Price - 238.87 INR\n";
            cout<<"3) Quant Large and Mid Cap Fund Direct Growth            --->    1Y Returns - 63.98%          3Y Return - 32.12%          5Y Return - 26.80%              Price - 123.36 INR\n";
            cout<<"4) HDFC Mid Cap Direct Plan Growth                       --->    1Y Returns - 57.12%          3Y Return - 31.00%          5Y Return - 26.15%              Price - 174.76 INR\n";
            cout<<"5) Nippon India Growth Fund Direct Growth                --->    1Y Returns - 56.51%          3Y Return - 30.45%          5Y Return - 25.56%              Price - 3618.81 INR\n";
            int e, r  ;
            /*
            cout<<"\nChoose a stock you want to purchase : ";
            cin>>e ;
            cout<<"Enter the number of stocks you want to purchase : " ;
            cin>>r ;
            cout<<"\nYou have Successfully Purchased "<<r<<" stocks. \n\n";
            */
            invest_in_stocks(accounts);

        }
        else if(w==3)
        {
            cout<<"Select : \n" ;
            cout<<"1) Quant Small Cap Fund Direct Plan Growth              --->    1Y Returns - 69.98%          3Y Return - 42.03%          5Y Return - 26.44%              Price - 259.88 INR\n";
            cout<<"2) Nippon India Small Cap Fund Direct Growth            --->    1Y Returns - 56.00%          3Y Return - 36.23%          5Y Return - 38.33%              Price - 161.46 INR\n";
            cout<<"3) TATA Small Cap Fund Direct Growth                    --->    1Y Returns - 43.97%          3Y Return - 33.02%          5Y Return - 30.48%              Price - 37.21  INR\n";
            cout<<"4) Canara Robeco Small Cap Fund Direct Growth           --->    1Y Returns - 42.62%          3Y Return - 32.05%          5Y Return - 22.23%              Price - 36.96  INR\n";
            cout<<"5) ICICI Prudential Smallcap Fund Direct Growth         --->    1Y Returns - 44.42%          3Y Return - 30.76%          5Y Return - 26.56%              Price - 85.22 INR\n";
            /*
            int e, r  ;
            cout<<"\nChoose a stock you want to purchase : ";
            cin>>e ;
            cout<<"Enter the number of stocks you want to purchase : " ;
            cin>>r ;
            cout<<"\nYou have Successfully Purchased "<<r<<" stocks. \n\n";
            */
            invest_in_stocks(accounts);
        }
        else
        {
            cout<<"\nWrong Input !!\n" ;
            goto start ;
        }
    }
    else if(q==2)
    {
edge :
        cout<<"Select : \n" ;
        cout<<"1) Nippon India Large Cap Fund Direct Growth             --->    1Y Returns - 43.27%          3Y Return - 26.56%          5Y Return - 18.04%              Price - 88.74 INR\n";
        cout<<"2) ICICI Prudential Bluechip Fund Direct Growth          --->    1Y Returns - 38.89%          3Y Return - 22.37%          5Y Return - 18.06%              Price - 104.17 INR\n";
        cout<<"3) Canara Robeco Bluechip Equity Fund Direct Growth      --->    1Y Returns - 31.49%          3Y Return - 17.36%          5Y Return - 18.31%              Price - 61.52 INR\n";
        cout<<"4) SBI Bluechip Equity Direct Growth                     --->    1Y Returns - 26.24%          3Y Return - 16.88%          5Y Return - 15.92%              Price - 87.81 INR\n";
        cout<<"5) Bandhan Nifty 50 Index Fund Direct Growth             --->    1Y Returns - 25.93%          3Y Return - 16.28%          5Y Return - 14.68%              Price - 48.61 INR\n";
        cout<<"6) Motilal Oswal Fund Direct Growth                      --->    1Y Returns - 60.99%          3Y Return - 38.36%          5Y Return - 27.68%              Price - 47.38 INR\n";
        cout<<"7) Quant Mid Cap Fund Direct Growth                      --->    1Y Returns - 67.61%          3Y Return - 37.94%          5Y Return - 32.67%              Price - 238.87 INR\n";
        cout<<"8) Quant Large and Mid Cap Fund Direct Growth            --->    1Y Returns - 63.98%          3Y Return - 32.12%          5Y Return - 26.80%              Price - 123.36 INR\n";
        cout<<"9) HDFC Mid Cap Direct Plan Growth                       --->    1Y Returns - 57.12%          3Y Return - 31.00%          5Y Return - 26.15%              Price - 174.76 INR\n";
        cout<<"10) Nippon India Growth Fund Direct Growth               --->    1Y Returns - 56.51%          3Y Return - 30.45%          5Y Return - 25.56%              Price - 3618.81 INR\n";
        cout<<"11) Quant Small Cap Fund Direct Plan Growth              --->    1Y Returns - 69.98%          3Y Return - 42.03%          5Y Return - 26.44%              Price - 259.88 INR\n";
        cout<<"12) Nippon India Small Cap Fund Direct Growth            --->    1Y Returns - 56.00%          3Y Return - 36.23%          5Y Return - 38.33%              Price - 161.46 INR\n";
        cout<<"13) TATA Small Cap Fund Direct Growth                    --->    1Y Returns - 43.97%          3Y Return - 33.02%          5Y Return - 30.48%              Price - 37.21  INR\n";
        cout<<"14) Canara Robeco Small Cap Fund Direct Growth           --->    1Y Returns - 42.62%          3Y Return - 32.05%          5Y Return - 22.23%              Price - 36.96  INR\n";
        cout<<"15) ICICI Prudential Smallcap Fund Direct Growth         --->    1Y Returns - 44.42%          3Y Return - 30.76%          5Y Return - 26.56%              Price - 85.22 INR\n";
        /*
         int e, r  ;
         cout<<"\nChoose a stock you want to purchase : ";
         cin>>e ;
         if(e>15 || e<=0)
         {
             cout<<"\nWrong Input !!\n\n" ;
             goto edge ;
         }
         cout<<"Enter the number of stocks you want to purchase : " ;
         cin>>r ;
         cout<<"\nYou have Successfully Purchased "<<r<<" stocks. \n\n";
          ;
        }
        else
        {
         cout<<"\nWrong Input\n" ;
         goto quit ;
        }*/
        invest_in_stocks(accounts);
    }
}

int mobile_length(long long mobile)
{
    int length = 0;
    int number;
    if (number < 0)
    {
        length++;
        number = -number;
    }

    do
    {
        length++;
        number /= 10;
    }
    while (number != 0);

    return length;
}

void investmore::createDEMATAccount()
{
    string name, address, panCard;
    int day, month, year;
    int l;
    long long aadhar,mobile;
    cin.ignore();
    cout << "\nCREATE YOUR DEMAT ACCOUNT\n\n";
    cout << "Enter Your Name: ";
    cin.ignore();
    getline(cin,name);
    cout << endl;

    cout<<"Enter your Date of Birth in dd mm yyyy format : ";
    cin>>day>>month>>year;

    int currentYear = 2024;
    if (currentYear - year < 18)
    {
        cout << "UNDERAGE!!\n";
        cout << "\nYou are not eligible to create a DEMAT account.\n";
        return;
    }
    else
    {
        cout<<"\nAge above 18....Eligble!!\n\n" ;
        cin.ignore();
    }
    cout<<"Enter Permanent Residential address : ";
    cin.ignore();
    getline(cin,address);
    mobnum :
    cout<<"Enter Mobile Number : ";
    cin.ignore();
    cin>>mobile;
    if (to_string(mobile).length() != 10)
    {
        cout << "Invalid mobile number. Please enter exactly 10 digits.\n";
       goto mobnum ;
    }
    l=mobile_length(mobile);
    aadnum :
    cout<<"Enter Aadhar Number (16-Digit) : ";
    cin.ignore();
    cin>>aadhar ;
    if (to_string(aadhar).length() != 16)
    {
        cout << "Invalid Aadhar Number! Please enter a 16-digit Aadhar Number.\n";
        goto aadnum;
    }
    cout<<"Enter PAN Number : " ;
    cin.ignore();
    getline(cin,panCard);
    char option;
    /*cout << "\nAre you sure you want to create a DEMAT account (Y/N): ";
    cin >> option;

    if (option == 'Y' || option == 'y')
    {
        cout << "\nAll the details have been verified.\n\n";
    }*/
    cout<<"\nACCOUNT HAS BEEN SUCCESSFULLY CREATED !\n\n";

}

void investmore::investInDigitalGold(vector<UserDetails> &accounts)
{
    long long accountNumber;
    double goldAmount;
    double gold;
    cout << "\nPrice of Gold is Rs 7566 per 1g\n";
    cout << "Enter Account Number you want to use for Investing : ";
    cin >> accountNumber;

    bool found = false;
    for (UserDetails &account : accounts)
    {
        if (account.getAccountNumber() == accountNumber)
        {
            found = true;
            cout << "Bank Name: " << account.getBankName() << endl;
            cout << "Balance Available in Account Number " << account.getAccountNumber() << " is: " << account.getBalance() << endl;

            cout << "Enter the Amount you want to invest in Digital gold (in Rs): ";
            cin >> goldAmount;
            gold = goldAmount / 7566;

            cout << "Gold purchased in grams : " << gold << endl<<endl;
        }
    }

    if(!found)
    {
        cout<<"Account Not Found !! "<<endl;
    }
}

//----------INVEST THROUGH FD------------

long long calculateFixedDepositReturn(long long principal, double rate, int tenure)
{
    rate /= 100.0;
    long long futureValue = principal * pow(1 + rate, tenure);
    return futureValue;
}

void invest_through_fd(vector<UserDetails> &accs)
{
    long long accountNumber;
    int tenure;
    long long amount;
    long long returnAfterTenure = 0;

    cout << endl << "Investing through Fixed Deposit(FD):" << endl;
    cout << "Enter Account Number: ";
    cin >> accountNumber;

    bool found = false;
    for (UserDetails &account : accs)
    {
        if (account.getAccountNumber() == accountNumber)
        {
            found = true;
            cout << "Bank Name: " << account.getBankName() << endl;
            cout << "Balance Available in Account Number " << account.getAccountNumber() << " is: " << account.getBalance() << endl;

            cout << "Enter the Number of Years you want to invest for: ";
            cin >> tenure;

            cout << "Enter Amount you want to Invest: ";
            cin >> amount;


            if (account.getBankName() == "HDFC")
            {
                if (tenure == 1)
                    returnAfterTenure = calculateFixedDepositReturn(amount, 6.6, tenure);
                else if (tenure == 2 || tenure == 3)
                    returnAfterTenure = calculateFixedDepositReturn(amount, 7, tenure);
                else if (tenure >= 4)
                    returnAfterTenure = calculateFixedDepositReturn(amount, 7.2, tenure);
            }
            else if (account.getBankName() == "SBI")
            {
                if (tenure == 1 || tenure == 2 || tenure == 3)
                    returnAfterTenure = calculateFixedDepositReturn(amount, 6.8, tenure);
                else if (tenure >= 4)
                    returnAfterTenure = calculateFixedDepositReturn(amount, 6.8, tenure);
            }
            else if (account.getBankName() == "ICICI")
            {
                if (tenure == 1)
                    returnAfterTenure = calculateFixedDepositReturn(amount, 6.5, tenure);
                else if (tenure == 2 || tenure == 3 || tenure >= 4)
                    returnAfterTenure = calculateFixedDepositReturn(amount, 7.3, tenure);
            }
            else if (account.getBankName() == "PNB")
            {
                if (tenure == 1)
                    returnAfterTenure = calculateFixedDepositReturn(amount, 6.8, tenure);
                else if (tenure == 2)
                    returnAfterTenure = calculateFixedDepositReturn(amount, 6.9, tenure);
                else if (tenure == 3)
                    returnAfterTenure = calculateFixedDepositReturn(amount, 7.5, tenure);
                else if (tenure >= 4)
                    returnAfterTenure = calculateFixedDepositReturn(amount, 6.6, tenure);
            }
            else if (account.getBankName() == "AXIS")
            {
                if (tenure == 1)
                    returnAfterTenure = calculateFixedDepositReturn(amount, 6.7, tenure);
                else if (tenure == 2)
                    returnAfterTenure = calculateFixedDepositReturn(amount, 7.1, tenure);
                else if (tenure == 3 || tenure >= 4)
                    returnAfterTenure = calculateFixedDepositReturn(amount, 7, tenure);
            }

            cout << "After " << tenure << " year(s) you will get a return of: " << returnAfterTenure << endl;
            account.balance-=amount;
            cout<<"Balance Left In Account Number "<<account.getAccountNumber()<<" is Rs. "<<account.getBalance()<<endl;
            break;
        }
    }

    if (!found)
    {
        cout << "Account Not Found!" << endl;
    }
}

//----------------------------------------------------------GOAL BASED INVESTING---------------------------------------------------------------------

long double lumpsum(long double fv,long double gold_rate,long double equity_rate,int t)
{
    gold_rate/=100.0;
    equity_rate/=100.0;
    long double pv=0.0,pv1=0.0,pv2=0.0;
    pv1=fv / pow(1+gold_rate,t);
    pv2=fv / pow(1+equity_rate,t);
    cout<<"Best Investment Strategy will be : "<<endl;
    cout<<"Invest "<<0.4*pv1<<" in Gold at current interest rate of 12%"
        <<" and "<<0.6*pv2<<" in Equity at current interest rate of 11.5 %"<<endl;
    pv= (0.4*pv1)+(0.6*pv2);

    return pv;

}
long double sip(long double fv,long double gold_rate,long double equity_rate,int t)
{
    int number_of_payments=t*12;
    long double pv=0.0,pv1=0.0,pv2=0.0;
    pv1= fv / ((pow(1+gold_rate,number_of_payments)-1)/gold_rate)*(1+gold_rate);
    pv2= fv / ((pow(1+equity_rate,number_of_payments)-1)/equity_rate)*(1+equity_rate);
    if(t>0 && t<4)
    {
        cout<<"Best Investment Strategy will be : "<<endl;
        cout<<"Invest "<<0.4*pv1<<" in Gold at current interest rate of 12%"
            <<" and "<<0.6*pv2<<" in Equity at current interest rate of 11.5 %"<<endl;
        pv=(0.4*pv1) + (0.6*pv2) ;

        return pv;
    }
    else if(t>3 && t<6)
    {
        cout<<"Best Investment Strategy will be : "<<endl;
        cout<<"Invest "<<0.3*pv1<<" in Gold at current interest rate of 12%"
            <<" and "<<0.7*pv2<<" in Equity at current interest rate of 11.5 %."<<endl;
        pv=(0.3*pv1) + (0.7*pv2) ;

        return pv;
    }
    else
    {
        cout<<"Best Investment Strategy will be : "<<endl;
        cout<<"Invest "<<0.2*pv1<<" in Gold at current interest rate of 12%"
            <<" and "<<0.8*pv2<<" in Equity at current interest rate of 11.5 %"<<endl;
        pv=(0.2*pv1) + (0.8*pv2) ;
        return pv;
    }
}
void goal_based_investing(vector<UserDetails> &accs)
{

    long double present_value_str;
    string goal;
    cout<<endl;
    cout<<"Your Goal : ";
    cin.ignore();
    getline(cin,goal);
    long long goal_amt;
    cout<<"Amount of money you require to achieve your goal :";
    cin>>goal_amt;
    int tenure;
    cout<<"In how many year(s) you want to achieve your goal : ";
    cin>>tenure;
    int opt;
    cout<<"Choose your preferred type : "<<endl<<"1)SIP (Systematic Investment Plan) "<<endl<<"2)Lumpsum "<<endl;
    cin>>opt;
    if(opt==1)
    {
        long double present_value;
        present_value=sip(goal_amt,12,11.5,tenure);
        cout<<"You need to invest "<<present_value<<" to achieve your goal in "<<tenure<<" year(s)!";
    }
    else if(opt==2)
    {
        long double present_value;
        present_value=lumpsum(goal_amt,12,11.5,tenure);
        cout<<"You need to invest "<<present_value<<" to achieve your goal in "<<tenure<<" year(s)!";
    }
    else
    {
        cout<<"Invalid option !! "<<endl;
    }
}


void invest_again(vector<UserDetails> &accs)
{
    int n;
    while(n=1)
    {
        cout<<endl<<"Do you have any other goal?"<<endl;
        cout<<"Press 1 if Yes else press any other Number : ";
        cin>>n;
        if(n==1)
        {
            goal_based_investing(accs);
        }
        else
        {
            break;
        }
    }

}

//-----------------------------------------------------BUDGETING----------------------------------------------------------------------------------
void budgeting(long double inc)
{
    if (inc <= 20000)
    {
        cout << "Rent: " << (0.5 * inc) << endl;
        cout << "Commute: " << (0.1 * inc) << endl;
        cout << "Food: " << (0.15 * inc) << endl;
        cout << "Miscellaneous: " << (0.05 * inc) << endl;
        cout << "Saving: " << (0.2 * inc) << endl;
    }
    if (inc > 20000 && inc <= 50000)
    {
        cout << "Rent: " << (0.55 * inc) << endl;
        cout << "Commute: " << (0.12 * inc) << endl;
        cout << "Food: " << (0.15 * inc) << endl;
        cout << "Miscellaneous: " << (0.03 * inc) << endl;
        cout << "Saving: " << (0.15 * inc) << endl;
    }
    if (inc > 50000)
    {
        cout << "Rent: " << (0.3 * inc) << endl;
        cout << "Commute: " << (0.05 * inc) << endl;
        cout << "Food: " << (0.15 * inc) << endl;
        cout << "Other allowances: " << (0.2 * inc) << endl;
        cout << "Saving: " << (0.3 * inc) << endl;
    }
}


//------------------------------------------------------------------------------------------------------------------------------------------------


void home(vector<UserDetails> &accounts)  //can change this to accounts
{
    int t ;
again:

    {
        cout<<"Select from the following :\n" ;
        cout<<"1) View Portfolio\n" ;
        cout<<"2) Invest more\n" ;
        cout<<"3) Rebalance\n";
        cout<<"4) View Current Market Status and Bank Rates for FD\n";
        cout<<"5) Goal Based Investing\n";
        cout<<"6) View Last 10 Bank Transactions \n";
        cout<<"7) Budgeting \n";
        cout<<"8) EXIT\n";
        cout<<"Enter your choice : " ;
        cin>>t ;
    }



    switch(t)
    {
    case 1 :
    {
        int x ;
        Portfolio p ;
        while(x = 1)
        {
            cout<<"\nDisplay : \n"<<"1) Mutual Fund Allocation by AMC \n"<<"2) MUTUAL FUND (Equity) CAP ALLOCATION\n"<<"3) MUTUAL FUND ALLOCATION BY SCHEME\n"<<"4) Press any other number key to Go to Home Page\n";
            cout<<"Choose option : " ;

            cin>>x ;
            cout<<"\n\n" ;
            if(x==1)
            {
                MutualfundsAllocation();
            }
            else if(x==2)
            {
                MutualfundsCap();
            }
            else if(x==3)
            {
                MutualfundsScheme();
            }
            else
            {
                goto again;

            }
        }
    }
    break ;
    case 2 :
    {
        investmore i ;
        int s ;
tryagain :
        cout<<"\nSelect the type of investment : \n" ;
        cout<<"1) Stocks \n"<<"2) Digital Gold\n"<<"3) Fixed Deposit(FD)\n\n" ;
        cout<<"Option : " ;
        cin>>s ;
        if(s==1)
        {
            i.stocks(accounts);
        }
        else if(s==2)
        {
            i.createDEMATAccount();
            i.investInDigitalGold(accounts);
        }
        else if(s==3)
        {
            invest_through_fd(accounts);
        }
        else
        {
            cout<<"\nWrong option selected !! \n" ;
            goto tryagain ;

        }

    }
    break ;
    case 3 :
    {
        cout<<"\nYour Portfolio is Perfect as of now.\nWe have no recommendations for you!!\n" ;
    }
    break ;
    case 4:
        view_rates();
        see_rates_again();
        break;
    case 5:
        goal_based_investing(accounts);
        invest_again(accounts);
        break;
    case 7:
        long double income;
        cout<<"\nPlease Enter Your Monthly Income in Rupees : ";
        cin>>income;
        budgeting(income);
        break;
    case 8:
        exit(0);
        break;
    default:
        cout<<endl<<"INVALID OPTION !! ";
    }
}



int main()
{
    introduction();
    vector<UserDetails> accounts;
    int n;
    string inp;

    do
    {
        addAccount(accounts);
        cout << "Do you Want to Add More Accounts ( Y / N ) : ";
        cin >> inp;
        inp = toUpper(inp);
    }
    while (inp == "Y");

    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout << "Details of all accounts:" <<endl;
    system("cls");
    introduction();
    for (const UserDetails &account : accounts)
    {
        account.displayDetails();
    }
    cout<<"ALL ACCOUNT(S) ADDED !! "<<endl;
    cout<<endl;
    while (true)
    {
        cout<<endl<<endl;
        home(accounts);
    }

}