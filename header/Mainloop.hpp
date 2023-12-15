
#pragma once
#include "VKAPI.hpp"
#include "TgAPI.hpp"

class Mainloop {
    VKAPI* vkapi;
    TgAPI* tgapi;
public:
    Mainloop(std::string config);
    void Start();
};