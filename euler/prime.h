#ifndef PRIME_H
#define PRIME_H

#include <unordered_map>
#include <vector>
#include <stdio.h>
#include <euler/macro.h>

// computes primes less than n
// this is only good for about a million because it overflows a 32 bit int
std::pair< std::vector<int>, std::vector<bool> > computePrimesAndPrimality(const int n, std::vector<int>& primes, std::vector<bool>& isPrime){
	isPrime.resize(n);
	isPrime.flip();
	isPrime[0] = isPrime[1] = 0;

	for(int i=2; i<n; i++)
		if(isPrime[i]) {
			primes.push_back(i);
			for(int j=i*i; j<n; j+=i)
				if(j>0)
					isPrime[j]=0;
		}
	
	return make_pair(primes, isPrime);
}

std::pair< std::vector<int>, std::vector<bool> > computePrimesAndPrimality(const int n){
	std::vector<int>primes;
	std::vector<bool> isPrime(n);
	return computePrimesAndPrimality(n,primes,isPrime);
}

std::vector<int> computePrimes(const int n){
	return computePrimesAndPrimality(n).first;
}

//
std::pair< std::vector<long long>, std::vector<bool> > computePrimesAndPrimalityLL(const long long n, std::vector<long long>& primes, std::vector<bool>& isPrime){
	isPrime.resize(n);
	isPrime.flip();
	isPrime[0] = isPrime[1] = 0;

	for(long long i=2; i<n; i++)
		if(isPrime[i]) {
			primes.push_back(i);
			for(long long j=i*i; j<n; j+=i)
				if(j>0)
					isPrime[j]=0;
		}

	return make_pair(primes, isPrime);
}

std::pair< std::vector<long long>, std::vector<bool> > computePrimesAndPrimalityLL(const long long n){
	std::vector<long long>primes;
	std::vector<bool> isPrime;

	return computePrimesAndPrimalityLL(n, primes, isPrime);
}


std::vector<long long> computePrimesLL(const long long n){
	std::pair< std::vector<long long>, std::vector<bool> > p = computePrimesAndPrimalityLL(n);
	return p.first;
}

std::unordered_map<long long,long long> computePhiLL(const int maxN){
	std::unordered_map<ll,ll> phi;
	ll n;
	std::vector<ll> primes;
	std::vector<bool> primality;

	computePrimesAndPrimalityLL(maxN,primes,primality);

	// phi(n^k) = n^k - n^(k-1)
	FIT(it,primes){
		n = *it;
		while(n<maxN && n > 0){
			phi[n] = n - n / *it;
			n *= *it;
		}
	}

	// if gcd(m,n) = 0 then phi(m*n) = phi(m)*phi(n)
	for(ll i=2; i<maxN; i++){
		if( phi[i] ){
			FIT(it,primes)
				if( i % *it != 0 ){
					n = *it;
					if( i*n>=maxN || i*n<=0 )
						break;
					while( i*n<maxN && i*n>0 && !phi[i*n] ){
						phi[ i*n ] = phi[i] * phi[n];
						n *= *it;
					}
				}
		}else{
			printf("unknown: %lld\n",i);
			return phi;
		}
	}

	return phi;
}


#endif
