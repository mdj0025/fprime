// ======================================================================
// \title  SchedulerComponentImpl.cpp
// \author wbs0013
// \brief  cpp file for Scheduler component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/Scheduler/SchedulerComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  SchedulerComponentImpl ::
#if FW_OBJECT_NAMES == 1
    SchedulerComponentImpl(
        const char *const compName
    ) :
      SchedulerComponentBase(compName)
#else
    SchedulerComponentImpl(void)
#endif
  {

  }

  void SchedulerComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    SchedulerComponentBase::init(queueDepth, instance);
  }

  SchedulerComponentImpl ::
    ~SchedulerComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void SchedulerComponentImpl ::
    SCHEDULE_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F32 time
    )
  {
	float t = time;
    this->tlmWrite_SCHED_SENT(t);
    this->schedulerOut_out(0,time);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref
