//doumo.h

//Sample for room: ̩ɽ��ĸ��
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_doumo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽ��ĸ��");

	set("monster_chance", 16);

	add_door("̩ɽһ����", "̩ɽһ����", "̩ɽ��ĸ��");
	add_door("̩ɽʯ����", "̩ɽʯ����", "̩ɽ��ĸ��");

	set("long","����һ��ɽ·������һ�㶼����������Ϊ��Ϣ������ĵ����Ѿ���̩ɽ�ڽ�������ɽΪ�ߣ��������������߱���ʯ������");

/*****************************************************
	set("exits", ([
		"eastup" : __DIR__"shijin",
		"southdown" : __DIR__"yitian",
	]));
	set("objects",([
		__DIR__"npc/jian-ke" : 1,
	]));
*****************************************************/
};


FIELD_END;
