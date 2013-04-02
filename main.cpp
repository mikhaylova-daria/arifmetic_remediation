#include "libr.h"

int main()
{
    FILE* fp =fopen("INPUT.TXT","r");
    BigNum a;
    BigNum b;
    BigNum c;
    a.finput(fp);
    b.finput(fp);
    a.output();
    b.output();
   // c = a + b;
    c = dif(a, b);
    c.output();
    return 0;

}

