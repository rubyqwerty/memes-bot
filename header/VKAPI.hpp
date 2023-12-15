#pragma once
#include "Post.hpp"
#include <cpr/cpr.h>
#include <map>

class VKAPI
{
private:
    std::string token;
    map_ptr id_group;
    std::unordered_map<std::string, std::string>::iterator CurItem;

public:
    VKAPI(std::string _token, unmap &);
    Post GetPost();
};
