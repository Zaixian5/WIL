#include <stdio.h>

int main()
{
    char a;
    signed char b;
    unsigned char c;
    short d;
    short int e;
    unsigned short f;
    unsigned short int g;
    int h;
    signed int i;
    unsigned j;
    unsigned int k;
    long l;
    long int m;
    signed long n;
    signed long int o;
    unsigned long p;
    unsigned long int q;
    long long r;
    long long int s;
    signed long long t;
    signed long long int u;
    unsigned long long v;
    unsigned long long int w;

    a=127;
    b=127;
    c=255;
    d=32767;
    e=32767;
    f=65535;
    g=65535;
    h=2147483647;
    i=2147483647;
    j=4294967295;
    k=4294967295;
    l=2147483647;
    m=2147483647;
    n=2147483647;
    o=2147483647;
    p=4294967295;
    q=4294967295;
    r=9223372036854775807;
    s=9223372036854775807;
    t=9223372036854775807;
    u=9223372036854775807;
    v=18446744073709551615;
    w=18446744073709551615;

    printf("max char c1: %d\n", a);
    printf("max signed char c2: %d\n", b);
    printf("max unsigned char c3: %d\n", c);
    printf("max short s1: %d\n", d);
    printf("max short int s2: %d\n", e);
    printf("max unsigned short s3: %d\n", f);
    printf("max unsigned short int s4: %d\n", g);
    printf("max int i1: %d\n", h);
    printf("max signed int i2: %d\n", i);
    printf("max unsigned u1: %u\n", j);
    printf("max unsigned int u2: %u\n", k);
    printf("max long l1: %ld\n", l);
    printf("max long int l2: %ld\n", m);
    printf("max signed long l3: %ld\n", n);
    printf("max signed long int l4: %ld\n", o);
    printf("max unsigned long l5: %u\n", p);
    printf("max unsigned long int l6: %u\n", q);
    printf("max long long l7: %lld\n", r);
    printf("max long long int l8: %lld\n", s);
    printf("max signed long long l9: %lld\n", t);
    printf("max signed long long int l10: %lld\n", u);
    printf("max unsigned long long l11: %llud\n", v);
    printf("max unsigned long long int l12: %llud\n", w);

    return 0;


}
