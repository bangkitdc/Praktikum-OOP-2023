import java.io.*;
import java.util.*;

public class Enclosure<T extends Animal> {
    private ArrayList<T> animals;

    public Enclosure() {
        // Inisialisasi ArrayList animals kosong
        this.animals = new ArrayList<>();
    } 

    public int getAnimalCount() {
        // Mengembalikan jumlah hewan dalam this.animals
        return this.animals.size();
    }

    public void addAnimal(T animal) {
        // menambahkan seekor hewan ke dalam this.animals
        // if (!isEmpty()) {
        //     if (animal.getClass().equals(getAnimalAt(0).getClass())) {
        //         this.animals.add(animal);
        //     }
        // } else {
        //     this.animals.add(animal);
        // }
        this.animals.add(animal);
    }

    public T getAnimalAt(int i) {
        // mengembalikan hewan dalam this.animals pada index i (tidak mengubah this.animals)
        return this.animals.get(i);
    }

    public void removeAnimalAt(int i) {
        // menghapus hewan pada this.animals pada index i
        this.animals.remove(i);
    }

    public boolean isEmpty() {
        // mengembalikan boolean yang menyatakan apakah this.animals kosong atau tidak
        return this.animals.isEmpty();
    }

    public void describe() {
        // Menuliskan output berikut apabila this.animals kosong:
        // Kandang ini kosong...
        // Apabila tidak kosong menuliskan output serupa dengan output berikut:
        // Kandang berisi 2 ekor hewan:
        // 1. po, spesies Pandamus Maximus, umur 5 tahun
        // 2. po2, spesies Pandamus Maximus, umur 5 tahun
        if (isEmpty()) {
            System.out.println("Kandang ini kosong...");
        } else {
            System.out.println("Kandang berisi " + getAnimalCount() + " ekor hewan:");

            int count = 1;
            for (Animal a : animals) {
                System.out.println(count + ". " + a.getName() + ", spesies " + a.getSpecies() + ", umur " + a.getAge() + " tahun");
                count ++;
            }
        }
    }

    public void feed() {
        // Menuliskan output berikut apabila this.animals kosong:
        // Kandang ini kosong...
        // Apabila tidak kosong maka akan memanggil method eat pada tiap animal dalam this.animals
        if (isEmpty()) {
            System.out.println("Kandang ini kosong...");
        } else {
            for (Animal a : animals) {
                a.eat();
            }
        }
    }

    public boolean safeForPetting() {
        // mengembalikan true apabila semua hewan dalam this.animals bersifat friendly
        for (Animal a : animals) {
            if (!a.isFriendly()) {
                return false;
            }
        }

        return true;
    }

    // public static void main(String[] args) {
    //     Enclosure e = new Enclosure();

    //     e.addAnimal(new Lion("a", 1));
    //     e.addAnimal(new Lion("b", 2));
    //     e.addAnimal(new Panda("c", 3));

    //     e.describe();
    // }
}