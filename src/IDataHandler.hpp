/**
 * @file IDataHandler.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2020-05-11
 *
 * @copyright Copyright (c) 2020
 *
 */
#ifndef IDATAHANDLER_HPP
#define IDATAHANDLER_HPP

#include "IMachine.hpp"
#include "machines/SimulatedMachine.hpp"

namespace IoTApp
{
/**
 * @brief
 *
 */
class IDataHandler
{
 public:
  IDataHandler() = default;
  virtual ~IDataHandler() = default;
  IDataHandler(const IDataHandler &) = delete;
  IDataHandler &operator=(const IDataHandler &) = delete;
  IDataHandler(IDataHandler &&) = delete;
  IDataHandler &operator=(IDataHandler &&) = delete;

  virtual void Process(const SimulatedMachine &machine) = 0;
  virtual void Process(const IMachine &machine) = 0;
};
}

#endif