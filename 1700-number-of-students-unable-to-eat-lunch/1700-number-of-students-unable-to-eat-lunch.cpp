class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(int student: students)
        {
            q.push(student);
        }

        int i = 0;
        int unable = 0;

        while(!q.empty() && unable < q.size())
        {
            if(q.front() == sandwiches[i])
            {
                q.pop();
                i++;
                unable = 0;
            }
            else
            {
                q.push(q.front());
                q.pop();
                unable++;
                
            }
        }

        return q.size();
    }
};