#ifndef SIGNALHANDLER_HPP
#define SIGNALHANDLER_HPP

#include "define.hpp"
#include <csignal>
#include <iostream>

class SignalHandler {
 private:
  // Signal handler callback
  static void HandleSignal(int signal_num);

 public:
  // Static flag to indicate if a SIGINT signal was received
  static bool received_sigint;

  // Sets up the signal handlers
  static void SetupSignalHandlers();

};

#endif