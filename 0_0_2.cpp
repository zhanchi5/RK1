#include <iostream>
#include <utility>


//BidirectionalIterator
template <typename Iterator, typename T>
auto find_two_elements_with_sum(Iterator first, Iterator last, T c)->std::pair<bool, std::pair<Iterator, Iterator>>
    {
        std::pair<bool, std::pair<Iterator, Iterator>> result;

        auto end = last - 1;

        while (*first < *end)
        {
            T sum = *first + *end;
            if (sum == c)
            {
                result.first = true;
                result.second.first = first;
                result.second.second = end;

                return result;
            }
            else
            {
                if (sum < c) first++;
                else end--;
            }
        }

        return result;
    }
int main(){
        int arr[] = { -3, 0, 2, 5, 7, 8, 8, 13, 17,44,57 };

        auto result = find_two_elements_with_sum(arr, arr + sizeof(arr)/sizeof(arr[0]), 11);

        return 0;
    }