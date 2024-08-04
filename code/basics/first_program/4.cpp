#include <iostream>
int main()
{
std::cout << 
R"###(
If you try to mimic this build system by hand, you’ll discover that
	' The GNU Build System has a lot of features.
	Some users may expect features you do not use.
	' Implementing them portably is difficult, and exhausting.
	(Think portable shell scripts/portable Makefiles, on systems you may
	not have handy.)
	' You will have to upgrade your setup to follow changes of the GNU
	Coding Standards.
GNU Autotools provide:
	' Tools to create the GNU Build System from simple instructions.
	' A central place where fixes and improvements are made.
	(A bug-fix for a portability issue benefits every package.)
)###";
}
