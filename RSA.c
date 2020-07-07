#include <stdio.h>	
#include <string.h>

/***********

********/
int Get_Modul_of_Power(int base, int power, int modul)
{
	int tem = 1;
	
	for (int i = 0; i < power; i++)
	{
		tem = tem * base;
		tem = tem % modul;
	}
	
	return tem;
}

/***********

********/

int mgcd(int a,int b)
{
    int t;
    if(a < b)
    {
        t=a;a=b;b=t;
    }
    while(a%b)
    {
        t=b;
        b=a%b;
        a=t;
    }

    return b;
}

/*******

*/
int code_one_symbol(int plaintext, int E, int N)
{
	int j = Get_Modul_of_Power(plaintext, E, N);
	printf("%d\n", j);

	return j;	
}

char decode_one_symbol(int cipher, int D, int N)
{
	char j = (char)(Get_Modul_of_Power(cipher, D, N));
	printf("%c\n", j);
	
	return j;
}

int code_symbols(char *plaintexthead, int length, int *cipherhead, int E, int N)
{
	for (int i = 0; i < length; i++)
	{
		*cipherhead = code_one_symbol(*plaintexthead,E,N);
		cipherhead += 1;
		plaintexthead += 1;
	}

	return length;
}

int decode_symbols(int *cipherhead, int length, char *plaintexthead, int D, int N)
{
	for (int i = 0; i < length; i++)
	{
		*plaintexthead = decode_one_symbol(*cipherhead,D,N);
		plaintexthead += 1;
		cipherhead += 1;
	}

	return length;
}

int main()
{
	//int E = 13;
	//int D = 937;
	//int N = 2537;
	int E= 4913;
	int D= 977;
	int N= 9797;
	char *hello = "hello world!";
	int cc[100];
	char plain[100];

	int j = code_symbols(hello, strlen(hello), cc, E,N);
	int i = decode_symbols(cc, j, plain, D, N);
	plain[i] = '\0';
	
	printf("%s\n", plain);
	printf("E,D,N=(%ld,%ld,%ld)\n", E,D,N);
	
	return 0;
}
