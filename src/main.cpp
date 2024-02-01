#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

long long to_num(std::string numStr, std::size_t fromNS)
{
    long long ret = 0;
    int i = 0;
    for(auto it = numStr.crbegin(); it != numStr.crend(); ++it, ++i)
    {
        char sym = std::tolower(*it);
        int val = 0;
        if (sym >= 'a' && sym <= 'z')
            val = sym - 'a' + 10;
        else
            val = sym - '0';

        ret += val * std::pow(fromNS, i);
    }
    return ret;
}

constexpr auto to_char(int digit)
{
    char ret = '0';
    if (digit > 9)
        ret = digit - 10 + 'A';
    else
        ret = '0' + digit;

    return ret;
}

auto to_num_system(std::string numStr, std::size_t fromNS, std::size_t toNS)
{
    long long num = to_num(numStr, fromNS);

    if (toNS == 10)
    {
        return std::to_string(num);
    }

    std::string ans{};
    while(num > 0)
    {
        int digit = num % toNS;
        ans.push_back(to_char(digit));
        num /= toNS;
    }
    std::ranges::reverse(ans);

    return ans;
}

int main(int argc, char** argv)
{
    std::size_t from = 10;
    std::size_t to = 10;
    long long num = 0;
    std::string input{};

    while(true)
    {
        std::cout << "> ";
        std::cin >> input;
        if (input == "exit")
            break;

        std::cout << "from: ";
        std::cin >> from;

        std::cout << "to: ";
        std::cin >> to;
        
        std::cout << to_num_system(input, from, to) << "\n";
    }

    return 0;
}
