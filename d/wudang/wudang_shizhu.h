//shizhu.h

//Sample for room: �䵱ʯ��
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_shizhu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱ʯ��");


	add_door("�䵱���ҷ�", "�䵱���ҷ�", "�䵱ʯ��");
	add_door("�䵱���ҹ�", "�䵱���ҹ�", "�䵱ʯ��");

    	

/*****************************************************
      set("exits",([  
          "northup"  : __DIR__"nanyanfeng",
          "enter"    : __DIR__"nanyangong",
      ]));
*****************************************************/
};


ROOM_END;
