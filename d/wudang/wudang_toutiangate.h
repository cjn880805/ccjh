//toutiangate.h

//Sample for room: �䵱ͷ����
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_toutiangate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱ͷ����");


	add_door("�䵱������", "�䵱������", "�䵱ͷ����");
	add_door("�䵱������", "�䵱������", "�䵱ͷ����");

    

/*****************************************************
      set("exits",([  
          "north"    : __DIR__"huixianqiao",
          "southup"  : __DIR__"ertiangate",
      ]));
*****************************************************/
};


ROOM_END;
