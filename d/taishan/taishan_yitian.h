//yitian.h

//Sample for room: ̩ɽһ����
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_yitian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽһ����");
	add_npc("pub_daoke");

	set("monster_chance", 40);

	add_door("̩ɽ�׺�Ȫ", "̩ɽ�׺�Ȫ", "̩ɽһ����");
	add_door("̩ɽ��ĸ��", "̩ɽ��ĸ��", "̩ɽһ����");


/*****************************************************
	set("exits", ([
		"northup" : __DIR__"doumo",
		"southdown" : __DIR__"baihe",
	]));
	set("objects",([
		__DIR__"npc/dao-ke" : 1,
	]));
*****************************************************/
};


FIELD_END;
