//
// Created by User on 5/8/2021.
//

#include "BinaryTree.h"

/*
 * Η συνάρτηση Insert() δέχεται δύο ορίσματα την συμβολοσειρά in, και τον δείκτη σε κόμβο (στοιχείο της κλάσης Node)
 * node. Εάν ο κόμβος είναι κενός τότε τοποθετείται στην μεταβλητή word του κόμβου η λέξη και αυξάνεται ο αριθμός
 * συνολικών εμφανίσεων της, εάν στον κόμβο υπάρχει ήδη η λέξη τότε αυξάνεται ο αριθμός εμφανίσεων της. Εάν η in είναι
 * μικρότερη από την λέξη που υπάρχει στον κόμβο τότε η συνάρτηση καλεί τον εαυτό της με το αριστερό παιδί του κόμβου,
 * ενώ αν είναι μεγαλύτερη με το δεξί και στο τέλος επιστρέφεται ο κόμβος.
 */
Node *BinaryTree::Insert(string in, Node *node) {
    if (node == nullptr){
        node = new Node();
        node->word = in;
        node->numofwords++;
    } else if (in == node->word){
        node->numofwords++;
    } else if (in < node->word){
        node->left = Insert(in, node->left);
    } else if (in > node->word){
        node->right = Insert(in, node->right);
    }
    node->height = calcheight(node);
    return node;
}

/*
 * Η συνάρτηση Delete() δέχεται δύο ορίσματα την συμβολοσειρά in, και τον δείκτη σε Node node. Εάν ο κόμβος είναι κενός
 * τότε επιστρέφεται, εάν είναι η in είναι μικρότερη από την λέξη που υπάρχει ήδη στην μεταβλητή word του κόμβου τότε
 * η συνάρτηση καλεί τον εαυτό της με το αριστερό παιδί ενώ αν είναι μεγαλύτερη με το δεξί παιδί. Εάν είναι η ίδια λέξη
 * τότε μειώνεται κατά ένα το σύνολο εμφανίσεων της που είναι αποθηκευμένο στην μεταβλητή numofwords του node. Στην
 * περίπτωση που η τιμή του numofwords είναι 0 μετά την αφαίρεση τότε η λέξη αφαιρείται από την δομή και αντικαθίσταται
 * η θέση του δέντρου ανάλογα με την περίπτωση που ισχύει αν έχει τουλάχιστον ένα παιδί.
 */
Node *BinaryTree::Delete(string in, Node *node) {
    if (node == nullptr){
        return node;
    } else if (in < node->word){
        node->left = Delete(in, node->left);
    } else if (in > node->word){
        node->right = Delete(in, node->right);
    } else if (in == node->word){
        node->numofwords--;
        if (node->numofwords == 0){
            if (node->left == nullptr && node->right == nullptr){
                node = nullptr;
            } else if (node->left != nullptr && node->right== nullptr){
                node = node->left;
            } else if (node->left == nullptr && node->right!= nullptr){
                node = node->right;
            } else {
                node->word = Findmax(node->left)->word;
                node->left = Delete(node->word, node->left);
            }
        }
    } else {
        node->height = calcheight(node);
    }
    return node;
}

/*
 * Η συνάρτηση Findmax() καλεί τον ευατό της χρησιμοποιώντας το δεξί παιδί του κάθε κόμβου που δέχεται ως
 * είσοδο έως το δεξί παιδί του κόμβου να ισούται με nullptr όπου και επιστρέφεται καθώς είναι ο κόμβος με τη μέγιστη τιμή.
 */
Node *BinaryTree::Findmax(Node *node) {
    if (node == nullptr){
        return nullptr;
    } else if (node->right == nullptr){
        return node;
    } else {
        return Findmax(node->right);
    }
}

/*
 * Η συνάρτηση find() δέχεται τρία ορίσματα την συμβολοσειρά in, τον δείκτη σε κόμβο (στοιχείο της κλάσης Node)
 * node και τον ακέραιο mode. Αν ο κόμβος είναι nullptr τότε η in δεν βρέθηκε και επιστρέφεται 0, εάν είναι μικρότερη
 * από την λέξη που ήδη υπάρχει στον κόμβο τότε καλείται με το αριστερό παιδί ως όρισμα, εάν είναι μεγαλύτερη καλείται
 * με το δεξί παιδί και εάν είναι ίδια τότε επιστρέφεται 1. Η τιμή αυξάνεται η αντίστοιχη τιμή στον πίνακα numofwords
 * κατά ένα, αυτή η λειτουργεία χρησιμοποιείται κατά την εισαγωγή λέξεων στην δομή. Αν το mode ισούται με 2 τότε η
 * συνάρτηση εμφανίζει την λέξη μαζί με τον σύνολο εμφανίσεων της. Σε περίπτωση που το mode έχει οποιαδήποτε άλλη τιμή
 * τότε η συνάρτηση λειτουργεί ως μία απλή συνάρτηση αναζήτησης.
 */
