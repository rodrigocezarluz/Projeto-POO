#include "LocalizacaoGeografica.h"
#include <iostream>

LocalizacaoGeografica::LocalizacaoGeografica() {}

LocalizacaoGeografica::LocalizacaoGeografica(double latitude, double longitude) : latitude(latitude),
                                                                                  longitude(longitude) {}

double LocalizacaoGeografica::getLatitude() {
    return latitude;
}

void LocalizacaoGeografica::setLatitude(double latitude) {
    this->latitude = latitude;
}

double LocalizacaoGeografica::getLongitude() {
    return longitude;
}

void LocalizacaoGeografica::setLongitude(double longitude) {
    this->longitude = longitude;
}
