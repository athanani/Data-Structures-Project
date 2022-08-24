//
// Created by User on 5/26/2021.
//

/*
 * Στην κλάση HashTable υλοποιείται η δομή της πίνακα κατακερματισμού.
 */

#include "HashTable.h"

/*
 * Ο κατασκευαστής, αρχικοποιεί το τιμές των μεταβλητών size, totaladded αλλά και τον δυναμικό πίνακα table με
 * μέγεθος size. Η μεταβλητή size είναι το μέγεθος των δυναμικού πινάκων table και η totaladded είναι ο αριθμός των μοναδικών λέξεων
 * που έχουν προστεθεί.
 */
HashTable::HashTable() {
    size = 100000;
    totaladded = 0;
    table = new Pair [size];
}

/*
 * Ο καταστροφέας, διαγράφει τον δυναμικό πίνακα table.
 */
HashTable::~HashTable() {
    delete [] table;
}

/*
 * Η συνάρτηση createkey() δέχεται σαν όρισμα την συμβολοσειρά in και δημιουργεί ένα μοναδικό κλειδί για αυτήν.
 */
unsigned long HashTable::createkey(string in) {
    unsigned long hash = 5381;
    for (int i = 0; i < in.size(); ++i) {
        hash = hash*33 + in[i];
    }
    return hash;
}


/*
 * Η συνάρτηση Insert() δέχεται σαν όρισμα την συμβολοσειρά in. Αρχικά ελέγχεται αν το σύνολο των λέξεων που έχουν
 * προστεθεί είναι μικρότερος από το μέγεθος του πίνακα δια δύο, εάν είναι μικρότερος καλείται η συνάρτηση insertfunction()
 * για την εισαγωγή της λέξης, αλλιώς δημιουργείται ένας νέος δυναμικός πίνακας τύπο Pair, εισάγονται ένα ένα τα στοιχεία
 * του πίνακα table σε αυτόν με την insertfunction(), μετά αντιγράφονται τα στοιχεία πίσω στον table και γίνεται η εισαγωγή
 * της λέξης insertfunction(). Η συνάρτηση insertfunction() δημιουργήθηκε με σκοπό την αποφυγή διπλότυπου κώδικα.
 */
void HashTable::Insert(string in) {
    if (totaladded < size/2) {
        insertfunction(in, table, size);
    } else {
        totaladded = 0;
        Pair *temp;
        temp = new Pair [2*size];
        for (int i = 0; i < size; ++i) {
            if (table[i].word != ""){
                insertfunction(table[i].word, temp, 2*size);
            }
        }
        delete[] table;
        table = temp;
        size *= 2;
        insertfunction(in, table, size);
    }
}

/*
 * Η συνάρτηση insertfunction() δέχεται τρία ορίσματα, μια συμβολοσειρά, έναν δείκτη σε δυναμικό πίνακα τύπου Pair και
 * και έναν ακέραιο που συμβολίζει το μέγεθος του πίνακα. Αρχικά δημιουργείται ένα κλειδί με την συνάρτηση createkey(),
 * εάν η μεταβλητή word του πίνακα στη θέση είναι κενή, τότε γίνεται εισαγωγή σε αυτή την θέση και αποθηκεύεται το κλειδί
 * στις αντίστοιχες μεταβλητές, αν υπάρχει η ίδια λέξη τότε αυξάνεται κατά ένα η μεταβλητή numofwords στην αντίστοιχη θέση.
 * Εάν υπάρχει διαφορετική λέξη, τότε αναζητείται γραμμικά μέχρι να βρεθεί κενή θέση ή η ίδια λέξη και ακολουθείται η ίδια
 * διαδικασία.
 */
void HashTable::insertfunction(string in, Pair *temptable, int tempsize) {
    unsigned long key = createkey(in)%tempsize;
    if (temptable[key].word == ""){
        temptable[key].word = in;
        temptable[key].key = key;
        temptable[key].numofwords = 1;
        totaladded++;
    } else if (temptable[key].word == in){
        temptable[key].numofwords++;
    } else {
        unsigned long key2=key+1;
        while (key2 != key){
            if (temptable[key2].word == ""){
                temptable[key2].word = in;
                temptable[key2].key = key;
                temptable[key2].numofwords = 1;
                totaladded++;
                break;
            } else if (temptable[key2].word == in) {
                temptable[key].numofwords++;
                break;
            }
            key2++;
            if (key2==tempsize){
                key2=0;
            }
        }
    }
}

/*
 * Η συνάρτηση find() δέχεται δύο ορίσματα, την συμβολοσειρά in και τον ακέραιο mode. Αρχικά δημιουργείται ένα κλειδί με
 * την συνάρτηση createkey(), εάν η μεταβλητή word του πίνακα στη θέση του κλειδιού είναι ίση με την συμβολοσειρά in, τότε
 * επιστρέφεται 1 εάν είναι κενή επιστρέφεται 0, αλλιώς αν υπάρχει διαφορετική λέξη, αναζητείται γραμμικά μέχρι να βρεθεί
 * ή να υπάρχει κενή συμβολοσειρά στη μεταβλητή word ακολουθώντας την ίδια διαδικασία. Η μεταβλητή mode καθορίζει την
 * λειτουργία της συνάρτησης, εάν ισούται με 2 τότε πριν την επιστροφή τυπώνεται η λέξη μαζί με τον συνολικές εμφανίσεις
 * της.
 */
int HashTable::find(string in, int mode) {
    unsigned long key = createkey(in)%size;
    if (table[key].word == in){
        if (mode==2){
            cout << in << ", " << table[key].getnumofwords() << endl;
        }
        return 1;
    } else if (table[key].word == ""){
        if (mode==2){
            cout << in << ", 0" << endl;
        }
        return 0;
    }
    unsigned long i = key+1;
    while (i!=key){
        if (table[i].word == in){
            if (mode==2){
                cout << in << ", " << table[i].getnumofwords() << endl;
            }
            return 1;
        } else if (table[i].word == ""){
            if (mode==2){
                cout << in << ", 0" << endl;
            }
            return 0;
        }
        i++;
        if (i==size){
            i=0;
        }
    }
}