//beiyidao.h

//Sample for room:  ���ݱ����
//coded by zwb
//data: 2000-11-22

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_beiyidao);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݱ����");

	//add npcs into the room
	add_npc("pub_poorman"); 
	add_npc("pub_playboy");       //add by zdn 2001-07-16

	//add exits for room
	//the first param: door id
	//from the second to the fifth params: position of door
	//the sixth param: to next room
	//the seventh param: to next door id of next room
	add_door("���ݱ���","���ݱ���","���ݱ����");
	add_door("�ƺ�����1","�ƺ�����1","���ݱ����");

    set("long","������һ����������Ĵ�����ϡ��������������������ӵ����̣����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������߷ɳ۶���������һ·��������·��������������������֡��������ݿ쵽�ˡ�");
	

/********************************************************
	set("exits", ([
		"south" : "/d/city/beimen",
		"north" : __DIR__"yidao1",
	]));
	set("outdoors", "shaolin");
*******************************************************/
 
};


ROOM_END;
