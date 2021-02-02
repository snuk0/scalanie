#include <bits/stdc++.h>

using namespace std;

int* pom;

void scal(int t[], int lewy, int srodek, int prawy)
{
	int i, j;

	for (i = srodek + 1; i > lewy; i--)
	{
		pom[i - 1] = t[i - 1];
	}
		

	for (j = srodek; j < prawy; j++)
	{
		pom[prawy + srodek - j] = t[j + 1];
	}

	for (int k = lewy; k <= prawy; k++)
	{
		if (pom[j] < pom[i])
			t[k] = pom[j--];
		else
			t[k] = pom[i++];
	}
}

void sortowanie(int t[], int lewy, int prawy)
{
	if (prawy <= lewy) return;

	int srodek = (prawy + lewy) / 2;

	sortowanie(t, lewy, srodek);
	sortowanie(t, srodek + 1, prawy);

	scal(t, lewy, srodek, prawy);
}

int main()
{
	int* t, n;
	cin >> n;
	t = new int[n]; 
	pom = new int[n]; 

	for (int i = 0; i < n; i++)
		cin >> t[i];

	sortowanie(t, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << t[i] << " ";

	return 0;
}
