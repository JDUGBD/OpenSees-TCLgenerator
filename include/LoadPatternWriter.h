#ifndef LOADPATTERNWRITER_H
#define LOADPATTERNWRITER_H

#include <vector>

#include "Config.h"

class LoadPatternwriter {
 public:
  LoadPatternwriter(const Config& cfg);

  // ---- Plain Load PAttern
  void addPlainPatternNodalLoad(const std::size_t& patternTAG,
                                const std::size_t& timeSeriesTAG,
                                const std::vector<std::size_t>& nodeTAG,
                                const std::vector<std::vector<double>>& ndfs);

  void addAdditionalPlainPatternNodalLoad(
      const std::size_t& patternTAG, const std::size_t& timeSeriesTAG,
      const std::vector<std::size_t>& nodeTAG,
      const std::vector<std::vector<double>>& ndfs);

  void addPlainPatternElementLoad(const std::size_t& patternTAG,
                                  const std::size_t& timeSeriesTAG,
                                  const std::vector<std::size_t>& eleTAG,
                                  const std::vector<std::vector<double>>& ndfs);

  void addPlainPatternElementLoad(const std::size_t& patternTAG,
                                  const std::size_t& timeSeriesTAG,
                                  const std::vector<std::size_t>& eleTAG,
                                  const std::vector<double>& ndfs);

  void addAdditionalPlainPatternElementLoad(
      const std::size_t& patternTAG, const std::size_t& timeSeriesTAG,
      const std::vector<std::size_t>& eleTAG,
      const std::vector<std::vector<double>>& ndfs);

  void addAdditionalPlainPatternElementLoad(
      const std::size_t& patternTAG, const std::size_t& timeSeriesTAG,
      const std::vector<std::size_t>& eleTAG, const std::vector<double>& ndfs);

 private:
  const Config& cfg_;
};

#endif
