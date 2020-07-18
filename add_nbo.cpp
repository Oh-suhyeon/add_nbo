#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h>
#include <math.h>


int main(int argc, char *argv[]) {

	char buf[1024];
	int len;
	FILE *fd1, *fd2;
	fd1 = fopen(argv[1], "r");
	fd2 = fopen(argv[2], "r");

	while ( len=fread(buf, 1, 256, fd1)  )
	{
		buf[len] = '\0';
	}
	uint32_t* p = reinterpret_cast<uint32_t*>(buf);
	uint32_t n = ntohl(*p);



	while ( len=fread(buf, 1, 256, fd2)  )
	{
		buf[len] = '\0';
	}

	uint32_t* p1 = reinterpret_cast<uint32_t*>(buf);
	uint32_t n1 = ntohl(*p1);


	int sum=0;
	sum = n + n1;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n, n, n1, n1, sum, sum);
}
	


