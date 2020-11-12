#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/inotify.h>
#include<unistd.h>
#define EVENT_SIZE  (sizeof (struct inotify_event))
#define BUF_LEN (1024 * (EVENT_SIZE + 16))
int main(){
    int longitud,i=0;
    int fd,wd;
    char buffer[BUF_LEN];
    fd=inotify_init();
    if(fd<0)
        perror("inotify_init");
    wd=inotify_add_watch(fd,"autos",IN_MODIFY | IN_CREATE | IN_DELETE);
    longitud=read(fd,buffer,BUF_LEN);
    if(longitud<0)
        perror("read");
    while(i<longitud){
        struct inotify_event *event =(struct inotify_event*)&buffer[i];
        if(event->mask &IN_CREATE)
            printf("El archivo %s ha sido creado\n",event->name);
        if(event->mask &IN_MODIFY)
            printf("El archivo %s ha sido modificado\n",event->name);
        if(event->mask &IN_DELETE)
            printf("El archivo %s ha sido eliminado\n",event->name);
    
        i+=EVENT_SIZE+event->len;
    }
        (void)inotify_rm_watch(fd,wd);
        (void)close(fd);
    
}
