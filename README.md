CRIU- Checkpoint and Restore in Userspace. <br>

This project mainly focuses with live migration of application as process/container levels, which means
userspace level program can be checkpointed and migrated accross the host and can be restored from the previous point.  <br>
This project is extensively written in C programming language as it has been a part of Linux Kernel projects and top level maintainers are 
working on it and others include python and Go for some functionalities like dumped pages and CRIU tools. <br>

For CRIU project on github, vist the page here: https://github.com/checkpoint-restore/criu <br>


## Checkpoint and Restore in podman container. 

Steps for Live Migration

1. Clone the repo. 
``` git clone https://github.com/omegazyadav/live-migration.git ```
2. Go to the podman director. 
``` cd live-migration/podman ``` 
3. Build the podman container. 
``` sudo podman build -t screen_locomotive . ```
4. Run the container interactively. 
``` sudo podman run -i --name sl screen_locomotive ``` 
5. Checkpoint the running container from another terminal. 
``` sudo podman container checkpoint sl ``` 
6. From the another terminal restore the checkpointed container. 
``` sudo podman container restore sl ``` 

Voila ! Your train will resume from the point where it was stoped earlier. 




