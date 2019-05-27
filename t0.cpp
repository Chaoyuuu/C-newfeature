#include <iostream>
 #include <vector>
 #include <random>
 #include <algorithm>
 #include <chrono>
 #include <execution>
 
 template<typename T>
 void run_sort(const T &policy, const std::vector<int> &data) {
    
         std::vector<int> curr_data(data);
 
         const auto start = std::chrono::steady_clock::now();
         std::sort(policy, curr_data.begin(), curr_data.end());
         const auto end = std::chrono::steady_clock::now();
         
	 //print time
	 std::chrono::duration<double> diff = end - start;
	 std::cout << "Elapsed time" << diff.count() << "ms\n" << std::endl; 
 }
 
 int main() {
     // Test samples and repeat factor
      size_t samples{5'000'000};
 
     std::vector<int> data(samples);
     for(size_t i=0; i<= samples; i++) {
         data[i] = rand();
     }
 
     // Sort data using different execution policies
     std::cout << "sort (std::seq)\n";
     run_sort(std::execution::seq, data);
 
     std::cout << "sort (std::par)\n";
     run_sort(std::execution::par, data);

     std::cout << "sort (std::par_unseq)\n";
     run_sort(std::execution::par_unseq, data);

}
