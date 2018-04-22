#include "seqstring.h"

SeqString::SeqString()
{
}

SeqString::SeqString(int msize)
{
    this->setLenght(0);
    this->setMaxLenght(msize);
    this->str = new char[this->maxlenght+1];
}

SeqString::SeqString(const char *s)
{
    this->setLenght(static_cast<int>(this->strlen(s)));
    this->setMaxLenght();
    this->str = new char[this->maxlenght+1];
    this->strcpy(this->str, s);
}

SeqString::SeqString(const SeqString &ss)
{
    this->setLenght(ss.lenght);
    this->setMaxLenght(ss.maxlenght);
    this->str = new char[this->maxlenght];
    this->strcpy(this->str, ss.str);
}

SeqString::~SeqString()
{
    delete[] this->str;
}

void SeqString::setLenght(int lenght)
{
    this->lenght = lenght;
}

void SeqString::setMaxLenght()
{
    this->maxlenght = 32;
    while(this->maxlenght<this->lenght)
    {
        this->maxlenght += 32;
    }
}

int SeqString::len()
{
    return this->lenght;
}
void SeqString::strcpy(char *_Destination, const char *_Source)
{
    int i;
    for(i=0;_Source[i]!='\0';i++)
    {
        _Destination[i] = _Source[i];
    }
    _Destination[i] = '\0';
}

int SeqString::strlen(const char *_Str)
{
    int i;
    for(i=0;_Str[i]!='\0';i++);
    return i;
}

void SeqString::strcat(char *_Destination, const char *_Source)
{
    int i, j;
    for(i=this->strlen(_Destination), j=0;_Source[j]!='\0';j++, i++)
    {
        _Destination[i] = _Source[j];
    }
    _Destination[i] = '\0';
}

void SeqString::setMaxLenght(int msize)
{
    this->maxlenght = msize;
}

int SeqString::index(const char *subs)
{
    if(!subs||this->strIsEqual(subs, ""))
    {
        cout << "子串不能为空" << endl;
        return -1;
    }
    char *s;
    for(int i=0;i<((this->len()-this->strlen(subs))+1);i++)
    {
        s = ((*this)(i, (i+this->strlen(subs)))).str;
        if(this->strIsEqual(s, subs))
        {
            return i;
        }
    }
    return -1;
}

void SeqString::delet(int pos, int len)
{
    if(pos<0||pos>this->len())
    {
        cout << "out of bounds" << endl;
        return;
    }
    if((pos+len)>this->len())
    {
        len = this->len() - pos;
    }
    int i;
    for(i=0;this->str[pos+len+i]!='\0';i++)
    {
        this->str[pos+i] = this->str[pos+len+i];
    }
    this->str[pos+i] = this->str[pos+len+i];
    this->lenght = this->lenght - len;
}

void SeqString::insert(int pos,const char *t)
{
    if(pos<0||pos>this->len())
    {
        cout << "out of bounds" << endl;
        return;
    }
    if((pos+strlen(t))>this->maxlenght)
    {
        cout << "space is small" << endl;
        return;
    }
    if(this->len() == this->maxlenght)
    {
        cout << "overflow" << endl;
        return;
    }
    for(int j=this->len();j >= pos;j--)
    {
        this->str[j+this->strlen(t)] = this->str[j];
    }
    for(int j=0;j<this->strlen(t);j++)
    {
        this->str[pos+j] = t[j];
    }
    this->lenght+=this->strlen(t);
    return;
}

void SeqString::replace(const char *s, const char *t)
{
    int i=0;
    char *ns;
    while(this->str[i]!='\0')
    {
        ns = (*this)(i, i+this->strlen(s)).str;
        if(this->strIsEqual(ns, s))
        {
            this->delet(i, this->strlen(s));
            this->insert(i, t);
        }
        i += this->strlen(t);
    }
}

void SeqString::operator =(const SeqString &ss)
{
    char *temp;
    this->lenght =ss.lenght;
    while(this->maxlenght<this->lenght)
    {
        this->maxlenght += 32;
    }
    temp = this->str;
    this->str = new char[this->maxlenght];
    this->strcpy(this->str, ss.str);
    delete[] temp;
}

SeqString& SeqString::operator ()(int start, int end)
{
    SeqString *ss = new SeqString;
    ss->setLenght(end-start);
    ss->setMaxLenght();
    ss->str = new char[ss->maxlenght+1];
    int i, j;
    for(i=start, j=0;i<end;i++, j++)
    {
        ss->str[j] = this->str[i];
    }
    ss->str[j] = '\0';
    return *ss;
}

bool SeqString::strIsEqual(const char *_Str1, const char *_Str2)
{
    int i;
    for(i=0;(_Str1[i]!='\0')&&(_Str2[i]!='\0');i++)
    {
        if(_Str1[i]!=_Str2[i])
            return false;
    }
    if((_Str1[i]=='\0')&&(_Str2[i]=='\0'))
        return true;
    return false;
}

bool SeqString::operator ==(const SeqString &ss)
{
    if((this->lenght==ss.lenght)&&this->strIsEqual(this->str, ss.str))
        return true;
    else
        return false;
}

SeqString& SeqString::operator +(const SeqString &ss)
{
    SeqString *result = new SeqString;
    result->setLenght(this->lenght + ss.lenght);
    result->setMaxLenght();
    result->str = new char[result->maxlenght+1];
    this->strcpy(result->str, this->str);
    this->strcat(result->str, ss.str);
    return *result;
}

SeqString& SeqString::operator +=(const SeqString &ss)
{
    char *temp;
    this->lenght = this->lenght + ss.lenght;
    this->setMaxLenght();
    temp = this->str;
    this->str = new char[this->maxlenght+1];
    this->strcpy(this->str, temp);
    this->strcat(this->str, ss.str);
    return *this;
}

ostream& operator <<(ostream &os, SeqString &ss)
{
    return os << ss.str;
}
