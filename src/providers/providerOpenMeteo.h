#pragma once
#include "IProvider.h"

namespace Weather {
class ProviderOpenMeteo : public IProvider {
public:
  ProviderOpenMeteo(std::string_view aHost): IProvider(), host(aHost){};
  std::map<std::string, std::string> getWeather(const GeoPoint& aLocation) const override;

private:
  std::string host;
};
} // namespace Weather