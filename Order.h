#ifndef ORDER_H_INCLUDED
#define ORDER_H_INCLUDED
using namespace std;
#include<iostream>
#include<string.h>
#include"kontragent.h"
#include <fstream>
class order {

protected:
    kontragent *P;
    int pay;
    int date;
public:
    string purpose;
    order();
    void setPay(int);
    void setDate(int);
    void setPurpose(string );
    int getPay()const;
    int getDate()const;
    string getPurpose()const;
    void CIN (kontragent*P);
    void print();
    friend ofstream& operator<<(ofstream& fout, const order& obj);
    ~order();
};

#endif // ORDER_H_INCLUDED
