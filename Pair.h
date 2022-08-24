//
// Created by User on 5/19/2021.
//

/*
 * Η κλάση Pair υλοποιεί ένα ζεύγος τιμών για την αποθήκευση στοιχείων της δομής του πίνακα κατακερματισμού.
 */

#ifndef DATASTRUCTURES_PAIR_H
#define DATASTRUCTURES_PAIR_H
#include <iostream>

using namespace std;

/*
 * unsigned long key: Ακέραιος αριθμός στον οποίο αποθηκεύεται η τιμή του μοναδικού κλειδιού της συμβολοσειράς word.
 * string word: Συμβολειρά στην οποία αποθηκεύεται μία λέξη κατά την εισαγωγή.
 * int numofwords: Ακέραια μεταβλητή αποθήκευσης συνολικού αριθμού εισαγωγής της λέξης word.
 * void setkey(unsigned long key): Συνάρτηση που θέτει την τιμή του key.
 * void setword(string word): Συνάρτηση που θέτει την τιμή του word
 * unsigned long getkey(): Συνάρτηση που επιστρέφει την τιμή του key.
 * string getword(): Συνάρτηση που επιστρέφει την τιμή του word.
 * int getnumofwords(): Συνάρτηση που επιστρέφει την τιμή του numofwords.
 * Pair(): Κατασκευαστής.
 */
class Pair{
public:
    unsigned long key;
    string word;
    int numofwords = 0;
    void setkey(unsigned long key){ this->key = key; }
    void setword(string word){ this->word = word; }
    unsigned long getkey(){return key;}
    string getword(){return word;}
    int getnumofwords(){return numofwords;}
    Pair(){
        this->word = "";
    }
};

#endif //DATASTRUCTURES_PAIR_H
