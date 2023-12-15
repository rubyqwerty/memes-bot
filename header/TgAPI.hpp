#pragma once
#include <tgbot/tgbot.h>
#include "Post.hpp"

class TgAPI
{
private:
    std::string token;
    std::string id_channel;
    TgBot::Bot *bot;

public:
    TgAPI(std::string _token, std::string channel);
    void SendPost(Post post);
};
