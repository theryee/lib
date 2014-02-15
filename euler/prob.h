#ifndef PROB_H
#define PROB_H

int combos(int n, int k){
	int ret = 1;
	for(int i=k+1; i<=n; i++)
		ret *= i;
	for(int i=1; i<=n-k; i++)
		ret /= i;
	return ret;
}

long long combos(long long n, long long k){
	long long ret = 1;
	for(long long i=k+1; i<=n; i++)
		ret *= i;
	for(long long i=1; i<=n-k; i++)
		ret /= i;
	return ret;
}

#endif
