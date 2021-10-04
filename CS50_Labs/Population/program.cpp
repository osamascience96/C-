#include <iostream>

int main()
{
    int start_size = 0;
    int end_size = 0;

    std::cout << "Enter the Start Size: ";
    std::cin >> start_size;

    // if the input fails
    // runtime if the many inputs gone wrong
    // O(n**2) * number of inputs performed wrong
    while (std::cin.fail()) {
        system("CLS");
        // clear the input stream
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // if the input summary fails
        std::cout << "Error! Start Size must be an integer" << std::endl;
        std::cout << "Please Enter the Start Size Again: ";
        std::cin >> start_size;

        // start size must be of atlease length 9
        if (!std::cin.fail()) {
            while (start_size <= 8)
            {
                system("CLS");
                // clear the input stream
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Error! Start Size must be atleast 9 \n";
                std::cout << "Please Enter the Start Size Again: ";
                std::cin >> start_size;
            }
        }

        std::cout << "\n";
    }

    std::cout << "Enter the End Size: ";
    std::cin >> end_size;

    // if the input fails
    // runtime if the many inputs gone wrong
    // O(n**2) * number of inputs performed wrong
    while (std::cin.fail()) {
        system("CLS");
        // clear the input stream
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // if the input summary fails
        std::cout << "Error! Start Size must be an integer" << std::endl;
        std::cout << "Please Enter End Size Again: ";
        std::cin >> end_size;

        // start size must be of atlease length 9
        if (!std::cin.fail()) {
            while (end_size <= 8)
            {
                system("CLS");
                // clear the input stream
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Error! Start Size must be atleast 9 \n";
                std::cout << "Please Enter the End Size Again: ";
                std::cin >> end_size;
            }
        }

        std::cout << "\n";
    }

    // init the threshold
    int current_threshold = start_size;
    // init the years 
    int years = 0;

    // iterate until the current threshold is less than the end size of the lamas
    while (current_threshold < end_size) {
        current_threshold = current_threshold + (current_threshold / 3) - (current_threshold / 4);
        years += 1;
    }

    std::cout << "Years: " << years << std::endl;
}
