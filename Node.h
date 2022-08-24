//
// Created by User on 5/3/2021.
//

/*
 * Η κλάση Node υλοποιεί ένα κόμβο για την αποθήκευση στοιχείων των δομών υλοποίησης δέντρων.
 */

#ifndef DATASTRUCTURES_NODE_H
#define DATASTRUCTURES_NODE_H
#include <iostream>

using namespace std;

/*
 * string word: Συμβολειρά στην οποία αποθηκεύεται μία λέξη κατά την εισαγωγή.
 * Node *left: Κόμβος αποθήκευσης του αριστερού παιδιού.
 * Node *right: Κόμβος αποθήκευσης του δεξιού παιδιού.
 * int height: Ακέραια μεταβληρή αποθήκευσης ύψους του κόμβου στο δέντρο.
 * int numofwords: Ακέραια μεταβλητή αποθήκευσης συνολικού αριθμού εισαγωγής της λέξης word.
 * int geth(): Συνάρτηση που επιστρέφει το ύψος του κόμβου εάν δεν είναι κενός.
 */
class Node{
public:
    string word;
    Node *left = nullptr;
    Node *right = nullptr;
    int height = 0;
    int numofwords = 0;
    int geth(){
        if (this != nullptr){
            return height;
        } else {
            return -1;
        }
    }
};
#endif //DATASTRUCTURES_NODE_H
