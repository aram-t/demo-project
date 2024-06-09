#include "nearest-greater-number-array.h"


std::vector<int> get_nearest_greater_values(const std::vector<int> & numbers)
{
	std::vector<int> result(numbers.size(), 0);
	std::vector<int> filo;
	filo.reserve(numbers.size());
	for (int i = 0; i < numbers.size(); ++i)
	{
		while (!filo.empty())
		{
			int j = filo.back();
			bool greater_number_found = (numbers[j] < numbers[i]);
			if (!greater_number_found)
			{
				break;
			}
			filo.pop_back();
			result[j] = i - j;
		}
		filo.push_back(i);
	}
	return result;
}
