//chaopath2.h

//Sample for room: ������С·2
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_chaopath2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������С·2");
	
	add_npc("pub_daoke");        //add by zdn 2001-07-17


	add_door("��ɽ������С·1", "��ɽ������С·1", "��ɽ������С·2");
	add_door("��ɽ������", "��ɽ������", "��ɽ������С·2");
	add_door("��ɽ����̨", "��ɽ����̨", "��ɽ������С·2");

	set("long", "�����ǳ�����С·��ɽ�ƶ��ͣ�����������ȣ�һ��С�Ķ��������ȥ��������һ��С·������û����");  
 
/*****************************************************
      set("outdoors", "xx");
      set("exits",([  
          "southwest": __DIR__"chaopath1",
          "eastup"   : __DIR__"chaoyang",
          "westup"   : __DIR__"ziqitai",
      ]));
//      
      set("objects", ([
          __DIR__"npc/shi-daizi" : 1,
      ]));
********************************************/
};


ROOM_END;
