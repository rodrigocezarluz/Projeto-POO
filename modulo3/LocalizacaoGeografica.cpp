#include "LocalizacaoGeografica.h"
#include <iostream>

LocalizacaoGeografica::LocalizacaoGeografica() {}

double LocalizacaoGeografica::getLatitude() const {
    return latitude;
}

void LocalizacaoGeografica::setLatitude(const double &latitude) {
    this->latitude = latitude;
}

double LocalizacaoGeografica::getLongitude() const {
    return longitude;
}

void LocalizacaoGeografica::setLongitude(const double &longitude) {
    this->longitude = longitude;
}
