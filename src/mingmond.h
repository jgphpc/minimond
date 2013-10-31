#include "storage.h"
#include "collector.h"
#include "display.h"

#define COLLECT_PERIOD 300

void fatal_error(char *s);

/*
 * Ganglia metrics:
 *
 * load_one       One minute load average (module load_module)
 * load_five      Five minute load average (module load_module)
 * load_fifteen   Fifteen minute load average (module load_module)
 * proc_run       Total number of running processes (module proc_module)
 * proc_total     Total number of processes (module proc_module)
 *
 * cpu_aidle      Percent of time since boot idle CPU (module cpu_module)
 * cpu_idle       Percentage of time that the CPU or CPUs were idle and the system did not have an outstanding disk I/O request (module cpu_module)
 * cpu_intr       cpu_intr (module cpu_module)
 * cpu_nice       Percentage of CPU utilization that occurred while executing at the user level with nice priority (module cpu_module)
 * cpu_num        Total number of CPUs (module cpu_module)
 * cpu_sintr      cpu_sintr (module cpu_module)
 * cpu_speed      CPU Speed in terms of MHz (module cpu_module)
 * cpu_steal      cpu_steal (module cpu_module)
 * cpu_system     Percentage of CPU utilization that occurred while executing at the system level (module cpu_module)
 * cpu_user       Percentage of CPU utilization that occurred while executing at the user level (module cpu_module)
 * cpu_wio        Percentage of time that the CPU or CPUs were idle during which the system had an outstanding disk I/O request (module cpu_modul
 * mem_sreclaimableAmount of reclaimable slab memory (module mem_module)
 * os_release     Operating system release date (module sys_module)
 * mem_total      Total amount of memory displayed in KBs (module mem_module)
 * disk_free      Total free disk space (module disk_module)
 * gexec          gexec available (module core_metrics)
 * mem_cached     Amount of cached memory (module mem_module)
 * mtu            Network maximum transmission unit (module sys_module)
 * pkts_in        Packets in per second (module net_module)
 * location       Location of the machine (module core_metrics)
 * bytes_in       Number of bytes in per second (module net_module)
 * swap_total     Total amount of swap space displayed in KBs (module mem_module)
 * bytes_out      Number of bytes out per second (module net_module)
 * mem_free       Amount of available memory (module mem_module)
 * os_name        Operating system name (module sys_module)
 * boottime       The last time that the system was started (module sys_module)
 * sys_clock      Time as reported by the system clock (module sys_module)
 * mem_buffers    Amount of buffered memory (module mem_module)
 * part_max_used  Maximum percent used for all partitions (module disk_module)
 * disk_total     Total available disk space (module disk_module)
 * heartbeat      Last heartbeat (module core_metrics)
 * mem_shared     Amount of shared memory (module mem_module)
 * machine_type   System architecture (module sys_module)
 * e)
 * pkts_out       Packets out per second (module net_module)
 * swap_free      Amount of available swap memory (module mem_module)
 */