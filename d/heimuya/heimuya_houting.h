//houting.h

//Sample for room: ��ľ�º���
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_houting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ľ�º���");

	//add npcs into the room
	add_npc("pub_zishanshizhe");

	add_door("��ľ�³ɵµ�", "��ľ�³ɵµ�", "��ľ�º���");
	add_door("��ľ��С��԰", "��ľ��С��԰", "��ľ�º���");

	set("long", "������������̵ĺ���������ȥ���ǻҳ������м���һ������ (wan)���ƺ��йŹ֡� ");
 
/*****************************************************
        set("exits", ([
                "east" : __DIR__"house1",
                "west" : __DIR__"restroom",
                "south":__DIR__"chengdedian",
        ]));
        set("objects" , ([
             __DIR__"npc/zish" : 4,
        ]));
        set("item_desc", ([
            "wan" : "����һ���Ժ��������µĹŶ����ܱ��¡�\n",
        ]));
********************************************/
};


ROOM_END;
