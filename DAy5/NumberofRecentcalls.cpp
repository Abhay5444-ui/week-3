class RecentCounter {
public:
    queue<int> q;

    RecentCounter() {
    }

    int ping(int t) {
        q.push(t);

        int low = t - 3000;

        while (!q.empty() && q.front() < low) {
            q.pop();
        }

        return q.size();
    }
};
