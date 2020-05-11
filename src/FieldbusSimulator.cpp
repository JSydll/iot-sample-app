/**
 * @file FieldbusSimulator.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2020-05-11
 *
 * @copyright Copyright (c) 2020
 *
 */
#include "FieldbusSimulator.hpp"

#include <iostream>

namespace IoTApp
{
FieldbusSimulator::FieldbusSimulator(int n)
{
  for (int no = 0; no < n; ++no)
  {
    mMachines.push_back(SimulatedMachine());
  }
  std::cout << "Started Fieldbus Simulator (with " << mMachines.size() << " machines).\n";
}

void FieldbusSimulator::Run()
{
  RunSimulation();
  ForwardData();
}

void FieldbusSimulator::Register(IDataHandler &handler)
{
  mHandlers.push_back(std::ref(handler));
}

void FieldbusSimulator::RunSimulation()
{
  for (auto &machine : mMachines)
  {
    // Do some simulated changes in the data
  }
}

void FieldbusSimulator::ForwardData()
{
  for (const auto &machine : mMachines)
  {
    for (const auto &handler : mHandlers)
    {
      handler.get().Process(machine);
    }
  }
}
}  // namespace IoTApp