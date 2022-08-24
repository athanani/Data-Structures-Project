//
// Created by User on 5/1/2021.
//

#ifndef DATASTRUCTURES_AVLBINARYTREE_H
#define DATASTRUCTURES_AVLBINARYTREE_H

#include <iostream>
#include "Node.h"

using namespace std;


/*
 * Node *Insert(string, Node *): Συνάρτηση εισαγωγής λέξης στην δομή.
 * Node *Delete(string, Node *): Συνάρτηση διαγραφής λέξης από την δομή.
 * Node *RRotate(Node *): Συνάρτηση υλοποίησης δεξιάς περιστροφής του κόμβου που δέχεται ως όρισμα.
 * Node *LRotate(Node *): Συνάρτηση υλοποίησης αριστερής περιστροφής του κόμβου που δέχεται ως όρισμα.
 * Node *Findmax(Node *): Συνάρτηση εύρεσης και επιστροφής της μεγαλύτερης λέξης.
 * int find(string, Node *, int): Συνάρτηση εύρεσης συμβολοσειράς, επιστρέφει 1 εάν βρέθηκε αλλιώς 0.
 * void inorder(Node *): Συνάρτηση υλοποίησης ενδοδιατεταγµένης διαπέρασης δένδρου.
 * void preorder(Node *): Συνάρτηση υλοποίησης προδιατεταγµένης διαπέρασης δένδρου.
 * void postorder(Node *): Συνάρτηση υλοποίησης μεταδιατεταγµένης διαπέρασης δένδρου.
 * int calcheight(Node *): Συνάρτηση εύρεσης και επιστροφής του ύψους του κόμβου που δέχεται ως όρισμα.
 * int getsize(Node *): Συνάρτηση εύρεσης και επιστροφής του συνολικού αριθμού μοναδικών λέξεων.
 */
class AVLBinaryTree {
public:
    Node *Insert(string, Node *);
    Node *Delete(string, Node *);
    Node *RRotate(Node *);
    Node *LRotate(Node *);
    Node *Findmax(Node *);
    int find(string, Node *, int);
    void inorder(Node *);
    void preorder(Node *);
    void postorder(Node *);
    int calcheight(Node *);
    int getsize(Node *);
};


#endif //DATASTRUCTURES_AVLBINARYTREE_H
