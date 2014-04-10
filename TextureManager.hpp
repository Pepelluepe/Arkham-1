#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include <map>
#include <memory>
#include "Window.hpp"
#include "Texture.hpp"

template<typename KEY>
class TextureManager
{
public:
    typedef std::map<KEY, std::unique_ptr<Texture>> Container_t;
private:
    Container_t m_textureContainer;

public:
    TextureManager() = default;
    ~TextureManager() = default;

    Texture* GetTexture(KEY key) const
    {
        auto it = m_textureContainer.find(key);
        if(it == m_textureContainer.end() )
            return nullptr;

        return it->second.get();
    }

    void Draw(KEY key, int x, int y) const
    {
        auto it = m_textureContainer.find(key);
        if(it == m_textureContainer.end() )
        {
            return;
            //Log error or something
        }
        else
        {
            it->second.get()->Draw(x, y);
        }

    }
    void Insert(KEY key, std::unique_ptr<Texture> tex)
    {
        m_textureContainer.insert( std::pair<KEY, std::unique_ptr<Texture>>(key, std::move(tex)));
    }

    typename Container_t::const_iterator GetTextureIterator(KEY key) const { return m_textureContainer.find(key); }

    inline bool IsEnd(typename Container_t::const_iterator it) const { return it == m_textureContainer.end(); }

    auto GetStart() const -> decltype(m_textureContainer.begin() )
    {
        return m_textureContainer.begin();
    }
    auto GetEnd() const -> decltype(m_textureContainer.end() )
    {
        return m_textureContainer.end();
    }

};

#endif //TEXTUREMANAGER_HPP
