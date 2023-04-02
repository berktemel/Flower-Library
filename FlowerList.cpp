//
// Berk Temel 22002675
//

#include "FlowerList.h"

FlowerList::FlowerList() {
    size = 0;
    head = NULL;
}

FlowerList::FlowerList(const FlowerList &aList) {
    this->size = aList.size;
    this->head = aList.head;
}

FlowerList::~FlowerList() {
    deleteAllFlowers();
}

bool FlowerList::isEmpty() const {
    return size == 0;
}

int FlowerList::getLength() const {
    return size;
}

bool FlowerList::retrieve(string flowerName, Flower& flower) const {
    if(!(nameExists(flowerName))) {
        return false;
    } else {
        FlowerNode* current;
        current = head;
        while (current != NULL && current->f.getName() != flowerName) {
            current = current->next;
        }
        flower = current->f;
        return true;
    }
}

bool FlowerList::add(string flowerName) {
    if(nameExists(flowerName)) {
        return false;
    } else {
        FlowerNode* newNode = new FlowerNode();
        Flower flower(flowerName);
        if (isEmpty() || (flowerName < head->f.getName())) {
            newNode->f = flower;
            newNode->next = head;
            head = newNode;
        } else {
            FlowerNode *current;
            FlowerNode *prevNode;
            prevNode = head;
            current = head->next;

            while (current != NULL && current->f.getName() < flowerName) {
                prevNode = current;
                current = current->next;
            }
            newNode->f = flower;
            if(current == NULL)
                newNode->next = NULL;
            else
                newNode->next = prevNode->next;
            prevNode->next = newNode;
        }
        size++;
        return true;
    }
}

bool FlowerList::remove(string flowerName) {
    if(!(nameExists(flowerName))) {
        return false;
    } else {
        FlowerNode* current = head;
        if(head->f.getName() == flowerName) {
            head = current->next;
            current->f.deleteAndPrint();
            delete current;
        } else {
            FlowerNode* prev;
            current = head->next;
            prev = head;
            while (current != NULL && current->f.getName() != flowerName) {
                prev = current;
                current = current->next;
            }
            prev->next = current->next;
            current->f.deleteAndPrint();
            delete current;
        }
        size--;
        return true;
    }
}

bool FlowerList::nameExists(string flowerName) const {
    FlowerNode* current;
    current = head;
    bool nameExists = false;
    while (current != NULL) {
        if(current->f.getName() == flowerName)
            nameExists = true;
        current = current->next;
    }
    return nameExists;
}

void FlowerList::printList() const {

    if(isEmpty()) {
        cout << "Library is empty." << endl;
    } else {
        FlowerNode *current;
        current = head;

        while (current != NULL) {
            cout << current->f.printFlower() << endl;
            current = current->next;
        }
    }
}

void FlowerList::printAFlower(string flowerName) const {
    if(nameExists(flowerName)) {
        Flower f = getFlower(flowerName);
        cout << f.printFlower() << endl;
    } else {
        cout << flowerName << " isn't found in library" << endl;
    }
}

void FlowerList::findFeatures(string feature) const {
    FlowerNode* current;
    current = head;

    int flowerCount = 0;
    while(current != NULL) {
        if(current->f.featureExists(feature))
            flowerCount++;
        current = current->next;
    }

    cout << feature << " flowers: ";
    current = head;
    int counterForComma = 0;
    while(current != NULL) {
        if(current->f.featureExists(feature)) {
            if(counterForComma != flowerCount - 1)
                cout << current->f.getName() << ", ";
            else
                cout << current->f.getName() << endl;
            counterForComma++;
        }
        current = current->next;
    }
    if(flowerCount == 0)
        cout << "there is no such flower" << endl;
}

Flower FlowerList::getFlower(string flowerName) const {
    FlowerNode *current;
    current = head;
    while (current != NULL && current->f.getName() != flowerName) {
        current = current->next;
    }
    return current->f;

}

bool FlowerList::addFeature(string name, string feature) {
    bool added = false;
    FlowerNode *current;
    current = head;
    while (current != NULL && current->f.getName() != name) {
        current = current->next;
    }

    bool retrieved = retrieve(name, current->f);
    if(retrieved) {
        added = current->f.add(feature);
    }
    return added;
}

bool FlowerList::removeFeature(string name, string feature) {
    bool removed = false;
    FlowerNode *current;
    current = head;
    while (current != NULL && current->f.getName() != name) {
        current = current->next;
    }

    bool retrieved = retrieve(name, current->f);
    if(retrieved) {
        removed = current->f.remove(feature);
    }
    return removed;
}

void FlowerList::deleteAllFlowers() {
    if(!isEmpty()) {
        FlowerNode *current = head;
        while (current != NULL) {
            FlowerNode *next = current->next;
            current->f.deleteAllFeatures();
            delete current;
            current = next;
        }
    }
    head = NULL;
}
