//gaotai.h

//Sample for room: �䵱���ҹ���̨
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_gaotai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱���ҹ���̨");

	add_npc("wudang_wuxing");	
	add_npc("wudang_wuxing");
	add_npc("wudang_wuxing");
	add_npc("wudang_wuxing");
	add_npc("wudang_wuxing");

	add_npc("wudang_bagua");	
	add_npc("wudang_bagua");	
	add_npc("wudang_bagua");	
	add_npc("wudang_bagua");	
	add_npc("wudang_bagua");	
	add_npc("wudang_bagua");	
	add_npc("wudang_bagua");	
	add_npc("wudang_bagua");	

	add_npc("wudang_yan");	

	add_door("�䵱���ҹ�", "�䵱���ҹ�", "�䵱���ҹ���̨");

    

/*****************************************************
      set("objects", ([
           CLASS_D("wudang") +"/wuxing": 5,
           CLASS_D("wudang") +"/bagua": 8,
           CLASS_D("wudang") +"/yan": 1,
      ]));
      set("exits",([  
          "northdown" : __DIR__"nanyangong",
      ]));
*****************************************************/
};


ROOM_END;
