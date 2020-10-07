## CRIU- Checkpoint and Restore in Userspace. <br>

This project mainly focuses with live migration of application as process/container levels, which means
userspace level program can be checkpointed and migrated accross the host and can be restored from the previous point.  <br>
This project is extensively written in C programming language as it has been a part of Linux Kernel projects and top level maintainers are 
working on it and others include python and Go for some functionalities like dumped pages and CRIU tools. <br>

For CRIU project on github, vist the page here: https://github.com/checkpoint-restore/criu <br>

## Checkpoint and Restore in Docker container. 
Currently docker lacks support for this feature but still you can checkpoint and restore simple container. 
For testing with docker container you can follow this link. 

- [CRIU on Docker](https://github.com/collabnix/dockerlabs/tree/master/advanced/live%20migration )<br>


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

Voila ! Your train will resume from the point where it was stopped earlier. 

## Testing from the ```example``` directory. 

The ```example``` directory contains bunch of test codes for process/container live migration. 

The ```simple_loop.c``` program written in C language which prints the numeric count.<br>
As the program runs from one console, we inspect the pid of the running program from another console i.e. <br>

	- gcc simple_loop.c
	- ./a.out

From the another console we inspect the pid of running assembler output file i.e. a.out <br>

	- pidof a.out

Now the running program can be dumped using criu library and images files are saved in another directory as shown: <br>

	- mkdir checkpoint
	- criu dump -t <pid> -D checkpoint/ -j -v4

Now the running program is killed and its metadata are stored in the form of image files in checkpoint directory. Now the important
task of checkpoint and restore is restring the killed program from the dumped images files which can be accomplished by following code snippet. <br>

	- criu restore -D checkpoint/ -j


In this way CRIU helps in checkpoint the userspace application and restore them in desired location.<br>


## Checkpointing ```runc``` containers

1. Create a runc config file 

    ```runc spec``` 
2. Create a OCI application bundle with ```skopeo``` and ```umoci```

    ```skopeo copy docker://busybox:latest oci:busybox:latest```
    ```umoci unpack --image busybox:latest bundle```

3. Copy the rootfs directory from bundle
    
    ```sudo cp -r bundle/rootfs . ```

4. Start the runc container 

    ``` sudo runc run test```


