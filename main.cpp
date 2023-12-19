#include "Mainloop.hpp"

int main(int argc, char **argv)
{

    Mainloop loop("/usr/local/memes-bot/config.json");
    loop.Start();
    return 0;
}