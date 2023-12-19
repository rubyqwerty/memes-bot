#pragma once
#include <tgbot/tgbot.h>
#include "Post.hpp"

class TgAPI
{
private:
    std::string token;
    long long id_channel;
    TgBot::Bot *bot;

public:
    TgAPI(std::string _token, long long channel);
    void SendPost(Post post);
};
