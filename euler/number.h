#ifndef NUMBER_H
#define NUMBER_H

#include <string.h>

int gcd(int a, int b){
	return b==0 ? a : gcd( b, a%b );
}

long long gcd(long long a, long long b){
	return b==0 ? a : gcd( b, a%b );
}

int lcm(int a, int b){
	return a*b / gcd(a,b);
}

long long lcm(long long a, long long b){
	return a*b / gcd(a,b);
}

unsigned int countDigits(int n){
	if(n<0)
		return -1;
	if(n<10)
		return 1;
	if(n<100)
		return 2;
	if(n<1000)
		return 3;
	if(n<10000)
		return 4;
	if(n<100000)
		return 5;
	if(n<1000000)
		return 6;
	if(n<10000000)
		return 7;
	if(n<100000000)
		return 8;
	if(n<1000000000)
		return 9;
	return -1;
}

int pow10(int n){
	switch(n){
		case 0:	return 1;
		case 1: return 10;
		case 2: return 100;
		case 3: return 1000;
		case 4: return 10000;
		case 5: return 100000;
		case 6: return 1000000;
		case 7: return 10000000;
		case 8: return 100000000;
		case 9: return 1000000000;
	}
	return -1;
}

long long sqrtll(long long n){
	long long lo = 1;
	long long hi = n;
	long long pivot;
	while(lo<=hi && hi-lo>1){
		pivot = (hi + lo) / 2;
		if(pivot*pivot < n)
			lo = pivot;
		else
			hi = pivot;
	}
	return lo;
}

bool ispan(int n){
	int counts[10];
	memset(counts,0,sizeof(counts));
	while(n){
		if( ++counts[n%10] > 1 )
			return false;
		n /= 10;
	}

	for(int i=1; i<=9; i++)
		if( counts[i] != 1 )
			return false;
	
	return true;
}

#endif
