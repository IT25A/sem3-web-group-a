#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <string>
#include <filesystem>
#include <iostream>

int main()
{
    std::filesystem::path p{"."};
    std::cout << p.string() << '\n';
}