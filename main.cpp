#include "libr.h"

int main()
{
    null_v.push_back(0);
    FILE* fp =fopen("INPUT.TXT","r");
    BigNum a;
    BigNum b;
    BigNum c;
    a.finput(fp);
    b.finput(fp);
    a.output();
    b.output();
   // c = a - b;
    c = a / b;
    c.output();
    return 0;

}

