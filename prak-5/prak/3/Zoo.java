import java.io.*;
import java.util.*;

public class Zoo {
    private ArrayList<Enclosure<? extends Animal>> enclosures;
    private float ticketPrice;

    public Zoo() {
        // Inisialisasi this.enclosures dan this.ticketPrice
        this.enclosures = new ArrayList<>();
        this.ticketPrice = 0;
    }

    public void addEnclosure(Enclosure<? extends Animal> enc) {
        // Menambahkan Enclosure enc ke dalam this.enclosures apabila enc tidak kosong
        if (!enc.isEmpty()) {
            enclosures.add(enc);
        }
    }

    public void updateTicketPrice() {
        // Melakukan update terhadap this.ticketPrice dengan rumus sebagai berikut
        // harga tiket baru = 0
        // Untuk setiap Enclosure dalam this.enclosures:
            // Apabila Enclosure bersifat safeForPetting:
            //     harga tiket baru += 1.5 * jumlah animal dalam enclosure
            // else:
            //     harga tiket baru += 1 * jumlah animal dalam enclosure 
        float res = 0;
        for (Enclosure x : enclosures) {
            if (x.safeForPetting()) {
                res += 1.5 * x.getAnimalCount();
            } else {
                res += 1 * x.getAnimalCount();
            }
        }

        this.ticketPrice = res;
    }

    public float getTicketPrice() {
        // getter untuk this.ticketPrice
        return this.ticketPrice;
    }

    public int getTotalAnimalCount() {
        // Mengembalikan jumlah total semua hewan yang ada pada semua enclosure dalam this.enclosures
        int res = 0;
        for (Enclosure x : enclosures) {
            res += x.getAnimalCount();
        }
        return res;
    }

    public int getEnclosureCount() {
        // Mengembalikan jumlah enclosures dalam this.enclosures
        return this.enclosures.size();
    }

    // public static void main(String[] args) {
    //     Zoo z = new Zoo();

    //     System.out.println(z.getEnclosureCount());
    // }
}