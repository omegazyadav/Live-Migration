# Getting started with container live migration using docker containers.

## Pre-requisites
- Understanding of virtualization concepts
- Understanding of Live Migration in virtualized environment

# Introduction to the Container Live Migration:
Containers are just a linux processes running in the namespace of the underlying kernel and can be checkpointed in the form of images. Such images i.e. metadata of the checkpointed container can be copied into the another containers and can be restored there hence resuming the previously checkpointed task in the namespace of another container. 
Docker comes with the inbuilt features of checkpointing the running containers which can be performed on play-on-docker platform with some modifications on the running docker daemon.

Docker checkpoint/restore features are backed by the seperate project called Checkpoint and Restore in Userspace and abbreviated as CRIU. This project deals with the container migration with various migratin protocols liek lazy migration, live migration, diskless migration, zero downtime migration, etc.

For more information regarding criu project, you can visit the following link and they have seperate mailing list if you want to contribute to it. 

- [CRIU Project](https://criu.org/Main_Page) <br>

- [CRIU github](https://github.com/checkpoint-restore) <br>

