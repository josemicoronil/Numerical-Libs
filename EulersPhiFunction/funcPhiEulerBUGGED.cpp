//	Rodríguez Marchena, José Miguel
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
void eratosthenesSieve(const unsigned& n, std::vector<unsigned>& sieve);
void getPrimeDividers(const unsigned& n, std::vector<unsigned>& primeDiv);
unsigned phi(const unsigned& n, std::vector<unsigned>& primeDiv);

const unsigned MAX = -2;
// ------------------------------------------------------------------------

int main()
{
	unsigned n = 0;
	std::vector<unsigned> primes;
	cout << " - Insert a number between 1 and " << MAX
		<< ":\n >";
	cin >> n;
	
	if (n > MAX)
	{
		cerr << "\n - The number inserted is too big -\n";
		exit(1);
	}

	cout << "\n - Phi of " << n << ": ";
	cout << phi(n, primes) << endl;
	cout << "\n - Prime dividers:\n";

	for (unsigned i = 0; i < primes.size(); ++i)
	{
		cout << endl << primes[i];
	}

	cout << endl;

	return 0;
}

// ------------------------------------------------------------------------

void eratosthenesSieve(const unsigned& n, std::vector<unsigned>& sieve)
{
	std::vector<bool> boolVec;

	//	From 0 to n add all values to 'true' in
	//	a bool vector representing the sieve:

	for (unsigned i = 0; i < n; ++i)
	{
		boolVec.push_back(true);
	}

	cout << "\nEratosthenesSieve: Bool vector made.\n";

	//	Set '0' and '1' to NOT prime:
	boolVec[1] = boolVec[0] = false; 

	//	THREADABLE
	//	Fill with 'false' all not-prime values:
	for (unsigned i=0; i < sqrt(n); ++i)
	{
		if (boolVec[i])
		{
			for (unsigned j= (i*i); j < sqrt(n); j+=i)
			{
				boolVec[j] = false;
			}

			//	Fill a unsigned vector with primes values
			//	from the bool vector:
			sieve.push_back(i);
		}
	}

	cout << "\nEratosthenesSieve: Bool vector filled.\n";

	//cout << "\nEratosthenesSieve: Unsigned vector filled.\n";
}

void getPrimeDividers(const unsigned& n, std::vector<unsigned>& primeDiv)
{
	//	Make a vector and fill with the sieve:
	std::vector<unsigned> sieve;
	eratosthenesSieve(n, sieve);

	cout << "\ngetPrimeDividers: Getting dividers.\n";

	//	Check if some prime number is a divider of 'n':
	for (unsigned i = 0; i < sieve.size(); ++i)
	{
		if ( !(n%sieve[i]) )
		{
			primeDiv.push_back(sieve[i]);
		}
	}
}

unsigned phi(const unsigned& n, std::vector<unsigned>& primeDiv)
{
	unsigned output = n;
	getPrimeDividers(n, primeDiv);
	if (n <= 0)
	{
		return 0;
	}
	else if ( (n == 1) || (n == 2) )
	{
		return 1;
	}

	if (primeDiv.size() > 0)
	{
		for (unsigned i = 0; i < primeDiv.size(); ++i)
		{
			output = (output / primeDiv[i]);
			output = (output * (primeDiv[i] - 1));
		}
	}
	else
	{
		output--;
	}

	return output;
}
