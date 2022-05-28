#ifndef LOCALIZACAOGEOGRAFICA_H
#define LOCALIZACAOGEOGRAFICA_H

class LocalizacaoGeografica {
private:
    double latitude, longitude;

public:
    LocalizacaoGeografica();

    double getLatitude() const;

    void setLatitude(const double &latitude);

    double getLongitude() const;

    void setLongitude(const double &longitude);

};
#endif
