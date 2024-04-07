#include "genome.h"
#include <iostream>

int main() {
    GeneticCode myGeneticCode;
  
  // Create an instance of the GeneticCode class






    
    std::cout << "Initial genetic code state:" << std::endl;
    myGeneticCode.print();

    
    myGeneticCode.allocate(4);
    std::cout << "\n After allocation is performed:" << std::endl;
    myGeneticCode.print();

    
    myGeneticCode.randomize();
    std::cout << "\nAfter randomization:" << std::endl;
    myGeneticCode.print();

    myGeneticCode.set_blue(0, 226);
    std::cout << "" << std::endl;
    myGeneticCode.print();

    // Set mutation rate
    myGeneticCode.set_mRate(0.5); 
  // Set mutation rate half
    std::cout << "\nMutation rate: " << myGeneticCode.get_mRate() << std::endl;

    
    myGeneticCode.mutate();
    std::cout << "\nAfter mutation:" << std::endl;
    myGeneticCode.print();



  
    Pixel targetPixel = {255, 0, 0}; 
    double fitness = myGeneticCode.calculate_gene_fitness(0, targetPixel);
    std::cout << " " << fitness << std::endl;

  
  
  // Set a pixel
    Pixel newPixel = {113, 65, 57};
    myGeneticCode.set_pixel(1, newPixel); // Set the second gene
  
    Pixel retrievedPixel = myGeneticCode.get_pixel(1);
    std::cout << "\nAfter setting the second gene to (113,65,57):" << std::endl;
    myGeneticCode.print();
    std::cout << "Retrieved pixel (should be 113,55,57): " << retrievedPixel.red << "," << retrievedPixel.green << "," << retrievedPixel.blue << std::endl;

    return 0;
}
