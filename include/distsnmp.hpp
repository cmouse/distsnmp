#ifndef DISTSNMP_HPP
#define DISTSNMP_HPP 1

#include <iostream>
#include <fstream>
#include <vector>
#include <boost/program_options.hpp>

namespace DistSNMP {
  class Configuration {
  public:
    static bool configure(int argc, const char *argv[], const char *envp[]) { return instance._configure(argc, argv, envp); };
    static boost::program_options::variables_map& vm() { return instance._vm; };
  private:
    Configuration(): desc("Options") {
      desc.add_options() 
        ("help,h", "Print usage information")
        ("config,c", "Path to configuration file")
        ("debug,d", "Run in debug mode")
        ("source", boost::program_options::value<std::vector<std::string> >()->composing(), "Source definition (startip-endip#startport-endport)")
        ("use-raw", "Use raw sockets instead of binding (will disable IO offloading)")
        ("use-freebind", "Use freebind") 
        ("queue", boost::program_options::value<std::vector<std::string> >()->composing(), "Named redis queue, with optional weight (Default: DEFAULT, 1)")
        ;
    }
 
    bool _configure(int argc, const char *argv[], const char *envp[]) { 
      try {
         boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), _vm);
         if ( _vm.count("help") ) {
           std::cerr << "Usage information" << std::endl << desc << std::endl;
           return false;
         }

         boost::program_options::notify(_vm);
         if (_vm.count("config")) {
           boost::program_options::store(boost::program_options::parse_config_file<char>(_vm["config"].as<std::string>().c_str(), desc, false), _vm);
           boost::program_options::notify(_vm);
         }
      } catch (std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return false;
      }

      return true;
    }

    static Configuration instance;
    boost::program_options::options_description desc;
    boost::program_options::variables_map _vm;
  };
};

#endif
