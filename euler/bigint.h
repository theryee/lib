#ifndef BIGINT_H
#define BIGINT_H

#include <string.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>

//forward declarations
class BigInt;
BigInt operator*(BigInt left, const int& right);

/**
 * Positive numbers only...
 */
class BigInt{
public:
	BigInt(char *s){
		unsigned int len=strlen(s);
		for(int i=len-1; i>=0; i--)
			buf.push_back(s[i]-'0');
		if(buf.size()==0)
			buf.push_back(0);
	}

	BigInt(int n){
		while(n){
			buf.push_back(n%10);
			n/=10;
		}

		if(buf.size()==0)
			buf.push_back(0);
	}
	BigInt(){
		BigInt(0);
	}
	BigInt(const BigInt& b){
		buf = b.buf;
	}

	BigInt& operator+=(const BigInt& right){
		int leftSize = this->buf.size();
		int rightSize = right.buf.size();
		int c = 0;
		for(int i=0; i<std::max(leftSize,rightSize); i++){
			int l = i < leftSize ? this->buf[i] : 0;
			int r = i < rightSize ? right.buf[i] : 0;
			int sum = l + r + c;
			c = sum / 10;
			sum %= 10;
			if(i < leftSize)
				buf[i] = sum;
			else
				buf.push_back(sum);
		}
		while(c){
			buf.push_back(c % 10);
			c /= 10;
		}
		return *this;
	}

	BigInt& operator*=(const int& right){
		int c = 0;
		int len = buf.size();
		for(int i=0; i<len; i++){
			buf[i] = buf[i]*right + c;
			c = buf[i] / 10;
			buf[i] %= 10;
		}
		while(c){
			buf.push_back(c % 10);
			c /= 10;
		}
		return *this;
	}

	BigInt& operator*=(const BigInt& right){
		int rightSize = right.buf.size();
		BigInt sum(0);
		int factor=0;

		for(int i=0; i<rightSize; i++){
			BigInt s = *this * ((right.buf[i]));
			for(int i=0; i<factor; i++)
				s *= 10;
			sum += s;
			factor++;
		}

		this->buf = sum.buf;

		return *this;
	}


	void print() const{
		for(int i=this->buf.size()-1; i>=0; i--)
			printf("%d",buf[i]);
	}

	void println() const{
		print();
		printf("\n");
	}

	std::string toString() const{
		std::string s;
		for(int i=this->buf.size()-1; i>=0; i--)
			s+=buf[i]+'0';
		return s;
	}

	unsigned size() const{
		return buf.size();
	}

	BigInt& reverse(){
		unsigned len = size();
		for(int i=0; i<len/2; i++)
			std::swap(buf[i],buf[len-1-i]);
		return *this;
	}

	bool operator==(const BigInt & right){
		return buf == right.buf;
	}

	int operator[](const int & index) const {
		return buf[index];
	}

	BigInt& operator=(const BigInt & right){
		this->buf = right.buf;
		return *this;
	}

private:
	std::vector<int> buf;
};

BigInt operator+(BigInt left, const BigInt& right){
	left += right;
	return left;
}

BigInt operator*(BigInt left, const BigInt& right){
	left *= right;
	return left;
}

BigInt operator*(BigInt left, const int& right){
	left *= right;
	return left;
}

#endif
