// M_PI is missing in mingw on windows but is present in gcc. This is to ensure cross platform compile

namespace MathConstants
{
    const float PI = 3.14159265358979323846;
}