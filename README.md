CRIU- Checkpoint and Restore in Userspace. <br>

This project mainly focuses with live migration of application as process/container levels, which means
userspace level program can be checkpointed and migrated accross the host and can be restored from the previous point.  <br>
This project is extensively written in C programming language as it has been a part of Linux Kernel projects and top level maintainers are 
working on it and others include python and Go for some functionalities like dumped pages and CRIU tools. <br>
For CRIU project on github, vist the link below:<br>

    	https://github.com/checkpoint-restore/criu 


Implementation strategies for Live migration are:
1. Pre Copy
2. Post Copy 
	- Post copy is also known as Lazy migration.   
The CRIU project also provides the summer internship through GSoC program. Some projects for upcoming Google Summer of Code are given in : https://criu.org/Google_Summer_of_Code_Ideas .  
