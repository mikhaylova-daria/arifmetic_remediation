#ifndef LIBR_H
#define LIBR_H
#ifndef STDLIB_H
#include <stdlib.h>
#endif
#ifndef _IOSTREAM
    #include <iostream>
    #define  _IOSTREAM
#endif
#ifndef _NEW
    #include <new>
    #define  _NEW
#endif
#ifndef MATH_H
    #include <math.h>
    #define MATH_H
#endif
#ifndef STDIO_H
   #include <stdio.h>
   #define STDIO_H
#endif
#define radix 10
#define X 10 //число, степенью которого является основание (только 10 )
#define radix_size 1 //степень 10
#define MAX_SIZE 1024
typedef int SMALLNUM ;
namespace  my {
template <typename T> class vector;
}

template <typename T> class my::vector
{
    T *p_vector;
    int  size;
    int capacity;
public:
    vector();
    vector (int _capacity);
    vector (vector const &a);
    ~vector();
    int push_back (T const & new_);
    int put_on_bot (T const  &new_);//положить на "дно"
    int size_of_vector() const;
    void output () const;
    int remove_top(); //удаление последнего (того, что сверху
    T &operator [] (int pos);
    const T &operator [] (int pos) const;
    my::vector<T> &operator = (my::vector<T> const& a);
    bool operator == (my::vector<T> const&a) const;
    bool operator != (my::vector<T> const& a) const;
    };

class BigNum
{
    my::vector<int> num;
    bool sign;
    BigNum Karatsuba(BigNum a);
    void remove_null ();
    friend BigNum dif (const BigNum &,const BigNum & );
    bool is_null();  //убирает - у нуля,+ если число ноль - истина,  нет - ложь
public:
    BigNum();
    BigNum(const BigNum &a);
    BigNum (SMALLNUM x);
    ~BigNum();
    void input();
    void finput (FILE*);
    void output() const;
    void foutput() const;
    void foutput(FILE*) const;
    BigNum min_size (const BigNum *a,const BigNum *b) const;
    BigNum max_size (const BigNum *a, const BigNum *b) const;
    BigNum Karats(BigNum a);
    BigNum power(int);
    BigNum power(BigNum);
    BigNum sqrt() const;          //целая часть от квадратного коряня
    BigNum abs() const;
    BigNum operator + (const BigNum &a) const;
    BigNum operator -(const BigNum &a) const;
    BigNum operator * (const SMALLNUM  &a) const;
    BigNum operator * (const BigNum &a) const;
    BigNum operator / (const SMALLNUM &a) const;
    BigNum operator / (const BigNum &a) const;
    BigNum operator % (const BigNum &a) const;
    void  operator = (const BigNum &a);
    bool operator == (const BigNum &a)const;
    bool operator != (const BigNum &a) const;
    bool operator >= (const BigNum &a) const;
    bool operator <= (const BigNum &a) const;
    bool operator > (const BigNum &a) const;
    bool operator < (const BigNum &a) const;
    friend BigNum division_of_positive_numbers_with_singledigit_result(const BigNum &dividend, const BigNum &divider, SMALLNUM &quotient);
    friend BigNum division(const BigNum &dividend, const BigNum &divider,  BigNum &quotient);// Возвращают остаток от деления (обе)!!!
};
struct Q_Num {
    BigNum numerator;
    BigNum denominator;
};
BigNum null(0);
my::vector<int> null_v;


#include "Vector.h"
#include "BigNum.h"

#endif // LIBR_H
