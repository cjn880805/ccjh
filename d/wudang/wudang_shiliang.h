//shiliang.h

//Sample for room: �䵱ʯ��
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_shiliang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱ʯ��");


	add_door("�䵱̫����", "�䵱̫����", "�䵱ʯ��");
	add_door("�䵱С�Ե�", "�䵱С�Ե�", "�䵱ʯ��");
	add_door("�䵱ʮ����", "�䵱ʮ����", "�䵱ʯ��");

   	

/*****************************************************
      set("exits",([  
          "northup"    : __DIR__"taizipo",
          "southup"    : __DIR__"shibapan",
          "east"       : __DIR__"shop",
      ]));
*****************************************************/
};


ROOM_END;
