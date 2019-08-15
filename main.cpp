#include "QTS.h"
#include "Statistic.h"
#include <iostream>
#include <time.h>


using namespace std;

int main() {
    auto start = chrono::steady_clock::now();// count execution time

    for (int i = 0; i < STATISTICAL_ROUND; i++) {
        cout << "Round " << (i + 1) << "/" << STATISTICAL_ROUND << endl;

        fileOpen();
        init();

        for (int j = 0; j < ROUND; j++) {
            measure();
            calcFitness();
            update();
//            prtPMatrix();
            outputEPIN(j);
        }

#if EACH_ROUND_RESULT
        showResult();
#endif

        statistic();
    }

    finalResult();
    fileClose();

    // count execution time
    auto end = chrono::steady_clock::now();
    cout << "Time taken: " << chrono::duration<double>(end - start).count() << " s" << endl;
    return 0;
}