# include "custom.hpp"

// Initialize the static member
bool SignalHandler::received_sigint = false;

// Sets up the signal handlers
void SignalHandler::SetupSignalHandlers() {
  std::signal(SIGINT, SignalHandler::HandleSignal);
}

// if SIGINT signal was received, set received_sigint to true

void SignalHandler::HandleSignal(int signal_num) {
  if (signal_num == SIGINT) {
    received_sigint = true;
    PhoneBook::ClosePhoneBook();
  }
}
