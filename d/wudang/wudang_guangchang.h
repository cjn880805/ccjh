//guangchang.h

//Sample for room: �䵱�㳡
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_guangchang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱�㳡");

	add_npc("wudang_yin");

	add_door("�䵱ʯ��", "�䵱ʯ��", "�䵱�㳡");
	add_door("�䵱�����", "�䵱�����", "�䵱�㳡");
	add_door("�䵱̫����", "�䵱̫����", "�䵱�㳡");
	add_door("�䵱����������", "�䵱����������", "�䵱�㳡");

	set("long","����һ���ɴ�ʯ���̳ɵĹ㳡�����䵱����ѧϰ�书�ͻ����д�ĵص㡣��Χ��������ͩ����һ������������ص���Ҷ��һ���������ĵ�ͯ���ڴ�ɨ���ϱ�������������");
    

/*****************************************************
      set("objects", ([
           CLASS_D("wudang") +"/daotong": 2,
      ]));
      set("exits",([  
          "northdown"  : __DIR__"zixiaogate",
          "south"      : __DIR__"sanqingdian",
          "eastdown"   : __DIR__"tyroad1",
          "east"       : __DIR__"shanlu2",
      ]));
*****************************************************/
};


ROOM_END;
