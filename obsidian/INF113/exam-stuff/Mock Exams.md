*mock exams made with gpt*

## Section 2
**Q1  - Explain the difference between hard links and soft links**

Hard links and soft links are both methods of creating additional pointers to data in a file system.

The hard link directly references the same data as the original file. You will create a new inode of a new name, which will behold the same privileges. The main data will then never disappear unless all hard links are removed  

The soft link will create an type of inode which will instead point to the point to the original inode for some data, and this will not inherit its privileges. If the original inode is removed, this soft link will not work.

**Q2 - Describe what happens during a page fault and how the operating system resolves it.**

When the Ram/memory sometimes run full, it will swap out some of its pages. I wont go deep into which, but the ones flagged as clean gets prioritized, as this won't lead to a needed write. 

When a page is swapped out its valid/present (book calls it valid, but in linux it will be present) flag will be set to 0.

This if a process now will try to access this entry through the MMU, and it will lead to a page fault exception, it will swap out a on the ram to make space for this data, and update its PTE. Then try again

To gather the right swap file, a page-fault-handler will be used, this controls how its saved in the swap space, and how to get it out.

When the location is set, the DMA will then copy the content from the disk to ram

the second time, the file will be present in the page table, and all will go well.


**Q3 - What are the primary advantages of using RAID 1 (Mirroring) compared to RAID 0 (Striping)**

The main advantage would be its redundancy, as striping will not have any. If one is lucky mirroring could be able to loose N/2 of its disks, if N is the number of disks. 

Then if i just were to quickly mention its drawback that would be its overall write, and read speed, as striping can utilize all N of its disks.

**Q4 - What is the role of base and bound registers in memory management**

Base and bound registers are used in two early concepts for mapping from virtual memory to memory (vram to ram).

The first technique is called base and bounds, where it will set off equally big slice of physical memory as the virtual space has allocated.

The information is used to check if the virtual address is out of bounds, and for the translation to physical memory. This translation is done like this: base + Virtual address = Physical address. It will also do a calculation to check if this is within the bounds, which ads to the security.

This requires an MMU which will do this translation super fast. For every context switch these registers will be saved in the context "file", and be switched out for the new process base and bounds

Another concept which uses builds upon this concept, which handles its main problem - internal fragmentation. This is called segmentation, which uses multiple base and bounds registers. Typically one for heap, stack, and program code, but this could be subdivided more. This is basically the same concept but splitted up more, which can lead external fragmenting, which can cause segmentation fault.


**Q5  - Briefly explain how a CPU handles an I/O request using interrupts. Why is this more efficient than polling?**

- When a process polls, it wastes useful compute time which could've been used form something else. That is why when a I/O request is sent it will do something else, and then ISR will send an interrupt when the I/O is done, and then depending on the scheduler, it can eventually switch back

**Q6 - How does the Log-Structured File System (LFS) handle crash recovery differently than traditional file systems?**
- LFS uses sequential writes and maintains an inode map. Crash recovery involves reading the latest checkpoint and imap, ensuring consistency.
- We also uses two CRs which will ensure that always one of then is consistent
- And we never overwrite files, so going back to the old version will never be wrong


# Mock exam 2

## Virtualization

**Question 1** - Explain how the **kernel** in an operating system manages system resources. Include examples of how it handles memory and process management.
- There is three main resources the kernel needs to distribute, which is CPU processing time,  memory usage (RAM), and the physical storage.
- The kernel uses syscalls to interact with the hardware, so that the user has to then interact with the kernel for the resources available.
- The kernel will virutalize the the memory for each process so they don't have worry about the actual size
- The same goes for processing time, each process acts as if they are processing in one single sequence, but the kernel does context switches both to manage the context switches, but also to share the time with other processes

**Question 2** - Define **virtual memory** and explain how it allows a system to run processes that require more memory than physically available. Include the roles of **paging** and **page tables**.
-  Depending on system, but we will take the standpoint of an 32 bit CPU, this will allow up to $2^{32}$ different virtual addresses. This is ignoring the small designated kernel part of the virtual space.
- This will then get splitted up into 4kB blocks of data, called pages. So this means that if a process is going to use data, it will round up to however many pages it will fit into.
	- 4kB is chosen so pages will fit with sectors in HDDs, as this is more or less a standardized size.
- Then to map from virtual address, and to the physical address, we use something called page tables, in smaller system with not that many addresses such as in in the 32bit they will have their own entry. In bigger systems, this will be a lot of overhead.
- then this entry will be saved in this manner:
	- VPN | PFN | flags, in the flags is where the present/valid is saved
	
- This can be a bit slow, as we have to do two reads from RAM, to get the data we want, so that is why we have a TLB in the MMU which can save a certain amount of entries, i think 32, 64, and 128 is a normal range. Which memory should stay here differs from what policy we use

- The physical memory is also split up into 4kB, this is so that that the same offset in an virtual page in an physical frame

