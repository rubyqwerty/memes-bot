#include "Post.hpp"

Post::Post(std::string json_post, map_ptr &ids, std::string id_)
{
        nlohmann::json resp = nlohmann::json::parse(json_post);
        std::string id_post = resp["response"]["items"][0]["id"];
        if ((*ids)[id_] != id_post)
        {
                binary_photo = resp["response"]["items"][0]["attachments"][0]["photo"]["sizes"][4]["url"];
                text_post = resp["response"]["items"][0]["text"];
                text_post = std::regex_replace(text_post, std::regex("\n"), " ");
                if (text_post.find("http") == std::string::npos)
                        text_post = "null";
                (*ids)[id_] = id_post;
        }
        else
        {
                text_post = "null";
                binary_photo = "null";
        }
}

std::string &Post::GetText()
{
        return text_post;
}

std::string &Post::GetPhoto()
{
        return binary_photo;
}