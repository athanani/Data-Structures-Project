//
// Created by User on 5/1/2021.
//

#include "AVLBinaryTree.h"

/*
 * Η συνάρτηση Insert() δέχεται δύο ορίσματα την συμβολοσειρά in, και τον δείκτη σε κόμβο (στοιχείο της κλάσης Node)
 * node. Εάν ο κόμβος είναι κενός τότε τοποθετείται στην μεταβλητή word του κόμβου η λέξη και αυξάνεται ο αριθμός
 * συνολικών εμφανίσεων της, εάν στον κόμβο υπάρχει ήδη η λέξη τότε αυξάνεται ο αριθμός εμφανίσεων της. Εάν η in είναι
 * μικρότερη από την λέξη που υπάρχει στον κόμβο τότε η συνάρτηση καλεί τον εαυτό της με το αριστερό παιδί του κόμβου,
 * ενώ αν είναι μεγαλύτερη με το δεξί και στο τέλος επιστρέφεται ο κόμβος. Εάν επιστραφεί ο κόμβος από της δύο τελευταίες
 * περίπτωσης και υπάρχει διαφορά ύψους μεταξύ του αριστερού και δεξιού υποδέντρου είναι 2 τότε πραγματοποιούνται
 * περιστροφές ανάλογα με την περίπτωση που ισχύει.
 */
Node *AVLBinaryTree::Insert(string in, Node *node) {
    if (node == nullptr){
        node = new Node();
        node->word = in;
        node->numofwords++;
    } else if (in == node->word){
        node->numofwords++;
    } else if (in < node->word){
        node->left = Insert(in, node->left);
        if (node->left->geth() - node->right->geth() == 2){
            if (in < node->left->word){
                node = RRotate(node);
            } else {
                node->left = LRotate(node->left);
                node = RRotate(node);
            }
        }
    } else if (in > node->word){
        node->right = Insert(in, node->right);
        if (node->right->geth() - node->left->geth() == 2){
            if (in > node->right->word){
                node = LRotate(node);
            } else {
                node->right = RRotate(node->right);
                node = LRotate(node);
            }
        }
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
 * η θέση του δέντρου ανάλογα με την περίπτωση που ισχύει αν έχει τουλάχιστον ένα παιδί. Εάν υπάρχει διαφορά ύψους
 * μεταξύ του αριστερού και δεξιού υποδέντρου μεγαλύτερη του 2 τότε πραγματοποιούνται περιστροφές ανάλογα με την
 * περίπτωση που ισχύει.
 */
Node *AVLBinaryTree::Delete(string in, Node *node) {
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
            } else if (node->left != nullptr && node->right == nullptr){
                node = node->left;
            } else if (node->left == nullptr && node->right!= nullptr){
                node = node->right;
            } else {
                node->word = Findmax(node->left)->word;
                node->left = Delete(node->word, node->left);
            }
        }
    } else {
        if (node->left->geth() - node->right->geth() == 2){
            if (in < node->left->word){
                node = RRotate(node);
            } else {
                node->left = LRotate(node->left);
                node = RRotate(node);
            }
        } else if (node->right->geth() - node->left->geth() == 2){
            if (in > node->right->word){
                node = LRotate(node);
            } else {
                node->right = RRotate(node->right);
                node = LRotate(node);
            }
        }
        node->height = calcheight(node);
    }
    return node;
}

/*
 * Η συνάρτηση RRotate() δέχεται ως όρισμα τον δείκτη σε Node node και υλοποιεί την δεξιά περιστροφή του κόμβου. Αυτό
 * επιτυγχάνεται με τη δημιουργεία του κόμβου temp στον οποίο τοποθετείται το αριστερό παιδί του κόμβου node. Ως αριστερό
 * παιδί του κόμβου node τοποθετείται το δεξί παιδί του κόμβου temp, ως δεξί παιδί του temp ο κόμβος node και τέλος
 * επιστρέφεται ο κόμβος temp.
 */
Node *AVLBinaryTree::RRotate(Node *node) {
    if (node->left != nullptr){
        Node *temp = node->left;
        node->left = temp->right;
        temp->right = node;
        node->height = calcheight(node);
        temp->height = calcheight(temp);
        return temp;
    }
    return node;
}

/*
 * Η συνάρτηση LRotate() δέχεται ως όρισμα τον δείκτη σε Node node και υλοποιεί την αριστερή περιστροφή του κόμβου. Αυτό
 * επιτυγχάνεται με τη δημιουργία του κόμβου temp στον οποίο τοποθετείται το δεξί παιδί του κόμβου node. Ως δεξί
 * παιδί του κόμβου node τοποθετείται το αριστερό παιδί του κόμβου temp, ως αριστερό παιδί του temp ο κόμβος node και
 * τέλος επιστρέφεται ο κόμβος temp.
 */
