//C++ libraries
#include <stdio.h>
#include <iostream>

//Pico
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "lwip/apps/http_client.h"

//FreeRTOS
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

//Custom
#include "stepper_motor.hpp"


void result(void* arg, httpc_result_t httpc_result, u32_t content_length, u32_t srv_res, err_t error) {
    std::cout << "Result callback called" << std::endl;
}


err_t headers(httpc_state_t* connection, void* args, struct pbuf* hdr, u16_t length, u32_t content_length){
    std::cout << "Header callback called" << std::endl;



    return ERR_OK;

}

err_t body (void* arg, struct altcp_pcb* conn, struct pbuf* p, err_t err) {
    std::cout << "Body callback called" << std::endl;


    return ERR_OK;
}



int main () {
    stdio_init_all();

    cyw43_arch_init();

    sleep_ms(1000);

    std::cout << "Program Starting" << std::endl;

    sleep_ms(5000);

    std::cout << "\n Trying to connect to network" << std::endl;

    char ssid[] = "stashina";
    char pass[] = "9713445290";
    uint32_t auth = CYW43_AUTH_WPA2_MIXED_PSK;


    cyw43_arch_enable_sta_mode();
    netif_set_hostname(netif_default, "mypicow");

    int connectionResult = cyw43_arch_wifi_connect_timeout_ms(ssid, pass, auth,10000);

    int connectionResultFromLinkStatus = cyw43_wifi_link_status(&cyw43_state,CYW43_ITF_STA);

    sleep_ms(5000);

    std::cout << "Connection Result: " << connectionResult << std::endl;
    std::cout << "Connection Result: " << connectionResultFromLinkStatus << std::endl;

    std:: cout << "IP: " << ip4addr_ntoa(netif_ip_addr4(netif_default)) << std::endl;
    std::cout << "Mask: " << ip4addr_ntoa(netif_ip_netmask4(netif_default)) << std::endl;
    std::cout << "Gateway: " << ip4addr_ntoa(netif_ip_gw4(netif_default)) << std::endl;
    std::cout << "Host Name: " << netif_get_hostname(netif_default) << std::endl;


    std::cout << "Attempting to connect to example.com" << std::endl;

    httpc_connection_t settings;
    settings.result_fn = result;
    settings.headers_done_fn = headers;


    err_t error = httpc_get_file_dns(
        "example.com",
        80,
        "/index.html",
        &settings,
        body,
        NULL,
        NULL
    );

    printf("status %d \n", error);


    while (true) {
        //std::cout << "While loop" << std::endl;
        sleep_ms(500); 
    }

    return 0;
}



// /**
//  * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
//  *
//  * SPDX-License-Identifier: BSD-3-Clause
//  */

// #include "pico/stdlib.h"
// #include "stepper_motor.hpp"
// #include <iostream>
// #include <stdio.h>
// #include <math.h>
// #include "FreeRTOS.h"
// #include "task.h"
// #include "queue.h"
// #include "pico/cyw43_arch.h"
// #include "lwip/apps/http_client.h"


// void vBlinkTask(void *test)
// {

//     //    for (;;) {

//     //       gpio_put(PICO_DEFAULT_LED_PIN, 1);

//     //       vTaskDelay(250);

//     //       gpio_put(PICO_DEFAULT_LED_PIN, 0);

//     //       vTaskDelay(250);

//     //    }
// }

// void turntableMotorTest(void *param)
// {
//     StepperMotor motor(19, 18, 17, 16);

//     int direction = 1;

//     while (true)
//     {
//         motor.rotateAngle(M_PI / 2 * direction);

//         if (direction == 1)
//         {
//             direction = -1;
//         }
//         else
//         {
//             direction = 1;
//         }
//     }
// }

// void s0MotorTest(void *param)
// {
//     StepperMotor s0(26, 22, 21, 20);

//     int direction = 1;

//     while (true)
//     {
//         s0.rotateAngle(M_PI * direction);

//         if (direction == 1)
//         {
//             direction = -1;
//         }
//         else
//         {
//             direction = 1;
//         }
//     }
// }

// void s1MotorTest(void *param)
// {
//     StepperMotor s1(0, 1, 2, 3);

//     int direction = 1;

//     while (true)
//     {
//         s1.rotateAngle(M_PI * direction);

//         if (direction == 1)
//         {
//             direction = -1;
//         }
//         else
//         {
//             direction = 1;
//         }
//     }
// }

// void s2MotorTest(void *param)
// {
//     StepperMotor s2(4, 5, 6, 7);

//     int direction = 1;

//     while (true)
//     {
//         s2.rotateAngle(M_PI * direction);

//         if (direction == 1)
//         {
//             direction = -1;
//         }
//         else
//         {
//             direction = 1;
//         }
//     }
// }

// void e0MotorTest(void *param)
// {
//     StepperMotor motor(8, 11, 10, 9);

//     int direction = 1;

//     while (true)
//     {
//         motor.rotateAngle(M_PI / 2 * direction);

//         if (direction == 1)
//         {
//             direction = -1;
//         }
//         else
//         {
//             direction = 1;
//         }
//     }
// }

// bool connectToWifi = true;
// char myBuff[2048];

// err_t body(void *arg, struct altcp_pcb *conn,
//            struct pbuf *p, err_t err)
// {
//     printf("body\n");
//     pbuf_copy_partial(p, myBuff, p->tot_len, 0);
//     printf("%s", myBuff);

