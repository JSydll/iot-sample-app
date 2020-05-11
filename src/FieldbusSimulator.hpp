/**
 * @file FieldbusSimulator.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2020-05-11
 *
 * @copyright Copyright (c) 2020
 *
 */
#ifndef FIELDBUS_SIMULATOR_HPP
#define FIELDBUS_SIMULATOR_HPP

#include <functional>
#include <vector>

#include "IFieldbus.hpp"
#include "machines/SimulatedMachine.hpp"

namespace IoTApp
{
/**
 * @brief
 *
 */
class FieldbusSimulator final : public IFieldbus
{
 public:
  FieldbusSimulator(int n = 3);
  ~FieldbusSimulator() override = default;

  void Run() override;
  void Register(IDataHandler &handler) override;

 private:
  std::vector<std::reference_wrapper<IDataHandler>> mHandlers;
  std::vector<SimulatedMachine> mMachines;

  void RunSimulation();

  void ForwardData();
};
}  // namespace IoTApp

#endif