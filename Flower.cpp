//
// Berk Temel 22002675
//

#include "Flower.h"
Flower::Flower() {
    flowerName = "";
    size = 0;
    head = NULL;
}

Flower::Flower(string flowerName) {
    this->flowerName = flowerName;
    size = 0;
    head = NULL;
}

Flower::Flower(const Flower &aFlower) {
    this->flowerName = aFlower.flowerName;
    this->size = aFlower.size;
    this->head = aFlower.head;
}

Flower::~Flower() {

}

bool Flower::isEmpty() const {
    return size == 0;
}

int Flower::getLength() const {
    return size;
}

bool Flower::add(string feature) {
    if(featureExists(feature)) {
        return false;
    } else {
        FeatureNode* newNode = new FeatureNode();
        if (isEmpty() || (feature < head->feature)) {
            newNode->feature = feature;
            newNode->next = head;
            head = newNode;
        } else {
            FeatureNode *current;
            FeatureNode *prevNode;
            prevNode = head;
            current = head->next;
            bool featureAdded = false;

            while (current != NULL) {
                if (feature < current->feature) {
                    newNode->feature = feature;
                    newNode->next = prevNode->next;
                    prevNode->next = newNode;
                    featureAdded = true;
                }
                prevNode = current;
                current = current->next;
            }
            if(!featureAdded) {
                newNode->feature = feature;
                newNode->next = current;
                prevNode->next = newNode;
            }
        }
        size++;
        return true;
    }
}

bool Flower::remove(string feature) {
    if(!(featureExists(feature))) {
        return false;
    } else {
        FeatureNode* current = head;
        if(head->feature == feature) {
            head = current->next;
            delete current;
        } else {
            FeatureNode* prev;
            current = head->next;
            prev = head;
            while (current != NULL && current->feature != feature) {
                prev = current;
                current = current->next;
            }
            prev->next = current->next;
            delete current;
        }
        size--;
        return true;
    }
}

string Flower::printFlower() const {
    FeatureNode* current;
    current = head;
    string features = flowerName + ": ";
    if(isEmpty()) {
        features += "No feature";
    } else {
        while (current != NULL) {
            if (current->next != NULL)
                features += current->feature + ", ";
            else
                features += current->feature;
            current = current->next;
        }
    }
    return features;
}

bool Flower::featureExists(string feature) {
    FeatureNode* current = head;
    while (current != NULL) {
        if(current->feature == feature)
            return true;
        current = current->next;
    }
    return false;
}

string Flower::getName() const {
    return flowerName;
}

void Flower::deleteAllFeatures() {
    if(!isEmpty()) {
        FeatureNode *current = head;
        while (current != NULL) {
            FeatureNode *next = current->next;
            delete current;
            current = next;
        }
    }
    head = NULL;
}

void Flower::deleteAndPrint() {
    if(!isEmpty()) {
        FeatureNode *current = head;
        while (current != NULL) {
            FeatureNode *next = current->next;
            cout << current->feature << " is removed from " << flowerName << endl;
            delete current;
            current = next;
        }
    }
    head = NULL;
}


