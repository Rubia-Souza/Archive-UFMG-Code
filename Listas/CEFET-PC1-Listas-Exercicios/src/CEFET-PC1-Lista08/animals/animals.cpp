#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
    private:
        Node *leftNode = NULL;
        Node *rightNode = NULL;
        string value = "";
    
    public: 
        Node() {}

        Node(const string value) {
            setValue(value);
        }

        Node(const string value, Node *leftNode, Node *rightNode) {
            setValue(value);
            setLeftNode(leftNode);
            setRightNode(rightNode);
        }

        void setValue(const string value) {
            this->value = value;
        }

        string getValue() {
            return value;
        }

        void setLeftNode(Node *nodeReference) {
            this->leftNode = nodeReference;
        }

        Node *getLeftNode() {
            return leftNode;
        }

        void setRightNode(Node *nodeReference) {
            this->rightNode = nodeReference;
        }

        Node *getRightNode() {
            return rightNode;
        }
};

class HierarchyTree {
    private:
        Node *root = NULL;
    
    public:
        HierarchyTree() {

        }

        HierarchyTree(Node *root) {
            this->root = root;
        }

        HierarchyTree(const string value) {
            root = new Node(value);
        }

        void setRoot(Node *root) {
            this->root = root;
        }

        Node *getRoot() {
            return this->root;
        }

        bool isEmpty() {
            return (root == NULL);
        }
};

#define AMOUNT_CHARACTERISTICS 3
void getAnimalCharacteristics(vector<string> *outvector);
void buildVertebrateTree(HierarchyTree *outTree);
void buildInvertebrateTree(HierarchyTree *outTree);
string identifyAnimal(HierarchyTree referenceTree, const vector<string> characteristics);

int main() {
    vector<string> animalCharacteristics;
    getAnimalCharacteristics(&animalCharacteristics);

    HierarchyTree *animalsTree = new HierarchyTree();
    if(animalCharacteristics[0] == "vertebrado") {
        buildVertebrateTree(animalsTree);
    }
    else {
        buildInvertebrateTree(animalsTree);
    }

    string animal = identifyAnimal(*animalsTree, animalCharacteristics);
    cout << animal << "\n";

    return 0;
}

void buildVertebrateTree(HierarchyTree *outTree) {
    Node *AlimentationNode4 = new Node("carnivoro");
    AlimentationNode4->setLeftNode(new Node("aguia"));

    Node *AlimentationNode3 = new Node("onivoro");
    AlimentationNode3->setLeftNode(new Node("pomba"));

    Node *PhylumNode2 = new Node("ave");
    PhylumNode2->setRightNode(AlimentationNode4);
    PhylumNode2->setLeftNode(AlimentationNode3);

    Node *AlimentationNode2 = new Node("onivoro");
    AlimentationNode2->setLeftNode(new Node("homem"));

    Node *AlimentationNode1 = new Node("herbivoro");
    AlimentationNode1->setLeftNode(new Node("vaca"));

    Node *PhylumNode1 = new Node("mamifero");
    PhylumNode1->setRightNode(AlimentationNode2);
    PhylumNode1->setLeftNode(AlimentationNode1);

    Node *root = new Node("vertebrado");
    root->setRightNode(PhylumNode2);
    root->setLeftNode(PhylumNode1);

    outTree->setRoot(root);
    return;
}

void buildInvertebrateTree(HierarchyTree *outTree) {
    Node *AlimentationNode4 = new Node("hematofato");
    AlimentationNode4->setLeftNode(new Node("pulga"));

    Node *AlimentationNode3 = new Node("herbivoro");
    AlimentationNode3->setLeftNode(new Node("lagarta"));

    Node *PhylumNode2 = new Node("inseto");
    PhylumNode2->setRightNode(AlimentationNode4);
    PhylumNode2->setLeftNode(AlimentationNode3);

    Node *AlimentationNode2 = new Node("hematofato");
    AlimentationNode2->setLeftNode(new Node("sanguessuga"));

    Node *AlimentationNode1 = new Node("onivoro");
    AlimentationNode1->setLeftNode(new Node("minhoca"));

    Node *PhylumNode1 = new Node("anelideo");
    PhylumNode1->setRightNode(AlimentationNode2);
    PhylumNode1->setLeftNode(AlimentationNode1);

    Node *root = new Node("invertebrado");
    root->setRightNode(PhylumNode2);
    root->setLeftNode(PhylumNode1);

    outTree->setRoot(root);
    return;
}

void getAnimalCharacteristics(vector<string> *outvector) {
    vector<string> inputs;

    for(int i = 0; i < AMOUNT_CHARACTERISTICS; i++) {
        string line = "";
        getline(cin, line);

        inputs.push_back(line);
    }

    *outvector = inputs;
    return;
}

string identifyAnimal(HierarchyTree referenceTree, const vector<string> characteristics) {
    Node *actualNode = referenceTree.getRoot();
    
    for(int i = 1; i < characteristics.size(); i++) {
        Node *nextLeftNode = actualNode->getLeftNode();
        string nextNodeLeftValue = nextLeftNode->getValue();
        
        if(nextNodeLeftValue == characteristics[i]) {
            actualNode = nextLeftNode;
        }
        else {
            actualNode = actualNode->getRightNode();
        }
    }

    return actualNode->getLeftNode()->getValue();
}
