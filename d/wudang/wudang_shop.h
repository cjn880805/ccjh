//shop.h

//Sample for room: С�Ե�
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRWuDang_shop);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "С�Ե�");

	//add npcs into the room
	add_npc("pub_xiaoer2");/////////////////////////

	add_door("�䵱ʯ��", "�䵱ʯ��", "�䵱С�Ե�");


/*****************************************************
     	set("exits", ([
            "west" : __DIR__"shiliang",
       	]));

        set("objects", ([
            "/d/city/npc/xiaoer2" : 1,
       	]));
*****************************************************/
};


ROOM_END;
