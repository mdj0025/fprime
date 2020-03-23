// ======================================================================
// \title  DriverComponentImpl.hpp
// \author wbs0013
// \brief  hpp file for Driver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef Driver_HPP
#define Driver_HPP

#include "Ref/Driver/DriverComponentAc.hpp"

namespace Ref {

  class DriverComponentImpl :
    public DriverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object Driver
      //!
      DriverComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object Driver
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object Driver
      //!
      ~DriverComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for driverIn
      //!
      void driverIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 message 
      );


    };

} // end namespace Ref

#endif
