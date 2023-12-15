#include "VKAPI.hpp"

VKAPI::VKAPI(std::string _token, unmap &_id_group)
{
    token = _token;
    for (auto &i : token)
        i -= 4;
    id_group = std::make_unique<unmap>(unmap(std::move(_id_group)));
    CurItem = id_group->begin();
}

Post VKAPI::GetPost()
{
    if (CurItem == id_group->end())
        CurItem = id_group->begin();
    auto id = CurItem->first;
    auto response = cpr::Get(
        cpr::Url{"https://api.vk.com/method/wall.get/"},
        cpr::Parameters{
            {"access_token", token},
            {"domain", id},
            {"count", "1"},
            {"offset", "1"},
            {"v", "5.199"}});
    CurItem++;
    return Post(response.text, id_group, id);
}