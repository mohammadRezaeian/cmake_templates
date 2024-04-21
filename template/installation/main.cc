
#include <iostream>
#include "config.hh"
#include <string_view>

#ifdef enable_use_calculator_lib
#include "calculator_lib/calculator.h"
#endif

namespace details {
std::string_view GetCompileTime()
    {
        return "libraryr isn't on";
    }

}
int main()
{
    std::cout << MY_PROJECT_NAME << std::endl;
#ifdef enable_use_calculator_lib
    std::cout << core::GetCompileTime() << std::endl;
#else
    std::cout << details::GetCompileTime() << std::endl;

#endif

}
