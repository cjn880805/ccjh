//jiejianyan.h

//Sample for room: �䵱�⽣��
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_jiejianyan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱�⽣��");

	add_npc("wudang_shan");
	add_npc("zm_wudang");

	add_door("�䵱����", "�䵱����", "�䵱�⽣��");
	add_door("�䵱������", "�䵱������", "�䵱�⽣��");

	set("long","���������м���ʢ�����䵱�⽣�ң����½⽣��ˮ�������ˡ�������ʿ���˶��Ծ��⽣����ʾ���䵱�ɵ��𾴡�ǧ���������������⡣"); 
 
/*****************************************************
      set("objects", ([
           CLASS_D("wudang") +"/shan": 1,
      ]));
      set("outdoors", "wudang");
      set("exits",([  
          "eastdown"  : __DIR__"slxl2",
          "westup"    : __DIR__"slxl3",
      ]));
*****************************************************/
};


ROOM_END;
