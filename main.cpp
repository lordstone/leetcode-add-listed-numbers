typedef struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};

class addListNumber{
public:
    static void printList(ListNode * a){
        while(a != NULL){
            cout << a -> val ;
            a = a -> next;
            if(a != NULL) cout << " - ";
        }
        cout << endl;
    }

    static ListNode * addTwoList(ListNode * num1, ListNode * num2){
        int n1 = 0, n2 = 0;

        while(num1 != NULL ){
            n1 *= 10;
            n1 += num1 -> val;
            num1 = num1 -> next;
        }
        while(num2 != NULL ){
            n2 *= 10;
            n2 += num2 -> val;
            num2 = num2 -> next;
        }
        int sum = n1 + n2;

        if(sum == 0) {
            ListNode * root = new ListNode(0);
            return root;
        }
        ListNode * tmpNode = NULL;
        while(sum != 0){
            if(tmpNode == NULL){
                tmpNode = new ListNode( sum % 10);
            }else{
                ListNode * tmpNode2 = new ListNode(sum % 10);
                tmpNode2 -> next = tmpNode;
                tmpNode = tmpNode2;
            }
            sum /= 10;
        }
        return tmpNode;
    }

    static ListNode *addListsReverse(ListNode *l1, ListNode *l2) {
        // write your code here
        //easier, can do in-place
        ListNode * root = new ListNode (0);
        ListNode * res = root;
        int carry = 0;
        while(l1 != NULL || l2 != NULL){
            int tmp = carry;
            if(l1 != NULL) {
                tmp += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2 != NULL) {
                tmp += l2 -> val;
                l2 = l2 -> next;
            }
            carry = tmp / 10;
            tmp %= 10;
            root -> val = tmp;
            if(l1 != NULL || l2 != NULL || carry != 0 ){
                root -> next = new ListNode (carry);
                root = root -> next;
            }
        }
        return res;
    }
};

int main(){
    // 3 - 4 - 5 - 8 - 9
    ListNode * a = new ListNode(3);
    a -> next = new ListNode (4);
    a -> next -> next = new ListNode (5);
    a -> next -> next -> next = new ListNode (8);
    a -> next -> next -> next -> next = new ListNode (9);
    cout << "a: " ;
    addListNumber::printList(a);
    // 8 - 0 - 7 - 6 - 2
    ListNode * b = new ListNode(8);
    b -> next = new ListNode (0);
    b -> next -> next = new ListNode (7);
    b -> next -> next -> next = new ListNode (6);
    b -> next -> next -> next -> next = new ListNode (2);
    cout << "b: " ;
    addListNumber::printList(b);
    cout<< "a + b : ";
    addListNumber::printList(addListNumber::addTwoList(a,b));
    return 0;
}
