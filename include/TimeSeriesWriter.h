#ifndef TIMESERIES_H
#define TIMESERIES_H

#include <string>
#include <vector>

#include "Config.h"

class TimeSeriesWriter {
 public:
  TimeSeriesWriter(const Config& cfg);

  // ---- Constant Time Series
  void addConstantTimeSeries(const std::size_t& tag,
                             const double& factor = 1.0);

  // ---- Linear Time Series
  void addLinearTimeSeries(const std::size_t& tag, const double& factor = 1.0);

  // ---- Path Time Series
  void addPathtimeSeries(const std::size_t& tag, std::string& filename,
                         const double& dt, const double& cFactor);

  void addPathTimeSeries(const std::size_t& tag, const double& dt,
                         const std::vector<double>& values,
                         const double factor = 1.0);

  // ---- Gaussian TimeSeries
  void addGaussianTimeSeries(const std::size_t& tag, const double& dt,
                             const std::size_t& nvalues,
                             const double factor = 1.0);

 private:
  const Config& cfg_;
};

#endif