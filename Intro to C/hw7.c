/**
 * @file hw7.c
 * @author Antonio Mattson
 * @collaborators NAMES OF PEOPLE THAT YOU COLLABORATED WITH HERE
 * @brief structs, pointers, pointer arithmetic, arrays, strings, and macros
 * @date 2022-03-xx
 */

// DO NOT MODIFY THE INCLUDE(S) LIST
#include <stdio.h>
#include "hw7.h"
#include "my_string.h"

// Global array of Animal structs
struct animal animals[MAX_ANIMAL_LENGTH];

int size = 0;

/** addAnimal
 *
 * @brief creates a new Animal and adds it to the array of Animal structs, "animals"
 *
 *
 * @param "species" species of the animal being created and added
 *               NOTE: if the length of the species (including the null terminating character)
 *               is above MAX_SPECIES_LENGTH, truncate species to MAX_SPECIES_LENGTH. If the length
 *               is 0, return FAILURE.  
 *               
 * @param "id" id of the animal being created and added
 * @param "hungerScale" hunger scale of the animal being created and added
 * @param "habitat" habitat of the animal being created and added
 * @return FAILURE on failure, SUCCESS on success
 *         Failure if any of the following are true:
 *         (1) "species" length is 0
 *         (2) "habitat" length is 0
 *         (3) adding the new animal would cause the size of the array "animals" to
 *             exceed MAX_ANIMAL_LENGTH
 *        
 */
int addAnimal(const char *species, int id, double hungerScale, const char *habitat)
{
  if (my_strlen(species) == 0) {
    return FAILURE;
  }
  if (my_strlen(habitat) == 0) {
    return FAILURE;
  }
  if ((size + 1) > MAX_ANIMAL_LENGTH) {
    return FAILURE;
  }
  struct animal ani;
  my_strncpy(ani.species, species, MAX_SPECIES_LENGTH);
  ani.id = id;
  ani.hungerScale = hungerScale;
  my_strncpy(ani.habitat, habitat, MAX_HABITAT_LENGTH);
  animals[size] = ani;
  size++;
  return SUCCESS;
}

/** updateAnimalSpecies
 *
 * @brief updates the species of an existing animal in the array of Animal structs, "animals"
 *
 * @param "animal" Animal struct that exists in the array "animals"
 * @param "species" new species of Animal "animal"
 *               NOTE: if the length of species (including the null terminating character)
 *               is above MAX_SPECIES_LENGTH, truncate species to MAX_SPECIES_LENGTH
 * @return FAILURE on failure, SUCCESS on success
 *         Failure if any of the following are true:
 *         (1) the Animal struct "animal" can not be found in the array "animals" based on its id
 */
int updateAnimalSpecies(struct animal animal, const char *species)
{
  if (size == 0) {
    return FAILURE;
  }
  int loop = 0;
  while (loop <= size) {
    if (animal.id == animals[loop].id) {
      my_strncpy(animals[loop].species, species, MAX_SPECIES_LENGTH);
      return SUCCESS;
    }
    loop++;
  }
  return FAILURE;
}

/** averageHungerScale
* @brief Search for all animals with the same species and find average the hungerScales
* 
* @param "species" Species that you want to find the average hungerScale for
* @return the average hungerScale of the specified species
*         if the species does not exist, return 0.0
*/
double averageHungerScale(const char *species)
{
  double total = 0.0;
  int loop = 0;
  int count = 0;
  while (loop < size) {
    if (my_strncmp(animals[loop].species, species, MAX_SPECIES_LENGTH) == 0) {
      total = total + animals[loop].hungerScale;
      count++;
    }
    loop = loop + 1;
  }
  if (count == 0) {
    return total;
  }
  total = total / count;
  return total;
}

/** swapAnimals
 *
 * @brief swaps the position of two Animal structs in the array of Animal structs, "animals"
 *
 * @param "index1" index of the first Animal struct in the array "animals"
 * @param "index2" index of the second Animal struct in the array "animals"
 * @return FAILURE on failure, SUCCESS on success
 *         Failure if any of the following are true:
 *         (1) "index1" and/or "index2" are negative numbers
 *         (2) "index1" and/or "index2" are out of bounds of the array "animals"
 */
int swapAnimals(int index1, int index2)
{
  if (index1 < 0 || index2 < 0) {
    return FAILURE;
  }
  if (index1 >= size || index2 >= size) {
    return FAILURE;
  }
  struct animal temp = animals[index1];
  animals[index1] = animals[index2];
  animals[index2] = temp;
  return SUCCESS;
}

/** compareHabitat
 *
 * @brief compares the two Animals animals' habitats (using ASCII)
 *
 * @param "animal1" Animal struct that exists in the array "animals"
 * @param "animal2" Animal struct that exists in the array "animals"
 * @return negative number if animal1 is less than animal2, positive number if animal1 is greater
 *         than animal2, and 0 if animal1 is equal to animal2
 */
int compareHabitat(struct animal animal1, struct animal animal2)
{
  return my_strncmp(animal1.habitat, animal2.habitat, MAX_HABITAT_LENGTH);
}

/** removeAnimal
 *
 * @brief removes Animal in the array of Animal structs, "animals", that has the same species
 *
 * @param "animal" Animal struct that exists in the array "animals"
 * @return FAILURE on failure, SUCCESS on success
 *         Failure if any of the following are true:
 *         (1) the Animal struct "animal" can not be found in the array "animals"
 */
int removeAnimal(struct animal animal)
{
  int loop = 0; 
  while (loop < size) {
    if (animal.id == animals[loop].id) {
      size = size - 1;
      while (loop < size) {
        animals[loop] = animals[loop + 1];
        loop++;
      }
      return SUCCESS;
    }
    loop++;
  }

  return FAILURE;
}

/** sortAnimal
 *
 * @brief using the compareHabitat function, sort the Animals in the array of
 * Animal structs, "animals," by the animals' habitat
 * If two animals have the same habitat, place the hungier animal first
 *
 * @param void
 * @return void
 */
void sortAnimalsByHabitat(void)
{
  int count = 0;
  int max = size - count;
  while (max > 0) {
    int current = 1;
    while (current < max) {
      int check = compareHabitat(animals[current-1], animals[current]);
      if (check > 0 || (check == 0 && animals[current].hungerScale > animals[current - 1].hungerScale)) {
        swapAnimals(current, current - 1);
      }
      current = current + 1;
    }
    max = max - 1;
  }
}