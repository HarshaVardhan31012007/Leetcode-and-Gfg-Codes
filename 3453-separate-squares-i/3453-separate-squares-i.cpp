class Solution {
public:
    double find(vector<vector<int>>& squares, double mid) {
        double up = 0, down = 0;
        for (auto &each : squares) {
            double y = each[1];
            double l = each[2];

            if (y >= mid) {
                up += l * l;
            } else if (mid >= y + l) {
                down += l * l;
            } else {
                up += l * (y + l - mid);
                down += l * (mid - y);
            }
        }
        return up - down;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double s = 1e9, e = 0;

        for (auto &each : squares) {
            s = min(s, (double)each[1]);
            e = max(e, (double)(each[1] + each[2]));
        }

        for (int i = 0; i < 80; i++) {  // fixed iterations = stable precision
            double mid = (s + e) / 2.0;
            double diff = find(squares, mid);

            if (diff > 0)
                s = mid;
            else
                e = mid;
        }

        return (s + e) / 2.0;
    }
};
