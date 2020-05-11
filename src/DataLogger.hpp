/**
 * @file DataLogger.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2020-05-11
 *
 * @copyright Copyright (c) 2020
 *
 */
#ifndef DATALOGGER_HPP
#define DATALOGGER_HPP

#include "IDataHandler.hpp"
#include "FileWriter.hpp"

namespace IoTApp
{
/**
 * @brief
 *
 */
class DataLogger final : public IDataHandler
{
 public:
  DataLogger(const std::string &name = "machine-data.log", const std::string &path = "./");
  ~DataLogger() override = default;

  void Process(const IMachine &machine) override;
  void Process(const SimulatedMachine &machine) override;

 private:
  FileWriter mLog;

  void LogBase(const IMachine &machine);

  void LogSpecific(const SimulatedMachine &machine);

  std::string GetTimestamp() const;
};
}  // namespace IoTApp

#endif