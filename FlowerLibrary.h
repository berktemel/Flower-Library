//
// Berk Temel 22002675
//

#ifndef HW3_FLOWERLIBRARY_H
#define HW3_FLOWERLIBRARY_H


#include "FlowerList.h"
class FlowerLibrary{
public:
    FlowerLibrary();
    ~FlowerLibrary();
    void addFlower(string name);
    void removeFlower(string name);
    void listFlowers() const;
    void listFeatures(string name) const;
    void addFeature(string name,string feature);
    void removeFeature(string name, string feature);
    void findFlowers(string feature) const;
    void toLowerCase(string& str) const;
private:
    FlowerList flowers;
};

#endif //HW3_FLOWERLIBRARY_H
