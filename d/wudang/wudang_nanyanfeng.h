//nanyanfeng.h

//Sample for room: �䵱���ҷ�
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_nanyanfeng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱���ҷ�");

	add_npc("wudang_mo");
	add_npc("wudang_xiaosong");

	add_door("�䵱ʯ��", "�䵱ʯ��", "�䵱���ҷ�");
	add_door("�䵱������", "�䵱������", "�䵱���ҷ�");
	add_door("�䵱��÷԰", "�䵱��÷԰", "�䵱���ҷ�");

    

/*****************************************************
      set("objects", ([
           CLASS_D("wudang") +"/mo": 1,
      ]));

      set("exits",([  
          "eastdown" : __DIR__"langmeiyuan",
          "southdown": __DIR__"shizhu",
          "west"     : __DIR__"sheshenya",
      ]));
*****************************************************/
};


ROOM_END;
