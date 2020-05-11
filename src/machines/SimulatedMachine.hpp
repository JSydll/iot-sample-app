/**
 * @file SimulatedMachine.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2020-05-11
 *
 * @copyright Copyright (c) 2020
 *
 */
#ifndef MACHINES__SIMULATEDMACHINE_HPP
#define MACHINES__SIMULATEDMACHINE_HPP

#include "../IMachine.hpp"

namespace IoTApp
{
struct SimulatedMachine final : public IMachine
{
  float mHeatLevel;
  int mRPM;
};
}  // namespace IoTApp

#endif