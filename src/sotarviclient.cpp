#include "sotarviclient.h"


#include <iostream>
#include <stdexcept>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/make_shared.hpp>

#include "logger.h"
#include "types.h"


void sotaNotify(int fd, void *service_data, const char *parameters){
    (void)fd;
    SotaRVIClient* client = *(SotaRVIClient**)service_data;
    (void)client;
    Json::Reader reader;
    Json::Value json;
    reader.parse(parameters, json);
    std::cout << json;
    client->sendEvent(boost::make_shared<event::UpdateAvailable>(event::UpdateAvailable(data::UpdateAvailable::fromJson(json[0]["update_available"]))));
    client->downloadUpdate(json[0]["update_available"]["update_id"].asString());
    std::cout << "-----------\n";
}

void sotaStart(int fd, void *service_data, const char *parameters){
    (void)fd;
    SotaRVIClient* client = *(SotaRVIClient**)service_data;
    (void)client;
    std::cout << parameters;
    LOGGER_LOG(LVL_info, "rvi callback called");
}

void sotaChunk(int fd, void *service_data, const char *parameters){
    (void)fd;
    SotaRVIClient* client = *(SotaRVIClient**)service_data;
    (void)client;
    std::cout << parameters;
    LOGGER_LOG(LVL_info, "rvi callback called");
}

void sotaFinish(int fd, void *service_data, const char *parameters){
    (void)fd;
    SotaRVIClient* client = *(SotaRVIClient**)service_data;
    (void)client;
    (void)parameters;
    LOGGER_LOG(LVL_info, "rvi callback called");
}

void sotaGetpackages(int fd, void *service_data, const char *parameters){
    (void)fd;
    SotaRVIClient* client = *(SotaRVIClient**)service_data;
    (void)client;
    (void)parameters;
    LOGGER_LOG(LVL_info, "rvi callback called");
}

void sotaAbort(int fd, void *service_data, const char *parameters){
    (void)fd;
    SotaRVIClient* client = *(SotaRVIClient**)service_data;
    (void)client;
    (void)parameters;
    LOGGER_LOG(LVL_info, "rvi callback called");
}

SotaRVIClient::SotaRVIClient(const RviConfig &config_in, event::Channel * events_channel_in): config(config_in), events_channel(events_channel_in)
{
    std::string client_config("./config/"+config.client_config);
    rvi = rviInit(const_cast<char*>(client_config.c_str()));
    if( !rvi ) {
        throw std::runtime_error("cannot initialize rvi with config file " + client_config);
    }
    connection = rviConnect(rvi, config.node_host.c_str(), config.node_port.c_str());

    if(connection <= 0) {
        throw std::runtime_error("cannot connect to rvi node");
    }
    registerService("notify", "sota/notify", sotaNotify);
    registerService("start", "sota/start", sotaStart);
    registerService("chunk", "sota/chunk", sotaChunk);
    registerService("finish", "sota/finish", sotaFinish);
    registerService("getpackages", "sota/getpackages", sotaGetpackages);
    registerService("abort", "sota/abort", sotaAbort);
    LOGGER_LOG(LVL_info, "rvi services registered");
    
}

void SotaRVIClient::sendEvent(const boost::shared_ptr<event::BaseEvent> &event){
    *events_channel << event;
}

void SotaRVIClient::run(){
    while (rviProcessInput(rvi, &connection, 1) == 0){
        
    }
}

void SotaRVIClient::registerService(const std::string &service_key, const std::string &service_name, TRviCallback callback){
    SotaRVIClient ** this_pointer = new SotaRVIClient*(this);
    int stat = rviRegisterService(rvi, service_name.c_str(), callback, this_pointer, sizeof(this_pointer));
    if(stat) {
        throw std::runtime_error("unable to register " + service_name);
    }
    services[service_key] = "genivi.org/device/64285c3c-ca04-4d58-b8d7-f0e002483647/" + service_name;
    
}

void SotaRVIClient::downloadUpdate(const data::UpdateRequestId &update_id){
    Json::Value value;
    value["device"] = "64285c3c-ca04-4d58-b8d7-f0e002483647";
    value["update_id"] = update_id;
    value["services"] = services;
    Json::Value params(Json::arrayValue);
    params.append(value);
    std::cout << Json::FastWriter().write(params);
    int stat = rviInvokeService(rvi, "genivi.org/backend/sota/start", Json::FastWriter().write(params).c_str());
    std::cout <<  stat;
}





