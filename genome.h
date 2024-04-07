#ifndef GENETIC_CODE_H
#define GENETIC_CODE_H

#include <cstdlib>


// define RGB
struct Pixel {
    int red;
    int green;
    int blue;
};

class GeneticCode {
public:
    GeneticCode();
    ~GeneticCode();

    void allocate(int numGenes); 
// allocate memory
    void deallocate();  
// free the alocated memory
    void randomize();
    void set_mRate(double val);
    double get_mRate() const;
    void mutate_gene(int index);
    void mutate();
    double calculate_gene_fitness(int index, Pixel targetPixel) const;

    double calculate_overall_fitness(Pixel* target, int nPixels) const;
    void set_pixel(int index, Pixel newPixel);

    Pixel get_pixel(int index) const;

    void set_red(int index, int value);

    void set_green(int index, int value);
    void set_blue(int index, int value);

/return values for for specfied index 
    int get_red(int index) const;
    int get_green(int index) const;
    int get_blue(int index) const;
    void print() const;

private:
    Pixel* genes;
    int nGenes;
    double mutationRate;
};

#endif // GENETIC_CODE_H
