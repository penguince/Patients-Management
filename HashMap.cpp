#include "HashMap.hpp"

template<typename T>
int HashMap<T>::getIntFromString(std::string name) {
    int finalValue = 0;
    int value = 0;
    for(int i = 0; i < name.length(); i++) {
        value = static_cast<int>(name[i]) + 127;
        value *= value;
        finalValue += value >> 2;
        finalValue = finalValue << 2;
        value = 0;
    }
    return finalValue % 1000;
}

template<typename T>
HashMap<T>::HashMap() {
    hashmaparr.resize(1000, nullptr);
}

template<typename T>
T* HashMap<T>::get(std::string key) {
    int index = getIntFromString(key);
    return hashmaparr[index];
}

template<typename T>
void HashMap<T>::insert(std::string key, T* value) {
    int index = getIntFromString(key);
    hashmaparr[index] = value;
}

template<typename T>
void HashMap<T>::remove(std::string key) {
    int index = getIntFromString(key);
    hashmaparr[index] = nullptr;
}

template class HashMap<Patients>;
