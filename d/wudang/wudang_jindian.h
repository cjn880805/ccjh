//jindian.h

//Sample for room: ���
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRWuDang_jindian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���");


	add_door("�䵱�Ͻ��", "�䵱�Ͻ��", "�䵱���");


/*****************************************************
      set("exits",([ 
          "north"     : __DIR__"zijincheng",
      ]));
      
*****************************************************/
};


ROOM_END;
