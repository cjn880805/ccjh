//dumo.h

//Sample for room: ��ĸ��
//coded by zouwenbin
//data: 2000-11-18

FIELD_BEGIN(CRTaiShan_dumo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ĸ��");

	set("monster_chance", 15);
	//add npcs into the room
	add_npc("pub_jianke");/////////////////////////

	add_door("̩ɽ", "̩ɽ", "̩ɽ��ĸ��");

	set("long","����һ��ɽ·������һ�㶼����������Ϊ��Ϣ������ĵ����Ѿ���̩ɽ�ڽ�������ɽΪ�ߣ��������������߱���ʯ������");

/*****************************************************
	set("exits", ([
		"eastup" : __DIR__"shijin",
		"southdown" : __DIR__"yitian",
	]));
	set("objects",([
		__DIR__"npc/jian-ke" : 1,
	]));
//	
	set("outdoors", "taishan");
*****************************************************/
};


FIELD_END;
//last, register the room into ../server/RoomSetup.cpp