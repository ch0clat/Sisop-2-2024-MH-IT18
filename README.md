# Sisop-2-2024-MH-IT18
## Anggota kelompok
   ### Callista Meyra Azizah 5027231060
   ### Abhirama Triadyatma Hermawan 5027231061
   ### Adi Satria Pangestu 5027231043


# Soal
## Soal 1
Gavriel adalah seorang cyber security enthusiast. Suatu hari, ia dikontrak oleh sebuah perusahaan ternama untuk membuat sebuah program yang cukup rumit dengan bayaran jutaan rupiah. Karena tergoda dengan nominal bayaran tersebut, Gavriel langsung menerima tawaran tersebut. Setelah mencoba membuat dan mengembangkan program tersebut selama seminggu, laptop yang digunakan Gavriel mengalami overheat dan mati total sehingga harus dilarikan ke tukang servis terdekat. Karena keterbatasan waktu dalam pembuatan program dan tidak ingin mengecewakan perusahaan, Gavriel meminta bantuan kalian untuk membuat program tersebut dengan ketentuan sebagai berikut:
Program dapat menerima input path berupa ‘argv’ untuk mengatur folder dimana file akan dieksekusi
Program tersebut berfungsi untuk mereplace string dengan ketentuan sebagai berikut:
String m4LwAr3 direplace dengan string [MALWARE]
String 5pYw4R3 direplace dengan string [SPYWARE]
String R4nS0mWaR3 direplace dengan string [RANSOMWARE]
Program harus berjalan secara daemon, dan tidak diperbolehkan menggunakan command system() dalam pembuatan program
Program akan secara terus menerus berjalan di background dengan jeda 15 detik
Catat setiap penghapusan string yang dilakukan oleh program pada sebuah file bernama virus.log dengan format: [dd-mm-YYYY][HH:MM:SS] Suspicious string at <file_name> successfully replaced!

Contoh penggunaan: ./virus /home/user/virus

Contoh isi file sebelum program dijalankan:
```
pU=-JWQ$5$)D-[??%AVh]$cB6bm4LwAr3jEQC2p3R{HV]=-AUaxj:Qe+h
```
```
!aNX,i:!z3W=2;.tHc3&S+}6F)CFf%tfZLP1*w5m1PAzZJUux(
Pd&f8$F5=E?@#[6jd{TJKj]5pYw4R3{KK1?hz384$ge@iba5GAj$gqB41
#C&&a}M9C#f64Eb.?%c)dGbCvJXtU[?SE4h]BY4e1PR4nS0mWaR3{]S/{w?*
```
Contoh isi file setelah setelah program dijalankan:
```
pU=-JWQ$5$)D-[??%AVh]$cB6b[MALWARE]jEQC2p3R{HV]=-AUaxj:Qe+h
```
```
!aNX,i:!z3W=2;.tHc3&S+}6F)CFf%tfZLP1*w5m1PAzZJUux(
Pd&f8$F5=E?@#[6jd{TJKj][SPYWARE]{KK1?hz384$ge@iba5GAj$gqB41
#C&&a}M9C#f64Eb.?%c)dGbCvJXtU[?SE4h]BY4e1P[RANSOMWARE]{]S/{w?*
```
## Soal 2
Paul adalah seorang mahasiswa semester 4 yang diterima magang di perusahaan XYZ. Pada hari pertama magang, ia diberi tugas oleh atasannya untuk membuat program manajemen file sederhana. Karena kurang terbiasa dengan bahasa C dan environment Linux, ia meminta bantuan kalian untuk mengembangkan program tersebut.
Atasannya meminta agar program tersebut dapat berjalan secara daemon dan dapat mengunduh serta melakukan unzip terhadap file berikut. Atasannya juga meminta program ini dibuat tanpa menggunakan command system()

Setelah ditelusuri, ternyata hanya 6 file teratas yang nama filenya tidak dienkripsi. Oleh karena itu, bantulah Paul untuk melakukan dekripsi terhadap nama file ke-7 hingga terakhir menggunakan algoritma ROT19

Setelah dekripsi selesai, akan terlihat bahwa setiap file memuat salah satu dari kode berikut: r3N4mE, d3Let3, dan m0V3. Untuk setiap file dengan nama yang memuat kode d3Let3, hapus file tersebut. Sementara itu, untuk setiap file dengan nama yang memuat kode r3N4mE, lakukan hal berikut:
Jika ekstensi file adalah “.ts”, rename filenya menjadi “helper.ts”
Jika ekstensi file adalah “.py”, rename filenya menjadi “calculator.py”
Jika ekstensi file adalah “.go”, rename filenya menjadi “server.go”
Jika file tidak memuat salah satu dari ekstensi diatas, rename filenya menjadi “renamed.file”

