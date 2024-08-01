#ifndef SPIFFSStorage_HPP
#define SPIFFSStorage_HPP
#include"..\lib\Domaine\Services\IFile\Ifile.hpp"
class SPIFFSStorage : public IFile{
public:
    void savePrayerTimes(const PrayerTimes& prayerTimes) override;
    PrayerTimes loadPrayerTimes() override;
};

#endif // SPIFFS_HPP
