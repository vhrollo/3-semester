Policies
- fifo

$C \leftrightarrow asm \leftrightarrow maskinkode$

**C**
+ built to be independent of machine hardware
- compiled to asm, machine relative
**asm**
- compiled to something.S
**Linker**
- Linker takes all the object files and makes an executable


# Memory
*Max virtual space is 0x7ffff*

- code
- global 
- vars
- heap
- ...


rbp base pointer 
- $-8(\%rbp)$

**Base & Bounds**
- cannot pretend to have more  space than physical memory has
- was too ass so it was changed to the segmentation model

# Segmentation
Emtpy memory is no longer reserved


# Paging

Equally sized memory frames

4 Kb basically standard to match hdd sectors

Page table can be split up into a tree


Pages of constant size


# Swap disk

disk frames matches frame size

**Swapping policies**


# Hard saving

plats
spinning
sector
- 4kB
- this is for easy of swapping


**How to organize the files**


## VSFS
- blocks 
- 4kB

## Ext2
SB |


failproof the system

using journaling


# Log based system

check what the first and last block is named


# RAID


## ZFS
chekc if zfs had  blocks are infront and at the end
- atomic transactions


Part with multiple choice
- to describe things

reflect between two concepts

One big in the end where you describe the process of something in the system