#include <FreeRTOS.h>
#include <semphr.h>
#include <SparkFun_u-blox_GNSS_v3.h>

class SFE_UBLOX_GNSS_FREERTOS : public SFE_UBLOX_GNSS
{
    private:
        SemaphoreHandle_t xMutex = NULL;
    
    protected:
        bool createLock(void) override;
        bool lock(void) override;
        void unlock(void) override;
        void deleteLock(void) override;

    public:
        bool publicLockI2C(void);
        void publicUnlockI2C(void);
};