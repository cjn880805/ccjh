//haohanpo.h

//Sample for room: �䵱�ú���
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_haohanpo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱�ú���");
	add_npc("pub_songlingong");

	add_door("�䵱����", "�䵱����", "�䵱�ú���");
	add_door("�䵱ɽ·1", "�䵱ɽ·1", "�䵱�ú���");

	
    set("resource/water", 1);

/*****************************************************
      set("exits",([  
          "northdown": __DIR__"wdbl",
          "southdown": __DIR__"shanlu1",
      ]));
*****************************************************/
};


ROOM_END;
