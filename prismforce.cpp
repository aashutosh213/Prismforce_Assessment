#include <bits/stdc++.h>
using namespace std;

bool CanCross(int p, int a, int b) {
    int powerOfEnemy[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};
    int noOfEnemy = sizeof(powerOfEnemy) / sizeof(powerOfEnemy[0]);
    int power = p;
    int rechargeCnt = 0;

    for (int i = 0; i < noOfEnemy; i++) {
        //if Abhimanyu has sufficient power for this enemy
        if (power < powerOfEnemy[i]) {
            //if Abhimanyu can skip battle
            if (a > 0) {
                a--;
                continue;
            }

            //if Abhimanyu can recharge
            if (b > 0 && rechargeCnt < i) {
                b--;
                power = p;
                rechargeCnt++;
                continue;
            }

            //Abhimanyu doesn't have enough power and cannot skip or recharge
            return false;
        }

        // Check if the enemy is k3 or k7
        if (i + 1 < noOfEnemy && (i + 1 == 2 || i + 1 == 6)) {
            int regenPower = powerOfEnemy[i] / 2;
            power -= powerOfEnemy[i];

            //if Abhimanyu has enough power
            if (power < regenPower) {
                //if Abhimanyu can skip
                if (a > 0) {
                    a--;
                    power += powerOfEnemy[i];
                    continue;
                }

                //if Abhimanyu can recharge
                if (b > 0 && rechargeCnt < i + 1) {
                    b--;
                    power = p;
                    rechargeCnt++;
                    continue;
                }

                //Abhimanyu doesn't have enough power
                return false;
            }

            power += regenPower;
        } else {
            power -= powerOfEnemy[i];
        }
    }

    // Abhimanyu successfully crossed the Chakravue
    return true;
}

int main() {
    // Test Case 1

    int p1 = 500;
    int a1 = 3;
    int b1 = 1;
    if (CanCross(p1, a1, b1)) {
        cout << "Abhimanyu can cross the Chakravue for Power: "<<p1<<", Enemy Recharge:"<< "a1"<<", and Self Recharge:"<< b1 << endl;
    } else {
        cout <<"Abhimanyu cannot cross the Chakravue for Power: "<<p1<<", Enemy Recharge:"<< "a1"<<", and Self Recharge:"<< b1 << endl;
    }

    // Test Case 2
    int p2 = 100;
    int a2 = 2;
    int b2 = 2;
    if (CanCross(p2, a2, b2)) {
        cout << "Abhimanyu can cross the Chakravue for Power: "<<p2<<", Enemy Recharge:"<< a2<<", and Self Recharge:"<< b2 << endl;
    } else {
        cout << "Abhimanyu cannot cross the Chakravue for Power: "<<p2<<", Enemy Recharge:"<< a2<<", and Self Recharge:"<< b2 << endl;
    }

    return 0;
}
