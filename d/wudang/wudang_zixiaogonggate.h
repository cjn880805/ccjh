//zixiaogonggate.h

//Sample for room: �䵱����������
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_zixiaogonggate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱����������");


	add_door("�䵱ʮ����", "�䵱ʮ����", "�䵱����������");
	add_door("�䵱�㳡", "�䵱�㳡", "�䵱����������");

    

/*****************************************************
      set("exits",([  
          "northdown"  : __DIR__"shijie2",
          "southup"    : __DIR__"guangchang",
      ]));
      set("outdoors", "wudang");
*****************************************************/
};


ROOM_END;
