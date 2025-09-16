#include <iostream>
#include <vector>

void fill_prefix(const std::vector<int>& array, int length, std::vector<int>& prefix)
{
    prefix[0] = array[0];
    for(int i = 1; i < length; ++i)
    {
        prefix[i] = prefix[i - 1] + array[i];
    }
}

void fill_suffix(const std::vector<int>& array, int length, std::vector<int>& suffix)
{
    suffix[length - 1] = array[length - 1];
    for(int i = length - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] + array[i];
    }
}


int main()
{
    /*
     * Prefix Sum - An algorithm technique where you use the previous sum to calculate the next sum. Usually used in arrays going from left to right
     *              Tip - prefix can also by used for products and maybe for other mathmatical sums
     * Example: Image an array [1, 2, 3, 4] the prefix sum will equal [1, 3, 6, 10] because (left->right) 1 + 2 = 3 | 3 + 3 = 6 | 6 + 4 = 10
     */

    /*
     * Suffix Sum - Same as the Prefix sum except your going from right to left.
     * Tip - Suffix can also by used for products and maybe for other mathmatical sums
     * Example: Image an array [1, 2, 3, 4] the prefix sum will equal [10, 9, 7, 4] because (right->left) 4 + 3 = 7 | 7 + 2 = 9 | 9 + 1 = 10
     */

    //? Prefix Sum Example
    std::cout << "Prefix Example\n";
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    int length = v.size();
    std::vector<int> prefix_sum(length);
    fill_prefix(v, length, prefix_sum);

    for(const int& value : v)
    {
        std::cout << value << " ";
    }
    std::cout << "\n";

    std::cout << "Prefix_sum:\n";
    for(const int& p : prefix_sum)
    {
        std::cout << p << " ";
    }
    std::cout << "\n";

    //? Suffix Sum Example
    std::cout << "\nSuffix Example\n";
    std::vector<int> v2 = {1, 2, 3, 4, 5, 6, 7};
    int length2 = v.size();
    std::vector<int> suffix_sum(length);
    fill_suffix(v2, length2, suffix_sum);

    std::cout << "Original:\n";
    for(const int& value : v2)
    {
        std::cout << value << " ";
    }
    std::cout << "\n";

    std::cout << "Suffix_sum:\n";
    for(const int& p : suffix_sum)
    {
        std::cout << p << " ";
    }
    std::cout << "\n";

}
