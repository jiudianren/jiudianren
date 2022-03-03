/*
 * mystring.cpp
 *
 *  Created on: 2022年3月3日
 *      Author: Administrator
 */

#include "mystring.h"
#include <iostream>

/*https://blog.csdn.net/sinat_34715587/article/details/88885647 */
#include <cstring>



using namespace std;

class mystring {
	friend ostream&  operator<<(ostream & os, const mystring & s);
	friend istream&  operator>>(istream & os,  const mystring & s);
public:
	mystring();
	virtual ~mystring();


	mystring(const char * from);
	mystring(const mystring & anther);
	mystring &  operator=(const mystring & from);

	char operator[](const int & index);
	mystring & operator+(const mystring & toadd);

	int size() const{return this->len};
	char* c_str() const{return this->context};
private:
	int len ;
	char* context;
};



mystring::mystring():len(0),context(new char[1]) {
	this->len= 0;
	*context = '\0';
}

mystring::~mystring() {
	if(this->context)
	{
		delete [] this->context;
		this->context = nullptr;
		this->len =0;
	}
}


mystring::mystring(const char * s) {
	if(s)
	{
		this->len = strlen(s);
		this->context = new char[this->len+1];
		strcpy(this->context, "");
	}
	else
	{
		this->len=0;
		this->context = new char[1];
		*this->context = '\0';
	}
}


mystring::mystring(const mystring & anther)
{
	this->len = anther.len;
	this->context = new char[this->len + 1];
	strcpy(this->context, anther.context);
}


mystring &  mystring::operator=(const mystring & from)
{
	if(this != &from)
	{
		if(this->context)
		{
			delete [] this->context;
			this->context = nullptr;
		}

		this->len = from.len;
		this->context = new char[this->len+1];
		strcpy(this->context, from.context);
	}
	return *this;

}


char mystring::operator[](const int  &index)
{
	if(index < this->len)
	{
		return this->context[index];
	}
	else
	{
		return '\0';
	}
}



ostream & operator<<(ostream & out, const mystring  & s)
{
	out << s.context;
	return out;
}

istream & operator >> (istream & in, mystring & s)
{
	// TODO: insert return statement here
	char p[50];
	in.getline(p, 50);
	s = p;
	return in;
}
