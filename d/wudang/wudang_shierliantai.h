//shierliantai.h

//Sample for room: �䵱ʮ����̨
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_shierliantai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱ʮ����̨");


	add_door("�䵱��", "�䵱��", "�䵱ʮ����̨");

    

/*****************************************************
      set("exits",([  
          "east"     : __DIR__"jinding",
      ]));
*****************************************************/
};


ROOM_END;
