#include <iostream>
#include "Ordered_Array.h"
#include <fstream>
#include <chrono>
#include "Unordered_Array.h"
#include "AVLBinaryTree.h"
#include "BinaryTree.h"
#include "HashTable.h"

using namespace std;

/*
 * Στη συνάρτηση main() αρχικοποιούνται οι απαραίτητες μεταβλητές, τα αντικείμενα των κλάσεων που υλοποιούν τις δομές
 * δεδομένων και ανοίγει το αρχείο κειμένου. Διαβάζει τις γραμμές μία-μία, αφαιρεί τα σημεία στίξης και εισάγει κάθε λέξη
 * σε όλες τις δομές, κρατώντας τον συνολικό αριθμό λέξεων που έχουν προστεθεί στον μετρητή counter. Στην συνέχεια κλείνει
 * το αρχείο, το ξανανοίγει και κάνει την ίδια διαδικασία με μόνη διαφορά ότι δεν γίνεται εισαγωγή στις δομές αλλά στον
 * πίνακα Q[] που κρατάει τις 1000 λέξεις για την αναζήτηση. Η επιλογή των λέξεων γίνεται με επιλογή τυχαίου
 * αριθμού μεταξύ του 0 και του 1, και αν είναι μικρότερο του 1/(counter/1150) (επιλέχθηκε το 1150 αντί του 1000 ώστε να
 * μην υπάρχει πιθανότητα να μην συμπληρωθεί ο πίνακας). Στην συνέχεια για κάθε δομή κάνει αναζήτηση της κάθε λέξης του
 * πίνακα σε κάθε δομή εμφανίζοντας τον αριθμό εμφάνισης της κάθε λέξης και τον συνολικό χρόνο που χρειάστηκε η κάθε δομή.
 */
int main() {
    int counter=0;
    int counter1=0;
    srand((int) time(0));
    Ordered_Array array;
    Unordered_Array array1;
    Node *root = nullptr;
    Node *root1 = nullptr;
    AVLBinaryTree tree = AVLBinaryTree();
    BinaryTree tree1 = BinaryTree();
    HashTable hash = HashTable();
    ifstream file;
    string filename = "small-file.txt"; // Αντικατάσταση της μεταβλητής filename για διαφορετικό αρχείο διαβάσματος
    file.open(filename);
    string str;
    string input;
    string *Q = new string [1000];

    chrono::high_resolution_clock sc;
    auto start = sc.now();

    while (getline(file, str)){
        for (int i=0; i<str.size(); i++){
            if (str[i]>=65 && str[i]<=92){
                str[i] += 32;
            }
            if (str[i]==46 || str[i]==63 || str[i]==33 || str[i]==44 || str[i]==59 || str[i]==58 || str[i]==45 ||
                str[i]==91 || str[i]==93 || str[i]==123 || str[i]==125 || str[i]==40 || str[i]==41 || str[i]==34){
                str[i] = ' ';
            } else if (str[i]==39){
                if (str[i-1]==' ' || str[i+1]==' ' || i==0 || i==str.size()-1){
                    str[i] = ' ';
                }
            }
        }
        str += " ";
        input = "";
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] != ' '){
                input += str[i];
            } else {
                if (input != ""){
                    array.Insert(input);
                    array1.Insert(input);
                    root = tree.Insert(input, root);
                    root1 = tree1.Insert(input, root1);
                    hash.Insert(input);
                    counter++;
                }
                input = "";
            }
        }
    }
    file.close();

    auto end = sc.now();
    auto time_span = static_cast<chrono::duration<double>>(end - start);
    cout<<"Insert took: "<<time_span.count()<<" seconds" << endl << endl;

    double rate = 1 / (double) (counter / 1150);
    file.open(filename);
    while (getline(file, str)){
        for (int i=0; i<str.size(); i++){
            if (str[i]>=65 && str[i]<=92){
                str[i] += 32;
            }
            if (str[i]==46 || str[i]==63 || str[i]==33 || str[i]==44 || str[i]==59 || str[i]==58 || str[i]==45 ||
                str[i]==91 || str[i]==93 || str[i]==123 || str[i]==125 || str[i]==40 || str[i]==41 || str[i]==34){
                str[i] = ' ';
            } else if (str[i]==39){
                if (str[i-1]==' ' || str[i+1]==' ' || i==0 || i==str.size()-1){
                    str[i] = ' ';
                }
            }
        }
        str += " ";
        input = "";
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] != ' '){
                input += str[i];
            } else {
                if (input != "" && counter1<1000){
                    double k = ((double) rand() / (double) (RAND_MAX));
                    if (k < rate) {
                        Q[counter1] = input;
                        counter1++;
                    }
                }
                input = "";
            }
        }
    }
    start = sc.now();
    for (int i = 0; i < 1000; ++i) {
        array.find(Q[i], 2);
    }
    end = sc.now();
    time_span = static_cast<chrono::duration<double>>(end - start);
    cout << "Ordered array search time: " << time_span.count() << " seconds" << endl;
    cout << "Ordered array has: " << array.getsize() << " words" << endl << endl;

    start = sc.now();
    for (int i = 0; i < 1000; ++i) {
        array1.find(Q[i], 2);
    }
    end = sc.now();
    time_span = static_cast<chrono::duration<double>>(end - start);
    cout << "Unordered array search time: " << time_span.count() << " seconds" << endl;
    cout << "Unordered array has: " << array1.getsize() << " words" << endl << endl;

    start = sc.now();
    for (int i = 0; i < 1000; ++i) {
        tree1.find(Q[i], root1, 2);
    }
    end = sc.now();
    time_span = static_cast<chrono::duration<double>>(end - start);
    cout << "Binary tree search time: " << time_span.count() << " seconds" << endl;
    cout << "Binary tree has: " << tree1.getsize(root1) << " words" << endl << endl;

    start = sc.now();
    for (int i = 0; i < 1000; ++i) {
        tree.find(Q[i], root, 2);
    }
    end = sc.now();
    time_span = static_cast<chrono::duration<double>>(end - start);
    cout << "AVL Binary tree search time: " << time_span.count() << " seconds" << endl;
    cout << "AVL Binary tree has: " << tree.getsize(root) << " words" << endl << endl;

    start = sc.now();
    for (int i = 0; i < 1000; ++i) {
        hash.find(Q[i], 2);
    }
    end = sc.now();
    time_span = static_cast<chrono::duration<double>>(end - start);
    cout << "Hashtable search time: " << time_span.count() << " seconds" << endl;
    cout << "Hashtable has: " << hash.gettotaladded() << " words" << endl;
    return 0;
}