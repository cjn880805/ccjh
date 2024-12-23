//westbridge.h

//Sample for room:  Ȫ�����ŵ���
//coded by Fisho
//data: 2000-11-4

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
RESIDENT_BEGIN(CRQuanzhou_westbridge);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ȫ�����ŵ���");

	set("resident", "Ȫ��");
	
	add_npc("pub_playboy");         //add by zdn 2001-07-14



	add_door("��ɽ�ּ��14", "��ɽ�ּ��14", "Ȫ�����ŵ���");
	add_door("Ȫ��", "Ȫ��", "Ȫ�����ŵ���");


	
	

/**************************************************************************
	set("outdoors", "foshan");
	set("exits",([ 
	    "west"  : "/d/foshan/road14",
	    "east"  : __DIR__"ximen",
	]));
***************************************************************************/
};


RESIDENT_END;
