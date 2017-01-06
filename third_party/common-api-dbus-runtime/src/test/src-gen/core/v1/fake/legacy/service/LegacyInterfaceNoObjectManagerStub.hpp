/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.5.v201512091035.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_FAKE_LEGACY_SERVICE_Legacy_Interface_No_Object_Manager_STUB_HPP_
#define V1_FAKE_LEGACY_SERVICE_Legacy_Interface_No_Object_Manager_STUB_HPP_

#include <functional>



#include <v1/fake/legacy/service/LegacyInterfaceStub.hpp>

#include <v1/fake/legacy/service/LegacyInterfaceNoObjectManager.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif


#include <CommonAPI/Stub.hpp>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1 {
namespace fake {
namespace legacy {
namespace service {

/**
 * Receives messages from remote and handles all dispatching of deserialized calls
 * to a stub for the service LegacyInterfaceNoObjectManager. Also provides means to send broadcasts
 * and attribute-changed-notifications of observable attributes as defined by this service.
 * An application developer should not need to bother with this class.
 */
class LegacyInterfaceNoObjectManagerStubAdapter
    : public virtual CommonAPI::StubAdapter, 
      public virtual LegacyInterfaceNoObjectManager, 
      public virtual LegacyInterfaceStubAdapter {
 public:



    virtual void deactivateManagedInstances() = 0;
protected:
    /**
     * Defines properties for storing the ClientIds of clients / proxies that have
     * subscribed to the selective broadcasts
     */
};

/**
 * Defines the necessary callbacks to handle remote set events related to the attributes
 * defined in the IDL description for LegacyInterfaceNoObjectManager.
 * For each attribute two callbacks are defined:
 * - a verification callback that allows to verify the requested value and to prevent setting
 *   e.g. an invalid value ("onRemoteSet<AttributeName>").
 * - an action callback to do local work after the attribute value has been changed
 *   ("onRemote<AttributeName>Changed").
 *
 * This class and the one below are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class LegacyInterfaceNoObjectManagerStubRemoteEvent
: public virtual LegacyInterfaceStubRemoteEvent
{
public:
    virtual ~LegacyInterfaceNoObjectManagerStubRemoteEvent() { }

};

/**
 * Defines the interface that must be implemented by any class that should provide
 * the service LegacyInterfaceNoObjectManager to remote clients.
 * This class and the one above are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class LegacyInterfaceNoObjectManagerStub
    : public virtual CommonAPI::Stub<LegacyInterfaceNoObjectManagerStubAdapter, LegacyInterfaceNoObjectManagerStubRemoteEvent>, 
      public virtual LegacyInterfaceStub
{
public:

    virtual ~LegacyInterfaceNoObjectManagerStub() {}
    virtual const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> clientId) = 0;



    using CommonAPI::Stub<LegacyInterfaceNoObjectManagerStubAdapter, LegacyInterfaceNoObjectManagerStubRemoteEvent>::initStubAdapter;
    typedef CommonAPI::Stub<LegacyInterfaceNoObjectManagerStubAdapter, LegacyInterfaceNoObjectManagerStubRemoteEvent>::StubAdapterType StubAdapterType;
    typedef CommonAPI::Stub<LegacyInterfaceNoObjectManagerStubAdapter, LegacyInterfaceNoObjectManagerStubRemoteEvent>::RemoteEventHandlerType RemoteEventHandlerType;
    typedef LegacyInterfaceNoObjectManagerStubRemoteEvent RemoteEventType;
    typedef LegacyInterfaceNoObjectManager StubInterface;
};

} // namespace service
} // namespace legacy
} // namespace fake
} // namespace v1


// Compatibility
namespace v1_0 = v1;

#endif // V1_FAKE_LEGACY_SERVICE_Legacy_Interface_No_Object_Manager_STUB_HPP_
