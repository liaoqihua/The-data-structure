#ifndef SEQSTRING_H
#define SEQSTRING_H
#include <iostream>
using namespace std;

class SeqString
{
public:
    SeqString();
    SeqString(int msize);
    SeqString(const char *s);
    SeqString(const SeqString &ss);
    ~SeqString();
    void setLenght(int lenght);
    void setMaxLenght();
    void setMaxLenght(int msize);
    int len();
    void strcpy(char *_Destination, const char *_Source);
    int strlen(const char *_Str);
    void strcat(char *_Destination, const char *_Source);
    bool strIsEqual(const char *_Str1, const char *_Str2);
    int index(const char *subs);
    void delet(int pos, int len);
    void insert(int pos,const char *t);
    void replace(const char *s, const char *t);
    void operator =(const SeqString &ss);
    bool operator ==(const SeqString &ss);
    SeqString& operator +(const SeqString &ss);
    SeqString& operator +=(const SeqString &ss);
    SeqString& operator ()(int start, int end);
    friend ostream& operator <<(ostream &os, SeqString &ss);
private:
    int lenght;
    int maxlenght;
    char *str;
};

#endif // SEQSTRING_H
