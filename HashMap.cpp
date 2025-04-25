#include "HashMap.hpp"

static int HashMap::getIntFromString(std::string name) {
  int finalValue = 0;
  int value = 0;
  for(int i = 0; i < name.length(); i++) {
    value = static_cast<int>(name[i]) + 127;
    value *= value;
    finalValue+=value>>2;
    finalValue = finalValue<<2;
    value=0;
  }
  return finalValue%1000;
}

template<typename T>
HashMap<T>::HashMap() {
  hashmaparr(1000, nullptr);
}

template<typename T>
T* HashMap<T>::get(std::string key) {
  return this.hashmaparr[getIntFromString(key)];
}

template<typename T>
void HashMap<T>::insert(std::string key, T* value) {
  int index = getIntFromString(key);
  this.hashmaparr[index] = value;
}

template<typename T>
void HashMap<T>::remove(std::string key) {
  int index = getIntFromString(key);
  this.hashmaparr.erase(index);
}



int main() {
  std::string name = "Keyshia";

  Hash* hash = new Hash();

  std::cout << hash->getIntFromString(name) << std::endl;
  name = "eKyshia";
  std::cout << hash->getIntFromString(name) << std::endl;
}
