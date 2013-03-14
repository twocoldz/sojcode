#include <iostream>  
#include <cstring>  
#include <cmath>  
  
using namespace std;  
  
#define MAXINT (1 << 16)  
#define MAXN 6600  
  
int prime[MAXN], nPrime = 0, factor[MAXN];  
  
// 素数判定。  
bool isPrime(int x)  
{  
    if (x <= 1) return false;  
    if (x == 2) return true;  
  
    if (x & 1)  
    {  
        int top = sqrt(x);  
        for (int i = 3; i <= top; i += 2)  
            if (x % i) continue;  
            else return false;  
        return true;  
    }  
    else return false;  
}  
  
// 生成指定范围内的所有素数。  
void getPrime(void)  
{  
    for (int i = 2; i <= MAXINT; i++)  
        if (isPrime(i))  
            prime[nPrime++] = i;  
}  
  
// 求最大公约数。  
int gcd(int x, int y)  
{  
    return x < y ? gcd(y, x) : (y ? gcd(y, x % y) : x);  
}  
  
// 素因子分解并求指数的最大公约数。  
int factoring(int x)  
{  
    int y = 0;  
  
    memset(factor, 0, sizeof(factor));  
  
    for (int i = 0; i < nPrime && x > 1; i++)  
        while (x % prime[i] == 0)  
        {  
            factor[i]++;  
            x /= prime[i];  
        }  
  
    for ( i = 0; i < MAXN; i++)  
        if (factor[i])  
        {  
            if (y) y = gcd(y, factor[i]);  
            else y = factor[i];  
        }  
          
    return y;  
}  
  
// 特例处理。  
void specialCase(int initCatHeight, int workerCatsNumber)  
{  
    if (initCatHeight == 1)  
        cout << "0 1" << endl;  
    else  
    {  
        int nest = 1;  
        for (int i = 2; i < initCatHeight; i *= 2, nest++)  
            ;  
        cout << nest << " " << (pow(2, nest + 1) - 1) << endl;  
    }  
}  
  
int main (int argc, char const* argv[])  
{  
    int nest, n;  
  
    getPrime();  
  
    int initCatHeight, workerCatsNumber;  
    while (cin >> initCatHeight >> workerCatsNumber, initCatHeight || workerCatsNumber)  
    {  
        // 特例处理。  
        if (workerCatsNumber == 1)  
        {  
            specialCase(initCatHeight, workerCatsNumber);  
            continue;  
        }  
  
        // 利用素因子分解求嵌套层数。  
        nest = factoring(initCatHeight);  
        nest = gcd(nest, factoring(workerCatsNumber));  
  
        // 利用素因子分解结果和嵌套层数求 N。  
        n = 1;  
        for (int i = 0; i < MAXN; i++)  
            if (factor[i])  
                n *= pow(prime[i], factor[i] / nest);  
  
        // 求未工作的猫数量和所有猫的高度总和。  
        int unworkCatsNumber = 0, totalHeight = 0;  
        while (workerCatsNumber > 1)  
        {  
            workerCatsNumber /= n;  
            unworkCatsNumber += workerCatsNumber;  
        }  
          
        int exponent = 1;  
        while (initCatHeight >= 1)  
        {  
            totalHeight += initCatHeight * exponent;  
            exponent *= n;  
            initCatHeight /= (n + 1);  
        }  
  
        // 输出。  
        cout << unworkCatsNumber << " " << totalHeight << endl;  
    }  
  
    return 0;  
}  