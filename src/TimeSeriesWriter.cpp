#include "TimeSeriesWriter.h"

TimeSeriesWriter::TimeSeriesWriter(const Config& cfg) : cfg_(cfg) {}

// ---- Constant Time Series
void TimeSeriesWriter::addConstantTimeSeries(const std::size_t& tag,
                                             const double& factor) {
  std::ofstream file(cfg_.timeSeriesFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >>" + cfg_.timeSeriesFile);
  file << "# Constant TimeSeries Definition\n";
  file << "timeSeries Constant " << tag << " " << "-factor " << factor << "\n";
  file.close();
}

// ---- Linear Time Series
void TimeSeriesWriter::addLinearTimeSeries(const std::size_t& tag,
                                           const double& factor) {
  std::ofstream file(cfg_.timeSeriesFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >>" + cfg_.timeSeriesFile);
  file << "# Linear TimeSeries Definition\n";
  file << "timeSeries Linear " << tag << " " << "-factor " << factor << "\n";
  file.close();
}

// ---- Path Time Series
void TimeSeriesWriter::addPathtimeSeries(const std::size_t& tag,
                                         std::string& filename,
                                         const double& dt,
                                         const double& cFactor) {
  std::ofstream file(cfg_.timeSeriesFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >>" + cfg_.timeSeriesFile);
  file << "# Path TimeSeries Definition\n";
  file << "timeSeries Path " << tag << " " << "-dt " << dt << " ";
  file << "-filePath " << filename << " " << "-factor " << cFactor << "\n";

  file.close();
}

void TimeSeriesWriter::addPathTimeSeries(const std::size_t& tag,
                                         const double& dt,
                                         const std::vector<double>& values,
                                         const double factor) {
  std::ofstream file(cfg_.timeSeriesFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >>" + cfg_.timeSeriesFile);
  std::size_t count = 0;
  // define a TCL list for values
  file << "# Path TimeSeries Definition\n";
  file << "set timeSeriesValues_" << tag << " {";
  for (auto& val : values) {
    file << val << " ";
  }

  file << "}";
  file << "\n";

  // write timeseries
  file << "eval timeSeries Path " << tag << " " << "-dt " << dt;
  file << " " << "-values $timeSeriesValues_" << tag << " -factor " << factor
       << "\n";

  file.close();
}

// ---- Gaussian TimeSeries
void TimeSeriesWriter::addGaussianTimeSeries(const std::size_t& tag,
                                             const double& dt,
                                             const std::size_t& nvalues,
                                             const double factor) {
  std::ofstream file(cfg_.timeSeriesFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >>" + cfg_.timeSeriesFile);
  file << "# Gaussian TimeSeries Definition\n";
  file << "proc gaussianRandom {} {\n";
  file << "\tset u1 [expr rand()]\n";
  file << "\tset u2 [expr rand()]\n";
  file << "\tset z1 [expr sqrt(-2.0 * log($u1)) * cos(2.0 * 3.1415926535 * "
          "$u2)]\n";
  file << "\treturn $z1 \n } \n";

  file << "proc createGaussianVector {n} {\n";
  file << "\tset vec {}\n";
  file << "for {set ii 0} {$ii < $n} {incr ii} {\n";
  file << "\t\tlappend vec [gaussianRandom]\n";
  file << "\t}\n\t return $vec \n";
  file << "}\n";

  file << "\nset gaussian_" << tag << " " << "[createGaussianVector " << nvalues
       << "]\n";

  file << "\neval timeSeries Path " << tag << " " << "-dt " << dt;
  file << " " << "-values $gaussian_" << tag << " -factor " << factor << "\n";

  file.close();
}