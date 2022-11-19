/* RSA algorithm - 202135570 이현지 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int gcd(int, int);
void encryption(double, double, double);
void decryption(double, double, double);
double ciphertext, plaintext;

void main()
{
    double p, q, n = 0, t = 0; //p, q: two large prime numbers
    double e, d; //e: relatively prime to t, d: private key
    double msg;

    p = 7, q = 3;
    printf("Message: ");
    scanf("%lf", &msg);
    n = p * q;
    /* Euler totient */
    t = (p - 1) * (q - 1); 
    /* Relatively prime number (Find e) */
    for (int i = 2; i < t; i++)
    {
        if (gcd((p - 1), i) == 1 && gcd((q - 1), i) == 1)
        {
            e = i;
            break;
        }
    }
    
    /* Find d: multiplicative inverse of e, mod 'Euler totient function' */
    for (int i = 1; i < n; i++)
    {
        if (fmod((e * i), t) == 1)
        {
            d = i;
            break;
        }
    }

    encryption(msg, e, n);
    decryption(msg, d, n);
}

int gcd(int a, int b)
{
    int temp, n;
    if (a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }

    /* gcd(a, 0) = a */
    while (b != 0) 
    {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}

void encryption(double m, double e, double n)
{
    ciphertext = fmod(pow(m, e), n);
    //printf("e = %.2lf\n", e);
    printf("Cipher text(encryption): %.2lf\n", ciphertext);
}

void decryption(double m, double d, double n)
{
    plaintext = fmod(pow(ciphertext, d), n);
    //printf("d = %.2lf\n", d);
    printf("Plain text(decryption): %.2lf", plaintext);
}