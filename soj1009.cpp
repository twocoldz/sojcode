#include <iostream>
using namespace std;

int s[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000,10000};
int main()
{
	int i, j;
	int d[5005] = {0};
	d[0] = 1;
	for (i = 0; i <= 10; ++i) {
		for (j = 0; s[i] + j <= 5000; ++j)
			d[s[i] + j] += d[j];
	}
	float n;
    while (scanf("%f", &n) == 1 && (int)(n * 100) != 0)
		printf("%5.2f%12d\n", n, d[(int)((n + 0.005) * 100)]);
    return 0;
}
