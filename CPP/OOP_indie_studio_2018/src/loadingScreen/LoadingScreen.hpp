/*
** EPITECH PROJECT, 2018
** Indie_Studio
** File description:
** LoadingScreen.hpp
*/

#ifndef INDIE_STUDIO_LOADINGSCREEN_HPP
#define INDIE_STUDIO_LOADINGSCREEN_HPP

#include "../core/Tab.hpp"
#include "../animatedTexture/AnimatedTexture.hpp"
#include <boost/filesystem.hpp>
#include <future>
#include <thread>
#include <chrono>


class LoadingScreen : public Tab
{
public:
    LoadingScreen(irr::IrrlichtDevice *, std::string &, AudioManager *);

    struct recursive_directory_range
    {
        typedef boost::filesystem::recursive_directory_iterator iterator;
        recursive_directory_range(boost::filesystem::path p) : p_(p) {}

        iterator begin() { return boost::filesystem::recursive_directory_iterator(p_); }
        iterator end() { return boost::filesystem::recursive_directory_iterator(); }

        boost::filesystem::path p_;
    };
    bool init() override;
    void update() override;
    void draw() override;

private:
    AnimatedTexture _spinner;
    std::map<std::string, irr::video::ITexture *> _textures;
    unsigned int _count = 0;
    unsigned int _totalCount = 0;
    std::vector<boost::filesystem::path> _paths;
    unsigned int _loadingWidth;
};


#endif //INDIE_STUDIO_LOADINGSCREEN_HPP
