//ForwardIterator
template <typename Iterator1, typename Iterator2>
auto merge(Iterator1 first1, Iterator1 last1, Iterator1 first2, Iterator1 last2, Iterator2 output)->Iterator2
{
	while (true)
	{
		if (first1 == last1)
		{
			while (first2 != last2)
			{
				*output = *first2;
				++output; ++first2;
			}

			return output;
		}
		if (first2 == last2)
		{
			while (first1 != last1)
			{
				*output = *first1;
				++output; ++first1;
			}

			return output;
		}

		*output++ = (*first2 < *first1) ? *first2++ : *first1++;
	}

	return output;
}

int main()
{
	int arr1[] = { -123, -42, 0, 212, 415, 742, 853, 864, 1013, 1700 };
	int arr2[] = {-12, -2, -1, 0, 153, 215, 298};
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	int arr3[sizeof(arr1) / sizeof(arr1[0]) + sizeof(arr2)/sizeof(arr2[0])];

	auto merged = merge(arr1, arr1 + size1, arr2, arr2 + size2, arr3);

	return 0;
}