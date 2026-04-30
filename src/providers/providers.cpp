#include "providers.h"
#include "providerOpenMeteo.h"

namespace Weather {

  std::unique_ptr<IProvider> CreateProviderOpenMeteo(std::string_view aHost) {
                            return std::make_unique<ProviderOpenMeteo>(aHost);
  }

} // namespace Weather