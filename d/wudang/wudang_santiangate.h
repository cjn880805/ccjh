//santiangate.h

//Sample for room: �䵱������
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_santiangate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱������");


	add_door("�䵱������", "�䵱������", "�䵱������");
	add_door("�䵱��", "�䵱��", "�䵱������");

    

/*****************************************************
      set("exits",([  
          "northdown": __DIR__"ertiangate",
          "southup"  : __DIR__"jinding",
      ]));
*****************************************************/
};


ROOM_END;
