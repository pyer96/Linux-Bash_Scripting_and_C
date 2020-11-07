/*
 *
 * This program reads a text file and copies it in reversed format into
 * another file. The input file and the output one are passed
 * through the arg verctor
 *
 * ./a.out <input_file> <output_file>
 *
 *
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

off_t get_file_size(int fd) {
  off_t before = lseek(fd, 0, SEEK_CUR);
  off_t ret = lseek(fd, 0, SEEK_END);
  lseek(fd, before, SEEK_SET);
  return ret;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    dprintf(2, "Wrong Usage: 2 arguments needed \
			  to specify input file and output file\n");
    exit(1);
  }
  int input_file = open(argv[1], O_RDONLY);
  int output_file =
      open(argv[2], O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
  off_t filesize = get_file_size(input_file);
  char *file = (char *)malloc((size_t)filesize * sizeof(char));
  if (read(input_file, file, filesize) != filesize) {
    perror("\nError while reading the file");
    exit(1);
  }
  for (ssize_t index = filesize - 1; index >= 0; index--) {
    if (write(output_file, &file[index], 1) != 1)
      perror("\nError while writing the file");
  }
  if (close(input_file) == -1 || close(output_file) == -1)
    perror("\nError while closing file descriptors");
  return 0;
}
