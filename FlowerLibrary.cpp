//
// Berk Temel 22002675
//

#include "FlowerLibrary.h"
FlowerLibrary::FlowerLibrary() {

}

FlowerLibrary::~FlowerLibrary() {

}

void FlowerLibrary::addFlower(string name) {
    toLowerCase(name);
    bool isAdded = flowers.add(name);
    if(isAdded) {
        cout << name << " has been added into the library." << endl;
    } else {
        cout << name << " cannot be added into the library because it already exists." << endl;
    }
}

void FlowerLibrary::removeFlower(string name) {
    toLowerCase(name);
    bool isRemoved = flowers.remove(name);
    if(isRemoved) {
        cout << name << " has been removed from the library." << endl;
    } else {
        cout << name << " cannot be removed because it's not in the library." << endl;
    }
}

void FlowerLibrary::listFlowers() const {
    flowers.printList();
}

void FlowerLibrary::listFeatures(string name) const {
    toLowerCase(name);
    flowers.printAFlower(name);
}

void FlowerLibrary::addFeature(string name, string feature) {
    toLowerCase(name);
    toLowerCase(feature);
    bool added = flowers.addFeature(name, feature);
    if(added)
        cout << feature << " is added into " << name << endl;
    else{
        if(!flowers.nameExists(name))
            cout << name << " isn't found in the library." << endl;
        else
            cout << feature << " already exists in " << name << endl;
    }
}

void FlowerLibrary::removeFeature(string name, string feature) {
    toLowerCase(name);
    toLowerCase(feature);
    bool removed = flowers.removeFeature(name, feature);
    if(removed)
        cout << feature << " is removed from " << name << endl;
    else {
        if(!flowers.nameExists(name))
            cout << name << " isn't found in the library." << endl;
        else
            cout << feature << " doesn't exists in " << name << endl;
    }
}

void FlowerLibrary::findFlowers(string feature) const {
    toLowerCase(feature);
    flowers.findFeatures(feature);
}

void FlowerLibrary::toLowerCase(string &str) const {
    for(int i = 0; i < str.size(); i++) {
        if(str.at(i) <= 90 && str.at(i) >= 65 )
            str.at(i) = str.at(i) + 32;
    }
}
