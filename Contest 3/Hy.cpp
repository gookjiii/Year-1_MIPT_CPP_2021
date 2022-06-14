#include<bits/stdc++.h>
using namespace std;

void rol(long long octalNumber) {
	long long decimalNumber = 0, i = 0;
    long long binaryNumber = 0;
    long long Pow = 1;
    while(octalNumber != 0)
    {
        decimalNumber += (octalNumber%10) * Pow;
        Pow *= 8;
        ++i;
        octalNumber/=10;
    }

    i = 1;
				char str[17];
    itoa(decimalNumber,str,2);
    char c = str[0];
    if(c == '0') c == '1'; else c == '0';
				long long res = 0;
				int pos = 1;
				while(str[pos] != '1') pos++;
				pos--;
				cout << str << endl;
				for (int i = pos; i < 16; i++)
    	res = res*10 + (str[i] == '0' ? 0 : 1);
    int octal = 0, decimal = 0;
    i = 1;
    cout << res << endl;
				while(res != 0)
    {
        decimal += (res%10) * pow(2,i);
        ++i;
        res/=10;
    }
    i = 1;
    while (decimal != 0)
    {
        octal += (decimal % 8) * i;
        decimal /= 8;
        i *= 10;
    }
				cout << octal;
}
long long OctaltoBinary(long long octalNumber)
{
				long long decimalNumber = 0, i = 0;
    long long binaryNumber = 0;
    long long Pow = 1;
    while(octalNumber != 0)
    {
        decimalNumber += (octalNumber%10) * Pow;
        Pow *= 8;
        ++i;
        octalNumber/=10;
    }
    i = 1;

    while (decimalNumber != 0)
    {
        binaryNumber += (decimalNumber % 2) * i;
        decimalNumber /= 2;
        i *= 10;
    }
    return binaryNumber;
}

int main() {
	rol(23456);
}


