class Solution {
    struct stack {
        int data;
        struct stack* next;
    };

public:
    int calPoints(vector<string>& operations) {
        stack* head = NULL;

        for(string x : operations) {
            if(x != "C" && x != "D" && x != "+") {
                // Number: push a new score
                stack* nn = new stack;
                nn->data = stoi(x);
                nn->next = head;
                head = nn;
            }
            else if(x == "C") {
                // Remove the most recent score
                stack* temp = head;
                head = head->next;
                delete temp;
            }
            else if(x == "D") {
                // Double the most recent score
                int value = head->data * 2;

                stack* nn = new stack;
                nn->data = value;
                nn->next = head;
                head = nn;
            }
            else if(x == "+") {
                // Sum of the previous two scores
                int value = head->data + head->next->data;

                stack* nn = new stack;
                nn->data = value;
                nn->next = head;
                head = nn;
            }
        }

        // Calculate the sum of all valid scores
        int sum = 0;
        stack* temp = head;

        while(temp != NULL) {
            sum += temp->data;
            temp = temp->next;
        }

        return sum;
    }
};