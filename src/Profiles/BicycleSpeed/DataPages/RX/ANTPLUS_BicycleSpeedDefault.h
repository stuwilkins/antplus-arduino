#ifndef ANTPLUS_BICYCLESPEEDDEFAULT_h
#define ANTPLUS_BICYCLESPEEDDEFAULT_h

#include <Profiles/BicycleSpeed/DataPages/Base/ANTPLUS_BicycleSpeedBaseMainDataPage.h>

class BicycleSpeedDefault : public BicycleSpeedBaseMainDataPage {
public:
    BicycleSpeedDefault(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLESPEEDDEFAULT_h
