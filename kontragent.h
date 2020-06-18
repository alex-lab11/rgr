#ifndef KONTRAGENT_H_INCLUDED
#define KONTRAGENT_H_INCLUDED
using namespace std;
#include<iostream>
#include<string.h>
#include <fstream>
class kontragent {

protected:

    int account;
    string title;
  public:
    kontragent();
    void setTitle(string );
    void setAccount(int);
    int getAccount()const;
    string getTitle() const;
    void CIN();
    ~kontragent();
   friend ofstream& operator<<(ofstream& fout, const kontragent& obj);
};

#endif // KONTRAGENT_H_INCLUDED
