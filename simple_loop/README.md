This directory contains the information of checkpoint and restore of the simple program.<br>

Here in this example we have taken a simple loop program written in C language which prints the counting starting from 1.<br>
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
