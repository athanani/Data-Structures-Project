//
// Created by User on 4/6/2021.
//

#ifndef DATASTRUCTURES_UNORDERED_ARRAY_H
#define DATASTRUCTURES_UNORDERED_ARRAY_H

#include <iostream>
using namespace std;

/*
 * Unordered_Array(): Κατασκευαστής.
 * ~Unordered_Array(): Καταστροφέας.
 * void Insert(string): Συνάρτηση εισαγωγής συμβολοσειράς στην δομή.
 * void Delete(string): Συνάρτηση διαγραφής δυμβολοσειράς από την δομή.
 * int find (string, int): Συνάρτηση αναζήτησης λέξης, επιστρέφει 1 αν βρει την συμβολοσειρά που δέχεται ως όρισμα ή 0 αν δεν την βρει.
 * int getsize(): Συνάρτηση που επιστρέφει τον συνολικό αριθμό ξεχωριστών λέξεων.
 * int getnumofwords(int value): Συνάρτηση που επιστρέφει το στοιχείο του πίνακα numofwords στη θέση value.
 * string &getarr(int value): Συνάρτηση που επιστρέφει την συμβολοσειρά του πίνακα arr στη θέση value.
 *
 * string *arr: Δυναμικός πίνακας συμβολοσειρών, στον οποίο αποθηκεύονται οι λέξεις κατά την εισαγωγή.
 * int *numofwords: Δυναμικός πίνακας ακεραίων, στον οποίο αποθηκεύονται ο αριθμός εμφανίσεων κάθε λέξης.
 * int size: Ακέραια μεταβλητή που χρησιμοποιείται για το μέγεθος των πινάκων.
 * int pos: Ακέραια μεταβλητή που δηλώνει των αριθμό μοναδικών λέξεων στην δομή.
 */
class Unordered_Array {
public:
    Unordered_Array();
    ~Unordered_Array();
    void Insert(string);
    void Delete(string);
    int find (string, int);
    int getsize(){return pos;}
    int getnumofwords(int value){ return numofwords[value]; }
    string &getarr(int value){ return arr[value]; }
private:
    string *arr;
    int *numofwords;
    int size;
    int pos;
};



#endif //DATASTRUCTURES_UNORDERED_ARRAY_H
