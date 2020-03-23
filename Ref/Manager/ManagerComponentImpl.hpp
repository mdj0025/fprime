// ======================================================================
// \title  ManagerComponentImpl.hpp
// \author wbs0013
// \brief  hpp file for Manager component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef Manager_HPP
#define Manager_HPP

#include "Ref/Manager/ManagerComponentAc.hpp"

namespace Ref {

  class ManagerComponentImpl :
    public ManagerComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object Manager
      //!
      ManagerComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object Manager
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object Manager
      //!
      ~ManagerComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for managerIn
      //!
      void managerIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 result /*!< the result of the operation*/
      );

      //! Handler implementation for schedulerIn
      //!
      void schedulerIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 message /*!< the result of the operation*/
      );

    PRIVATE:
	bool isEnabled;

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for MGR_IS_ENABLED command handler
      //! Do a math operation
      void MGR_IS_ENABLED_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          bool isEnabled 
      );


    };

} // end namespace Ref

#endif
