#pragma once

#include <memory>
#include <string_view>
#include "IProvider.h"

namespace Weather {

  std::unique_ptr<IProvider> CreateProviderOpenMeteo(std::string_view aHost);

} // namespace Weather