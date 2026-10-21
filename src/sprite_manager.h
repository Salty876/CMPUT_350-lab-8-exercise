#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H

#include <unordered_map>
#include "sprite.h"
#include <SFML/Graphics.hpp>

using SpriteID = size_t;

class SpriteManager {
public:

    sf::Texture& registerTexture(const std::string& filepath) {
        auto it = mTextures.find(filepath);

        if (it != mTextures.end()){
            return it->second;
        }

        sf::Texture texty = sf::Texture(filepath);
        mTextures.emplace(filepath, std::move(texty));
        return mTextures.find(filepath)->second;
    }

    template <typename... Args> SpriteID createSprite(Args&&... args) {
        SpriteID ID = mSprites.size();
        mSprites.emplace_back(std::forward<Args>(args)...);
        return ID;
    }
    Sprite& getSprite(SpriteID id){
        return mSprites.at(id);
    }
private:
std::unordered_map<std::string, sf::Texture> mTextures;
std::vector<Sprite> mSprites;
};

#endif  // SPRITE_MANAGER_H
