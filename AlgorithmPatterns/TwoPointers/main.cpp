#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>

// Example of converging pointers based on context
std::vector<int> twoSum_sorted(std::vector<int> nums, const int& target)
{
    int i = 0;
    int j = nums.size() - 1;
    while(i < j)
    {
        int two_sum = nums[i] + nums[j];
        if(two_sum > target) j--;
        else if(two_sum  < target) i++;
        else return {i, j};
    }
}

// Converging pointers example
bool isPalindrome(std::string word)
{
    int i = 0;
    int j = word.length() - 1;
    while(i < j)
    {
        if(word[i] != word[j]) return false;
        i++;
        j--;
    }
    return true;
}

// Trigger pointer example
int nthNode(const std::list<int>& list, int nth_distance)
{
    auto i = list.begin();
    auto j = list.begin();
    while(std::distance(i, j) < 4)
    {
        ++j;
    }
    while(j != list.end())
    {
        ++i;
        ++j;
    }
    return *(i);
}

// Fast and slow pointer example
int middleNode(const std::list<int>& list)
{
    auto slow = list.begin();
    auto fast = list.begin();
    // Since the fast pointer moves by two increments there is a chance that
    // it skips over the .end() iterator, therefore, we must check if the fast is at the end and if
    // fast.next is at the end before incrementing fast by 2.
    while(fast != list.end() && std::next(fast) != list.end())
    {
        ++slow;
        std::advance(fast, 2); // Move the fast iterator by 2
    }
    return *slow;
}


int main()
{
   /*
    * Two pointers - An algorithm where you use two distinct pointers to
    *                1. Move toward each other.
    *                2. Move away from each other.
    *                3. Move in the same direction.
    *
    *                This algorithm has different variations depending on the context of the problem.
    *                This algorithm is used to help make O(n^2) array and string traversal into O(n)
    *
    * When to use: This technique is useful on linear data structures such as arrays, strings, and linked lists.
    *              Also, useful when the problem wants a pair of values or if there is a predictable pattern while traversing
    *              the linear data structure
    */

    //? Converging pointers: This is where two pointers are opposite of each other [0] and [length - 1]
    //?                      and close in toward each other i++ and j--.


    // isPalindrome example
    std::string word = "racecar";
    std::cout << "isPalindrome(racecar): " << isPalindrome(word) << "\n";

    //? Conversing pointers based on context: This is where two pointers are opposite of each other [0] and [length - 1]
    //?                                       and close in toward each other i++ and j-- based on a scenerio which means it does not
    //?                                       converge at constant rate.
   // Two sum example
    std::vector<int> nums = {0, 1, 2, 3, 5, 7};
    int target = 5;
    std::vector<int> res = twoSum_sorted(nums, target);
    for(auto& r : res)
    {
        std::cout << r << " ";
    }
    std::cout << "\n";

    //? Trigger pointer: This is where the both pointers start at the same location but only one moves until it reaches a condition.
    //?                  Once the first pointer condition has been reached the second pointer moves

    // Nth node from the end in a linked list
    std::list<int> l = {1, 2, 5, 7, 9, 11, 12};
    std::cout << "4th node from the last element: " << nthNode(l, 4) << "\n";\


    //? Fast and Slow pointers: This is where both pointers start at the same position but the fast pointer will move twice the increment of the slow
    //?                         pointer. slow++, fast += 2.

    // Find middle node in the linked list
    std::cout << "middle node is: " << middleNode(l) << "\n";



    return 0;
}
