// ======================================================================
// \title  SchedulerComponentImpl.hpp
// \author wbs0013
// \brief  hpp file for Scheduler component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef Scheduler_HPP
#define Scheduler_HPP

#include "Ref/Scheduler/SchedulerComponentAc.hpp"

namespace Ref {

  class SchedulerComponentImpl :
    public SchedulerComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object Scheduler
      //!
      SchedulerComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object Scheduler
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object Scheduler
      //!
      ~SchedulerComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for SCHEDULE command handler
      //! Schedule a command
      void SCHEDULE_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          F32 time 
      );


    };

} // end namespace Ref

#endif
