//ertiangate.h

//Sample for room: �䵱������
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_ertiangate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱������");


	add_door("�䵱ͷ����", "�䵱ͷ����", "�䵱������");
	add_door("�䵱������", "�䵱������", "�䵱������");

    

/*****************************************************
      set("exits",([  
          "northdown": __DIR__"toutiangate",
          "southup"  : __DIR__"santiangate",
      ]));
*****************************************************/
};


ROOM_END;
