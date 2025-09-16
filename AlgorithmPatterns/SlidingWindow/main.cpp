#include <iostream>
#include <vector>

// first way solution | Brute Force
// Time Complexity: O(n^2)
// Space Complexity: O(1)
int most_expensive_books_BF(const std::vector<int>& prices, const int& k)
{
    if(prices.size() < k) return 0; // Check if k is valid

    int max_total{};
    // Loop through the array until you reach the first index that
    // has the last 5 books including that index
    for(int i = 0; i < prices.size() - k + 1; i++) // O(n - k + 1)
    {
        int total{};
        // For each index of i calculate the total price from i up to 5 five books including i
        for(int j = i; j < i + k; j++) // O(k)
        {
            total += prices[j];
        }
        if(total > max_total) max_total = total; // Check if the current set is greater than the max_total
    }
    return max_total;

    // Time Complexity: O(n - k + 1)k = O(nk - k^2 + k) = O(nk) = O(n) since k = constant
    // Space Complexity: O(1)
}

// Second Solution | Sliding Window Technique
// Time Complexity:
// Space Complexity:
int most_expensive_books_SW(const std::vector<int>& prices, const int& k)
{
    if(prices.size() < k) return 0; // Check if k is valid

    int max_total{};
    int total{};
    // Loop through the first k prices and save that as the total price
    for(int i = 0; i < k; i++) // O(k)
    {
        total += prices[i];
    }

    max_total = total;
    // Loop through each price up to the first index of the last set.
    // loop until i reaches the index where the first price is located of the last five prices
    for(int i = 0; i < prices.size() - k; i++) // O(n - k)
    {
        total -= prices[i]; // subtract the price of the i
        total += prices[i + k]; // add the price of the next price
        if(total > max_total) max_total = total; // update total price if larger
    }
    return max_total;

    // Time Complexity: O(k + n - k) = O(n)
    // Space Complexity: O(1)
}




int main()
{
    // Sliding Window - A sliding window technique is a problem-solving technique that works by maintaining a window, a
    //                  continuous part of the data that respects the constraints. Then we keep moving that window by extending
    //                  it and shrinking it while respecting constraints until we finish whole input.

    // Most expensive books Ex - Lets say that you get a list of books, and you have to find a set of k books next to each other
    //                            that will give you the largest total sum of the books.
    // Example: Lets say you get 12, 9, 23, 17, 25, 19, 4, 8, 21, 34 prices of books next to each-other and k = 5
    //          Here we can see that there is 6 sets of five books
    //          Set 1: 12, 9, 23, 17, 25 - total = 86
    //          Set 2: 9, 23, 17, 25, 19 - total = 93 - most expensive set of five books
    //          Set 3: 23, 17, 25, 19, 4 - total = 88
    //          Set 4: 17, 25, 19, 4, 8 - total = 73
    //          Set 5: 25, 19, 4, 8, 21 - total = 77
    //          Set 6: 19, 4, 8, 21, 34 - total = 86

    // There are two ways of solving this problem.
    // 1. For each five book prices in a set we count the total cost of the five books each time.
    //    This will look like this:
    //    1. 12 + 9 + 23 + 17 + 25 = 86
    //    2. 9 + 23 + 17 + 25 + 19 = 93
    //    3.... it keeps going

    // 2. There is a second way of solving this that is faster. If you look at the five books in a set
    //    above in the problem description, you can see that at each next set the first price is removed and the next book price
    //    is added at the end.
    //    Example: Notice how the 12 is removed and 19 is added at the next on set 2.
    //    Set 1: 12, 9, 23, 17, 25 - total = 86
    //    Set 2: 9, 23, 17, 25, 19 - total = 93 - most expensive set of five books

    // With this logic we can just subtract the cost of the first book from the total and add the cost of the next book in line
    // Example:
    //    Set 1: 12, 9, 23, 17, 25 - total = 86
    //    Set 2: 86 - 12 + 19 = 93 |  Set 2: 9, 23, 17, 25, 19 - total = 93


    std::vector<int> book_prices = {12, 9, 23, 17, 25, 19, 4, 8, 21, 34, 26, 17, 19, 14, 27, 22, 15, 7, 2, 14, 5, 18, 24};
    int k = 5;
    int largest_value_BF = most_expensive_books_BF(book_prices, k);
    int largest_value_SW = most_expensive_books_SW(book_prices, k);
    std::cout << "largest_value_BF: " << largest_value_BF << "\n";
    std::cout << "largest_value_SW: " << largest_value_SW << "\n";

    return 0;
}