Atasan Paul juga meminta agar program ini dapat membackup dan merestore file. Oleh karena itu, bantulah Paul untuk membuat program ini menjadi 3 mode, yaitu:
default: program berjalan seperti biasa untuk me-rename dan menghapus file. Mode ini dieksekusi ketika program dijalankan tanpa argumen tambahan, yaitu dengan command ./management saja
backup: program memindahkan file dengan kode m0V3 ke sebuah folder bernama “backup”
restore: program mengembalikan file dengan kode m0V3 ke folder sebelum file tersebut dipindahkan
Contoh penggunaan: ./management -m backup


Terkadang, Paul perlu mengganti mode dari program ini tanpa menghentikannya terlebih dahulu. Oleh karena itu, bantulan Paul untuk mengintegrasikan kemampuan untuk mengganti mode ini dengan mengirim sinyal ke daemon, dengan ketentuan:
SIGRTMIN untuk mode default
SIGUSR1 untuk mode backup
SIGUSR2 untuk mode restore
Contoh penggunaan: kill -SIGUSR2 <pid_program>

Program yang telah dibuat ini tidak mungkin akan dijalankan secara terus-menerus karena akan membebani sistem. Maka dari itu, bantulah Paul untuk membuat program ini dapat dimatikan dengan aman dan efisien

Terakhir, program ini harus berjalan setiap detik dan mampu mencatat setiap peristiwa yang terjadi ke dalam file .log yang bernama “history.log” dengan ketentuan:
Format: [nama_user][HH:MM:SS] - <nama_file> - <action>
nama_user adalah username yang melakukan action terhadap file
Format action untuk setiap kode:
kode r3N4mE: Successfully renamed.
kode d3Let3: Successfully deleted.
mode backup: Successfully moved to backup.
mode restore: Successfully restored from backup.
Contoh pesan log:
[paul][00:00:00] - r3N4mE.ts - Successfully renamed.
[paul][00:00:00] - m0V3.xk1 - Successfully restored from backup.

Berikut adalah struktur folder untuk pengerjaan nomor 2:
    soal_2/
    ├── history.log
    ├── management.c
    └── library/
        └── backup/

## Soal 3
Pak Heze adalah seorang admin yang baik. Beliau ingin membuat sebuah program admin yang dapat memantau para pengguna sistemnya. Bantulah Pak Heze untuk membuat program  tersebut!
Nama program tersebut dengan nama admin.c
Program tersebut memiliki fitur menampilkan seluruh proses yang dilakukan oleh seorang user dengan menggunakan command:
./admin <user>
Program dapat memantau proses apa saja yang dilakukan oleh user. Fitur ini membuat program berjalan secara daemon dan berjalan terus menerus. Untuk menjalankan fitur ini menggunakan command: 
./admin -m <user>
Dan untuk mematikan fitur tersebut menggunakan: 
./admin -s <user>
Program akan mencatat seluruh proses yang dijalankan oleh user di file <user>.log dengan format:
[dd:mm:yyyy]-[hh:mm:ss]_pid-process_nama-process_GAGAL/JALAN
Program dapat menggagalkan proses yang dijalankan user setiap detik secara terus menerus dengan menjalankan: 
./admin -c user
sehingga user tidak bisa menjalankan proses yang dia inginkan dengan baik. Fitur ini dapat dimatikan dengan command:
./admin -a user
Ketika proses yang dijalankan user digagalkan, program juga akan melog dan menset log tersebut sebagai GAGAL. Dan jika di log menggunakan fitur poin c, log akan ditulis dengan JALAN

