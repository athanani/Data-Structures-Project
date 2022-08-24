//
// Created by User on 5/26/2021.
//

#ifndef DATASTRUCTURES_HASHTABLE_H
#define DATASTRUCTURES_HASHTABLE_H
#include <iostream>
#include "Pair.h"

/*
 * Hastable(): Κατασκευαστής.
 * ~HashTable(): Καταστροφέας.
 * unsigned long createkey(string): Συνάρτηση που δημιουργεί μοναδικό κλειδί με βάση την συμβολοσειρά in και το επιστρέφει
 * string getword(int value): Συνάρτηση που επιστρέφει την μεταβλητή word του πίνακα table στην θέση value.
 * void Insert(string): Συνάρτηση που εισάγει την συμβολοσειρά που δέχεται ως όρισμα στην δομή.
 * void insertfunction(string, Pair *, int): Συνάρτηση που εισάγει την συμβολοσειρά που δέχεται ως όρισμα στο δυναμικό
 * πίνακα που δέχεται ως όρισμα.
 * int find(string, int): Συνάρτηση που επιστρέφει 1 αν βρει την συμβολοσειρά που δέχεται ως όρισμα ή 0 αν δεν την βρει.
 * int getsize(): Επιστρέφει το μέγεθος του πίνακα table.
 * int gettotaladded(): Επιστρέφει το σύνολο μοναδικών λέξεων που έχουν εισαχθεί στην δομή.
 *
 * Pair *table: Δυναμικός πίνακας τύπου Pair, στον οποίο αποθηκεύονται οι λέξεις, το μοναδικό κλειδί τους και σύνολο
 * εμφανίσεων τους στοις μεταβλητές word, key και numofwords αντίστοιχα.
 * int size: Το μέγεθος του πίνακα Pair.
 * int totaladded: Το σύνολο μοναδικών λέξεων που έχουν εισαχθεί στην δομή.
 */
class HashTable {
public:
    HashTable();
    ~HashTable();
    unsigned long createkey(string);
    string getword(int value){return table[value].word;}
    void Insert(string);
    void insertfunction(string, Pair *, int);
    int find(string, int);
    int getsize(){return size;}
    int gettotaladded(){return totaladded;}
private:
    Pair *table;
    int size;
    int totaladded;
};


#endif //DATASTRUCTURES_HASHTABLE_H
