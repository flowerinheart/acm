


    if((sock_fd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_IP) < 0)) < 0) {
        printf("fail to create_raw_socket\n");
        return -1;
    }
    while(true) {
        //not need src_addr, 
        unsigned char *buffer = (unsigned char *) malloc(65536); 
        memset(buffer,0,65536);
        struct sockaddr saddr;
        int saddr_len = sizeof (saddr);
//Receive a network packet and copy in to buffer
buflen=recvfrom(sock_r,buffer,65536,0,&saddr,(socklen_t *)&saddr_len)
        n_read  = recvfrom(sock_fd, buffer, 2048, 0, NULL, NULL);
    }
