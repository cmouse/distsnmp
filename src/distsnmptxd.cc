#include "config.h"
#include <iostream>
#include <event2/event.h>
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <hiredis/hiredis.h>

#include "distsnmp.hpp"

namespace DistSNMP {
 class Poller {
 public: 
   void run() {};
 };
};

int main(int argc, const char *argv[], const char *envp[]) {
  DistSNMP::Poller poller;
  DistSNMP::Configuration::configure(argc, argv, envp);
  poller.run();

  return 0;
}
