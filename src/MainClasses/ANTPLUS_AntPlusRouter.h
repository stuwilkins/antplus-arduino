#ifndef ANTPLUS_ANTPLUSROUTER_h
#define ANTPLUS_ANTPLUSROUTER_h

#include <ANTPLUS_Defines.h>
#include <BaseClasses/ANTPLUS_BaseProfile.h>

#include "ANT.h"

// Handle circular dependency
class BaseProfile;

class AntPlusRouter {
public:
    AntPlusRouter();
    AntPlusRouter(BaseAntWithCallbacks* driver);
    AntPlusRouter(BaseAntWithCallbacks* driver, const uint8_t* key);
    uint8_t setDriver(BaseAntWithCallbacks* driver);
    void setAntPlusNetworkKey(const uint8_t* key);
    void setProfile(uint8_t channel, BaseProfile* profile);
    void send(AntRequest& msg);
    uint8_t getMaxChannels();
    void loop();
    void reset();
    void resetRadio(uint8_t waitForStartup);
private:
    void pushNetworkKey();
    // Driver callbacks
    void onPacketError(uint8_t error, uintptr_t data);
    void onAcknowledgedData(AcknowledgedData& msg, uintptr_t data);
    void onAdvancedBurstData(AdvancedBurstData& msg, uintptr_t data);
    void onBroadcastData(BroadcastData& msg, uintptr_t data);
    void onBurstTransferData(BurstTransferData& msg, uintptr_t data);
    void onAdvancedBurstCapabilitiesConfiguration(AdvancedBurstCapabilitiesConfiguration& msg, uintptr_t data);
    void onAntVersion(AntVersion& msg, uintptr_t data);
    void onCapabilities(Capabilities& msg, uintptr_t data);
    void onChannelEventResponse(ChannelEventResponse& msg, uintptr_t data);
    void onChannelIdResponse(ChannelIdResponse& msg, uintptr_t data);
    void onChannelStatus(ChannelStatus& msg, uintptr_t data);
    void onEncryptionModeParameters(EncryptionModeParameters& msg, uintptr_t data);
    void onEventFilter(EventFilter& msg, uintptr_t data);
    void onSelectiveDataUpdateMaskSetting(SelectiveDataUpdateMaskSetting& msg, uintptr_t data);
    void onStartUpMessage(StartUpMessage& msg, uintptr_t data);

    BaseAntWithCallbacks* _ant = NULL;
    BaseProfile* _profiles[ANTPLUS_MAX_CHANNELS_POSSIBLE]; // Might be less, need to check on startup
    uint8_t _maxChannels;
    const uint8_t* _networkKey = NULL;
    uint8_t _radioStarted = ANTPLUS_DRIVER_STATE_UNKNOWN;
};

#endif // ANTPLUS_ANTPLUSROUTER_h