import java.lang.reflect.Method;
import java.lang.reflect.Field;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Reflection{
    //TIDAK BOLEH MENGUBAH NAMA METHOD YANG SUDAH ADA DAN PARAMS SERTA INPUT TYPENYA
    //BOLEH MENAMBAHKAN PRIVATE / PROTECTED METHOD SESUAI DENGAN KEBUTUHAN
    //DI LUAR SANA ADA KELAS YANG NAMANYA Ghost DAN Secret.
    public ArrayList<String> ghostMethods(){
        ArrayList<String> methodList = new ArrayList<>();

        Class ghostClass = Ghost.class;

        // Semua private, maka gabisa pake getMethods() (liat stackoverflow)
        Method[] methods = ghostClass.getDeclaredMethods();

        // Method[] method = Ghost.getClass().getDeclaredMethods();

        for (Method method : methods) {
            methodList.add(method.getName()); // getName return string
        }

        return methodList;
    }   

    public Integer sumGhost() throws Exception{
        Ghost ghost = new Ghost();
        Integer res = 0;

        Class ghostClass = Ghost.class;
        Method[] methods = ghostClass.getDeclaredMethods();

        for (Method method : methods) {
            if (method.getReturnType() == Integer.class) {
                method.setAccessible(true);
                res += (Integer) method.invoke(ghost);
            }
        }

        return res;
    }

    public String letterGhost() throws Exception{
        Ghost ghost = new Ghost();
        String res = "";

        Class ghostClass = Ghost.class;
        Method[] methods = ghostClass.getDeclaredMethods();

        for (Method method : methods) {
            if (method.getReturnType() == String.class) {
                method.setAccessible(true);
                res = res.concat((String) method.invoke(ghost));
            }
        }

        return res;
    }

    public String findSecretId(List<Secret> sl, String email) throws Exception{
        for (Secret secret: sl) {
            if (secret.isThis(email)) {
                Class secretClass = secret.getClass();
                Field uniqueIdField = secretClass.getDeclaredField("uniqueId");
                uniqueIdField.setAccessible(true);
                String uniqueId = (String) uniqueIdField.get(secret);

                return uniqueId;
            }
        }

        return "NaN";
    }
}


// Tugas anda adalah implementasi ke empat method tersebut dengan ketentuan sebagai berikut

// Terdapat sebuah kelas Ghost yang memiliki N method, dan semua method tersebut adalah private. Sesuai namanya, yaitu Ghost, maka isi kelas tersebut adalah misterius dan tidak diketahui baik nama method maupun return dari method tersebut (dipastikan return dari Ghost antara Integer dan String saja).
// Implementasi method getMethod() dimana akan membaca seluruh method yang dimiliki oleh kelas Ghost dan menyimpan nama method tersebut ke dalam ArrayList
// Implementasi method sumGhost() dimana akan menjumlahkan seluruh return dari method dari kelas Ghost yang memiliki kembalian Integer
// Implementasi method letterGhost() dimana akan mengembalikan concat dari seluruh method di kelas Ghost yang memiliki kembalian String. (Ketika concat langsung concat aja, gausah di kasih spasi atau pemisah lainnya).
// Terdapat kelas lain yang bernama Secret dengan isi sebagai berikut

// public class Secret{
//     private String email;
//     private String nama;
//     public static Integer counter = 0;
//     private String uniqueId;

//     //KELAS SUDAH PATEN, TIDAK BOLEH DIEDIT EDIT

//     public Secret(String email, String nama){
//         //MAGIC HAPPENED THERE.
//         //Intinya konstruktor biasa, cuma ada randomisasi buat uniqueId, dan jangan lupa
//         //counter++ pada bagan akhir konstruktor ini.
//     }

//     public boolean isThis(String email){
//         //GUNAKAN FUNGSI INI UNTUK MENCOCOKAN EMAIL DENGAN EMAIL YANG DIMILIKI KELAS
//         return this.email.equalsIgnoreCase(email);
//     }

// }

// Implementasi method findSecretId(List<Secret> sl, String email) yang berfungsi akan mencari Secret sesuai dengan email yang hendak dicari. Apabila Secret dengan email yang dimaksud ada, maka kembalikan uniqueId dari email tersebut, jika tidak kembalikan NaN sesuai dengan template yang ada diatas.
// Tips, gunakan setAccessible(true) untuk mengakses method maupun attribut private / protected.
// Untuk implementasi no. 6, manfaatkan method isThis(String email)
// Untuk debugging di local teman-teman bisa membuat kelas Secret sesuai dengan template diatas, lalu memberikan uniqueId dengan String random, dan kelas Ghost dengan membuat beberapa method private yang mengembalikan Integer dan String.
// kumpulkan Reflection.java