## Soal 4
Salomo memiliki passion yang sangat dalam di bidang sistem operasi. Saat ini, dia ingin mengotomasi kegiatan-kegiatan yang ia lakukan agar dapat bekerja secara efisien. Bantulah Salomo untuk membuat program yang dapat mengotomasi kegiatan dia!
(NB: Soal di uji coba dan berhasil di sistem yang menggunakan MacOS dan linux yang menggunakan dual boot dan VM. Untuk teman-teman yang menggunakan WSL bisa mengerjakan soal yang lain ya)
Salomo ingin dapat membuka berbagai macam aplikasi dengan banyak jendela aplikasi dalam satu command. Namai file program tersebut setup.c
Program dapat membuka berbagai macam aplikasi dan banyak jendela aplikasi sekaligus (bisa membuka 1 atau lebih aplikasi dengan 1 atau lebih window (kecuali aplikasi yang tidak bisa dibuka dengan banyak window seperti discord)) dengan menjalankan: 
./setup -o <app1> <num1> <app2> <num2>.....<appN> <numN>
Contoh penggunaannya adalah sebagai berikut: 
./setup -o firefox 2 wireshark 2
Program akan membuka 2 jendela aplikasi firefox dan 2 jendela aplikasi wireshark.
Program juga dapat membuka aplikasi dengan menggunakan file konfigurasi dengan menggunakan 
./setup -f file.conf 
Format file konfigurasi dibebaskan, namun pastikan dapat menjalankan fitur dari poin 2.
Contoh isi file.conf:
Firefox 2
Wireshark 3
Ketika menjalankan command contoh, program akan membuka 2 jendela aplikasi firefox dan 3 jendela aplikasi wireshark.
Program dapat mematikan semua aplikasi yg dijalankan oleh program tersebut dengan: 
./setup -k
Program juga dapat mematikan aplikasi yang dijalankan sesuai dengan file konfigurasi. 
Contohnya: 
./setup -k file.conf 
Command ini hanya mematikan aplikasi yang dijalankan dengan 
./setup -f file.conf

NB: Mohon untuk testing, adaptasikan dengan kemampuan device masing-masing. Jangan menjalankan program jika device anda tidak kuat (contohnya laptop anda menggunakan RAM hanya 2gb namun mentesting dengan menjalankan setup -o firefox 10 wireshark 8). Jika terdapat kerusakan dikarenakan testing dari soal, ASISTEN LAB tidak memiliki tanggung jawab apapun terhadap kerusakan tersebut.

NB: Semua soal tidak boleh dikerjakan menggunakan fungsi system(). Di utamakan menggunakan fungsi fork() atau exec().

# Penyelesaian

