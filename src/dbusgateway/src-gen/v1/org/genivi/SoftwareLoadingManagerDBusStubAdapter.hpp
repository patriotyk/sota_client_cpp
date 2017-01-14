/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.dbus 3.1.5.v201601121430.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
/**
 * description: Software Loading Manager interfaace
 */
#ifndef V1_ORG_GENIVI_Software_Loading_Manager_DBUS_STUB_ADAPTER_HPP_
#define V1_ORG_GENIVI_Software_Loading_Manager_DBUS_STUB_ADAPTER_HPP_

#include <v1/org/genivi/SoftwareLoadingManagerStub.hpp>
#include "v1/org/genivi/SoftwareLoadingManagerDBusDeployment.hpp"        
#include <v1/org/genivi/SoftwareLoadingManagerDBusDeployment.hpp>        

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/DBus/DBusAddressTranslator.hpp>
#include <CommonAPI/DBus/DBusFactory.hpp>
#include <CommonAPI/DBus/DBusStubAdapterHelper.hpp>
#include <CommonAPI/DBus/DBusStubAdapter.hpp>
#include <CommonAPI/DBus/DBusDeployment.hpp>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1 {
namespace org {
namespace genivi {

typedef CommonAPI::DBus::DBusStubAdapterHelper<SoftwareLoadingManagerStub> SoftwareLoadingManagerDBusStubAdapterHelper;

class SoftwareLoadingManagerDBusStubAdapterInternal
    : public virtual SoftwareLoadingManagerStubAdapter,
      public SoftwareLoadingManagerDBusStubAdapterHelper
{
public:
    SoftwareLoadingManagerDBusStubAdapterInternal(
            const CommonAPI::DBus::DBusAddress &_address,
            const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection> &_connection,
            const std::shared_ptr<CommonAPI::StubBase> &_stub);

    ~SoftwareLoadingManagerDBusStubAdapterInternal();

    virtual bool hasFreedesktopProperties();

    inline static const char* getInterface() {
        return SoftwareLoadingManager::getInterface();
    }




    const SoftwareLoadingManagerDBusStubAdapterHelper::StubDispatcherTable& getStubDispatcherTable();
    const CommonAPI::DBus::StubAttributeTable& getStubAttributeTable();

    void deactivateManagedInstances();
    

static CommonAPI::DBus::DBusGetAttributeStubDispatcher<
        ::v1::org::genivi::SoftwareLoadingManagerStub,
        CommonAPI::Version
        > getSoftwareLoadingManagerInterfaceVersionStubDispatcher;



/**
 * description: Message, sent by SC or DiagTollMgr to SWLM, to inform that a new
    package is
 *   available for download.
	This is a fire and forget message. If the update is
 *   to be downloaded,
	org.genivi.swm.sc.initiate_download() will be called.
 */

static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    ::v1::org::genivi::SoftwareLoadingManagerStub,
    std::tuple<std::string, std::string, std::string, bool, uint64_t, std::string>,
    std::tuple<>,
    std::tuple<CommonAPI::DBus::StringDeployment, CommonAPI::DBus::StringDeployment, CommonAPI::DBus::StringDeployment, CommonAPI::EmptyDeployment, CommonAPI::EmptyDeployment, CommonAPI::DBus::StringDeployment>,
    std::tuple<>
    
    > updateAvailableStubDispatcher;
/**
 * description: Message, sent by SC to SWLM, to indicate
	that a download previously initiated
 *   by a
 */

static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    ::v1::org::genivi::SoftwareLoadingManagerStub,
    std::tuple<std::string, std::string>,
    std::tuple<>,
    std::tuple<CommonAPI::DBus::StringDeployment, CommonAPI::DBus::StringDeployment>,
    std::tuple<>
    
    > downloadCompleteStubDispatcher;
/**
 * description: Message, sent by HMI to SWLM to specify
	if a user confirmed or declined an
 *   update notified to HMI through a
	org.genivi.swm.hmi.updateNotificataion()
 *   call.
 */

static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    ::v1::org::genivi::SoftwareLoadingManagerStub,
    std::tuple<uint32_t, bool>,
    std::tuple<>,
    std::tuple<CommonAPI::EmptyDeployment, CommonAPI::EmptyDeployment>,
    std::tuple<>
    
    > updateConfirmationStubDispatcher;
/**
 * description: Abort a download in progress.
	Invoked by HMI in response to SWLM in response
 *   to a user abort.
	Will be forwarded by SWLM to SC in order to complete the
 *   abort.
 */

static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    ::v1::org::genivi::SoftwareLoadingManagerStub,
    std::tuple<std::string>,
    std::tuple<>,
    std::tuple<CommonAPI::DBus::StringDeployment>,
    std::tuple<>
    
    > abortDownloadStubDispatcher;
/**
 * description: Message, sent by other components to SWLM to report the result
	of an update
 *   operation initiated by a previous
	call to one of the following
 *   methods:
	org.genivi.swm.packmgr.installPackage()
	org.genivi.swm.packmgr.upgra
 *  dePackage()
	org.genivi.swm.packmgr.removePackage()
	org.genivi.swm.partmgr.crea
 *  teDiskPartition()
	org.genivi.swm.packmgr.deleteDiskPartition()
	org.genivi.swm.
 *  packmgr.resizeDiskPartition()
	org.genivi.swm.packmgr.writeDiskPartition()
	org.
 *  genivi.swm.packmgr.patchDiskPartition()
	org.genivi.swm.ml.flashModuleFirmware()
 */

static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    ::v1::org::genivi::SoftwareLoadingManagerStub,
    std::tuple<uint32_t, SoftwareLoadingManager::SWMResult, std::string>,
    std::tuple<>,
    std::tuple<CommonAPI::EmptyDeployment, CommonAPI::EmptyDeployment, CommonAPI::DBus::StringDeployment>,
    std::tuple<>
    
    > operationResultStubDispatcher;
/**
 * description: Message, sent by CEDM or SC to SWLM to retrieve a
	list of installed software
 *   packages and/or module
	firmware versions.
 */

static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    ::v1::org::genivi::SoftwareLoadingManagerStub,
    std::tuple<bool, bool>,
    std::tuple<std::vector<SoftwareLoadingManager::InstalledPackage>, std::vector<SoftwareLoadingManager::InstalledFirmware>>,
    std::tuple<CommonAPI::EmptyDeployment, CommonAPI::EmptyDeployment>,
    std::tuple<CommonAPI::DBus::ArrayDeployment<SoftwareLoadingManager_::InstalledPackageDeployment_t>, CommonAPI::DBus::ArrayDeployment<SoftwareLoadingManager_::InstalledFirmwareDeployment_t>>
    
    > getInstalledSoftwareStubDispatcher;




 protected:
    virtual const char* getMethodsDBusIntrospectionXmlData() const;

 private:
    SoftwareLoadingManagerDBusStubAdapterHelper::StubDispatcherTable stubDispatcherTable_;
    CommonAPI::DBus::StubAttributeTable stubAttributeTable_;
};

class SoftwareLoadingManagerDBusStubAdapter
    : public SoftwareLoadingManagerDBusStubAdapterInternal,
      public std::enable_shared_from_this<SoftwareLoadingManagerDBusStubAdapter> {
public:
    SoftwareLoadingManagerDBusStubAdapter(
    	const CommonAPI::DBus::DBusAddress &_address,
        const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection> &_connection,
        const std::shared_ptr<CommonAPI::StubBase> &_stub)
    	: CommonAPI::DBus::DBusStubAdapter(
    		_address, 
    		_connection,
            false),
          SoftwareLoadingManagerDBusStubAdapterInternal(
          	_address, 
          	_connection, 
          	_stub) { 
    }
};

} // namespace genivi
} // namespace org
} // namespace v1

#endif // V1_ORG_GENIVI_Software_Loading_Manager_DBUS_STUB_ADAPTER_HPP_
