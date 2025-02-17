#include <FreeRTOS.h>
#include <semphr.h>
#include <u-blox_GNSS_FREERTOS.h>

bool SFE_UBLOX_GNSS_FREERTOS::createLock(void)
{
    xMutex = xSemaphoreCreateMutex();
    return (xMutex != NULL);
}

bool SFE_UBLOX_GNSS_FREERTOS::lock(void)
{
    if (xMutex != NULL)
    {
        return (xSemaphoreTake(xMutex, portMAX_DELAY) == pdPASS);
    }
    return false;
}

void SFE_UBLOX_GNSS_FREERTOS::unlock(void)
{
    if (xMutex != NULL)
    {
        configASSERT(xSemaphoreGive(xMutex) == pdPASS);
    }
}

void SFE_UBLOX_GNSS_FREERTOS::deleteLock(void)
{
    if (xMutex != NULL)
    {
        vSemaphoreDelete(xMutex);
        xMutex = NULL;
    }
}

bool SFE_UBLOX_GNSS_FREERTOS::publicLockI2C(void)
{
    return lock();
}

void SFE_UBLOX_GNSS_FREERTOS::publicUnlockI2C(void)
{
    return unlock();
}