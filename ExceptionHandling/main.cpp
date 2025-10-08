#include <iostream>
#include <exception> // This is the general exception header which will catch most exceptions
#include <stdexcept> // This is a specific exception header if you want to handle specific exceptions.

// Example of a simple try-catch block with a std::runtime_error
void simple_try_catch()
{
    try
    {
        throw std::runtime_error("Mockup error");
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << "\n";
    }
}

// Handle multiple types of exceptions
// Useful when there can be potential for different types of exceptions occurring, and you want to have
// specific handlers for each exception. The general std::exception handler should come last to handle
// any unknown exceptions
void multiple_catch_blocks(const int& x)
{
    try
    {
        if (x < 0) throw std::invalid_argument("Negative number not allowed");
        throw std::runtime_error("Runtime error");
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Invalid argument: " << e.what() << "\n";
    }
    catch (const std::runtime_error& e)
    {
        std::cout << "Runtime error: " << e.what() << "\n";
    }
    catch (...) // ... syntax catches any exceptions not already handled.
    {
        std::cout << "Caught unknown exception: " << "\n";
    }
}

// Rethrowing an exception to a higher catch-block.
// Sometimes you can detect an error but not handle it - instead just log it
// or add context, then let higher-level functions handle it.
// Common in layered systems where the lower level catches the error sends it to the
// higher code and the higher code decides what to do.
void exception_rethrow()
{
    try
    {
        try
        {
            throw std::runtime_error("Runtime Error");
        }
        catch (const std::runtime_error e)
        {
            std::cout << "Caught inside: " << e.what() << "\n";
            throw; // rethrow the same exception
        }
    }
    catch (const std::runtime_error e)
    {
        std::cout << "Caught outside: " << e.what() << "\n";
    }
}


int main()
{
    // Example of a try-catch block with a std::runtime_error
    simple_try_catch();

    // Multiple Catch Blocks
    multiple_catch_blocks(-2);

    // Rethrowing Exceptions
    exception_rethrow();

    return 0;
}