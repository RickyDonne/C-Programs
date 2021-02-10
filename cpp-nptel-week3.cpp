#include<iostream>
#include<malloc.h>
#include<string.h>
using namespace std;

class Myclass{
    char *str;
public:
    Myclass(char *s) : str(s) {}     //LINE-1

    ~Myclass(){ delete str; }                 //LINE-2

    Myclass& operator = (Myclass& m){    //LINE-3

        free(str);
        str = strdup(m.str);
        return *this;
    }
    void update(char* x){
        strcat(str, " ");
      	strcat(str, x);//LINE-4
    }