//     std::cout << "body?" << std::endl;
//     return ERR_OK;
// }

// void result(void *arg, httpc_result_t httpc_result,
//             u32_t rx_content_len, u32_t srv_res, err_t err)

// {
//     printf("transfer complete\n");
//     printf("local result=%d\n", httpc_result);
//     printf("http result=%d\n", srv_res);

//     std::cout << "result?" << std::endl;
// }

// err_t headers(httpc_state_t *connection, void *arg,
//               struct pbuf *hdr, u16_t hdr_len, u32_t content_len)
// {
//     printf("headers recieved\n");
//     printf("content length=%d\n", content_len);
//     printf("header length %d\n", hdr_len);
//     pbuf_copy_partial(hdr, myBuff, hdr->tot_len, 0);
//     printf("headers \n");
//     printf("%s", myBuff);

//     std::cout << "headers?" << std::endl;
//     return ERR_OK;
// }

// int setup(uint32_t country, const char *ssid,
//           const char *pass, uint32_t auth,
//           const char *hostname, ip_addr_t *ip,
//           ip_addr_t *mask, ip_addr_t *gw)
// {
//     if (cyw43_arch_init_with_country(country))
//     {
//         return 1;
//     }

//     cyw43_arch_enable_sta_mode();
//     if (hostname != NULL)
//     {
//         netif_set_hostname(netif_default, hostname);
//     }

//     if (cyw43_arch_wifi_connect_timeout_ms(ssid, pass, auth, 10000))
//     {
//         return 2;
//     }

//     int flashrate = 1000;
//     int status = CYW43_LINK_UP + 1;
//     while (status >= 0 && status != CYW43_LINK_UP)
//     {
//         int new_status = cyw43_tcpip_link_status(
//             &cyw43_state, CYW43_ITF_STA);
//         if (new_status != status)
//         {
//             status = new_status;
//             flashrate = flashrate / (status + 1);
//             printf("connect status: %d %d\n",
//                    status, flashrate);
//         }
//         cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
//         sleep_ms(flashrate);
//         cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
//         sleep_ms(flashrate);
//     }
//     if (status < 0)
//     {
//         cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
//     }
//     else
//     {
//         cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
//         if (ip != NULL)
//         {
//             netif_set_ipaddr(netif_default, ip);
//         }
//         if (mask != NULL)
//         {
//             netif_set_netmask(netif_default, mask);
//         }
//         if (gw != NULL)
//         {
//             netif_set_gw(netif_default, gw);
//         }
//         printf("IP: %s\n",
//                ip4addr_ntoa(netif_ip_addr4(netif_default)));
//         printf("Mask: %s\n",
//                ip4addr_ntoa(netif_ip_netmask4(netif_default)));
//         printf("Gateway: %s\n",
//                ip4addr_ntoa(netif_ip_gw4(netif_default)));
//         printf("Host Name: %s\n",
//                netif_get_hostname(netif_default));
//     }
//     return status;
// }

// int main()
// {

//     stdio_init_all();
//     setup(CYW43_COUNTRY_USA, "stashina", "9713445290", CYW43_AUTH_WPA2_MIXED_PSK, "MyPicoW", NULL, NULL, NULL);

//     // if (cyw43_arch_init())
//     // {
//     //     printf("Wi-Fi init failed");
//     //     return -1;
//     // }

//     for (int index = 0; index < 6; index++)
//     {
//         cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, index % 2);
//         sleep_ms(1000);
//         std::cout << index << std::endl;
//     }

//     cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);

    

//     // int connectioNResult = -1;

//     // cyw43_arch_enable_sta_mode();

//     // connectioNResult = cyw43_arch_wifi_connect_blocking("stashina", "9713445290", CYW43_AUTH_WPA2_MIXED_PSK);

//     // std::cout << "connection result: " << connectioNResult << std::endl;

//     // httpc_connection_t settings;
//     // settings.result_fn = result;

//     // err_t error = httpc_get_file(
//     //         "172.16.0.15",
//     //         "5000",
//     //         "/test"
//     //     );

    

//     std::cout << "before" << std::endl;
//     ip_addr_t ip;
//     IP4_ADDR(&ip, 172, 16, 300, 15);


//     httpc_connection_t settings;
//     settings.result_fn = result;
//     settings.headers_done_fn = headers;
    


//     // IP4_ADDR(&ip,127,0,0,1);

//     for (int index = 0; index < 10; index++) {
//         httpc_get_file(
//             &ip,
//             5000,
//             "/test",
//             &settings,
//             body,
//             NULL,
//             NULL
//         ); 
//     }




//     //printf("status %d \n", err2);
//     std::cout << "finished" << std::endl;

//     while (true){
//         sleep_ms(500);
//         std::cout << "boop" << std::endl;
//     }

//     // xTaskCreate(turntableMotorTest, "turntableMotorTest", 128, NULL, 1, NULL);

//     // xTaskCreate(s0MotorTest, "s0",128,NULL, 2, NULL);
//     // xTaskCreate(s1MotorTest, "s1",128,NULL, 2, NULL);
//     // xTaskCreate(s2MotorTest, "s2",128,NULL, 2, NULL);

//     // xTaskCreate(e0MotorTest,"e0", 128, NULL, 3, NULL);

//     // vTaskStartScheduler();

//     return 0;
// }
