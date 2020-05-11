/**
 * @file main.cpp
 * @author Joschka Seydell (joschka@seydell.org)
 * @brief
 * @version 0.1
 * @date 2020-05-11
 *
 * @copyright Copyright (c) 2020
 *
 */
#include <atomic>
#include <chrono>
#include <csignal>
#include <thread>
#include <iostream>

#include "DataLogger.hpp"
#include "FieldbusSimulator.hpp"

std::atomic<bool> gShutdown(false);
namespace
{
void SigHandler(int signal)
{
  if (signal == SIGINT)
  {
    if (gShutdown.exchange(true))
    {
      std::terminate();
    }
  }
}
}  // namespace

int main(int argc, char** argv)
{
  using namespace IoTApp;
  using namespace std::chrono_literals;

  std::signal(SIGINT, SigHandler);

  // Bootstrapping
  std::cout << "Setting up the IoT Sample Application...\n";
  DataLogger logger;
  FieldbusSimulator simulator;

  simulator.Register(logger);

  // Run phase
  std::cout << "Running the IoT Sample Application...\n";
  while (not gShutdown.load())
  {
    simulator.Run();
    std::this_thread::sleep_for(1s);
  }

  std::cout << "\nShutting down.\n";
  return 0;
}
