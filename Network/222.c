#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

#define FILENAME "base.atl"
#define CHUNK_SIZE 256

typedef struct {
    size_t size;
    uint32_t owner_id;
    uint32_t parent_id;
    uint8_t i_state;
    uint8_t i_type;
    uint8_t i_status;
    char i_name[CHUNK_SIZE];
    char i_path[CHUNK_SIZE];
} Inode;

int main() {
    int fd;
    Inode *inode_ptr;

    // Open or create the file
    fd = open(FILENAME, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Truncate the file to the size of Inode structure
    if (ftruncate(fd, sizeof(Inode)) == -1) {
        perror("Error truncating file");
        close(fd);
        exit(EXIT_FAILURE);
    }
    // Map the file into memory
    inode_ptr = mmap(NULL, sizeof(Inode), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (inode_ptr == MAP_FAILED) {
        perror("Error mapping file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Input values for Inode structure
    printf("Enter size: ");
    scanf("%zu", &(inode_ptr->size));
    printf("Enter owner_id: ");
    scanf("%u", &(inode_ptr->owner_id));
    printf("Enter parent_id: ");
    scanf("%u", &(inode_ptr->parent_id));
    printf("Enter i_state: ");
    scanf("%hhu", &(inode_ptr->i_state));
    printf("Enter i_type: ");
    scanf("%hhu", &(inode_ptr->i_type));
    printf("Enter i_status: ");
    scanf("%hhu", &(inode_ptr->i_status));
    printf("Enter i_name: ");
    scanf("%s", inode_ptr->i_name);
    printf("Enter i_path: ");
    scanf("%s", inode_ptr->i_path);

    // Unmap the file from memory
    if (munmap(inode_ptr, sizeof(Inode)) == -1) {
        perror("Error unmapping file");
    }

    // Close the file
    close(fd);

    return 0;
}