## Soal 1
Kita masukkan beberapa header sebagai library yang dipakai. Untuk penjelasan penggunaan tiap library, ada pada komentar.
 ```sh
#include <stdio.h> // input-output
#include <stdlib.h> // memory allocations
#include <string.h> // string manipulation
#include <dirent.h> // directory handling
#include <sys/stat.h> // getting file info
#include <time.h> // manipulates time
#include <unistd.h> // POSIX os API access
#include <fcntl.h> // file control
#include <errno.h> // error handling
#include <syslog.h> // system logging
```
Lalu, sesuai soal, kita membuka file log (disini virus.log) yang baru. "a" digunakan sebagai appendix, dimana program akan membuat file virus.log jikalau belum ada file bernama virus.log pada directory yang dituju. Log ini akan mencatat waktu saat string yang mencurigakan ditemukan dan dihapus dari file, dengan format: [dd-mm-YYYY][HH:MM:SS] Suspicious string at <file_name> successfully replaced!
```sh
void createNewLog(const char *fileName) { 
    time_t rawtime;
    struct tm *timeInfo;
    char currentTime[100];
    FILE *log = fopen("/home/cal/Viruses/virus.log", "a");
    
    if (log == NULL) {
        perror("Failed to open log file. :(");
        exit(EXIT_FAILURE);

    }
    time(&rawtime);
    timeInfo = localtime(&rawtime);
    strftime(currentTime, sizeof(currentTime), "[%d-%m-%Y][%H:%M:%S]", timeInfo);
    fprintf(log, "%s Suspicious string at %s successfully removed!\n", currentTime, fileName);
    fclose(log); // File log di close di line ini.
}
```
 Setelah file log dibuat, `changeContent(char *content) mengganti string yang mencurigakan itu dengan string yang benar. Seperti pada soal, kata-kata "m4LwAr3", "5pYw4R3", dan "R4nS0mWaR3" akan diganti menjadi "[MALWARE]", "[SPYWARE]", dan "[RANSOMWARE]" pada konten file yang ditemukan pada direktori yang dituju.
```sh
//Duplicate input content strings (sesuai sama file yang di masukkan).
char *changeContent(char *content) {
    char *replaced = strdup(content);
    if (replaced == NULL) {
        perror("Failed to duplicate string. :(");
        exit(EXIT_FAILURE);
    }

    //Merubah kata aneh menjadi benar, m4LwAr3 menjadi [MALWARE], dan seterusnya...
    char *patterns[] = {"m4LwAr3", "5pYw4R3", "R4nS0mWaR3"}; 
    char *replacements[] = {"[MALWARE]", "[SPYWARE]", "[RANSOMWARE]"};
    for (int i = 0; i < sizeof(patterns) / sizeof(patterns[0]); ++i) {
        char *found = strstr(replaced, patterns[i]);
        while (found != NULL) {

            strncpy(found, replacements[i], strlen(replacements[i]));
            found = strstr(replaced, patterns[i]);
        }
    }
    return replaced;
```
Command dibawah ini kemudian akan menyecan setiap direktori dan subdirektori secara rekursif, dimana ia akan membuka setiap file yang ditemukan dan mengedit konten file bila ditemukan string "m4LwAr3", "5pYw4R3", atau"R4nS0mWaR3". Kemudian, perubahan yang dilakukan akan dicatat di virus.log tadi.
```sh
}
// Scans a directory (termasuk juga subdirectories)
 ```sh
void scanDir(const char *path) {
    struct dirent *entry;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("Failed to open directory. :(");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) { // Bakal jalan ke setiap direktori 
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
 
        // Constructs the full path.
        char fullpath[1024];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (lstat(fullpath, &statbuf) == -1) { // Mendapat status file
            perror("Failed to get file status. :(");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            // Kalo entry termasuk direktori, maka akan memanggil fungsi scanDir secara rekursif dengan full path subdirektori.
            scanDir(fullpath);
        } else if (S_ISREG(statbuf.st_mode)) {
            // Kalau file itu regular file, bakal diopen secara read-write mode (r+")
            FILE *file = fopen(fullpath, "r+");
            if (file == NULL) {
                perror("Failed to open file for editing. :(");
                continue;
            }
            

            // Reads the file's content menggunakan malloc sebagai memory allocation, fread juga.
            fseek(file, 0, SEEK_END);
            long fileSize = ftell(file);
            rewind(file);
            char *content = malloc(fileSize + 1);
            if (content == NULL) {
                perror("Failed to allocate memory. :(");
                fclose(file);
                exit(EXIT_FAILURE);
            }
            fread(content, 1, fileSize, file);
            content[fileSize] = '\0';

            // Edits content, sesuai pattern dan replacement tadi.
           char *correctedContent = changeContent(content);
            if (strcmp(correctedContent, content) != 0) {
                // Mengganti isi file sesuai pattern dan replacement yang sudah ada di atas tadi.
                rewind(file);
                fwrite(correctedContent, 1, strlen(correctedContent), file);
                fclose(file);
                free(correctedContent);

                // Replacement nya di taruh di log, in this occassion, di virus.log
                createNewLog(fullpath);
            } else {
                free(correctedContent);
                fclose(file);
            }
            free(content); // Memory cleanup (biar gak menuh2in memory gara2 dynamic memory allocation tadi).
        }
    }
    closedir(dir);
}
```
Disini adalah fungsi main dari program virus ini, dimana ia akan menjalankan program secara daemon, sesuai ketentuan soal. Command ini akan initiate proses scan directory yang akan berjalan secara terus-menerus selama 15 detik (karena sesuai ketentuan soal, Program harus secara terus menerus berjalan di background dengan jeda 15 detik). lalu, karena pada soal diminta agar kita bisa menerima input path berupa ‘argv’ untuk mengatur folder dimana file akan dieksekusi, maka digunakan `int main(int argc, char *argv[]`
```sh
int main(int argc, char *argv[]) {
    // Agar file berjalan secara proses Daemon
    pid_t pid, sid;
    pid = fork(); // Membuat child process menggunakanm fork. Kalau pid < 0, ya fail. Kalo pid > 0, maka parent process lancar jaya.
  
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    umask(0); // Agar daemon memiliki full permission untuk membuat file (in this case, virus.log). Makanya mode creation masknya 0. 

    sid = setsid(); // Membuat new session, lalu setsid ini akan mengdetach (seperti memisahkan diri) dari terminal, agar tetap berjalan meskipun di close.
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }

    if (chdir("/") < 0) { // Mengganti working directory supaya gak ada issues kalo ada perubahan pada filesystem dan semacamnya.
        exit(EXIT_FAILURE);
    }
    // Agar daemon tidak menulis/edit terminal accidentally.
    close(STDIN_FILENO); 
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // Main daemon loop (ini infinite loop, dan akan selalu bekerja setiap 15 detik)
    while (1) {
        scanDir(argv[1]); // Scan the directory provided as an argument (karena pada soal diminta agar bisa menjalankan file argv). Ini akan menginisiasi directory scanning process.
        sleep(15); // Yang membuat program berjalan setiap 15 detik.
    }

    return 0;
}
```
Penjelasan kode bagian daemon secara lebih lengkap:
- `fork` akan membuat proses baru. Jika berhasil, parent proses akan kembali ke child process ID, dan child process akan memiliki ID 0.
- `setsid()` membuat session baru jika prosesnya bukan member dari existing session. Ia juga akan menjadi session leader dan group leader dalam prosesnya.
- `umask(0)` mengatur default access right untuk file yang baru dibuat oleh proses (Kan nanti ada konten file yang perlu diedit. Dengan itu, perlu menggunakan command ini).
- `chdir("/")` mengubah working directory menjadi root directory (/), supaya gak ada issues kalo ada perubahan pada filesystem dan semacamnya.
- `close(STDIN_FILENO)`, `close(STDOUT_FILENO)`,`close(STDERR_FILENO)` menutup standard file descriptors untuk input, output, dan error. Ini digunakan untuk menghindari daemon menulis ke terminal.
- `while(1)` merupakan loop utama yang menjalankan scan directory tiap 15 detik, yang menggunakan `scanDir(argv[1]`, dan terakhir akan memberi jeda 15 detik menggunakan `sleep(15)`.

