//wulaofeng.h

//Sample for room: �䵱���Ϸ�
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_wulaofeng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱���Ϸ�");


	add_door("�䵱���Ϸ�", "�䵱���Ϸ�", "�䵱���Ϸ�");
	add_door("�䵱��ͷ��", "�䵱��ͷ��", "�䵱���Ϸ�");

    

/*****************************************************
      set("exits",([  
          "northdown": __DIR__"sanlaofeng",
          "southup"  : __DIR__"hutouyan",
      ]));
      set("outdoors", "wudang");
*****************************************************/
};


ROOM_END;
