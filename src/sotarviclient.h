#ifndef SOTARVICLIENT_H
#define SOTARVICLIENT_H
#include "rvi.h"
#include <string>
#include <json/json.h>


#include "config.h"
#include "events.h"



class SotaRVIClient
{
public:
    SotaRVIClient(const RviConfig& config, event::Channel * events_channel_in);
    void run();
    void sendEvent(const boost::shared_ptr<event::BaseEvent> &event);
    void downloadUpdate(const data::UpdateRequestId &update_id);

private:
    TRviHandle rvi;
    RviConfig config;
    void registerService(const std::string &service_key, const std::string &service_name, TRviCallback callback);
    int connection;
    event::Channel * events_channel;
    Json::Value services;
    

};

#endif // SOTARVICLIENT_H
