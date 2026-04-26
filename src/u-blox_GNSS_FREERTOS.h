#ifndef GNSS_FREERTOS_H
#define GNSS_FREERTOS_H

#include <FreeRTOS.h>
#include <semphr.h>
#include <SparkFun_u-blox_GNSS_v3.h>

class SFE_UBLOX_GNSS_FREERTOS : public SFE_UBLOX_GNSS
{
    protected:
        bool lock(void) override;
        void unlock(void) override;
};

#endif // GNSS_FREERTOS_H