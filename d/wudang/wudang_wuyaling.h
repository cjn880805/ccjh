//wuyaling.h

//Sample for room: �䵱��ѻ��
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_wuyaling);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱��ѻ��");


	add_door("�䵱��÷԰", "�䵱��÷԰", "�䵱��ѻ��");
	add_door("�䵱���Ϸ�", "�䵱���Ϸ�", "�䵱��ѻ��");

    

/*****************************************************
      set("objects", ([
                __DIR__"npc/wuya" : 5,
      ]));
      set("exits",([  
          "northdown": __DIR__"langmeiyuan",
          "southup"  : __DIR__"sanlaofeng",
      ]));
*****************************************************/
};


ROOM_END;
