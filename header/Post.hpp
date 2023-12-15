
#pragma once
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <vector>
#include <regex>

using unmap = std::unordered_map<std::string, std::string>;
using map_ptr = std::unique_ptr<unmap>;

class Post
{
private:
    std::string text_post;
    std::string binary_photo;

public:
    Post(std::string json_post, map_ptr &ids, std::string id);
    std::string &GetText();
    std::string &GetPhoto();
};