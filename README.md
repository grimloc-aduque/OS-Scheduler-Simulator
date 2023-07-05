# OS-Scheduler-Simulator

Scheduler simulator with the following components:
* Processes (IO/CPU bound)
* Scheduling Algorithms (Priority/RoundRobin/ShortestJob)
* Virtual CPU time
* Interruptions
* Context Switching

The simulator has two modes: interactive and benchmark

# Compilation

Run the [compile.sh](./compile.sh) script to compile all three versions of the simulator

```
bash ./compile.sh
```

# Execution

The executable files are:
```
./out/priority_scheduling_simulator

./out/round_robin_scheduling_simulator

./out/shortes_job_scheduling_simulator
```

Simulation modes supported via cmd arguments.

## Interactive Mode

Run the executable with the -i flag
```
./out/<scheduling_algorithm>_scheduling_simulator -i
```

<font size="1">

Example execution:

```
--------------------
TOTAL CPU CYCLES: 2
TOTAL CPU TIME: 1.000 [s]
PROCESSES INFO
[-] FINISHED: 
[+] EXECUTING: 
[Process] ID:1 - Priority:67 - CPU_Start_Cycle:0 - CPU_End_Cycle:-1 - CPU_Total_Cycles:65 - IO_ratio:0.12 - State:EXECUTING - CPU_Cycles:1
[*] READY: 
[Process] ID:2 - Priority:56 - CPU_Start_Cycle:0 - CPU_End_Cycle:-1 - CPU_Total_Cycles:65 - IO_ratio:0.70 - State:READY - CPU_Cycles:0
[Process] ID:3 - Priority:43 - CPU_Start_Cycle:0 - CPU_End_Cycle:-1 - CPU_Total_Cycles:20 - IO_ratio:0.06 - State:READY - CPU_Cycles:0
[Process] ID:4 - Priority:108 - CPU_Start_Cycle:0 - CPU_End_Cycle:-1 - CPU_Total_Cycles:72 - IO_ratio:0.77 - State:READY - CPU_Cycles:0
[Process] ID:5 - Priority:23 - CPU_Start_Cycle:0 - CPU_End_Cycle:-1 - CPU_Total_Cycles:67 - IO_ratio:0.06 - State:READY - CPU_Cycles:0
[!] BLOQUED: 
[Process] ID:0 - Priority:17 - CPU_Start_Cycle:0 - CPU_End_Cycle:-1 - CPU_Total_Cycles:65 - IO_ratio:0.61 - State:BLOQUED - CPU_Cycles:1
[?] INCOMING: 
--------------------

...

```
</font>



## Benchmark Mode

Run the executable with the -b flag
```
./out/<scheduling_algorithm>_scheduling_simulator -b
```
The benchmark mode compares the turn around time and throughput of the simulator at different ratios of CPU/IO bound processes.

<font size="1">

Example execution:

```
--------------------> IO/CPU: 0.10/0.90

* Repetition 1

--------------------
TOTAL_PROCESSES: 100
TOTAL_CPU_CYCLES: 5674
TOTAL_CPU_TIME: 1.702 [s]
THROUGHPUT: 211491 [P/h]
TURNAROUND_TIME: 1.156 [s]
--------------------

...
```
</font>


## User Mode

Run the executable with the -u flag
```
./out/<scheduling_algorithm>_scheduling_simulator -u
```

Receives process information:
* Priority
* CPU_Start_Cycle
* CPU_Total_Cycles
* IO_ratio

Some input examples for the user mode are as follows:

Without IO

```
5
2 0 9 0
4 0 7 0
4 0 5 0
1 2 6 0
3 5 3 0
```

With IO

```
5
2 0 9 0.5 
4 0 7 0.3 
4 0 5 0.2 
3 2 6 0.1 
1 5 3 0.2 
```
