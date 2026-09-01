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


	std::vector<std::pair<int, int> > sortedPairs;
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


	std::vector<std::size_t> largePos(sortedPairs.size());
	for (std::size_t i = 0; i < sortedPairs.size(); ++i)
		largePos[i] = i + 1;
	
	std::vector<std::size_t> order = generateInsertionOrder(pend.size()+1); // order = 3 2 5 4

	for (std::size_t idx = 0; idx < order.size(); ++idx)
	{
		std::size_t i = order[idx] - 2;
		int val = pend[i];
		std::size_t pairIndex = i + 1;   // largePos = 1 2 3 4 , main = 2, 6, 7, 8, 9 | pend = 4 , 3 , 1 | i = 1 , val = 3 | bound = largePos[i + 1] = largePos[2] = 3
		std::size_t bound = largePos[pairIndex];

		std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.begin() + bound, val);
		std::size_t insertPos = static_cast<std::size_t>(pos - main.begin());
		
		main.insert(pos, val);

		for (std::size_t j = 0; j < largePos.size(); ++j)
			if (largePos[j] >= insertPos)
				largePos[j]++;
	}

	if (odd)
	{
		std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), last);
		main.insert(pos, last);
	}

	arr.swap(main);
}


