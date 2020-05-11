/**
 * @file IFieldbus.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2020-05-11
 *
 * @copyright Copyright (c) 2020
 *
 */
#ifndef IFIELDBUS_HPP
#define IFIELDBUS_HPP

#include "IDataHandler.hpp"

namespace IoTApp
{
/**
 * @brief Fetches data from machines and forwards them to registered handlers
 *
 */
class IFieldbus
{
 public:
  IFieldbus() = default;
  virtual ~IFieldbus() = default;
  IFieldbus(const IFieldbus &) = delete;
  IFieldbus &operator=(const IFieldbus &) = delete;
  IFieldbus(IFieldbus &&) = delete;
  IFieldbus &operator=(IFieldbus &&) = delete;

  virtual void Run() = 0;

  virtual void Register(IDataHandler &handler) = 0;
};
}

#endif