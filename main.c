
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "./util.h"
#include "./process.h"
#include "./scheduler.h"

// BENCHMARK

void generate_random_processes(int num_processes, double IO_proportion){
    Process* process = NULL;
    for(int i=0; i<num_processes; i++){
        if(rand_probability()<IO_proportion)
            process = init_random_IO_process();
        else
            process = init_random_CPU_process();
        add_process_to_scheduler(process);
    }
}

void run_benchmark_simulation(double IO_proportion){
    int num_repetitions = 3;
    printf("\n\n--------------------> IO/CPU: %.2f/%.2f\n\n", IO_proportion, 1 - IO_proportion);
    for(int i=0; i<num_repetitions; i++){
        printf("* Repetition %d\n", i + 1);
        init_scheduler_params();
        generate_random_processes(NUM_PROCESSES, IO_proportion);
        benchmark_simulation();
    }
}

void run_IO_benchmark_comparison(){
    init_scheduler_queues();
    run_benchmark_simulation(0.1);
    run_benchmark_simulation(0.5);
    run_benchmark_simulation(0.9);
    free_scheduler_memory();
}

// INTERACTIVE

void run_interactive_simulation(){
    init_scheduler_queues();
    init_scheduler_params();
    int num_processes = 6;
    for(int i=0; i<num_processes/2; i++){
        add_process_to_scheduler(init_random_IO_process());
        add_process_to_scheduler(init_random_CPU_process());
    }
    interactive_simulation();
    free_scheduler_memory();
}

void read_input_processes(){
    printf("\nNumber of processes: ");
    int num_processes;
    scanf("%d", &num_processes);
    for(int i=0; i<num_processes; i++){
        Process* process = init_input_process();
        add_process_to_scheduler(process);
    }
}

void run_user_simulation(){
    init_scheduler_queues();
    init_scheduler_params();
    read_input_processes();
    interactive_simulation();
    free_scheduler_memory();
}


// MAIN

int main(int argc, char const *argv[]){
    srand(time(NULL));
    if(argc == 2){
        if(strcmp(argv[1], "-b") == 0)
            run_IO_benchmark_comparison();
        if(strcmp(argv[1], "-i") == 0)
            run_interactive_simulation();
        if(strcmp(argv[1], "-u") == 0)
            run_user_simulation();
    }else{
        run_interactive_simulation();
    }
    return 0;
}
