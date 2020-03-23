// ======================================================================
// \title  ManagerComponentImpl.cpp
// \author wbs0013
// \brief  cpp file for Manager component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/Manager/ManagerComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"
#include <Os/Log.hpp>
#include <stdio.h>

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ManagerComponentImpl ::
#if FW_OBJECT_NAMES == 1
    ManagerComponentImpl(
        const char *const compName
    ) :
      ManagerComponentBase(compName)
#else
    ManagerComponentImpl(void)
#endif
  {

  }

  void ManagerComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
	 
    )
  {
	this->isEnabled = false;
    ManagerComponentBase::init(queueDepth, instance);
  }

  ManagerComponentImpl ::
    ~ManagerComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void ManagerComponentImpl ::
    managerIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 result
    )
  {
	float res = result;
    this->tlmWrite_MGR_MSG(res);
  }

  void ManagerComponentImpl ::
    schedulerIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 message
    )
  {
    if (this->isEnabled) {
	this->driverOut_out(0,2);
	this->tlmWrite_MGR_IS_ENABLED(isEnabled);
	}
    else {
	this->tlmWrite_MGR_IS_ENABLED(isEnabled);
	}
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void ManagerComponentImpl ::
    MGR_IS_ENABLED_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        bool isEnabled
    )
  {
    this->isEnabled = isEnabled;
    this->tlmWrite_MGR_IS_ENABLED(isEnabled);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref
