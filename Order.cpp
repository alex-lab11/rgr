#include "order.h"

using namespace std;

 order::order(){}
 void order::setPurpose(string purpose)
{
 this->purpose=purpose;
}
void order::setDate(int date)
{
    this->date=date;
}
void order::setPay(int pay)
{
    this->pay=pay;
}
 int order:: getPay()const
{
    return pay;
}
 int order::getDate()const
{
    return date;
}
 string order::getPurpose()const
{
    return purpose;
}

 void order:: CIN (kontragent *P)
{   int pay, date;
    string  purpose;
    setlocale(LC_ALL, "Russian");

    cout<<"3)������� ����� ������� - ";
    cin>>pay;
    this->setPay(pay);
    cout<<"4)������� ���� ������ ������ - ";
    cin>>date;
    this->setDate(date);
    cout<<"5)������� ���������� ������� - ";
    cin>>purpose;
    this->setPurpose(purpose);
    this->P=P;
    }
    void order:: print()
    {
    setlocale(LC_ALL, "Russian");
    cout<<endl<<"���� ������ - "<<this->getDate()<<" �������� ����������� - "<<this->P->getTitle()<<"����� ����� - "<<this->P->getAccount()<<" ���������� ������� - "<<this->getPurpose()<<" ����� ������ - "<<this->getPay()<<endl;
    }
    order::~order(){}
    ofstream& operator<<(ofstream& fout, const order& P)
{
    setlocale(LC_ALL, "Russian");
    fout <<"\t���� ������ - "<< P.getDate() ;
    fout <<"\t����� ������ - "<< P.getPay() ;
    fout <<"\t���������� ������� - "<<P.getPurpose();
    fout<<"\n" ;
    return fout;
}


