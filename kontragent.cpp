#include "kontragent.h"
using namespace std;


kontragent::kontragent(){}

void kontragent::setAccount(int account)
{
    this->account=account;
}

void kontragent::setTitle(string title)
{
   this->title=title;
}
void kontragent::CIN()
{     setlocale(LC_ALL, "Russian");

    cout<<"1)������� ����� ����� - ";
    cin>>account;
    this->setAccount(account);
    cout<<"2)������� �������� ����������� - ";
    cin>>title;
    this->setTitle(title);
}
int kontragent::getAccount()const
{
    return account;
}

string kontragent::getTitle()const
{
    return title;
}

kontragent::~kontragent(){}
ofstream& operator<<(ofstream& fout, const kontragent& P)
{setlocale(LC_ALL, "Russian");
    fout <<"\t����� ����� - \t"<< P.getAccount() ;
    fout << "\t�������� �����������- \t"<<P.getTitle() ;
    fout<<"\n";
 return fout;
}
