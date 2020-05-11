/**
 * @file IMachine.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2020-05-11
 *
 * @copyright Copyright (c) 2020
 *
 */
#ifndef IMACHINE_HPP
#define IMACHINE_HPP

#include <string>

namespace IoTApp
{
/**
 * @brief
 *
 */
struct IMachine
{
  std::string mLabel;
  std::string mFirmwareVersion;
};
}

#endif
