//taizipo.h

//Sample for room: �䵱̫����
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_taizipo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱̫����");


	add_door("�䵱ɽ·1", "�䵱ɽ·1", "�䵱̫����");
//	add_door("�䵱�����", "�䵱�����", "�䵱̫����");
	add_door("�䵱ʯ��", "�䵱ʯ��", "�䵱̫����");

	set("long","�˴��ش�����֮����������Ҫ���ഫ���ֹ�̫��(��������)��ɽ�޵�ʱ�����ڴ���ס���飬������̫���£�����һ���ˮܽ�أ�ӿ���̲�����������������Զ�����·ת���������𣬾�������֮�С�");
    

/*****************************************************
      set("exits",([  
          "northdown"  : __DIR__"shanlu1",
          "southdown"  : __DIR__"shiliang",
          "east"       : __DIR__"fuzhenguan",
      ]));
*****************************************************/
};


ROOM_END;
