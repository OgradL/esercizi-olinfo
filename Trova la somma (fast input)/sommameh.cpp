#include <stdio.h>

long long readint(void)
{
	long long n, c;
	n = _getchar_nolock() - '0';
	while ((c = _getchar_nolock()) > ' ')
		n = 10*n + c-'0';
	return n;
}

int main() {
	printf("%lld\n", readint());
}