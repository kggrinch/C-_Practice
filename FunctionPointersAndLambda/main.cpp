#include <iostream>
#include <vector>
#include <functional>

/**
 * ----------------------------------------------------------------------------------------------------------------------------
 * Function Pointer Functions
 * ----------------------------------------------------------------------------------------------------------------------------
 */
void HelloWorld()
{
    std::cout << "Hello World!" << "\n";
}

int sum(const int& a, const int& b)
{
    return a + b;
}

void PrintValue(const int& value)
{
    std::cout <<"Value: " << value << "\n";
}

// Function that uses a function pointer
// This function iterates through the vector calling a function pointer to
// print the value at each iteration.
void forEach(const std::vector<int>& values, void(*print_value)(const int&))
{
    for(int value : values)
    {
        print_value(value);
    }
}



/**
 * ----------------------------------------------------------------------------------------------------------------------------
 * Lambda Functinos
 * ----------------------------------------------------------------------------------------------------------------------------
 */

// Function that uses a function pointer
// This function iterates through the vector calling a function pointer to
// print the value at each iteration.
void forEach2(const std::vector<int>& values, void(*print_value)(const int&))
{
    for(int value : values)
    {
        print_value(value);
    }
}




int main()
{
    /**
     * ----------------------------------------------------------------------------------------------------------------------------
     * Function Pointers
     * ----------------------------------------------------------------------------------------------------------------------------
     */

    // Function Pointers: A way to assign functions to variables. It works by saving the address of a function into a variable
    //                    which then the variable can be passed as arguments into other functions and classes, stored in data structures, and
    //                    used dynamically at run time which means it is activated when the program is currently running.

    // Polymorphism: Using a function pointer different implementations can be created based on the function pointer requirements

    // Regular function with a function call
    HelloWorld(); // calls HelloWorld function

    // Function pointer.
    // Same function pointer but the real way to create it
    // This shows the actual type pointer instead of using the auto keyword
    // Can be made like this

    //[ReturnType][*VariableName](parameters) = [Function it pointer to]
    void(*function)() = HelloWorld;

    // Short cut implementation method
    // [dataType auto] [VariableName]
    auto function2 = HelloWorld; // This is the most up-to-date way of assigning function pointers. It is simplified.
    function();
    function2();

    // Another shortcut
    // Using typedef
    typedef void(*function3)(); // Creates a type for a function variable
    function3 funct3 = HelloWorld;
    funct3();

    // Using function pointer with parameters
    int(*sum_function)(const int&, const int&) = sum;
    std::cout << sum_function(1, 2) << "\n";

    // Using and passing function pointers in functions
    std::vector<int> values = {1, 2, 3, 4, 5, 6, 7};
    forEach(values, PrintValue);


    /**
    * ----------------------------------------------------------------------------------------------------------------------------
    * Lambda
    * ----------------------------------------------------------------------------------------------------------------------------
    */

    // Lambda: A anonymous function which means that the function is never "declared" instead it is defined and used somewhere in the code.
    //         It is a small, inline function that doesn't require a formal name. They are similar to function pointers except that the implementation
    //         is created inplace and after a call it deallocates the lambda. They are usually used when you need a short function for a single
    //         task without defining a full function.
    //         1. If you want to store the lambda into a variable you need to define the type to store the lambda
    //            Need to include functional (or can use auto)
    //

    // Lambda Syntax
    // 1. [capture] = What is the scope variable you want to bring into this lambda
    // 2. (parameters) = What parameters are required for this function
    // 3. -> return_type = return type. If no return type then no need for -> return_type
    // 4. {function_body} = implementation of the function
    // [capture](parameters) -> return_type {function_body}

    // Functional return type syntax
    // std::function<ReturnType(Parameters)> function_name;


    // Example lambda to print helloWorld while storing the lambda in a function variable
    std::function<void()> printHello = []() -> void
    {
        std::cout << "Hello World!\n";
    };
    printHello(); // calling the lambda

    // Same example but using auto keyword
    auto printHello2 = []() -> void
    {
        std::cout << "Hello World!\n";
    };
    printHello2(); // calling the lambda

    // Example of directly calling the lambda while returning a string
    std::cout << [](std::string passedString) -> std::string {return passedString;}("Hello World!\n") << "\n";

    // Example of passing creating lambda in a parameter
    std::vector<int> my_values = {1, 2, 3, 4, 5, 6};
    forEach2(my_values, [](const int& value) {std::cout << "Value: " << value << "\n";});


    // Add operation with parameters and passing in a function pointer to print all vector values
    // This uses the [capture] syntax to pass in the vector and two function pointers.
    // 1. one function pointer to iterate through the vector
    // 2. one function pointer to print the values in the vector
    // It also uses the (parameter) function to sum the two values given in the parameter and returns the sum via an int
    std::cout << "\n";
    void(*for_each_function_pointer)(const std::vector<int>&, void(*print_value)(const int&)) = forEach2; // Function pointer to forEach2
    void(*print_value)(const int&) = PrintValue;
    std::function<int(int a, int b)> sum2 = [&my_values, for_each_function_pointer, print_value](int a, int b) -> int
    {
        for_each_function_pointer(my_values, print_value); // This calls a function pointer to print all value in the vector
        return a + b; // this returns the sum of a and b
    };

    std::cout << sum2(1, 2) << "\n";


    // Recursive lambda
    // To use recursion in a lambda anonymous function you must pass the function by reference into the parameter.
    // This is used to be able to access the function inside its own function
    // This example shows how every function call is taken by reference
    auto factorial = [&](int n, auto& factorial) -> int
    {
        if(n <= 0) return 1;
        return n * factorial(n - 1, factorial);
    };
    std::cout << "factorial of 3: " << factorial(3, factorial) << "\n";

    return 0;
}
