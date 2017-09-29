#include <cstdio>
using namespace std;

inline char read_valid_char() {
	char c;
	for (c=getchar();c==' ';c=getchar());
	return c;
}

void proc_expr() {
	char c[2];
	c[0]=read_valid_char();
	if (c[0]=='+') {
		proc_expr();
		printf(" ");
		proc_expr();
		printf(" +");
	} else if (c[0]=='-') {
		proc_expr();
		printf(" ");
		proc_expr();
		printf(" -");
	} else {
		c[1]=0;
		printf(c);
	}
}

int main() {
	proc_expr();
	return 0;
}
