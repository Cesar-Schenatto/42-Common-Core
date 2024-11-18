collect_info()
{
    echo "------------------------------------------------------" 
    echo "System Status" 
    echo "------------------------------------------------------" 

    echo "Architecture: $(uname -m)"   
    echo "Kernel Version: $(uname -r)" 

    echo "Physical Processors: $(grep -c '^physical id' /proc/cpuinfo)" 
    echo "Virtual Processors: $(nproc)" 
	
    total_ram=$(free -m | awk '/Mem:/ {print $2}') 
    used_ram=$(free -m | awk '/Mem:/ {print $3}') 
    ram_percentage=$((100 * used_ram / total_ram))
    echo "RAM Usage: $used_ram/$total_ram MB ($ram_percentage%)" 

    total_storage=$(df -h --total | awk '/total/ {print $2}')
    used_storage=$(df -h --total | awk '/total/ {print $3}') 
    storage_percentage=$(df -h --total | awk '/total/ {print $5}')
    echo "Storage Usage: $used_storage/$total_storage ($storage_percentage)" 

    cpu_usage=$(top -bn1 | grep "Cpu(s)" | awk '{print $2 + $4}')
    echo "CPU Usage: $cpu_usage%" 

    last_reboot=$(uptime -s)
    echo "Last Reboot: $last_reboot" 

    lvm_status=$(lvs > /dev/null 2>&1 && echo "Active" || echo "Inactive") 
    echo "LVM Status: $lvm_status" 
	
    active_connections=$(ss -tun | grep -c ESTAB)
    echo "Active Connections: $active_connections" 

    logged_in_users=$(who | wc -l)
    echo "Logged-in Users: $logged_in_users" 

    ipv4_address=$(hostname -I | awk '{print $1}') 
    mac_address=$(ip link show | awk '/ether/ {print $2}' | head -n 1) 
    echo "IPv4 Address: $ipv4_address" 
    echo "MAC Address: $mac_address" 

    sudo_commands=$(journalctl _COMM=sudo | grep -c COMMAND)
    echo "Sudo Commands Executed: $sudo_commands"

    echo "-----------------------------------------------------"	
}

collect_info | wall
