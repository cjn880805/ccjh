//riyuetan.h

//Sample for room: ̨������̶
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRTaiWan_riyuetan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "̨������̶");

	set("monster_chance", 20);
	add_npc("pub_wangyiming");
	add_npc("pub_wangyipeng");

	add_door("̨��ĵ�", "̨��ĵ�", "̨������̶");

	set("long", "��廷������ˮ�α̵�����̶��̶���������֣�̶���������£�Ϊ̨�����ʤ�ء�  " );
	

/*****************************************************
	set("exits", ([
                "westdown" : __DIR__"chiqian",
	]));
********************************************/
};


ROOM_END;
