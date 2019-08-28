#ifndef ANTPLUS_PROFILESHIFTINGSHIFTER_h
#define ANTPLUS_PROFILESHIFTINGSHIFTER_h

#include <BaseClasses/ANTPLUS_BaseMasterProfile.h>
#include <Profiles/Shifting/DataPages/ANTPLUS_ProfileShiftingDataPages.h>
#include <Profiles/Shifting/ANTPLUS_ShiftingPrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

class ProfileShiftingShifter : public BaseMasterProfile {
public:
    ProfileShiftingShifter(uint16_t deviceNumber, uint8_t transmissionType = ANTPLUS_SHIFTING_SHIFTER_TRANSMISSIONTYPE);

    /**
     * Register callback to populate default data messages (Datapage 1)
     */
    void createShiftingShiftSystemStatusMsg(void(*func)(ShiftingShiftSystemStatusMsg&, uintptr_t), uintptr_t data = 0) { _createShiftingShiftSystemStatusMsg.set(func, data); }
    /**
     * Register callback to populate multi component system manufacturer information data messages (Datapage 78)
     */
    void createMultiComponentSystemManufacturersInformationMsg(void(*func)(MultiComponentSystemManufacturersInformationMsg&, uintptr_t), uintptr_t data = 0) { _createMultiComponentSystemManufacturersInformationMsg.set(func, data); }
    /**
     * Register callback to populate multi component system product information data messages (Datapage 79)
     */
    void createMultiComponentSystemProductInformationMsg(void(*func)(MultiComponentSystemProductInformationMsg&, uintptr_t), uintptr_t data = 0) { _createMultiComponentSystemProductInformationMsg.set(func, data); }
    /**
     * Register callback to populate battery status data messages (Datapage 82)
     */
    void createBatteryStatusMsg(void(*func)(BatteryStatusMsg&, uintptr_t), uintptr_t data = 0) { _createBatteryStatusMsg.set(func, data); }
    /**
     * Register callback to handle incoming request dataPage. The profile will automatically
     * adjust the broadcast pattern, there is no need for you to do anything with this message.
     */
    void onRequestDataPage(void (*func)(RequestDataPage&, uintptr_t), uintptr_t data = 0) { _onRequestDataPage.set(func, data); }

protected:
    virtual void transmitNextDataPage();
    virtual bool isDataPageValid(uint8_t dataPage);
    void onAcknowledgedData(AcknowledgedData& msg);
    void onBroadcastData(BroadcastData& msg);

private:
    void transmitShiftingMainPageMsg();
    void transmitMultiComponentSystemManufacturersInformationMsg();
    void transmitMultiComponentSystemProductInformationMsg();
    void transmitBatteryStatusMsg();
    bool handleRequestDataPage(BaseDataPage<AcknowledgedData>& dataPage);

    void transmitBackgroundDataPage();
    void setChannelConfig();

    uint8_t _patternStep;
    uint8_t _backgroundStep;
    uint8_t _shiftCounter;

    Callback<ShiftingShiftSystemStatusMsg&> _createShiftingShiftSystemStatusMsg;
    Callback<MultiComponentSystemManufacturersInformationMsg&> _createMultiComponentSystemManufacturersInformationMsg;
    Callback<MultiComponentSystemProductInformationMsg&> _createMultiComponentSystemProductInformationMsg;
    Callback<BatteryStatusMsg&> _createBatteryStatusMsg;
    Callback<RequestDataPage&> _onRequestDataPage;
};

#endif // ANTPLUS_PROFILESHIFTINGSHIFTER_h