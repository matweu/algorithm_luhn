#include <iostream>
#include <string>
#include <stdio.h>
#include <execution>

//algorithm LUNA
bool isNumberString(std::string& number_card)
{
    int size_number_card = number_card.size();
    for (int i = 0; i < size_number_card; ++i)
    {
        if (number_card[i] <'0' || number_card[i] > '9')
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    while (true)
    {
        try {
            std::string number_card;
            if (argc > 1) {
                number_card = argv[1];
            }
            else {
                std::cout << "Please enter the number to check the LUNA algorithm:";
                std::cin >> number_card;
            }

            if (!isNumberString(number_card))
            {
                std::cout << "!Warning, you made a mistake when entering!" << std::endl;
                continue;
            }
            int evenSum = 0;
            int size_number_card = number_card.size();
            for (int i = 0; i < size_number_card; i = i + 2)
            {
                int temp = (number_card[i] - '0') * 2;
                if (temp > 9) {
                    temp = (temp / 10) + (temp % 10);
                }
                evenSum += temp;
            }

            for (int i = 1; i < size_number_card; i = i + 2)
            {
                evenSum += (number_card[i] - '0');

            }
            std::cout << (evenSum % 10 == 0 ? "Number is Valid" : "Invalid!") << std::endl;
            if (argc > 1) {
                break;
            }
            number_card = "";
        }
        catch (std::exception& ex)
        {
            std::cout << "An error has occurred, restart the application." << std::endl;
        }
    }
    return 0;
}