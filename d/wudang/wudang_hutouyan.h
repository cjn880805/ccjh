//hutouyan.h

//Sample for room: �䵱��ͷ��
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_hutouyan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱��ͷ��");


	add_door("�䵱���Ϸ�", "�䵱���Ϸ�", "�䵱��ͷ��");
	add_door("�䵱���칬", "�䵱���칬", "�䵱��ͷ��");


/*****************************************************
      set("objects", ([
          __DIR__"npc/laohu" : 1,
      ]));
      set("exits",([  
          "northdown": __DIR__"wulaofeng",
          "southup"  : __DIR__"chaotiangong",
      ]));
*****************************************************/
};


ROOM_END;
