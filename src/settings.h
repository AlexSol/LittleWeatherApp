#pragma once
#include <map>
#include <string>

namespace Weather {

namespace Window {
extern const int WIDTH;
extern const int HEIGHT;
extern const char *TITLE;
extern const int FPS;
} // namespace Window

extern const unsigned short NUMBER_CITIES;
extern const unsigned short NUMBER_CARDS;
extern const unsigned short NUMBER_POINTS;

struct Palette {
  unsigned int dark;
  unsigned int accent;
  unsigned int light;
  unsigned int pleasant;
};

extern const Palette palette;

struct GeoPoint {
  double latitude;
  double longitude;
};

struct City {
  unsigned short id;
  std::string name;
  GeoPoint location;
};

enum Cities { KHARKOV, KYIV, MIAMI };
enum Token { PART_ONE, PART_TWO, PART_THREE };
enum Prediction { CLOUD, VISIBILITY, HUMIDITY, WINDY };

extern const City CITIES[];

namespace Const {
  inline static constexpr std::string_view HostOpenMeteo{"api.open-meteo.com"};
}

} // namespace Weather