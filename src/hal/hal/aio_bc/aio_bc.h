#ifndef _BOON_AIO_CAMERA_H
#define _BOON_AIO_CAMERA_H

#include "common.h"
#include "bglobal.h"
#include "net_tcp.h"

/*
 * 智能机初始化
 * 1. 初始化相机
 */
bool aio_ipc_start();

/*
 * 开闸命令
 * flag: once表示开一次，keep表示一直开
 */
bool aio_open_door(std::string channel_id, std::string in_out,
		std::string flag);

/*
 * A通道推送车辆识别信息
 */
void aio_send_car_come_a();
/*
 * B通道推送车辆识别信息
 */
void aio_send_car_come_b();

/*抓拍相机类 AioCamera
 *
 */
class AioCamera
{
public:
	std::string camera_ip;
	std::string username;
	std::string password;
	std::string camera_label;	// A表示入口主机；AA表示入口辅机；B表示出口主机；BA表示出口辅机
	bool initialize();
	int listen_port;						//端口分配：A入口主机8080，AA入口辅机XXXX，B出口主机8090，BA出口辅机XXXX
public:
	NetTcpServer	tcp_server;	//Tcp接收器
};

//智能相机服务端侦听线程
void * aio_camera_loop(void* para);

#endif
