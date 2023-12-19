#include "Mainloop.hpp"

Mainloop::Mainloop(std::string load_to_config)
{
    std::ifstream config_file(load_to_config);
    std::string config;
    std::string a;
    while (std::getline(config_file, a))
        config += a;
    nlohmann::json json = nlohmann::json::parse(config);
    std::unordered_map<std::string, int> id_group;
    for (std::string item : json["groups"])
    {
        id_group.insert({item, 0});
    }

    std::string vk_token = json["vktoken"];
    std::string tg_token = json["tgtoken"];
    long long channel = json["channel"];
    vkapi = new VKAPI(vk_token, id_group);
    tgapi = new TgAPI(tg_token, channel);
}

void Mainloop::Start()
{
    while (1)
    {
        try
        {
            tgapi->SendPost(vkapi->GetPost());
            sleep(300);
        }
        catch (TgBot::TgException &e)
        {
            std::cerr << e.what() << "\n";
        }
    }
}