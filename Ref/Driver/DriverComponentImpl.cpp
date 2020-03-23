// ======================================================================
// \title  DriverComponentImpl.cpp
// \author wbs0013
// \brief  cpp file for Driver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/Driver/DriverComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"
#include <stdlib.h>

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  DriverComponentImpl ::
#if FW_OBJECT_NAMES == 1
    DriverComponentImpl(
        const char *const compName
    ) :
      DriverComponentBase(compName)
#else
    DriverComponentImpl(void)
#endif
  {

  }

  void DriverComponentImpl ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    DriverComponentBase::init(instance);
  }

  DriverComponentImpl ::
    ~DriverComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void DriverComponentImpl ::
    driverIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 message
    )
  {
    float v1 = rand() % 100;
    this->managerOut_out(0,v1);
    this->tlmWrite_MGR_MSG(v1);
  }

} // end namespace Ref
