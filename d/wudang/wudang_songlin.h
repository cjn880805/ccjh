//songlin.h

//Sample for room: �䵱����
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_songlin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱����");

	//add npcs into the room
	add_npc("pub_xiaolouluo");
	add_npc("wudang_famu");
	

	add_door("�䵱����·3", "�䵱����·3", "�䵱����");
	add_door("�䵱��ʯ���1", "�䵱��ʯ���1", "�䵱����");
	add_door("�䵱�⽣��", "�䵱�⽣��", "�䵱����");

	set("long","������������������գ�������ֻ�о�������ǰ�󵽴�������Ӱ��������һ�����������ã�������ӫӫ���׹⡣�㾪��֮�䣬һ�Ų��ڸ����������ϣ�"); 
    
 
/*****************************************************
      set("objects", ([
           __DIR__"npc/xiao_louluo": 2,
      ]));
      set("outdoors", "wudang");
      set("exits",([  
          "south"  : __DIR__"songlin2",
      ]));
*****************************************************/
};


ROOM_END;