int  BinaryTree::find(string in, Node *node, int mode) {
    if (node == nullptr){
        if (mode == 2){
            cout << in << ", 0" << endl;
        }
        return 0;
    } else if (in < node->word) {
        return find(in, node->left, mode);
    } else if (in > node->word) {
        return find(in, node->right, mode);
    } else if (in == node->word) {
        if (mode == 2){
            cout << in << ", " << node->numofwords << endl;
        }
        return 1;
    }
}

/*
 * Η συνάρτηση calcheight() δέχεται ως όρισμα τον δείκτη σε Node node και υπολογίζει το ύψους του κόμβου. Αν έχει δύο
 * παιδιά τότε ελέγχεται πιο υποδέντρο έχει μεγαλύτερο ύψος και επιστρέφεται το ύψος αυξημένο κατά ένα, εάν έχει μόνο
 * ένα παιδί τότε επιστρέφεται απευθείας το ύψος του αυξημένο κατά ένα.
 */
int BinaryTree::calcheight(Node *node) {
    if (node->left != nullptr && node->right != nullptr){
        if (node->left->height > node->right->height){
            return node->left->height + 1;
        } else {
            return node->right->height + 1;
        }
    } else if (node->left != nullptr){
        return node->left->height + 1;
    } else if (node->right != nullptr){
        return node->right->height + 1;
    }
    return 0;
}

/*
 * Η συνάρτηση inorder() δέχεται ως όρισμα τον δείκτη σε Node node και υλοποιεί την ενδοδιατεταγµένη διαπέραση δένδρου.
 * Για κάθε κόμβο που δέχεται ως είσοδο, αν δεν είναι ίσος με nullptr καλεί αρχικά τον εαυτό της με το αριστερό παιδί μετά
 * τυπώνει τον λέξη που είναι αποθηκευμένη στην μεταβλητή word  του κόμβου μαζί με το ύψος του κόμβου και τις συνολικές
 * εμφανίσεις της λέξης και τέλος καλεί τον εαυτό της με δεξί παιδί.
 */
void BinaryTree::inorder(Node *node) {
    if (node != nullptr) {
        inorder(node->left);
        cout << node->word << ", " << node->height << ", " << node->numofwords << endl;
        inorder(node->right);
    }
}

/*
 * Η συνάρτηση preorder() δέχεται ως όρισμα τον δείκτη σε Node node και υλοποιεί την προδιατεταγµένη διαπέραση δένδρου.
 * Για κάθε κόμβο που δέχεται ως είσοδο, αν δεν είναι ίσος με nullptr τυπώνει τον λέξη που είναι αποθηκευμένη στην
 * μεταβλητή word του κόμβου μαζί με το ύψος του κόμβου και τις συνολικές εμφανίσεις της λέξης, καλεί τον εαυτό της
 * με το αριστερό παιδί και τέλος καλεί τον εαυτό της με δεξί παιδί.
 */
void BinaryTree::preorder(Node *node) {
    if (node != nullptr) {
        cout << node->word << ", " << node->height << ", " << node->numofwords << endl;
        preorder(node->left);
        preorder(node->right);
    }
}

/*
 * Η συνάρτηση postorder() δέχεται ως όρισμα τον δείκτη σε Node node και υλοποιεί την μεταδιατεταγµένη διαπέραση δένδρου.
 * Για κάθε κόμβο που δέχεται ως είσοδο, αν δεν είναι ίσος με nullptr καλεί αρχικά τον εαυτό της με το αριστερό παιδί,
 * μετά καλεί τον εαυτό της με δεξί παιδί και τέλος τυπώνει τον λέξη που είναι αποθηκευμένη στην μεταβλητή word του
 * κόμβου μαζί με το ύψος του κόμβου και τις συνολικές εμφανίσεις της λέξης.
 */
void BinaryTree::postorder(Node *node) {
    if (node != nullptr) {
        postorder(node->left);
        postorder(node->right);
        cout << node->word << ", " << node->height << ", " << node->numofwords << endl;
    }
}

/*
 * Η συνάρτηση getsize() δέχεται ως όρισμα τον δείκτη σε Node node υπολογίζει τον συνολικό αριθμό μοναδικών λέξεων. Για
 * κάθε κόμβο που δέχεται ως είσοδο, αν είναι ίσος με nullptr τότε επιστρέφει 0 αλλιώς καλεί αρχικά τον εαυτό της με το
 * αριστερό παιδί και μετά με το δεξί παιδί αυξάνοντας την τιμή της μεταβλητή της μεταβλητής size ώστε να μετρήσει το
 * συνολικό αριθμό λέξεων του δένδρου και μετά επιστρέφει το size.
 */
int BinaryTree::getsize(Node *node) {
    int size=1;
    if (node != nullptr){
        size += getsize(node->left);
        size += getsize(node->right);
        return size;
    } else {
        return 0;
    }
}