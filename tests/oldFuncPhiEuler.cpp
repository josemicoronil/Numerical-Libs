#include <cstdlib>
#include <iostream>
#include <vector>


using namespace std;

template <typename T>
bool isprimefromvec(const T& n, const std::vector<T>& v)
{
	for (unsigned i=0; i < v.size(); ++i)
	{
		// cout << "\n v[" << i << "]: " << v[i];
		if ( ((n % v[i]) == 0) && (v[i] != n) )
		{
			return false;
		}
	}

	return true;
}

template <typename T>
bool isprime(const T& n)
{
	for (T i = 2; i < n; ++i)
	{
		if ((n%i) == 0) return false;
	}

	return true;
}

template<typename T>
bool notContain(const T& n, const std::vector<T>& v)
{
	for (unsigned i = 0; i < v.size(); ++i)
	{
		if (n == v[i])
		{
			return false;
		}
	}

	return true;
}

template <typename T>
void getPrimeDividers(const T& n, std::vector<T>& v)
{
	T temp = n;
	bool foundAll = false;
	while( !foundAll )
	{
		for (T i = 2; i <= temp; ++i)
		{	
			//cout << "\n i: " << i;

			if (i == n)
			{
				foundAll = true;
				break;
			}

			if (temp%i == 0)
			{
				if (isprime<T>(i))
				{
					if (notContain(i, v))
					{
						v.push_back(i);
						cout << "\n - Unique prime divider: " << i;
					}
					
				}
				else
				{
					getPrimeDividers<T>(i, v);
				}

				temp = temp/i;
				break;
			}
		}

		if (temp == 1)
		{
			foundAll = true;
		}	
	}
}

template<typename T>
void primeList(const T& n)
{
	std::vector<T> v;

	for (T i=2; i < n; ++i)
	{
		if ( isprimefromvec(n, v) && isprime<T>(i))
		{
			v.push_back(i);
			cout << endl << i;
		}
	}
}

template <typename T>
T phi(const T& n)
{
	T output = n;
	if (n <= 0)
	{
		std::exit(1);
	}
	else if ( (n == 1) || (n == 2) )
	{
		return 1;
	}

	if (isprime<T>(n))
	{
		return (n - 1);
	}

	std::vector<T> vecPrime;
	getPrimeDividers(n, vecPrime);

	if (vecPrime.size() > 0)
	{
		for (unsigned i = 0; i < vecPrime.size(); ++i)
		{
			output = (output / vecPrime[i]);
			output = (output * (vecPrime[i] - 1));
		}
	}
	else
	{
		output--;
	}

	return output;
}

int main(int argc, char const *argv[])
{
	//cout << "\nPhi de 3301: "	<< phi<unsigned>(3301) << endl;
	//cout << "\nPhi de 6: "		<< phi<unsigned>(6) << endl;
	//cout << "\nPhi de 45: "		<< phi<unsigned>(45) << endl;
	//cout << "\nPhi de 82: "		<< phi<unsigned>(82) << endl;
	//cout << "\nPhi de 31: "		<< phi<unsigned>(31) << endl;
	//cout << "\nPhi de 24: "		<< phi<unsigned>(24) << endl;
	/*
	cout << "\nPhi de 92376459724242: "
		 << phi<unsigned long long>(92376459724242)
		 << endl;
	*/

	return 0;
}
