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

    cout<<"3)Введите сумму платежа - ";
    cin>>pay;
    this->setPay(pay);
    cout<<"4)Введите дату оплаты числом - ";
    cin>>date;
    this->setDate(date);
    cout<<"5)Введите назначение платежа - ";
    cin>>purpose;
    this->setPurpose(purpose);
    this->P=P;
    }
    void order:: print()
    {
    setlocale(LC_ALL, "Russian");
    cout<<endl<<"Дата оплаты - "<<this->getDate()<<" Название организации - "<<this->P->getTitle()<<"Номер счета - "<<this->P->getAccount()<<" Назначение платежа - "<<this->getPurpose()<<" Сумма оплаты - "<<this->getPay()<<endl;
    }
    order::~order(){}
    ofstream& operator<<(ofstream& fout, const order& P)
{
    setlocale(LC_ALL, "Russian");
    fout <<"\tДата оплаты - "<< P.getDate() ;
    fout <<"\tСумма оплаты - "<< P.getPay() ;
    fout <<"\tНазначение платежа - "<<P.getPurpose();
    fout<<"\n" ;
    return fout;
}


