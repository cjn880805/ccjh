//sanlaofeng.h

//Sample for room: �䵱���Ϸ�
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_sanlaofeng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱���Ϸ�");
	add_npc("pub_xucong");

	add_door("�䵱��ѻ��", "�䵱��ѻ��", "�䵱���Ϸ�");
	add_door("�䵱���Ϸ�", "�䵱���Ϸ�", "�䵱���Ϸ�");

    

/*****************************************************
      set("exits",([  
          "northdown": __DIR__"wuyaling",
          "southup"  : __DIR__"wulaofeng",
      ]));
*****************************************************/
};


ROOM_END;
