#include "calculator_lib/calculator.h"

std::string_view core::GetCompileTime()
{
    return __TIME__;
}