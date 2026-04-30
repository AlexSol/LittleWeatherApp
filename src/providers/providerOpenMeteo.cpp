#include "providerOpenMeteo.h"
#include "httplib.h"
#include <iostream>
#include <sstream>
#include "../settings.h"

namespace Weather {

std::map<std::string, std::string>
ProviderOpenMeteo::getWeather(const GeoPoint& aLocation) const {
                  
  httplib::Client cli(host);

  const static std::map<Token, std::string> REQUEST_PATH = {
                {PART_ONE, "/v1/forecast?latitude="},
                {PART_TWO, "&longitude="},
                {PART_THREE,
                "&hourly=temperature_2m,rain,cloud_cover,snowfall,weather_code,"
                "precipitation,wind_speed_10m,wind_direction_10m,"
                "relativehumidity_2m,visibility,is_day&timezone=auto&forecast_days=1&format=json"}};
  
  std::stringstream strBuild;
  strBuild << REQUEST_PATH.at(PART_ONE) << aLocation.latitude
  << REQUEST_PATH.at(PART_TWO) << aLocation.longitude
  << REQUEST_PATH.at(PART_THREE);
  
  const std::string query = strBuild.str();
                  
  std::map<std::string, std::string> answer = {
      {"status", ""},
      {"body", ""},
  };

  if (auto res = cli.Get(query)) {
    answer.at("status") = std::to_string(res->status);
    answer.at("body") = res->body;
  }

  return answer;
};

} // namespace Weather
