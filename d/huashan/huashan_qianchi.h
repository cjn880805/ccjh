//qianchi.h

//Sample for room: ��ɽǧ�ߴ�
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_qianchi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽǧ�ߴ�");

	//add npcs into the room
	add_npc("pub_youke");
	add_npc("huashan_cong_buqi");

	add_door("��ɽ����ʯ", "��ɽ����ʯ", "��ɽǧ�ߴ�");
	add_door("��ɽ�ٳ�Ͽ", "��ɽ�ٳ�Ͽ", "��ɽǧ�ߴ�");

	set("long", "ǰ����һб���촹ʯ�ݵ�ɽ�ף�����Ǻպ�������ǧ�ߴ���ǧ�ߴ�����һ�����Ҽ����ѷ쿪����ɣ�б��Լ��ʮ�ȣ���Լ��ʮ�ף�����һ�����䡣̧ͷ����һ����⣬�����ұڶ��ͣ���ͷ�Ǹ���������ķ���ʯ�����׳ơ��쾮�����쾮�Ե�Σ���Ͽ��С�̫���ʺ�����̡�");  
    
 
/*****************************************************
        set("exits", ([  
            "westdown" : __DIR__"huixinshi",
            "southup" : __DIR__"baichi",
        ]));
        set("objects", ([
            __DIR__"npc/youke": 2,
        ]));
********************************************/
};


ROOM_END;
