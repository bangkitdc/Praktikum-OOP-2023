import java.lang.reflect.*;

public class MahasiswaDecoder {
    private Class c;
    private Mahasiswa mahasiswa;

    MahasiswaDecoder(Mahasiswa mahasiswa) {
        this.mahasiswa = mahasiswa;
        this.c = mahasiswa.getClass();
    }

    public void addMatkul(String name) throws Exception {
        Method addMatkul = c.getDeclaredMethod("addMatkul", String.class);
        addMatkul.setAccessible(true);
        addMatkul.invoke(mahasiswa, name);
    }

    public int getNIM() throws Exception {
        Field NIM = c.getDeclaredField("NIM");
        NIM.setAccessible(true);
        return NIM.getInt(mahasiswa);
    }

    public double getIPK() throws Exception {
        Field IPK = c.getDeclaredField("IPK");
        IPK.setAccessible(true);
        return IPK.getDouble(mahasiswa);
    }
}