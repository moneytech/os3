#ifndef OS_FILE_DESCRIPTOR_H
#define OS_FILE_DESCRIPTOR_H
#include <stdbool.h>
#include <stdint.h>

// OS/3 does not have a built-in filesystem, so file descriptors
// are actually either:
//   * Standard I/O streams
//   * IPC channels to other processes

typedef enum {
  OS3_FD_STD_STREAM,
  OS3_FD_IPC
} os3_fd_type_t;

typedef struct _os3_blob {
  unsigned int size, foreign_pid;
  uint8_t* data;
  struct _os3_blob* next;
} os3_blob_t;

typedef struct _os3_fd {
  unsigned int id;
	bool is_closed;
  os3_fd_type_t type;
  os3_blob_t *incoming, *outgoing;
  struct _os3_fd* next;
} os3_fd_t;

#endif
