#include "PmergeMe.hpp"

void Jacobsthal_numbers(std::vector<int> &jacb,size_t size)
{
	jacb.push_back(0);
	jacb.push_back(1);
	size_t J;
	while (1)
	{
		J = jacb[jacb.size()-1] + 2 * jacb[jacb.size()-2];
		if (J < size)
			jacb.push_back(J);
		else
		{
			jacb.push_back(size);
			break;
		}
	}
}


void sortVector(std::vector<int>& arr)
{
	if (arr.size() <= 1)
		return ;
	bool oddNumber = false; 
	int oddNbr; 
	if (arr.size() % 2 == 1)
	{
		oddNumber = true;
		oddNbr = arr[arr.size()-1];
	}
	
	std::vector<std::pair<int, int> > pairs;
	pairs.reserve(arr.size() / 2);
	size_t i = 0;
	while(i + 1 < arr.size())
	{
		if (arr[i] > arr[i+1])
			pairs.push_back(std::make_pair(arr[i],arr[i+1]));
		else
			pairs.push_back(std::make_pair(arr[i+1],arr[i]));
		i += 2;
	}

	std::vector<int> winners;
	winners.reserve(pairs.size());
	for (size_t i = 0; i < pairs.size(); i++)
		winners.push_back(pairs[i].first);
	
	sortVector(winners);

	std::vector<std::pair<int, int> > sortPairs;
	sortPairs.reserve(pairs.size());
	
	for (size_t i = 0; i < winners.size();i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == winners[i])
			{
				sortPairs.push_back(pairs[j]);
				break ;
			}
		}
	}
	std::vector<int> main;
	main.reserve(arr.size());
	std::vector<int> losers;
	losers.reserve(arr.size()/2);

	if (sortPairs.size() >= 1)
	{
		main.push_back(sortPairs[0].second);
		main.push_back(sortPairs[0].first);
	}
	std::vector<int> range;
	range.reserve(arr.size()/2);
	for (size_t t = 1; t < sortPairs.size(); t++)
	{
		main.push_back(sortPairs[t].first);
		losers.push_back(sortPairs[t].second);
		range.push_back(main.size());
	}

	std::vector<int> other;
	range.reserve(losers.size());
	Jacobsthal_numbers(other,losers.size() + 1);

	for (size_t i = 3; i < other.size(); i++)
	{
		for (int j = other[i]; j > other[i-1]; j--)
		{
			std::vector<int>::iterator pos =
				lower_bound(main.begin(), main.begin() + range[j-2], losers[j-2]);

			main.insert(pos, losers[j-2]);
			for (size_t n = j-2; n < range.size(); n++)
				range[n]++;
		}
	}

	if(oddNumber)
	{
		std::vector<int>::iterator pos = lower_bound(main.begin(), main.end(), oddNbr);
		main.insert(pos, oddNbr);
	}

	arr.swap(main); 
}

void sortDeque(std::deque<int>& arr)
{
	if (arr.size() <= 1)
		return ;
	bool oddNumber = false; 
	int oddNbr; 
	if (arr.size() % 2 == 1)
	{
		oddNumber = true;
		oddNbr = arr[arr.size()-1];
	}
	
	std::deque<std::pair<int, int> > pairs;
	size_t i = 0;
	while(i + 1 < arr.size())
	{
		if (arr[i] > arr[i+1])
			pairs.push_back(std::make_pair(arr[i],arr[i+1]));
		else
			pairs.push_back(std::make_pair(arr[i+1],arr[i]));
		i += 2;
	}

	std::deque<int> winners;
	for (size_t i = 0; i < pairs.size(); i++)
		winners.push_back(pairs[i].first);
	
	sortDeque(winners);

	std::deque<std::pair<int, int> > sortPairs;
	
	for (size_t i = 0; i < winners.size();i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == winners[i])
			{
				sortPairs.push_back(pairs[j]);
				break ;
			}
		}
	}
	std::deque<int> main;
	std::deque<int> losers;
	if (sortPairs.size() >= 1)
	{
		main.push_back(sortPairs[0].second);
		main.push_back(sortPairs[0].first);
	}
	std::deque<int> range;
	for (size_t t = 1; t < sortPairs.size(); t++)
	{
		main.push_back(sortPairs[t].first);
		losers.push_back(sortPairs[t].second);
		range.push_back(main.size());
	}

	std::vector<int> other;
	Jacobsthal_numbers(other,losers.size()+1);

	for (size_t i = 3; i < other.size(); i++)
	{
		for (int j = other[i]; j > other[i-1]; j--)
		{
			std::deque<int>::iterator pos =
				lower_bound(main.begin(), main.begin() + range[j-2], losers[j-2]);
			main.insert(pos, losers[j-2]);
			for (size_t n = j-2; n < range.size(); n++)
				range[n]++;
		}
	}
	if(oddNumber)
	{
		std::deque<int>::iterator pos = lower_bound(main.begin(), main.end(), oddNbr);
		main.insert(pos, oddNbr);
	}

	arr.swap(main); 
}