#include <iostream>
#include <string>

class Erro {
  std::string tipo_erro;
  public:
    Erro(const std::string &tp) : tipo_erro(tp) {};
    void out() {std::cout << tipo_erro;};
};

