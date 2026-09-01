
#include "PmergeMe.hpp"

std::vector<std::size_t> PmergeMe::generateInsertionOrder(std::size_t size)
{
	std::vector<std::size_t> order;
	if (size == 0)
		return order;
	
	std::vector<std::size_t> jacob;
	jacob.push_back(1);
	jacob.push_back(3);

	while (jacob.back() < size)
	{
		std::size_t next = jacob.back() + 2 * jacob[jacob.size() - 2];
		jacob.push_back(next);
	}

	std::size_t prev = 1;
	for (std::size_t i = 1; i < jacob.size(); ++i)
	{
		std::size_t j = jacob[i];
		if (j > size)
			break;
		for (std::size_t k = j; k > prev; --k)
			order.push_back(k);
		prev = j;
	}

	for (std::size_t k = size; k > prev; --k)
		order.push_back(k);

	return order;
}


void PmergeMe::sortVector(std::vector<int>& arr) // 9 5 2 1 5
{
	if (arr.size() <= 1)
		return;
	
	std::vector<std::pair<int, int> > pairs;
	pairs.reserve(arr.size() / 2);

	bool odd = arr.size() % 2 != 0;
	int last = 0;
	if (odd) last = arr.back();

	for (std::size_t i = 0; i + 1 < arr.size(); i += 2)
	{
		if (arr[i] > arr[i+1])
			pairs.push_back(std::make_pair(arr[i], arr[i+1]));
		else
			pairs.push_back(std::make_pair(arr[i+1], arr[i]));
	}

	std::vector<int> maxElems;
	maxElems.reserve(pairs.size());
	for (std::size_t i = 0; i < pairs.size(); ++i)
		maxElems.push_back(pairs[i].first);
	
	sortVector(maxElems);


	std::vector<std::pair<int, int> > sortedPairs;   //max elemnts 
	sortedPairs.reserve(pairs.size());

	std::vector<bool> used(pairs.size(), false);

	for (std::size_t i = 0; i < maxElems.size(); ++i)
	{
		for (std::size_t j = 0; j < pairs.size(); ++j)
		{
			if (!used[j] && pairs[j].first == maxElems[i])
			{
				sortedPairs.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}

	std::vector<int> main;
	main.reserve(arr.size());

	if (!sortedPairs.empty())
	{
		main.push_back(sortedPairs[0].second);
		main.push_back(sortedPairs[0].first);
	}

	std::vector<int> pend;
	pend.reserve(sortedPairs.size() - 1);

	for (std::size_t i = 1; i < sortedPairs.size(); ++i)
	{
		main.push_back(sortedPairs[i].first);
		pend.push_back(sortedPairs[i].second);
	}

}