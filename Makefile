# htserver
#g++ -g -D_REENTRANT -Wall -lresolv -lpthread *.cpp ./server/*.cpp ./std/*.cpp ./setup_item/*.cpp ./setup_npc/*.cpp ./setup_room/*.cpp ./setup_skill/*.cpp -o test

all:
	g++ -g -D_REENTRANT -Wall -lresolv -lpthread -lmysqlclient -lnsl *.cpp ./server/*.cpp ./std/*.cpp ./setup_item/*.cpp ./setup_npc/*.cpp ./setup_room/*.cpp ./setup_skill/*.cpp -o test

main:
	g++ -Wall -c -g -D_GNU_SOURCE -std=c++11 -fPIC *.cpp
	ar rcs libmudos.a *.o
	rm *.o
	g++ -Wall -g -D_GNU_SOURCE -std=c++11 -lresolv -lpthread -lmysqlclient -lnsl -lstdc++ libmudos.a -o esii

lib:
	rm -rf core *.log *.o
	g++ -Wall -c -g -D_GNU_SOURCE -std=c++11 -fPIC ./server/*.cpp
	g++ -Wall -c -g -D_GNU_SOURCE -std=c++11 -fPIC ./combat/*.cpp
	g++ -Wall -c -g -D_GNU_SOURCE -std=c++11 -fPIC ./std/*.cpp
	g++ -Wall -c -g -D_GNU_SOURCE -std=c++11 -fPIC ./sql/*.cpp
	g++ -Wall -c -g -D_GNU_SOURCE -std=c++11 -fPIC ./setup_item/*.cpp
	g++ -Wall -c -g -D_GNU_SOURCE -std=c++11 -fPIC ./setup_npc/*.cpp
	g++ -Wall -c -g -D_GNU_SOURCE -std=c++11 -fPIC ./setup_skill/*.cpp
	g++ -Wall -c -g -D_GNU_SOURCE -std=c++11 -fPIC ./setup_room/*.cpp
	ar rcs libmudos.a *.o
	rm *.o
	g++ -Wall -g -D_GNU_SOURCE -std=c++11 -lresolv -lpthread -I/usr/include/mysql -L/usr/lib/i386-linux-gnu -lmysqlclient -lnsl -lstdc++ libmudos.a -o esii 

libs:
	g++ -Wall -c -g -D_GNU_SOURCE -std=c++11 -I/usr/include/mysql -fPIC *.cpp ./server/*.cpp
	ar rcs libmudos.a *.o
	rm *.o
	g++ -Wall -g -D_GNU_SOURCE -std=c++11 -lresolv -lpthread -lmysqlclient -lnsl -I/usr/include/mysql -L/usr/lib/i386-linux-gnu -lstdc++ libmudos.a -o lt

libo3:
	rm -rf core *.log *.o
	g++ -Wall -c -O3 -D_GNU_SOURCE -std=c++11 -fPIC *.cpp ./server/*.cpp
	g++ -Wall -c -O3 -D_GNU_SOURCE -std=c++11 -fPIC ./combat/*.cpp
	g++ -Wall -c -O3 -D_GNU_SOURCE -std=c++11 -fPIC ./std/*.cpp
	g++ -Wall -c -O3 -D_GNU_SOURCE -std=c++11 -fPIC ./setup_item/*.cpp
	g++ -Wall -c -O3 -D_GNU_SOURCE -std=c++11 -fPIC ./setup_npc/*.cpp
	g++ -Wall -c -O3 -D_GNU_SOURCE -std=c++11 -fPIC ./setup_room/*.cpp
	g++ -Wall -c -O3 -D_GNU_SOURCE -std=c++11 -fPIC ./setup_skill/*.cpp
	ar rcs libmudos.a *.o
	rm *.o
	g++ -Wall -O3 -D_GNU_SOURCE -std=c++11 -lresolv -lpthread -I/usr/include/mysql -L/usr/lib/i386-linux-gnu -lmysqlclient -lnsl -lstdc++ libmudos.a -o esii
	
output:
	g++ -m32 -g -D_GNU_SOURCE -Wall -o esii libmudos.a -lresolv -lpthread -lmysqlclient -lnsl -lstdc++
#End Makefile