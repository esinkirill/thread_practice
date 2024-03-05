#include <iostream>
#include <omp.h>

int main() {
    int rank;


    omp_lock_t lock;
    omp_init_lock(&lock);

#pragma omp parallel shared (rank)
    {
        rank = omp_get_thread_num();


        omp_set_lock(&lock);

        std::cout << "thread " << rank << std::endl;

        omp_unset_lock(&lock);
    }

#pragma omp parallel private(rank)
        {
            rank = omp_get_thread_num();
 
 
            omp_set_lock(&lock);
 
            std::cout << "thread " << rank  << std::endl;
 
            omp_unset_lock(&lock);
        }

    return 0;
}
