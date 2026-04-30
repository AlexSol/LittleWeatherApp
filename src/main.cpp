// clang-format off
#include <raylib.h>
#include "settings.h"
#include "wallpaper.h"
#define RAYGUI_IMPLEMENTATION
#include "ui.h"
#include "providers/providers.h"
#include "parser.h"
//---
// clang-format on

int main(void) {
  InitWindow(Weather::Window::WIDTH, Weather::Window::HEIGHT,
             Weather::Window::TITLE);
  SetTargetFPS(Weather::Window::FPS);
  GuiLoadStyle("theme/style_cyber.rgs");
  GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, Weather::palette.light);
  Weather::Wallpaper wallpaper("assets/forest_default.jpg");
  wallpaper.Set(Weather::Window::WIDTH, Weather::Window::HEIGHT);
  Weather::UI ui(Weather::CITIES, Weather::NUMBER_CITIES, "assets/atlas.png",
                 "assets/Roboto_Bold.ttf", "assets/Roboto_Regular.ttf",
                 "assets/Roboto_Big.ttf", "assets/celsius.png");
  int activeItem = ui.GetActiveItemDropdownMenu();

  const std::unique_ptr<Weather::IProvider> providerWeather = Weather::CreateProviderOpenMeteo(Weather::Const::HostOpenMeteo);
  Weather::GeoPoint cityLocation = Weather::CITIES[activeItem].location;

  std::map<std::string, std::string> response = providerWeather->getWeather(cityLocation);
  Weather::Parser parser;
  parser.Parse(response.at("body"), Weather::CITIES[activeItem]);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GetColor(Weather::palette.dark));
    wallpaper.Draw();
    //--- GUI
    ui.DropdownMenu(Weather::Window::WIDTH);
    
    if (activeItem != ui.GetActiveItemDropdownMenu()) {
      activeItem = ui.GetActiveItemDropdownMenu();
      const Weather::City& city = Weather::CITIES[ui.GetActiveItemDropdownMenu()]; 
      response = providerWeather->getWeather(city.location);
      parser.Parse(response.at("body"), city);
    }
    
    ui.ShowDayOfWeek(parser.GetTimeCity());
    ui.WeatherHeroCard(parser.GetDataHero());
    ui.WeatherHourlyCard(parser.GetDataHourly());
    ui.WeatherPredictionsCard(parser.GetDataPrediction());
    ui.ButtonRefresh(Weather::Window::WIDTH, Weather::Window::HEIGHT);

    if (ui.isRefresh) {
      activeItem = ui.GetActiveItemDropdownMenu();
      const Weather::City& city = Weather::CITIES[activeItem];
      response = providerWeather->getWeather(city.location);
      parser.Parse(response.at("body"), city);
      ui.isRefresh = false;
    }
    //---
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
