//zijincheng.h

//Sample for room: �䵱�Ͻ��
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_zijincheng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱�Ͻ��");


	add_door("�䵱��", "�䵱��", "�䵱�Ͻ��");
	add_door("�䵱���", "�䵱���", "�䵱�Ͻ��");

    

/*****************************************************
       set("exits",([  
          "north"     : __DIR__"jinding",
          "south"     : __DIR__"jindian",
      ]));
*****************************************************/
};


ROOM_END;
