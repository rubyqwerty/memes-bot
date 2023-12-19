#include "TgAPI.hpp"

TgAPI::TgAPI(std::string _token, long long channel)
{
    token = _token;
    for (auto &i : token)
        i += 5;
    bot = new TgBot::Bot(token);
    id_channel = channel;
}

void TgAPI::SendPost(Post post)
{
    std::cout << post.GetText();
    if (post.GetText() != "null")
        bot->getApi().sendPhoto(id_channel, post.GetPhoto(), post.GetText());
}