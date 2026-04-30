#pragma once
#include <map>
#include <string>

namespace Weather {

struct  GeoPoint;

class IProvider {
public:
  virtual std::map<std::string, std::string> getWeather(const GeoPoint& aLocation) const = 0;

  virtual ~IProvider() = default;
};
} // namespace Weather