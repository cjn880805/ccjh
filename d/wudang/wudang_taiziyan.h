//taiziyan.h

//Sample for room: �䵱̫����
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_taiziyan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱̫����");


	add_door("�䵱�㳡", "�䵱�㳡", "�䵱̫����");
	add_door("�䵱��÷԰", "�䵱��÷԰", "�䵱̫����");

    	

/*****************************************************
      set("exits",([  
           "northdown":__DIR__"shanlu4",
          "southdown": __DIR__"langmeiyuan",
      ]));
*****************************************************/
};


ROOM_END;
