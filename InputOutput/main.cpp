#include <iostream> // Basic command I/O - std::cout, std::cin, std::cerr, std::clog
#include <fstream> // includes both file input and output streams
#include <filesystem> // Manages files within the device (File System Library)
#include <string> // string handling | Used for getLine() function
#include <vector>


void console_IO()
{
    int x;
    std::cout << "Enter a number: ";
    std::cin >> x;
    std::cout << "You entered: " << x << "\n";
}

void file_IO_basic(const std::string& file)
{
    // Ofstream = Opening/Creating a file to input data into it.
    try
    {
        // ofstream creates the new file in the compiled directory. To change directories you can use the filesystem
        // library or add an absolute path or add a relative path from the current directory.
        std::ofstream outfile(file); // creates or opens file ()
        if (!outfile) throw std::runtime_error("Could not open file");
        outfile << "Testing, file inputs";
        outfile.close(); // always close files when done.
    }
    // This is main exception handler for file I/O
    catch (const std::runtime_error& e)
    {
        std::cout << "Runtime Error: " << e.what() << "\n";
    }

    // Istream = Opening/Reading a file to read data from it
    try
    {
        std::ifstream infile(file);
        if (!infile) throw std::runtime_error("Error opening file");

        std::string line;
        while (getline(infile, line)) // Read line by line
        {
            std::cout << line << "\n";
        }

        infile.close();
    }
    catch (const std::runtime_error& e)
    {
        std::cout << "Error: " << e.what() << "\n";
    }
}

void file_IO_intermediate(const std::string& file)
{
    // Writing More Complex data
    // Name, age\n
    // Name, age
    std::vector<std::pair<std::string, int>> data;
    data.push_back({"John", 21});
    data.push_back({"Bob", 42});
    try
    {
        // Create new file
        std::ofstream outfile(file);
        if (!outfile) throw std::runtime_error("Error opening outfile");

        // Write each data into file with a delimiter
        for (std::pair<std::string, int> item : data)
        {
            outfile << item.first << ", " << item.second << "\n";
        }
        outfile.close();
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what() << "\n";
    }

    // Read file
    data.clear();
    try
    {
        // Open file
        std::ifstream infile(file);
        if (!infile) throw std::runtime_error("Error opening infile");

        // Read each line in file
        std::string line{};
        while (std::getline(infile, line))
        {
            // Save each string line into a string stream
            std::stringstream ss(line);

            // temp variables
            std::string name, age_token;
            int age;

            // Read each token from stringstream seperated by , delimiter, parse to correct datatype,
            // and store in temp variables
            std::getline(ss, name, ',');
            std::getline(ss, age_token, ',');
            age = std::stoi(age_token);

            // store data into list
            data.push_back({name, age});
        }

        // Loop through list and print each data
        for (auto [data_name, data_age] : data)
        {
            std::cout << data_name << ", " << data_age << "\n";
        }
    }
    catch (const std::runtime_error& e)
    {
        std::cout << "Error: " << e.what() << "\n";
    }
}

int main()
{
    // Basic console I/O
    console_IO();

    // Basic File I/O
    file_IO_basic("data.txt");

    // Intermediate File I/O (Parsing and delimiter)
    file_IO_intermediate("database.txt");

    // Hard File I/O (Directory Traversing)
    try
    {
        std::ofstream outfile("text.txt");
        if (!outfile) throw std::runtime_error("Error opening outfile");
        outfile << "Bobby ," << 16 << "\n";
        outfile << "Joe ," << 25 << "\n";
        outfile.close();

    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what() << "\n";
    }

    try
    {
        std::ifstream infile("text.txt");
        if (!infile) throw std::runtime_error("Error opening infile");
        std::string line;
        while (std::getline(infile, line))
        {
            std::stringstream ss(line);

            std::string name;
            std::string age_token;
            int age;

            std::getline(ss, name, ',');
            std::getline(ss, age_token);
            age = std::stoi(age_token);

            std::cout << "name: " << name << ", " << "age: " << age << "\n";
        }
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what() << "\n";
    }


    return 0;
}