#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void eratosthenesSieve(const unsigned& n, std::vector<unsigned>& v)
{
	std::vector<bool> boolVec;
	
	// From 2 to n add all values to 'true'.
	
	for (unsigned i = 0; i < n; ++i)
	{
		boolVec.push_back(true);
	}

	cout << "\nEratosthenesSieve: Bool vector filled.\n";

	boolVec[1] = boolVec[0] = false; 

	for (unsigned i=0; i < sqrt(n); ++i)
	{
		if (boolVec[i])
		{
			for (unsigned j= (i*i); j < boolVec.size(); j+=i)
			{
				boolVec[j] = false;
			}
		}
	}

	for (unsigned i=0; i < boolVec.size(); ++i)
	{
		if (boolVec[i])
		{
			v.push_back(i);
		}
	}

	cout << "\nEratosthenesSieve: Unsigned vector filled.\n";
}
