//
// Berk Temel 22002675
//

#ifndef HW3_FLOWER_H
#define HW3_FLOWER_H
#include <string>
#include <iostream>
using namespace std;

class Flower{
public:
    Flower();
    Flower(string flowerName);
    Flower(const Flower& aFlower);
    ~Flower();
    bool isEmpty() const;
    int getLength() const ;
    bool add(string feature);
    bool remove(string feature);
    string printFlower() const;
    bool featureExists(string feature);
    string getName() const;
    void deleteAllFeatures();
    void deleteAndPrint();
private:
    struct FeatureNode{
        string feature;
        FeatureNode* next;
    };
    int size;
    string flowerName;
    FeatureNode *head;
};


#endif //HW3_FLOWER_H
