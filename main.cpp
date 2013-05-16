#include "libr.h"

int main()
{
    null_v.push_back(0);
//    BigNum z;
//    z.input();
//    z.output();
//    try {
//    z = z / (z /BigNum (123456));
//    } catch(const char * ch) {
//        cout << ch<<'\n';
//    }

//    z.output();

    FILE* fp =fopen("INPUT.TXT","r");
    BigNum a;
    BigNum b;
    BigNum c;
    a.finput(fp);
    b.finput(fp);
    a.output();
    b.output();
    c = a - b;
    c.output();
    c = a + b;
    c.output();
    c = a.Karats(b);
    c.output();
    c = a * b;
    c.output();
    BigNum r;
    c = b.abs();
    c.output();
     c = division(a, b, r);
    c.output();
    r.output();
    c = division(b, a, r);
     c.output();
     r.output();
    c = a.operator % (b);
    c.output();
    c = b % a;
    c.output();
    c = b / a;
    BigNum x(100000000);
    c = x.sqrt();
    c.output();
    x = BigNum (-100000000);
    try {
        c = x.sqrt();
    } catch (const char* ex){
        cout << ex << '\n';
    }

    c.output();
    BigNum y(640009);
    c = y.sqrt();
    c.output();
    return 0;

}

