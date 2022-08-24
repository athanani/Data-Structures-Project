//
// Created by User on 4/6/2021.
//

/*
 * Στην κλάση Ordered_Array υλοποιείται η δομή της ταξινομημένου πίνακα.
 */

#include "Ordered_Array.h"

/*
 * Ο κατασκευαστής, αρχικοποιεί το τιμές των μεταβλητών size, pos αλλά και τους δυναμικούς πίνακες arr και numofwords με
 * μέγεθος size. Η μεταβλητή size είναι το μέγεθος των δυναμικών πινάκων arr και numofwords, η pos είναι ο αριθμός των μοναδικών λέξεων
 * που έχουν προστεθεί, στον δυναμικό πίνακα συμβολοσειρών arr αποθηκεύεται κάθε μοναδική λέξη και στον δυναμικό πίνακα
 * ακεραίων numofwords αποθηκεύεται ο αριθμός εμφανίσεων κάθε λέξης.
 */
Ordered_Array::Ordered_Array() {
    size = 100000;
    pos = 0;
    arr = new string [size];
    numofwords = new int [size];
}

/*
 * Ο καταστροφέας, διαγράφει του δύο δυναμικούς πίνακες arr και numofwords.
 */
Ordered_Array::~Ordered_Array() {
    delete [] arr;
    delete [] numofwords;
}

/*
 * Η συνάρτηση find() δέχεται δύο ορίσματα την συμβολοσειρά in και τον ακέραιο αριθμό mode, και επιστρέφει 1 αν η λέξη
 * in υπάρχει στην δομή ή 0 αν δεν υπάρχει. Η μέθοδος αναζήτησης που χρησιμοποιείται είναι η δυαδική αναζήτηση. Η τιμή
 * του mode καθορίζει την λειτουργεία της συνάρτησης. Αν το mode ισούται με 1 τότε σε περίπτωση που η λέξη υπάρχει
 * αυξάνεται η αντίστοιχη τιμή στον πίνακα numofwords κατά ένα, αυτή η λειτουργεία χρησιμοποιείται κατά την εισαγωγή
 * λέξεων στην δομή. Αν το mode ισούται με 2 τότε η συνάρτηση εμφανίζει την λέξη μαζί με τον σύνολο εμφανίσεων της. Σε
 * περίπτωση που το mode έχει οποιαδήποτε άλλη τιμή τότε η συνάρτηση λειτουργεί ως μία απλή συνάρτηση αναζήτησης.
 */
int Ordered_Array::find(string in, int mode) {
    int left = 0;
    int right = pos-1;
    int mid;
    while (right >= left){
        mid = left + (right-left)/2;
        if (in == arr[mid]){
            if (mode == 1){
                numofwords[mid]++;
            } else if (mode == 2){
                cout << in << ", " << numofwords[mid] << endl;
            }
            return 1;
        }
        if (in < arr[mid]){
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    if (mode == 2){
        cout << in << ", 0" << endl;
    }
    return 0;
}

/*
 * Η συνάρτηση Insert() δέχεται ένα όρισμα την συμβολοσειρά in. Σε περίπτωση που η λέξη δεν υπάρχει ήδη στην δομή τότε
 * ελέγχεται έαν μπορεί να προστεθεί στην δομή. Αν μπορεί τότε προστίθεται στη θέση pos δηλαδή στο τέλος των λέξεων που
 * έχουν ήδη προστεθεί και μετά μετακινείται σειριακά με την προηγούμενη λέξη μέχρι να μην υπάρχει μικρότερη λέξη από
 * αυτήν. Αν δεν υπάρχει χώρος για την προσθήκη της τότε δημιουργείται δύο καινούργιοι προσωρινούς πίνακες με διπλάσιο
 * μέγεθος, αντιγράφονται οι λέξεις και ο αριθμός εμφάνισής τους και μετά αντιγράφονται οι καινούργιοι πίνακες στους
 * παλιούς και μετά προστίθεται η λέξη.
 */
void Ordered_Array::Insert(string in) {
    if (find(in, true) == 0){
        if (pos == size){
            int *temp2;
            temp2 = new int[2*size];
            for (int i=0; i<size; i++){
                temp2[i] = numofwords[i];
            }
            delete[] numofwords;
            numofwords = temp2;

            string *temp;
            temp = new string[2*size];
            for (int i=0; i<size; i++){
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            size *= 2;
        }
        arr[pos] = in;
        numofwords[pos] = 1;
        for (int j = pos; j >= 0; j--){
            if (arr[j] < arr[j - 1]){
                swap(arr[j], arr[j - 1]);
                swap(numofwords[j], numofwords[j-1]);
            } else {
                break;
            }
        }
        pos++;
    }
}

/*
 * Η συνάρτηση Delete() δέχεται ως όρισμα την συμβολοσειρά d. Σε περίπτωση που υπάρχει μειώνει τον αριθμό εμφανίσεων
 * της (numofwords) κατά ένα. Εάν μετά την αφαίρεση η τιμή του numofwords είναι ίση με το 0 τότε η λέξη αφαιρείται από
 * την δομή μετακινώντας το σύνολο εμφανίσεων της κατά μία θέση δεξιά μέχρι να γίνει η τελευταία λέξη στον πίνακα  και
 * στο τέλος διαγράφεται η λέξη από την δομή μαζί με τον αριθμό εμφανίσεων της.
 */
void Ordered_Array::Delete(string d) {
    int left = 0;
    int right = pos-1;
    int mid;
    while (right >= left){
        mid = left + (right-left)/2;
        if (d == arr[mid]){
            numofwords[mid]--;
            if (numofwords[mid]==0){
                arr[mid] = "";
                for (int j = mid; j < pos-1; ++j) {
                    swap(arr[j], arr[j+1]);
                    swap(numofwords[j], numofwords[j+1]);
                }
                pos--;
            }
            break;
        }
        if (d < arr[mid]){
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
}