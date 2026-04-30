#include "settings.h"

namespace Weather {

namespace Window {
const int WIDTH = 800;
const int HEIGHT = 600;
const char *TITLE = "Weather";
const int FPS = 60;
} // namespace Window

const unsigned short NUMBER_CITIES = 3;
const unsigned short NUMBER_CARDS = 5;
const unsigned short NUMBER_POINTS = 4;

const Palette palette = {
    0x00303BFF,
    0xFF7777FF,
    0xF1F2DAFF,
    0xFFCE96FF,
};

const City kharkiv = {
    0,
    "Kharkiv",
    {49.9808,36.2527},
};

const City kyiv = {
    1,
    "Kyiv",
    {50.4547,30.5238},
};

const City miami = {
    2,
    "Miami",
    {25.75048,-80.20894},
};

const City CITIES[NUMBER_CITIES] = {kharkiv, kyiv, miami};

// const char *HOST = "api.open-meteo.com";
} // namespace Weather