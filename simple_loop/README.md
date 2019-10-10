CRIU- Checkpoint and Restore in Userspace. <br>

This project mainly focuses with live migration of application as process/container levels, which means
userspace level program can be checkpointed and migrated accross the host and can be restored from the previous point.  <br>
This project is extensively written in C programming language as it has been a part of Linux Kernel projects and top level maintainers are 
working on it and others include python and Go for some functionalities like dumped pages and CRIU tools. <br>

This directory contains the information of checkpoint and restore of the simple program.<br>

Here in this example we have taken a simple loop program written in C language which prints the counting starting from 1.<br>
As the program runs from one console, we inspect the pid of the running program from another console i.e. <br>

	- gcc simple_loop.c <br>
	- ./a.out <br>

From the another console we inspect the pid of running assembler output file i.e. a.out <br>
	- pidof a.out <br>

Now the running program can be dumped using criu library and images files are saved in another directory as shown: <br>
	- mkdir checkpoint <br>	
	- criu dump -t <pid> -D checkpoint/ -j -v4 <br>

Now the running program is killed and its metadata are stored in the form of image files in checkpoint directory. Now the important 
task of checkpoint and restore is restring the killed program from the dumped images files which can be accomplished by following code snippet. <br>

	- criu restore -D checkpoint/ -j <br> 


In this way CRIU helps in checkpoint the userspace application and restore them in desired location.<br>
