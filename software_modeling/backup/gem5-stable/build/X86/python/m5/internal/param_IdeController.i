%module(package="m5.internal") param_IdeController

%{
#include "sim/sim_object.hh"
#include "params/IdeController.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "params/IdeDisk.hh"
#include <cstddef>
#include "base/types.hh"
#include "dev/ide_ctrl.hh"
/**
  * This is a workaround for bug in swig. Prior to gcc 4.6.1 the STL
  * headers like vector, string, etc. used to automatically pull in
  * the cstddef header but starting with gcc 4.6.1 they no longer do.
  * This leads to swig generated a file that does not compile so we
  * explicitly include cstddef. Additionally, including version 2.0.4,
  * swig uses ptrdiff_t without the std:: namespace prefix which is
  * required with gcc 4.6.1. We explicitly provide access to it.
  */
#include <cstddef>
using std::ptrdiff_t;
%}

%import "stdint.i"
%import "base/types.hh"
%import "IdeDisk_vector.i"
%import "stdint.i"
%import "base/types.hh"

%import "python/m5/internal/param_PciDevice.i"


// stop swig from creating/wrapping default ctor/dtor
%nodefault IdeController;
class IdeController
    : public PciDevice
{
  public:
};

%include "params/IdeController.hh"
