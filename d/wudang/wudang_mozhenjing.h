//mozhenjing.h

//Sample for room: �䵱ĥ�뾮
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_mozhenjing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱ĥ�뾮");

	add_npc("wudang_yu");

	add_door("�䵱ɽ·1", "�䵱ɽ·1", "�䵱ĥ�뾮");

    
    set("resource/water", 1);

/*****************************************************
      set("exits",([ 
          "west"     : __DIR__"shanlu1",
      ]));
      set("item_desc",([ 
          "jing"     : "���ع��ӣ�ˮɫ����������װƿ���á�\n",
      ]));
      set("outdoors", "wudang");
*****************************************************/
};


ROOM_END;
