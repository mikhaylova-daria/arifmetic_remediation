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
#define SMALLNUM int
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
    int push_back (T const new_);
    int put_on_bot (T const new_);//положить на "дно"
    int size_of_vector();
    void output ();
    int remove_top(); //удаление последнего (того, что сверху
    T &operator [] (int pos);
    const T &operator [] (int pos) const;
    my::vector<T> &operator = (my::vector<T> const& a);
    bool operator == (my::vector<T> const&a);
    bool operator != (my::vector<T> const& a);
    };

class BigNum
{
    my::vector<int> num;
    bool sign;
public:
    BigNum();
    BigNum(const BigNum &a);
    BigNum (SMALLNUM x);
    ~BigNum();
    void input();
    void finput (FILE*);
    void output();
    void foutput();
    void foutput(FILE*);
    BigNum min_size (BigNum a, BigNum b);
    BigNum max_size (BigNum a, BigNum b);
    void remove_null ();
    BigNum Karatsuba(BigNum a);
    friend BigNum dif (BigNum, BigNum );
    BigNum power(int);
    BigNum power(BigNum);
    BigNum sqrt();          //целая часть от квадратного коряня
    BigNum operator + (BigNum a);
    BigNum operator -(BigNum a);
    BigNum operator * (SMALLNUM a);
    BigNum operator * (BigNum a);
    BigNum operator / (SMALLNUM a);
    BigNum operator / (BigNum a);
    BigNum operator % (BigNum a);
    void  operator = (BigNum a);
    bool operator == (BigNum a);
    bool operator != (BigNum a);
    bool operator >= (BigNum a);
    bool operator <= (BigNum a);
    bool operator > (BigNum a);
    bool operator < (BigNum a);
    friend BigNum division_of_numbers_similar_length__return_modulo (BigNum dividend, BigNum divider, SMALLNUM &quotient);
    friend BigNum division(BigNum dividend, BigNum divider, BigNum &quotient);// Возвращают остаток от деления (обе)!!!
};
struct Q_Num {
    BigNum numerator;
    BigNum denominator;
};

#include "Vector.h"
#include "BigNum.h"

#endif // LIBR_H
