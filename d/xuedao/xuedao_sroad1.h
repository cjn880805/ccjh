//sroad1.h

//Sample for room:  Ѫ����ѩɽ·1
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_sroad1);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѫ����ѩɽ·1");



	add_door("Ѫ����ѩɽ·2", "Ѫ����ѩɽ·2", "Ѫ����ѩɽ·1");
	add_door("�ɶ��Ϻ���", "�ɶ��Ϻ���", "Ѫ����ѩɽ·1");

	set("long","�������ǳ�ɽ���룬��ͨ���㡣һ��ɽ·������ɽ�䣬�����Ųرߺ���ԭ��");
    

/******************************************************************************
        set("exits",([
                "north"  : "/d/city3/nanheqiaos",
                "westup" : __DIR__"sroad2",
        ]));
******************************************************************************/
};


ROOM_END;
