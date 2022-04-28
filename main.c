#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>
#include <unistd.h>
#define HIGHLIGHT   "\x1B[31m \033[1m"
#define ENDHL "\033[0m"
// dedicated to colleen 


int main () {

// system info stuff
char *currentUser = getenv("USER");
char *desktopenv = getenv("DESKTOP_SESSION"); 

char hostname[1024];
gethostname(hostname, 1024);

struct sysinfo sysi;
sysinfo (&sysi);

// conversions!!
 const long minute = 60;
 const long hour = minute * 60;
 const long day = hour * 24;
 const double megabyte = 1000 * 1000;

// printf(HIGHLIGHT " " ENDHL "");
// Display highlighted info 
 printf(HIGHLIGHT ">------------------------------------\n" ENDHL);
 printf(HIGHLIGHT "de - " ENDHL "%s\n", desktopenv);
 printf(HIGHLIGHT "system uptime - " ENDHL "%ld:%ld:%02ld:%02ld\n", (sysi.uptime / day), (sysi.uptime % day) / hour, (sysi.uptime % hour) / minute, sysi.uptime % minute);
 printf (HIGHLIGHT  "ram - "  ENDHL "%5.1f MB\n" , sysi.totalram / megabyte);
 printf (HIGHLIGHT  "free ram - " ENDHL "%2.1f MB\n", sysi.freeram / megabyte);
 printf (HIGHLIGHT  "user - "  ENDHL "%s@%s \n", currentUser, hostname );
 printf (HIGHLIGHT ">------------------------------------\n" ENDHL);
 return 0;
}