**Question 3** - Describe the differences between **segmentation** and **paging** as memory management techniques. What are the advantages and disadvantages of each?
- The core advantage with paging over segmentation is that segmentation requires 1-1 mapping of from the amount of virtual space memory and memory.
- Paging on the other hand can have an arbitrary amount of virtual space, without needing to have a physical addr for it, this is good as each process doesn't have think about how much memory is left, that is the kernels  job.

**Question 4** - Outline the process of **address translation** in a system with multi-level page tables. Use a concrete example with a virtual address to demonstrate the translation process.
- The incredibly large virtual memory space, would technically require unnecessary amount of space for the Page Table. This is bad as multiple of these pages are unused. 
- That is why the page directory is broken down into pages again.
- Basically some kind of directory, this way if an directory is empty it doesn't need to point to all of the underlying pages, thus saving space.
- In an modern architecture 4 layers of this is normal, as 64 bit computers has a lot more virtual memory 

**Question 5** - Explain the role of the **Translation Lookaside Buffer (TLB)** in improving memory access performance. Include a discussion on TLB misses and context switches.
- The Translation Lookaside Buffer (TLB) is a cache in in the MMU module. When using a page table, the lookup can be slow, as one has to read 2+ addresses to find your data. 
- That is why the TLB buffer will cache the last used PTE
- It will keep if it is valid, if you can read/write to it
- In an context switch there is two options, flush the whole cache when switching, or we need to tag each entry with en process identifier tag so that we don't use another process's data

**Question 6** - Explain the difference between **user mode** and **kernel mode**. How does the system transition between these modes during a syscall?
- This is a way to ensure safety in our programs
- Kernel mode allows unrestricted access to our hardware. A trap instruction transitions the system during a syscall.

**Question 7** - Describe how **context switching** enables multitasking in operating systems. Include examples of what data is saved and restored during a switch.
- Open files, user-id, process id, the instruction counter, %rip, and general memory

**Question 8** - Compare **cooperative switching** and **preemptive switching**. Provide an example scenario where each method might be preferred.
- Cooperative switching consists of the program voluntarily giving the kernel time to run, this can be done with syscalls.
- Then preemptive switching happens at a preset interval, the OS sends an interrupt. This can be avoided, but then you have to state this beforehand

**Question 9** 
- The virtual runtime is based on the priority of an process, but also take into account how important all the other processes, to then assign it a runtime value
+ Then the lowest vruntime will run
- The Sched value will be something ike 40ms/proc number and each process will get a proportional time of this value depending on their nice value

**Question 10**
- Turnaround time
	- This one you would have to know how long a process is, which is not always the case.
	- This would be pretty good otherwise
- FIFO
	- If the first one is super long, would you do this one first
- Round Robin
	- This assumes that incoming processes are short
	- 

**Question 11**
+ Journaling is something introduced in ext4 to solve a recurrent problem. If the system where to crash whilst writing something, is everything in place after, was we able to finish and such.
+ This is clever way to only say we are finished writing data into memory once we know for sure it is there.
+ It works very cleverly by using a dedicated part in memory, where it can be written in sequence as a small checkpoint
+ TxB| bitmap.v2 | inode.v2 | TxE
+ This will also include checksums to ensure that this is correct along with a checksum containing all of the data in TxE
- This will be a entry in our journal, and it wont be removed (the beginning pointer moves to next entry) before it is all written out

**Question 12** 
+ RAID levels 0 is striping, which basically mean that you split your data in different disks in a pattern, this make you able to parallelized reading things sequentially. And if randomly it would also be as fast. The down side is that there is no redundancy, if a bit flips or you loose a whole drive, you cannot get that data back
+ RAID level 1 is when you mirror your data, this will lead to redundancy up to N/2 if you are lucky. The only downside is that it takes Longer to write.
	+ S/2 and R/2 as it has to be mirrored
	- Suprisingly the S/2 is also in the read sequentially, this is bc we want the right data in the right order. Therefore the seq read is S/2.
	- Random read will only be R/2
- RAID level 5 will be distributed parity, something which can survive a whole disk as redundancy. This is bc all the lost bits are a part of the parity in some other disk, and the lost parity of this disk can be built again
	- this will have a performance of (N-1) *R Since the data is now distributed
	- compared to the level 4 were it is only R/2


**Question 13** - Describe how **Log-structured File Systems (LFS)** manage writes and crash recovery. What are the roles of the **imap** and **checkpoint region**?
- The main difference behind LFS is that it is copy-on-write, which means that it will never overwrite other data
- When adding new data it usually gathers together data before doing a bigger sequential write
	- this will be collected in a write buffer
- It can do it this way, and this will be along with all of the updated inodes towards some data. In the end there will be an imap which says what inode it includes.
- Then we have not changed anything yet, we have just written extra data, then when we want to use this new version we just add the imap pointer in the CR and if this goes wrong we have another in the end which will will be okey
- The old one will get taken away with an garbage truck

**Question 14**
- The block bitmap and inode bitmap will show which inode and which block are free and which are in use. This is important as we dont want to overwrite stuff

**Question 15** - DMA
- The DMA will take control of moving data, the CPU will just say what data, where it will go and how big it is. This way the cpu doenst have to poll everytime it is going to fetch data, and instead.