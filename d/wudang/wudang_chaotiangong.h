//chaotiangong.h

//Sample for room: �䵱���칬
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_chaotiangong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱���칬");

	add_npc("wudang_qingxu");	

	add_door("�䵱��ͷ��", "�䵱��ͷ��", "�䵱���칬");
	add_door("�䵱������", "�䵱������", "�䵱���칬");


/*****************************************************
      set("objects", ([
           CLASS_D("wudang") +"/qingxu": 1,
      ]));

      set("exits",([  
          "northdown": __DIR__"hutouyan",
          "south"    : __DIR__"huixianqiao",
      ]));
*****************************************************/
};


ROOM_END;
