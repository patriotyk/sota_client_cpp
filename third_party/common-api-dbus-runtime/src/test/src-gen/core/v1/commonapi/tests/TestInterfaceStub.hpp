/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.5.v201512091035.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_COMMONAPI_TESTS_Test_Interface_STUB_HPP_
#define V1_COMMONAPI_TESTS_Test_Interface_STUB_HPP_

#include <functional>



#include <commonapi/tests/DerivedTypeCollection.hpp>
#include <commonapi/tests/PredefinedTypeCollection.hpp>

#include <v1/commonapi/tests/TestInterface.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/Deployment.hpp>
#include <CommonAPI/InputStream.hpp>
#include <CommonAPI/OutputStream.hpp>
#include <CommonAPI/Struct.hpp>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <CommonAPI/Stub.hpp>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1 {
namespace commonapi {
namespace tests {

/**
 * Receives messages from remote and handles all dispatching of deserialized calls
 * to a stub for the service TestInterface. Also provides means to send broadcasts
 * and attribute-changed-notifications of observable attributes as defined by this service.
 * An application developer should not need to bother with this class.
 */
class TestInterfaceStubAdapter
    : public virtual CommonAPI::StubAdapter, 
      public virtual TestInterface {
 public:
    ///Notifies all remote listeners about a change of value of the attribute TestPredefinedTypeAttribute.
    virtual void fireTestPredefinedTypeAttributeAttributeChanged(const uint32_t& TestPredefinedTypeAttribute) = 0;
    ///Notifies all remote listeners about a change of value of the attribute TestDerivedStructAttribute.
    virtual void fireTestDerivedStructAttributeAttributeChanged(const ::commonapi::tests::DerivedTypeCollection::TestStructExtended& TestDerivedStructAttribute) = 0;
    ///Notifies all remote listeners about a change of value of the attribute TestDerivedArrayAttribute.
    virtual void fireTestDerivedArrayAttributeAttributeChanged(const ::commonapi::tests::DerivedTypeCollection::TestArrayUInt64& TestDerivedArrayAttribute) = 0;

    /**
     * Sends a broadcast event for TestPredefinedTypeBroadcast. Should not be called directly.
     * Instead, the "fire<broadcastName>Event" methods of the stub should be used.
     */
    virtual void fireTestPredefinedTypeBroadcastEvent(const uint32_t &_uint32Value, const std::string &_stringValue) = 0;
    /**
     * Sends a selective broadcast event for TestSelectiveBroadcast. Should not be called directly.
     * Instead, the "fire<broadcastName>Event" methods of the stub should be used.
     */
    virtual void fireTestSelectiveBroadcastSelective(const std::shared_ptr<CommonAPI::ClientId> _client) = 0;
    virtual void sendTestSelectiveBroadcastSelective(const std::shared_ptr<CommonAPI::ClientIdList> _receivers = nullptr) = 0;
    virtual void subscribeForTestSelectiveBroadcastSelective(const std::shared_ptr<CommonAPI::ClientId> clientId, bool& success) = 0;
    virtual void unsubscribeFromTestSelectiveBroadcastSelective(const std::shared_ptr<CommonAPI::ClientId> clientId) = 0;
    virtual std::shared_ptr<CommonAPI::ClientIdList> const getSubscribersForTestSelectiveBroadcastSelective() = 0;
    /**
     * Sends a selective broadcast event for TestBroadcastWithOutArgs. Should not be called directly.
     * Instead, the "fire<broadcastName>Event" methods of the stub should be used.
     */
    virtual void fireTestBroadcastWithOutArgsSelective(const std::shared_ptr<CommonAPI::ClientId> _client, const uint32_t &_uint32Value, const std::string &_stringValue) = 0;
    virtual void sendTestBroadcastWithOutArgsSelective(const uint32_t &_uint32Value, const std::string &_stringValue, const std::shared_ptr<CommonAPI::ClientIdList> _receivers = nullptr) = 0;
    virtual void subscribeForTestBroadcastWithOutArgsSelective(const std::shared_ptr<CommonAPI::ClientId> clientId, bool& success) = 0;
    virtual void unsubscribeFromTestBroadcastWithOutArgsSelective(const std::shared_ptr<CommonAPI::ClientId> clientId) = 0;
    virtual std::shared_ptr<CommonAPI::ClientIdList> const getSubscribersForTestBroadcastWithOutArgsSelective() = 0;


    virtual void deactivateManagedInstances() = 0;
protected:
    /**
     * Defines properties for storing the ClientIds of clients / proxies that have
     * subscribed to the selective broadcasts
     */
    std::shared_ptr<CommonAPI::ClientIdList> subscribersForTestSelectiveBroadcastSelective_;
    std::shared_ptr<CommonAPI::ClientIdList> subscribersForTestBroadcastWithOutArgsSelective_;
};

/**
 * Defines the necessary callbacks to handle remote set events related to the attributes
 * defined in the IDL description for TestInterface.
 * For each attribute two callbacks are defined:
 * - a verification callback that allows to verify the requested value and to prevent setting
 *   e.g. an invalid value ("onRemoteSet<AttributeName>").
 * - an action callback to do local work after the attribute value has been changed
 *   ("onRemote<AttributeName>Changed").
 *
 * This class and the one below are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class TestInterfaceStubRemoteEvent
{
public:
    virtual ~TestInterfaceStubRemoteEvent() { }

    /// Verification callback for remote set requests on the attribute TestPredefinedTypeAttribute
    virtual bool onRemoteSetTestPredefinedTypeAttributeAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, uint32_t _value) = 0;
    /// Action callback for remote set requests on the attribute TestPredefinedTypeAttribute
    virtual void onRemoteTestPredefinedTypeAttributeAttributeChanged() = 0;
    /// Verification callback for remote set requests on the attribute TestDerivedStructAttribute
    virtual bool onRemoteSetTestDerivedStructAttributeAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, ::commonapi::tests::DerivedTypeCollection::TestStructExtended _value) = 0;
    /// Action callback for remote set requests on the attribute TestDerivedStructAttribute
    virtual void onRemoteTestDerivedStructAttributeAttributeChanged() = 0;
    /// Verification callback for remote set requests on the attribute TestDerivedArrayAttribute
    virtual bool onRemoteSetTestDerivedArrayAttributeAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, ::commonapi::tests::DerivedTypeCollection::TestArrayUInt64 _value) = 0;
    /// Action callback for remote set requests on the attribute TestDerivedArrayAttribute
    virtual void onRemoteTestDerivedArrayAttributeAttributeChanged() = 0;
};

/**
 * Defines the interface that must be implemented by any class that should provide
 * the service TestInterface to remote clients.
 * This class and the one above are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class TestInterfaceStub
    : public virtual CommonAPI::Stub<TestInterfaceStubAdapter, TestInterfaceStubRemoteEvent>
{
public:
    typedef std::function<void ()>testEmptyMethodReply_t;
    typedef std::function<void ()>testVoidPredefinedTypeMethodReply_t;
    typedef std::function<void (uint32_t _uint32OutValue, std::string _stringOutValue)>testPredefinedTypeMethodReply_t;
    typedef std::function<void ()>testVoidDerivedTypeMethodReply_t;
    typedef std::function<void (::commonapi::tests::DerivedTypeCollection::TestEnumExtended2 _testEnumExtended2OutValue, ::commonapi::tests::DerivedTypeCollection::TestMap _testMapOutValue)>testDerivedTypeMethodReply_t;
    typedef std::function<void ()>TestArrayOfPolymorphicStructMethodReply_t;
    typedef std::function<void ()>TestMapOfPolymorphicStructMethodReply_t;
    typedef std::function<void ()>TestStructWithPolymorphicMemberMethodReply_t;
    typedef std::function<void ()>TestStructWithEnumKeyMapMemberReply_t;

    virtual ~TestInterfaceStub() {}
    virtual const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> clientId) = 0;

    /// Provides getter access to the attribute TestPredefinedTypeAttribute
    virtual const uint32_t &getTestPredefinedTypeAttributeAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) = 0;
    /// Provides getter access to the attribute TestDerivedStructAttribute
    virtual const ::commonapi::tests::DerivedTypeCollection::TestStructExtended &getTestDerivedStructAttributeAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) = 0;
    /// Provides getter access to the attribute TestDerivedArrayAttribute
    virtual const ::commonapi::tests::DerivedTypeCollection::TestArrayUInt64 &getTestDerivedArrayAttributeAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) = 0;

    /// This is the method that will be called on remote calls on the method testEmptyMethod.
    virtual void testEmptyMethod(const std::shared_ptr<CommonAPI::ClientId> _client, testEmptyMethodReply_t _reply) = 0;
    /// This is the method that will be called on remote calls on the method testVoidPredefinedTypeMethod.
    virtual void testVoidPredefinedTypeMethod(const std::shared_ptr<CommonAPI::ClientId> _client, uint32_t _uint32Value, std::string _stringValue, testVoidPredefinedTypeMethodReply_t _reply) = 0;
    /// This is the method that will be called on remote calls on the method testPredefinedTypeMethod.
    virtual void testPredefinedTypeMethod(const std::shared_ptr<CommonAPI::ClientId> _client, uint32_t _uint32InValue, std::string _stringInValue, testPredefinedTypeMethodReply_t _reply) = 0;
    /// This is the method that will be called on remote calls on the method testVoidDerivedTypeMethod.
    virtual void testVoidDerivedTypeMethod(const std::shared_ptr<CommonAPI::ClientId> _client, ::commonapi::tests::DerivedTypeCollection::TestEnumExtended2 _testEnumExtended2Value, ::commonapi::tests::DerivedTypeCollection::TestMap _testMapValue, testVoidDerivedTypeMethodReply_t _reply) = 0;
    /// This is the method that will be called on remote calls on the method testDerivedTypeMethod.
    virtual void testDerivedTypeMethod(const std::shared_ptr<CommonAPI::ClientId> _client, ::commonapi::tests::DerivedTypeCollection::TestEnumExtended2 _testEnumExtended2InValue, ::commonapi::tests::DerivedTypeCollection::TestMap _testMapInValue, testDerivedTypeMethodReply_t _reply) = 0;
    /// This is the method that will be called on remote calls on the method TestArrayOfPolymorphicStructMethod.
    virtual void TestArrayOfPolymorphicStructMethod(const std::shared_ptr<CommonAPI::ClientId> _client, std::vector<std::shared_ptr<::commonapi::tests::DerivedTypeCollection::TestPolymorphicStruct>> _inArray, TestArrayOfPolymorphicStructMethodReply_t _reply) = 0;
    /// This is the method that will be called on remote calls on the method TestMapOfPolymorphicStructMethod.
    virtual void TestMapOfPolymorphicStructMethod(const std::shared_ptr<CommonAPI::ClientId> _client, ::commonapi::tests::DerivedTypeCollection::MapIntToPolymorphic _inMap, TestMapOfPolymorphicStructMethodReply_t _reply) = 0;
    /// This is the method that will be called on remote calls on the method TestStructWithPolymorphicMemberMethod.
    virtual void TestStructWithPolymorphicMemberMethod(const std::shared_ptr<CommonAPI::ClientId> _client, ::commonapi::tests::DerivedTypeCollection::StructWithPolymorphicMember _inStruct, TestStructWithPolymorphicMemberMethodReply_t _reply) = 0;
    /// This is the method that will be called on remote calls on the method TestStructWithEnumKeyMapMember.
    virtual void TestStructWithEnumKeyMapMember(const std::shared_ptr<CommonAPI::ClientId> _client, ::commonapi::tests::DerivedTypeCollection::StructWithEnumKeyMap _inStruct, TestStructWithEnumKeyMapMemberReply_t _reply) = 0;
    /// Sends a broadcast event for TestPredefinedTypeBroadcast.
    virtual void fireTestPredefinedTypeBroadcastEvent(const uint32_t &_uint32Value, const std::string &_stringValue) = 0;
    /**
     * Sends a selective broadcast event for TestSelectiveBroadcast to the given ClientIds.
     * The ClientIds must all be out of the set of subscribed clients.
     * If no ClientIds are given, the selective broadcast is sent to all subscribed clients.
     */
    virtual void fireTestSelectiveBroadcastSelective(const std::shared_ptr<CommonAPI::ClientIdList> _receivers = nullptr) = 0;
    /// retreives the list of all subscribed clients for TestSelectiveBroadcast
    virtual std::shared_ptr<CommonAPI::ClientIdList> const getSubscribersForTestSelectiveBroadcastSelective() = 0;
    /// Hook method for reacting on new subscriptions or removed subscriptions respectively for selective broadcasts.
    virtual void onTestSelectiveBroadcastSelectiveSubscriptionChanged(const std::shared_ptr<CommonAPI::ClientId> _client, const CommonAPI::SelectiveBroadcastSubscriptionEvent _event) = 0;
    /// Hook method for reacting accepting or denying new subscriptions 
    virtual bool onTestSelectiveBroadcastSelectiveSubscriptionRequested(const std::shared_ptr<CommonAPI::ClientId> _client) = 0;
    /**
     * Sends a selective broadcast event for TestBroadcastWithOutArgs to the given ClientIds.
     * The ClientIds must all be out of the set of subscribed clients.
     * If no ClientIds are given, the selective broadcast is sent to all subscribed clients.
     */
    virtual void fireTestBroadcastWithOutArgsSelective(const uint32_t &_uint32Value, const std::string &_stringValue, const std::shared_ptr<CommonAPI::ClientIdList> _receivers = nullptr) = 0;
    /// retreives the list of all subscribed clients for TestBroadcastWithOutArgs
    virtual std::shared_ptr<CommonAPI::ClientIdList> const getSubscribersForTestBroadcastWithOutArgsSelective() = 0;
    /// Hook method for reacting on new subscriptions or removed subscriptions respectively for selective broadcasts.
    virtual void onTestBroadcastWithOutArgsSelectiveSubscriptionChanged(const std::shared_ptr<CommonAPI::ClientId> _client, const CommonAPI::SelectiveBroadcastSubscriptionEvent _event) = 0;
    /// Hook method for reacting accepting or denying new subscriptions 
    virtual bool onTestBroadcastWithOutArgsSelectiveSubscriptionRequested(const std::shared_ptr<CommonAPI::ClientId> _client) = 0;

    using CommonAPI::Stub<TestInterfaceStubAdapter, TestInterfaceStubRemoteEvent>::initStubAdapter;
    typedef CommonAPI::Stub<TestInterfaceStubAdapter, TestInterfaceStubRemoteEvent>::StubAdapterType StubAdapterType;
    typedef CommonAPI::Stub<TestInterfaceStubAdapter, TestInterfaceStubRemoteEvent>::RemoteEventHandlerType RemoteEventHandlerType;
    typedef TestInterfaceStubRemoteEvent RemoteEventType;
    typedef TestInterface StubInterface;
};

} // namespace tests
} // namespace commonapi
} // namespace v1


// Compatibility
namespace v1_0 = v1;

#endif // V1_COMMONAPI_TESTS_Test_Interface_STUB_HPP_
