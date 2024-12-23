//lhqmen.h
//Sample for room: 刑堂
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_lhqmen);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "明教烈火旗大门");

	add_door("明教烈火旗牌坊", "明教烈火旗牌坊", "明教烈火旗大门");
	add_door("烈火旗牌坊", "明教烈火旗牌坊", "明教烈火旗大门");

	set("long", "这里是明教烈火旗的大门，庄严古朴，门前对插四面镶红飞龙旗。金色门钉扣在火漆红门上，分外精神。也是通往明教总舵的必经之地。所以来往的人也特别多。    冷谦执掌明教刑堂。");
    

/*****************************************************

********************************************/

};


ROOM_END;
