/**
 * Animal.java
 * [Jelaskan kegunaan class ini]
 * @author [NIM] [Nama]
 */

public abstract class Animal implements Comparable<Animal> {
  protected int numberOfLegs;
  protected int children;

  public int getNumberOfLegs() {
    return numberOfLegs;
  }

  public int getNumberOfChildren() {
    return children;
  }

  public void increaseChild(int inc) {
    this.children += inc;
  }

  abstract int getAnimalPower(); // abstract

  public int compareTo(Animal a) {
    // compareTo mengembalikan:
    // 0 bila this sama dengan m
    // 1 bila this lebih dari m
    // -1 bila this kurang dari m
    
    if (this.getAnimalPower() == a.getAnimalPower()) {
      return 0;
    } else if (this.getAnimalPower() > a.getAnimalPower()) {
      return 1;
    } else {
      return -1;
    }
  }
}
