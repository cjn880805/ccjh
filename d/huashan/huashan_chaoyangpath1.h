//chaoyangpath1.h

//Sample for room: ������С·1
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_chaoyangpath1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������С·1");
	
	add_npc("pub_jianke");   //add by zdn 2001-07-20


	add_door("��ɽ���䳡", "��ɽ���䳡", "��ɽ������С·1");
	add_door("��ɽ������С·2", "��ɽ������С·2", "��ɽ������С·1");

	set("long", "�����ǳ�����С·��ɽ�ƶ��ͣ�����������ȣ�һ��С�Ķ��������ȥ��������һ��С·������û����");  
 
/*****************************************************
      set("outdoors", "xx");
      
      set("exits",([  
          "northeast": __DIR__"chaopath2",
          "southeast": __DIR__"square",
      ]));
********************************************/
};


ROOM_END;
