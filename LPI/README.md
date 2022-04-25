# Taken from 'The Linux Programming Interface: A Linux and UNIX System Programming Handbook', by Michael Kerrisk

## Basic Idea
* Make Directories per chapter

### Selected System Data Types
* OR just man system_data_types

| Data Type    | SUSv3 Type Requirement    | Description                                |
| :--          | :--                       | :--                                        |
| blkcnt_t     | signed integer            | File block count (Section 15.1)            |
| blksize_t    | signed integer            | File block size (Section 15.1)             |
| cc_t         | unsigned integer          | Terminal special character (Section 62.4)  |
| clock_t      | integer or real-floating  | System time in clock ticks (Section 10.7)  |
| clockid_t    | an arithmetic type        | Clock identifier for POSIX.1b              |
| comp_t       | not in SUSv3              | Compressed clock ticks (Section 28.1)      |
| dev_t        | an arithmetic type        | Device # consisting of major and minor #'s |
| DIR          | no type requirement       | Directory stream (Section 18.8)            |
| fd_set       | structure type            | File descriptor set for select()           |
| fsblkcnt_t   | unsigned integer          | File-system block count (Section 14.11)    |
| fsfilcnt_t   | unsigned integer          | File count (Section 14.11)                 |
| gid_t        | integer                   | Numeric group identifier (Section 8.3)     |
| id_t         | integer                   | generic type for holding identifiers*      |
| in_addr_t    | 32-bit unsigned integer   | IPv4 address (Section 59.4)                |
| in_port_t    | 16-bit unsigned integer   | IP port number (Section 59.4)              |
| ino_t        | unsigned integer          | File i-node number (Section 15.1)          |
| key_t        | an arithmetic type        | System V IPC key (Section 45.2)            |
| mode_t       | integer                   | File Permissions and Type                  |
| mqd_t        | anything BUT array type   | Posix message queue descriptor             |
| msglen_t     | unsigned integer          | Number of bytes allowed in System V m*     |
| msgqnum_t    | unsigned integer          | Counts of messages in System V message q*  |
| nfds_t       | unsigned integer          | Number of file descriptors for poll()      |
| nlink_t      | integer                   | Count of (hard) links to a file            |
| off_t        | signed integer            | File offset or size                        |
| pid_t        | signed integer            | Process ID, process group ID, session ID   |
| ptrdiff_t    | signed integer            | Difference between two pointer values*     |
| rlim_t       | unsigned integer          | Resource limit (Section 36.2)              |
| sa_family_t  | unsigned integer          | Socket address family (Section 56.4)       |
| shmatt_t     | unsigned integer          | Count of attached processes for a*         |
| sig_atomic_t | integer                   | Data type that can be atomically accessed  |
| siginfo_t    | structure type            | Information about the origin of a signal   |
| sigset_t     | integer or structure type | Signal set (Section 20.9)                  |
| size_t       | unsigned integer          | Size of an object in bytes                 |
| socklen_t    | integer type 32 bits*     | Size of a socket addr structure in bytes   |
| speed_t      | unsigned integer          | Terminal line speed (Section 62.7)         |
| ssize_t      | signed integer            | Byte count or (negative) error indication  |
| stack_t      | structure type            | Description of an alternate signal stack   |
| suseconds_t  | signed integer*           | Microsecond time interval (Section 10.1)   |
| tcflag_t     | unsigned integer          | Terminal mode flag bit mask                |
| time_t       | integer or real-floating  | Calendar time in seconds since the Epoch   |
| timer_t      | an arithmetic type        | Timer identifier for POSIX.1b*             |
| uid_t        | integer                   | Numeric user identifier (Section 8.1)      |


* clockid_t 		= Clock identifier for POSIX.1b clock and timer functions 
* id_t			= generic type for holding identifiers; large hold at least pid_t, uid_t, and gid_t
* msglen_t		= Number of bytes allowed in System V message queue
* msgqnum_t		= Counts of messages in System V message queue
* ptrdiff_t		= Difference between two pointer values, as a signed integer
* shmatt_t		= Count of attached processes for a System V shared memory segment (Section 48.8)
* timer_t 		= Timer identifier for POSIX.1b interval timer functions
* socklen_t		= integer type of at least 32 bits
* suseseconds_t 	= signed integer allowing range [–1, 1000000]
