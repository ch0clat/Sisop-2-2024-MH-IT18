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

// Membuka file log (disini virus.log) yang baru. "a" digunakan sebagai appendix (kalo belum ada file virus.log, bakal di create sama programnya.
void createNewLog(const char *fileName) { 
    time_t rawtime;
    struct tm *timeInfo;
    char currentTime[100];
    FILE *log = fopen("/home/cal/Viruses/virus.log", "a");
    
    if (log == NULL) {
        perror("Failed to open log file. :(");
        exit(EXIT_FAILURE);
    }
    // Dapetin waktu buat dimasukin ke log
    time(&rawtime);
    timeInfo = localtime(&rawtime);
    strftime(currentTime, sizeof(currentTime), "[%d-%m-%Y][%H:%M:%S]", timeInfo);
    fprintf(log, "%s Suspicious string at %s successfully removed!\n", currentTime, fileName);
    fclose(log); // File log di close di line ini.
}

// Duplicates the input content strings (sesuai sama file yang di masukkan).
char *changeContent(char *content) {
    char *replaced = strdup(content);
    if (replaced == NULL) {
        perror("Failed to duplicate string. :(");
        exit(EXIT_FAILURE);
    }

    // Merubah kata aneh menjadi benar, m4LwAr3 menjadi [MALWARE], dan seterusnya...
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
}
// Scans a directory (termasuk juga subdirectories)
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
