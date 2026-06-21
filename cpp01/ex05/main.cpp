#include "harl.hpp"

int main()
{
    Harl harl;

    harl.complain("DEBUG");
    harl.complain("WARNING");
    harl.complain("ERROR");
    harl.complain("INVALID_LEVEL"); // 変な文字列のテスト
    return (0);
}
