#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
#include "tuya_log.h"
#include "tuya_error_code.h"
#include "system_interface.h"
#include "mqtt_client_interface.h"
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>
#include <unistd.h>
#include <argp.h>
#include "become_daemon.h"
#include "tuya_funcions.h"

tuya_mqtt_context_t client_instance;
tuya_mqtt_context_t* client = &client_instance;

static void sig_handler()
{
    tuya_mqtt_disconnect(client);
    tuya_mqtt_deinit(client);
    closelog();
    exit(0);
}

int main(int argc, char** argv)
{   
    int ret = OPRT_OK;
    char doc[] = "Program to communicate with tuya cloud";
    char args_doc[] = "Device-ID Pruduct-ID Device-secret";
    struct argp_option options[] = {
        {"device-ID", 'd', "Dev-ID", 0, "Enter Device ID", 0},
        {"product-ID", 'p', "Prod-ID", 0, "Enter Product ID ", 0},
        {"device-secret", 's', "Dev-S", 0, "Enter Device secret", 0},
        {"start-as-daemon", 'b', 0, 0, "Start as daemon", 0},
        {0}
    };
    struct argp argp = {options, parse_opt, args_doc, doc, 0, 0, 0};
    
    //argp begin
    struct arguments arguments;
    arguments.start_as_daemon = 0;
    ret = argp_parse (&argp, argc, argv, 0, 0, &arguments);
    if (argc < 7){
        ret = -1;
        return ret;
    }
    // argp end

    signal(SIGINT,sig_handler);
    signal(SIGQUIT,sig_handler);
    signal(SIGTERM,sig_handler);

    const char *LOGNAME = "TUYA_COMM";
    openlog(LOGNAME, LOG_PID, LOG_USER);
    
    // daemon begin
    if(arguments.start_as_daemon == 1){
        ret = become_daemon(0); 
        if(ret)
        {
            syslog(LOG_USER | LOG_ERR, "error starting daemon process");
            goto closelog;
        }
        syslog(LOG_USER | LOG_INFO, "starting daemon process");
    }
    // daemon end

    ret = tuya_mqtt_init_function(client,&arguments);
    if(ret != OPRT_OK){
        syslog(LOG_USER | LOG_ERR, "error initiating mqtt");
        goto closelog;
    }
    syslog(LOG_USER | LOG_INFO, "success initiating mqtt");

    ret = tuya_mqtt_connect(client);
    if(ret != OPRT_OK){
        syslog(LOG_USER | LOG_ERR, "error connecting to mqtt");
        goto deinit;
    }
    syslog(LOG_USER | LOG_INFO, "success connecting to mqtt");

    for (;;) {
        /* Loop to receive packets, and handles client keepalive */
        send_f_m_p_to_tuya(client);
        tuya_mqtt_loop(client);
    }
    tuya_mqtt_disconnect(client);
    deinit:
    tuya_mqtt_deinit(client);
    closelog:
    closelog();
    return ret;
}