Node *AVLBinaryTree::LRotate(Node *node) {
    if (node->right != nullptr){
        Node *temp = node->right;
        node->right = temp->left;
        temp->left = node;
        node->height = calcheight(node);
        temp->height = calcheight(temp);
        return temp;
    }
    return node;
}

/*
 * Η συνάρτηση Findmax() καλεί τον εαυτό της χρησιμοποιώντας το δεξί παιδί του κάθε κόμβου που δέχεται ως
 * είσοδο έως το δεξί παιδί του κόμβου να ισούται με nullptr όπου και επιστρέφεται καθώς είναι ο κόμβος με τη μέγιστη τιμή.
 */
Node *AVLBinaryTree::Findmax(Node *node) {
    if (node == nullptr){
        return nullptr;
    } else if (node->right == nullptr){
        return node;
    } else {
        return Findmax(node->right);
    }
}

/*
 * Η συνάρτηση calcheight() δέχεται ως όρισμα τον δείκτη σε Node node και υπολογίζει το ύψους του κόμβου. Αν έχει δύο
 * παιδιά τότε ελέγχεται πιο υποδέντρο έχει μεγαλύτερο ύψος και επιστρέφεται το ύψος αυξημένο κατά ένα, εάν έχει μόνο
 * ένα παιδί τότε επιστρέφεται απευθείας το ύψος του αυξημένο κατά ένα.
 */
int AVLBinaryTree::calcheight(Node *node) {
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
 * Η συνάρτηση find() δέχεται τρία ορίσματα την συμβολοσειρά in, τον δείκτη σε κόμβο (στοιχείο της κλάσης Node)
 * node και τον ακέραιο mode. Αν ο κόμβος είναι nullptr τότε η in δεν βρέθηκε και επιστρέφεται 0, εάν είναι μικρότερη
 * από την λέξη που ήδη υπάρχει στον κόμβο τότε καλείται με το αριστερό παιδί ως όρισμα, εάν είναι μεγαλύτερη καλείται
 * με το δεξί παιδί και εάν είναι ίδια τότε επιστρέφεται 1. Η τιμή αυξάνεται η αντίστοιχη τιμή στον πίνακα numofwords
 * κατά ένα, αυτή η λειτουργεία χρησιμοποιείται κατά την εισαγωγή λέξεων στην δομή. Αν το mode ισούται με 2 τότε η
 * συνάρτηση εμφανίζει την λέξη μαζί με τον σύνολο εμφανίσεων της. Σε περίπτωση που το mode έχει οποιαδήποτε άλλη τιμή
 * τότε η συνάρτηση λειτουργεί ως μία απλή συνάρτηση αναζήτησης.
 */
int AVLBinaryTree::find(string in, Node *node, int mode) {
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
 * Η συνάρτηση inorder() δέχεται ως όρισμα τον δείκτη σε Node node και υλοποιεί την ενδοδιατεταγµένη διαπέραση δένδρου.
 * Για κάθε κόμβο που δέχεται ως είσοδο, αν δεν είναι ίσος με nullptr καλεί αρχικά τον εαυτό της με το αριστερό παιδί μετά
 * τυπώνει τον λέξη που είναι αποθηκευμένη στην μεταβλητή word  του κόμβου μαζί με το ύψος του κόμβου και τις συνολικές
 * εμφανίσεις της λέξης και τέλος καλεί τον εαυτό της με δεξί παιδί.
 */
void AVLBinaryTree::inorder(Node *node) {
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
void AVLBinaryTree::preorder(Node *node) {
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
void AVLBinaryTree::postorder(Node *node) {
    if (node != nullptr) {
        postorder(node->left);
        postorder(node->right);
        cout << node->word << ", " << node->height << ", " << node->numofwords << endl;
    }
}

/*
 * Η συνάρτηση δέχεται ως όρισμα τον δείκτη σε Node node υπολογίζει τον συνολικό αριθμό μοναδικών λέξεων. Για κάθε κόμβο
 * που δέχεται ως είσοδο, αν είναι ίσος με nullptr τότε επιστρέφει 0 αλλιώς καλεί αρχικά τον εαυτό της με το αριστερό παιδί
 * και μετά με το δεξί παιδί αυξάνοντας την τιμή της μεταβλητή της μεταβλητής size ώστε να μετρήσει το συνολικό αριθμό
 * λέξεων του δένδρου και μετά επιστρέφει το size.
 */
int AVLBinaryTree::getsize(Node *node) {
    int size=1;
    if (node != nullptr){
        size += getsize(node->left);
        size += getsize(node->right);
        return size;
    } else {
        return 0;
    }
}