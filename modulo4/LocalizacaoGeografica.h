#ifndef LOCALIZACAOGEOGRAFICA_H
#define LOCALIZACAOGEOGRAFICA_H

class LocalizacaoGeografica {
private:
    double latitude;
    double longitude;

public:
    LocalizacaoGeografica();

    LocalizacaoGeografica(double latitude, double longitude);

    double getLatitude();

    void setLatitude(double latitude);

    double getLongitude();

    void setLongitude(double longitude);

};
#endif
