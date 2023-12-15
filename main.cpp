#include "Mainloop.hpp"

int main(int argc, char **argv)
{

    Mainloop loop("config.json");
    loop.Start();
    return 0;
}