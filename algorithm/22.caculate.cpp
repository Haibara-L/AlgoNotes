#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int totalnum, partialnum;
    long double minnumber;
    if (!(cin >> totalnum >> partialnum >> minnumber)) return 0;

    vector<long double> v(totalnum, 0);
    for (int i = 0; i < totalnum; i++) {
        cin >> v[i];
    }

    int lower = partialnum; 
    int upper = totalnum; 
    int ans = -1;           

    while (lower <= upper) {
        int mid = lower + (upper - lower) / 2; 
        vector<long double> tempv(v.begin(), v.begin() + mid);
        sort(tempv.begin(), tempv.end());

        vector<long double> presum(mid);
        vector<long double> prepowsum(mid);
        presum[0] = tempv[0];
        prepowsum[0] = tempv[0] * tempv[0];
        for (int i = 1; i < mid; i++) {
            presum[i] = tempv[i] + presum[i - 1];
            prepowsum[i] = tempv[i] * tempv[i] + prepowsum[i - 1];
        }

        bool flag = false;
        for (int i = 0; i + partialnum - 1 < mid; i++) {
            int j = i + partialnum - 1;
            long double d;
            long double current_sum, current_powsum;
            if (i == 0) {
                current_sum = presum[j];
                current_powsum = prepowsum[j];
            } else {
                current_sum = presum[j] - presum[i - 1];
                current_powsum = prepowsum[j] - prepowsum[i - 1];
            }
            long double avg = current_sum / partialnum;
            d = (current_powsum / partialnum) - (avg * avg);

            if (d < minnumber) {
                flag = true;
                break;
            }
        }

        if (flag) {
            ans = mid;     
            upper = mid - 1; 
        } else {
            lower = mid + 1; 
        }
    }

    cout << ans << endl;
    return 0;
}