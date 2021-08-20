#pragma once

#include <string>

const int total_dinos = 8;

enum class DinoId {
    velocirraptor,      // 0
    estegosaurio,       // 1
    tiranosaurio,       // 2
    procompsagnatus,    // 3
    triceratops,        // 4
    paquicefalosaurio,  // 5
    parasaurolofus,     // 6
    pteranodon          // 7
};

class DinoSet {

public:

    void add(DinoId id)
    {
        int index = static_cast<int>(id);
        _dino[index] = true;
    }

    std::string to_string() const
    {
        std::string result = "";
        for (int i = 0; i < total_dinos; ++i) {
            if (_dino[i]) {
                result += "1 ";
            } else {
                result += "0 ";
            }
        }
        return result;
    }

    bool contains(DinoId id) const
    {
        int index = static_cast<int>(id);
        return _dino[index];
    }

    int size() const
    {
        int result = 0;
        for (int i = 0; i < total_dinos; ++i) {
            DinoId id = static_cast<DinoId>(i);
            if (contains(id)) {
                ++result;
            }
        }
        return result;
    }

    DinoSet operator+(const DinoSet& other) const
    {
        DinoSet result;
        for (int i = 0; i < total_dinos; ++i) {
            DinoId id = static_cast<DinoId>(i);
            if (contains(id) or other.contains(id)) {
                result.add(id);
            }
        }
        return result;
    }

private:

    bool _dino[total_dinos] {};
};
