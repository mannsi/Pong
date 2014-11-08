// M_PI is missing in mingw on windows but is present in gcc. This is to ensure cross platform compile

namespace MathConstants
{
    #ifndef M_PI
    #define M_PI 3.14159265358979323846
    #endif
}