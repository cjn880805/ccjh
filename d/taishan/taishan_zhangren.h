//zhangren.h

//Sample for room: ̩ɽ���˷�
//coded by zouwenbin
//data: 2000-11-28

FIELD_BEGIN(CRTaiShan_zhangren);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̩ɽ���˷�");

	set("monster_chance", 20);
	//add npcs into the room
	add_npc("pub_weishi2");
	
	add_door("̩ɽ��ʶ�", "̩ɽ��ʶ�", "̩ɽ���˷�");
	add_door("̩ɽ������", "̩ɽ������", "̩ɽ���˷�");

	set("long","����λ����ʶ���������ĵط�����״����һ�����͵����ˡ������лƻ�������·��ΪΣ�գ������ڽ�·��д�ϡ��س��ҡ��������������߱���᷶��ı����š�");
	

/*****************************************************
	set("exits", ([
		"east" : __DIR__"yuhuang",
		"northup" : __DIR__"beitian",
	]));
	set("objects",([
		__DIR__"npc/wei-shi1" : 2,
	]));
*****************************************************/
};


FIELD_END;