## soal 2
   
## Soal 3

## Soal 4
```
void open (const char *appName, int count, int state){
    for (int i = 0; i < count; i++){
        pid_t pid;
        pid = fork();
        if (pid == 0) {
            execlp(appName, appName, NULL); 
            fprintf(stderr, "Error : Failed to start %s\n", appName);
            exit(1);
        } else if (pid > 0) {
            FILE* log = fopen("setup.log", "a");
            fprintf(log, "%s %d %d\n", appName, pid, state);
            num_pids++;
            fclose(log);
        }
    }
}
```
```
void file_open (const char *filename, int state){
    FILE* config = fopen(filename, "r");

    if (config == NULL) {
        fprintf(stderr, "Error : Unable to open file\n");
        return;
    }

    char appName [255];
    int count;

    while (fscanf(config, "%s %d", appName, &count) == 2){
        open(appName, count, state);
    }
    
    fclose(config);

}
```
```
void stop (int state) {
    FILE* log = fopen("setup.log", "r");
    
    pid_t pid;
    int log_state;
    char appName [255];


    while (fscanf(log, "%s %d %d", appName, &pid, &log_state) == 3){
        if (state == 1) {
            if (log_state == state){
                if (kill(pid, SIGTERM) == -1) {
            printf("Error : Failed to send SIGTERM %d\n", pid);
            } else {
                printf("Sent SIGTERM to PID %d\n", pid);
            }
            }
        } else if (state == 0) {
        printf("%d", log_state);
        if (kill(pid, SIGTERM) == -1) {
            printf("Error : Failed to send SIGTERM %d\n", pid);
        } else {
            printf("Sent SIGTERM to PID %d\n", pid);
        }
        } else {
            printf("Somethinge went wrong");
        }
    }
    
    remove("setup.log");
    fclose(log);
    exit (0);

}
```
```
int main (int argc, char *argv[]){
    int state = 0;
     
 
    if (strcmp(argv[1], "-o") == 0 && argc > 3){
        for (int i = 2; i < argc; i += 2){
            open(argv[i], atoi(argv[i + 1]), state);
        }
    }
    else if (strcmp(argv[1], "-k") == 0){
        if (argc == 3){
            state = 1;
            stop(state);
        } else if (argc == 2) {
            stop(state);
        } else {
            printf("Error : Invalid amount of arguments");
        }
    }
    else if (strcmp(argv[1], "-f") == 0 && argc == 3){
        state = 1;
        file_open(argv[2], state);
    }
    else {
        printf("Error : Wrong arguments\n try >> -o For manual setup \n \t-f For config file setup \n \t-k For closing setup");
        return 1;
    }

    return 0;
}
```
