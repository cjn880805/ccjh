//taoyuan.h

//Sample for room: ��԰
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRWuDang_taoyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��԰");
        set("sleep_room",1);
	//add_npc("shouyuan");
		add_npc("helpnpc020");

	add_door("�䵱��԰С·2", "�䵱��԰С·2", "�䵱��԰");

	set("taocount",2);

/*****************************************************
	set("exits", ([
		"east" : __DIR__"lameigt",
	]));
	
	set("item_desc", ([
        	"feng" : (:look_feng:),
		"tree" : 
"����һƬ���֣����������ˮ���ң������˹����Ӷ��������ˡ�\n"
	 ]));
	set("objects", ([
 		CLASS_D("wudang") + "/shouyuan" : 1,
		__DIR__"npc/"+npcs[i] : 1
	]));
*****************************************************/
};


ROOM_END;
