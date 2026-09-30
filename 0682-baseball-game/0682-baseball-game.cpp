class Solution {

    struct stack
    {
        int data;
        stack* next;
    };

public:

    int calPoints(vector<string>& operations)
    {
        stack* top = NULL;

        for(int i = 0; i < operations.size(); i++)
        {
            // Case 1: Number
            if(operations[i] != "D" &&
               operations[i] != "+" &&
               operations[i] != "C")
            {
                int value = stoi(operations[i]);

                stack* newstack = new stack;
                newstack->data = value;
                newstack->next = top;
                top = newstack;
            }

            // Case 2: Double
            else if(operations[i] == "D")
            {
                int value = top->data * 2;

                stack* newstack = new stack;
                newstack->data = value;
                newstack->next = top;
                top = newstack;
            }

            // Case 3: Sum of previous two
            else if(operations[i] == "+")
            {
                int value = top->data + top->next->data;

                stack* newstack = new stack;
                newstack->data = value;
                newstack->next = top;
                top = newstack;
            }

            // Case 4: Cancel previous score
            else if(operations[i] == "C")
            {
                stack* temp = top;
                top = top->next;
                delete temp;
            }
        }

        // Calculate final sum
        int sum = 0;

        stack* temp = top;

        while(temp != NULL)
        {
            sum = sum + temp->data;
            temp = temp->next;
        }

        return sum;
    }
};