//
// Berk Temel 22002675
//

#ifndef HW3_FLOWERLIST_H
#define HW3_FLOWERLIST_H


#include "Flower.h"
class FlowerList{
public:
    FlowerList();
    FlowerList(const FlowerList& aList);
    ~FlowerList();
    bool isEmpty() const;
    int getLength() const;
    bool retrieve(string flowerName, Flower& flower) const;
    bool add(string flowerName);
    bool remove(string flowerName);
    bool nameExists(string flowerName) const;
    void printList() const;
    void printAFlower(string flowerName) const;
    void findFeatures(string feature) const;
    bool addFeature(string name, string feature);
    bool removeFeature(string name, string feature);
    Flower getFlower(string flowerName) const;
    void deleteAllFlowers();
private:
    struct FlowerNode{
        Flower f;
        FlowerNode* next;
    };
    int size;
    FlowerNode* head;
};


#endif //HW3_FLOWERLIST_H
