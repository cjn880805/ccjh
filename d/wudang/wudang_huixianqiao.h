//huixianqiao.h

//Sample for room: �䵱������
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_huixianqiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱������");

	add_npc("pub_yuzhuzi");
	add_door("�䵱���칬", "�䵱���칬", "�䵱������");
	add_door("�䵱ͷ����", "�䵱ͷ����", "�䵱������");

    

/*****************************************************
      set("exits",([  
          "north"    : __DIR__"chaotiangong",
          "south"    : __DIR__"toutiangate",
      ]));
*****************************************************/
};


ROOM_END;
