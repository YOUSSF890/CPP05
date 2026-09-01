#include "PmergeMe.hpp"



void sortVector(std::vector<int>& arr)
{
	if (arr.size() <= 1)
		return ;
	std::vector<std::pair<int, int> > pairs;
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
	for (size_t i = 0; i < pairs.size(); i++)
		winners.push_back(pairs[i].first);

	
	
	sortVector(winners);

	std::vector<std::pair<int, int> > sortPairs;
	
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
	if (sortPairs.size() >= 1)
	{
		main.push_back(sortPairs[0].second);
		main.push_back(sortPairs[0].first);
	}
	std::vector<int> range;
	for (size_t t = 1; t < sortPairs.size(); t++)
	{
		main.push_back(sortPairs[t].first);
		losers.push_back(sortPairs[t].second);
		range.push_back(main.size());
	}

	std::vector<int> other;
	for (size_t i = 0; i < losers.size(); i++)
	{
	    std::vector<int>::iterator pos =
	        lower_bound(main.begin(), main.begin() + range[other[i]], losers[other[i]]);
		for (size_t j = 0; j < other.size();j++)
		{
			if (other[j] )
		}
	    main.insert(pos, losers[i]);
	}





	std::cout << "losers = ";
	for (size_t i = 0; i < losers.size(); i++)
		std::cout  << losers[i] << " " ;
	std::cout << std::endl;

	std::cout << "main = ";
	for (size_t i = 0; i < main.size(); i++)
		std::cout  << main[i] << " " ;
	std::cout << std::endl;

	arr.swap(main); 
}