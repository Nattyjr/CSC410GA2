#include "genome.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;



// Default constructor initializes the genetic code with no genes and mutation rate set to 0
GeneticCode::GeneticCode() : genes(nullptr), nGenes(0), mutationRate(0.0) {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed RNG
}

// Destructor to clean up dynamically allocated memory
GeneticCode::~GeneticCode() {
    deallocate();
}

// Allocates memory for the specified number of genes and sets them to default values
void GeneticCode::allocate(int numGenes) {
    deallocate();
    nGenes = numGenes;
    genes = new Pixel[nGenes];
    for (int i = 0; i < nGenes; ++i) {
        genes[i].red = genes[i].green = genes[i].blue = 0;
    }
}

// Frees the dynamically allocated memory for genes

void GeneticCode::deallocate() {
    if (genes) {
        delete[] genes;
        genes = nullptr;
        nGenes = 0;
    }
}

// Randomizes the RGB values for each gene in the genetic code
void GeneticCode::randomize() {
    for (int i = 0; i < nGenes; ++i) {
        genes[i].red = rand() % 256;
        genes[i].green = rand() % 256;
        genes[i].blue = rand() % 256;
    }
}

// Sets the mutation rate to the specified value
void GeneticCode::set_mRate(double val) {
    if (val >= 0.0 && val <= 1.0) mutationRate = val;
    else cout << "Mutation rate value must be between 0 and 1." << endl;
}

// Returns the current mutation rate
double GeneticCode::get_mRate() const {
    return mutationRate;
}

// Mutates a single gene at the specified index if the condition is met
void GeneticCode::mutate_gene(int index) {
    if (index >= 0 && index < nGenes) {
        double chance = static_cast<double>(rand()) / RAND_MAX;
        if (chance < mutationRate) genes[index].red = rand() % 256;
        chance = static_cast<double>(rand()) / RAND_MAX;
        if (chance < mutationRate) genes[index].green = rand() % 256;
        chance = static_cast<double>(rand()) / RAND_MAX;
        if (chance < mutationRate) genes[index].blue = rand() % 256;
    }
}

// Mutates the entire genetic code based on the mutation rate
void GeneticCode::mutate() {
    for (int i = 0; i < nGenes; ++i) {
        mutate_gene(i);
    }
}

// Calculates the fitness of a single gene at the specified index against a target pixel
double GeneticCode::calculate_gene_fitness(int index, Pixel targetPixel) const {
    if (index < 0 || index >= nGenes) return -1.0;
    double diff = abs(genes[index].red - targetPixel.red) + abs(genes[index].green - targetPixel.green) + abs(genes[index].blue - targetPixel.blue);
    return diff / (3.0 * 256.0);
}

// Calculates the overall fitness of the genetic code against an array of target pixels
double GeneticCode::calculate_overall_fitness(Pixel* target, int nPixels) const {
    if (nPixels != nGenes) return -1.0;
    double totalFitness = 0.0;
    for (int i = 0; i < nGenes; ++i) {
        totalFitness += calculate_gene_fitness(i, target[i]);
    }
    return totalFitness / nGenes;
}

// Sets a new pixel at the specified index
void GeneticCode::set_pixel(int index, Pixel newPixel) {
    if (index >= 0 && index < nGenes) genes[index] = newPixel;
}

// Returns the pixel at the specified index
Pixel GeneticCode::get_pixel(int index) const {
    if (index >= 0 && index < nGenes) return genes[index];
    return { -1, -1, -1 }; // Invalid index
}

// Sets the red value of the pixel at the specified index
void GeneticCode::set_red(int index, int value) {
    if (index >= 0 && index < nGenes) genes[index].red = value;
}

// Sets the green value of the pixel at the specified index
void GeneticCode::set_green(int index, int value) {
    if (index >= 0 && index < nGenes) genes[index].green = value;
}

// Sets the blue value of the pixel at the specified index
void GeneticCode::set_blue(int index, int value) {
    if (index >= 0 && index < nGenes) genes[index].blue = value;
}

// Returns the red value of the pixel at the specified index, or -1 if the index is invalid
int GeneticCode::get_red(int index) const {
    if (index >= 0 && index < nGenes) return genes[index].red;
    return -1;
}

// Returns the green value of the pixel at the specified index, or -1 if the index is invalid
int GeneticCode::get_green(int index) const {
    if (index >= 0 && index < nGenes) return genes[index].green;
    return -1;
}

// Returns the blue value of the pixel at the specified index, or -1 if the index is invalid
int GeneticCode::get_blue(int index) const {
    if (index >= 0 && index < nGenes) return genes[index].blue;
    return -1;
}

// Prints the genetic code's information to the console (const because it does not modify any member variable)
void GeneticCode::print() const {
    cout << "GENETIC CODE: " << nGenes << " genes";
    for (int i = 0; i < nGenes; ++i) {
        cout << " (" << genes[i].red << "," << genes[i].green << "," << genes[i].blue << ")";
    }
    cout << endl;
}
