/**
 * @file DataLogger.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2020-05-11
 *
 * @copyright Copyright (c) 2020
 *
 */
#include "DataLogger.hpp"

#include <chrono>
#include <sstream>
#include <iomanip>

namespace IoTApp
{
DataLogger::DataLogger(const std::string &name, const std::string &path) : mLog(path + name)
{
}

void DataLogger::Process(const IMachine &machine)
{
  LogBase(machine);
  mLog << "\n";
}

void DataLogger::Process(const SimulatedMachine &machine)
{
  LogBase(machine);
  LogSpecific(machine);
  mLog << "\n";
}

void DataLogger::LogBase(const IMachine &machine)
{
  mLog << GetTimestamp() << "; "
       << "[" << machine.mLabel << "]; FW: " << machine.mFirmwareVersion << "; ";
}

void DataLogger::LogSpecific(const SimulatedMachine &machine)
{
  mLog << "Heat: " << machine.mHeatLevel << "; RPM: " << machine.mRPM << "; ";
}

std::string DataLogger::GetTimestamp() const
{
  using namespace std::chrono;
  const auto tt = system_clock::to_time_t(system_clock::now());
  const auto tm = *std::localtime(&tt);
  std::stringstream ss;
  ss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
  return ss.str();
}
}  // namespace IoTApp