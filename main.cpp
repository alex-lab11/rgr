using namespace std;
#include <iostream>
#include <string>
#include"kontragent.h"
#include"order.h"
#include"cachIN.h"
#include"cashOUT.h"
#include <fstream>


int main()
{setlocale(LC_ALL, "Russian");
    int i,x,k,j, date1, pay1=0, pay2=0, account1, account2, balance=0,n = 0;
    string purpose1, purpose2, title1,title2;
    ofstream fout;
        fout.open("information.txt", ios::app);
        cout<<"Введите колличество ордеров: "<<endl;
        cin>>x;

    kontragent kin[x];
    kontragent kout[x];
        cashIN in[x];
        cashOUT out[x];
        cout<<"\nУкажите данные приходного ордера\n"<<endl;
        fout<<"Данные приходного ордера\n";
        for(i=0; i<x;  i++)
    {
        kin[i].CIN();
        in[i].CIN(&kin[i]);
        cout<<"\n\t\t**********\n";
    }
        for(i=0; i<x;  i++)
    {
        in[i].print();
        fout<<in[i];
    }

    cout<<"\nУкажите данные расходного ордера\n";
    fout<<"Данные расходного ордера\n";
    for(j=0; j<x; j++)
    {
        kout[j].CIN();
        out[j].CIN(&kout[j]);
        cout<<"\n\t\t**********\n";

    }
    for(j=0; j<x; j++)
    {
        out[j].print();
        fout<<out[j];
    }
    cout<<"\nДля получения информации по параметру(назначение) нажмите 1\n"<<"\n Для получения информации по параметру(счет) нажмите 2\n"<<"\n Для получения информации по параметру (название оргианизации) нажмите 3\n"<<"\n Введите 4 , чтобы узнать баланс на определенную дату\n";
    cin>>k;
switch(k){
/////////////////////////////////////////////////
case 1:
    cout <<"Введите назначение платежа для поиска в приходном ордере"<<endl;
    cin>>purpose1;

        n=-1;
        for ( i = 0; i < x; i++)
    {
    if (in[i].getPurpose() == purpose1)
    n= i;
    }
    if (n!= -1)
    {
    in[n].print();
    fout<<"Информация по параметру (назначение)\n";
    fout<<in[n];
    }
    else
    {
        cout << " Платежа с введенным параметром нет" << endl;
        fout <<"Информация по параметру (назначение)\n";
        fout<<  "Платежа с введенным параметром нет\n";
    }

        cout <<"Введите назначение платежа для поиска в расходном ордере"<<endl;
        cin>>purpose2;

        n=-1;
        for ( j = 0; j < x; j++)
    {
        if (out[j].getPurpose() == purpose2)
        n= j;

    }
    if (n!= -1)
    {
        cout <<"информация по параметру (назначение)"<<endl;
        out[ n].print();
        fout<<"информация по параметру (назначение)\n";
        fout<<out[n];
    }
        else
    {
    cout << "Платежа с введенным парматером нет\n" ;
    fout<<"Информация по параметру (назначение)\n";
    fout<<"Платежа с введенным параметром нет\n" ;
 }
 break;
 ///////////////////////////////////////////////////////
  case 2:
    cout <<"введите счет платежа для поиска в приходном ордере"<<endl;
    cin>>account1;
     n= -1;
for ( i = 0; i < x; i++)
 {
     if (kin[i].getAccount()  == account1)
     n= i;
 }

if (n!= -1)
 {
    in[ n].print();
    fout<<"информация по параметру (счет)\n";
    fout<<in[n];
 }
else
 {
    cout << " платежа с введенным парметром нет\n" ;
    fout<<"информация по параметру (счет)\n";
    fout<<"платежа с введенным параметром нет\n" ;
 }

    cout <<"введите счет платежа для поиска в расходном ордере"<<endl;
    cin>>account2;
    n= -1;
for ( j = 0; j < x; j++)
 {
     if (kout[j].getAccount() == account2)
     n= j;
 }

if (n!= -1)
 {
    out[ n].print();
    fout<<"информация по параметру (счет)\n";
    fout<<out[n];
 }
 else
 {
    cout << " платежа с введенным параметром нет\n";
    fout<<"информация по параметру (счет)\n";
    fout<<"платежа с введенным параметром нет\n" ;
 }
 break;
//////////////////////////////////////////////////
 case 3 :
    cout <<"введите название организации для поиска в приходном ордере"<<endl;
    cin>>title1;
    n= -1;
for ( i = 0; i < x; i++)
 {
     if (kin[i].getTitle()  == title1)
     n= i;
 }

 if (n!= -1)
{
    in[ n].print();
    fout<<"информация по пармаметру (название)\n";
    fout<<in[n];
}
 else
 {
    cout << " платежа с введенным параметром нет\n" ;
    fout<<"информация по пармаметру (название)\n";
    fout<<"платежа с введенным параметром нет\n" ;
 }

    cout <<"введите название организации для поиска в расходном ордере"<<endl;
    cin>>title2;
    n= -1;

for ( j = 0; j < x; j++)
 {
    if (kout[j].getTitle() == title2)
    n= j;
 }

 if (n!= -1)
 {
    out[ n].print();
    fout<<"информаия по параметру название\n";
    fout<<out[n];
 }
 else
 {
    cout << " платежа с введенным параметром нет\n";
    fout<<"информация по параметру название\n";
    fout<<"платежа с введенным параметром нет\n" ;
 }
 break;
////////////////////////////////////////
case 4:
    cout <<"\n\t\t\tУкажите дату для просмотра баланса за этот день\n"<<endl;
    cin>>date1;

for ( i = 0; i < x; i++)
 {
     if (in[i].getDate()  <= date1)
    {
      pay1=pay1+in[i].getPay();
    }
 }
for ( j = 0; j < x;  j++)
 {
     if (out[j].getDate()  <= date1)
    {
      pay2=pay2+out[j].getPay();
    }
 }
if ((pay1!=0)&&(pay2!=0))
 {
    balance=pay1-pay2;
    cout<<"баланс = "<<balance<<"платеж приходного = "<<pay1<<"платеж расходного =  "<<pay2;

    fout<<"баланс на введенную дату: "<<balance;
 }
 break;
 }
fout.close();
cout<<"\n\n\n\t\t\tчтобы выйти из приложения нажмите  любую кнопку\n\n\n\n";
    return 0;
}

