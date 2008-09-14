
#ifndef ERL_COMM_H__
#define ERL_COMM_H__

typedef unsigned char byte;

int read_cmd(byte *buf);

int write_cmd(byte *buf, int len);

int read_exact(byte *buf, int len);

int write_exact(byte *buf, int len);

#endif //ERL_COMM_H__
