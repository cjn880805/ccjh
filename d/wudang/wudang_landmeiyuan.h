//landmeiyuan.h

//Sample for room: �䵱��÷԰
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_landmeiyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱��÷԰");

	add_npc("wudang_shouyuan");	

	add_door("�䵱̫����", "�䵱̫����", "�䵱��÷԰");
	add_door("�䵱���ҷ�", "�䵱���ҷ�", "�䵱��÷԰");
	add_door("�䵱��ѻ��", "�䵱��ѻ��", "�䵱��÷԰");

    

/*****************************************************
      set("objects", ([
            CLASS_D("wudang") +"/shouyuan": 1,

      ]));
      set("exits",([  
          "northup"  : __DIR__"taiziyan",
          "southup"  : __DIR__"wuyaling",
          "westup"   : __DIR__"nanyanfeng",
      ]));
      ]));
*****************************************************/
};


ROOM_END;
