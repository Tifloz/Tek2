/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Interface for OOP_arcade_2018
*/

#ifndef OOP_ARCADE_2018_INTERFACE_HPP
#define OOP_ARCADE_2018_INTERFACE_HPP

#include <glob.h>
#include <string>
#include <vector>

namespace lib
{
    enum COLOR {
        RED,
        BLUE,
        GREEN,
        WHITE,
        BLACK,
        TRANSPARENT,
    };
    enum KEY {
        KEY_A,
        KEY_B,
        KEY_C,
        KEY_D,
        KEY_E,
        KEY_F,
        KEY_G,
        KEY_H,
        KEY_I,
        KEY_J,
        KEY_K,
        KEY_L,
        KEY_M,
        KEY_N,
        KEY_O,
        KEY_P,
        KEY_Q,
        KEY_R,
        KEY_S,
        KEY_T,
        KEY_U,
        KEY_V,
        KEY_W,
        KEY_X,
        KEY_Y,
        KEY_Z,
        KEY_1,
        KEY_2,
        KEY_3,
        KEY_4,
        KEY_5,
        KEY_6,
        KEY_7,
        KEY_8,
        KEY_9,
        KEY_0,
        KEY_ECHAP,
        KEY_ENTER,
        KEY_SUPPR,
        KEY_SPACE,
        KEY_DELETE,
        KEY_TAB,
        KEY_MAJ,
        KEY_RIGHT_CLICK,
        KEY_LEFT_CLICK,
        KEY_MIDDLE_CLICK,
        KEY_UP,
        KEY_DOWN,
        KEY_LEFT,
        KEY_RIGHT,
    };

	template <typename windows_t, typename sprite_t, typename sound_t, typename text_t, typename vertex_t>
    class ILibrary {
            public:
                virtual ~ILibrary() = default;
                virtual windows_t createWindows(size_t _width, size_t _height, std::string _windowsName) = 0;
                virtual sprite_t createSprite(std::string pathTexture, size_t width, size_t height) = 0;
	            virtual sound_t createSound(std::string pathSound) = 0; //rajouter peut être le volume ?
                virtual text_t createText(std::string text, size_t size, COLOR color, std::vector<int> position, size_t font) = 0;
        };
}
#endif //OOP_ARCADE_2018_INTERFACE_HPP
