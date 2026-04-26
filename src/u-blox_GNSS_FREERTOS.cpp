#include <u-blox_GNSS_FREERTOS.h>
#include <i2c.h>

bool SFE_UBLOX_GNSS_FREERTOS::lock(void)
{
    return i2c_lock();
}

void SFE_UBLOX_GNSS_FREERTOS::unlock(void)
{
    i2c_unlock();
}